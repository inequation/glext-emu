#!/usr/bin/env python
"""
glext-emu - code generator script for the EXT_direct_state_access extension

Copyright (c) 2013 Leszek Godlewski

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
"""

import glext_emu
import sys
from os import path

# Concatenates argument dictionary into a string.
def get_args_string(args, print_types = True):
	fstr = print_types and '{0} {1}, ' or '{1}, '
	s = ''
	for a in args:
		s += fstr.format(a['type'], a['name'])
	return s == '' and s or s[:-2]

def fixup_internal_format(command, args):
	for a in args:
		if ('Copy' not in command and 'Compressed' not in command and
			'Buffer' not in command and
			a['type'] == 'GLenum' and a['name'] == 'internalformat'):
			a['type'] = 'GLifmt'
		if (a['type'] == 'const GLvoid*'):
			a['type'] = 'const void*'
	return args

# This is where the magic is done: state binding and classic OpenGL command
# generation.
def get_indirect_info(proto):
	info = {}
	if (proto['command'].startswith('Matrix')):
		# work out the classic command name
		classic = proto['command'][6:-3]	# drop the prefix and suffix
		# determine data type suffix
		suffix = ''
		if (classic.endswith('f')):
			suffix = 'f'
			classic = classic[:-1]
		elif (classic.endswith('d')):
			suffix = 'd'
			classic = classic[:-1]
		classic = 'Identity' in classic								\
			and 'LoadIdentity'										\
			or ('Translate' in classic or 'Rotate' in classic 		\
				 or 'Scale' in classic or 'Frustum' in classic		\
				 or 'Ortho' in classic)								\
				and (classic + suffix)								\
				or (classic + 'Matrix') + suffix
		
		info['prologue'] = '_GLEXTEMU_MATRIX_MODE(mode)'
		info['epilogue'] = 'GLEXTEMU_POP_MATRIX_MODE'
		info['command'] = classic
		info['args'] = proto['args'][1:]
	elif (proto['command'].startswith('Texture')
	   or proto['command'].startswith('CopyTexture')
	   or proto['command'].startswith('GetTexture')
	   or proto['command'].startswith('CompressedTexture')
	   or proto['command'].startswith('GetCompressedTexture')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Texture', 'Tex', 1)
		if ('Renderbuffer' in classic):
			classic += 'NV'
		
		info['prologue'] = '_GLEXTEMU_TEXTURE(texture, target)'
		info['epilogue'] = 'GLEXTEMU_POP_TEXTURE(target)'
		info['command'] = classic
		info['args'] = fixup_internal_format(proto['command'], proto['args'][1:])
	elif (proto['command'].startswith('MultiTex')
	   or proto['command'].startswith('CopyMultiTex')
	   or proto['command'].startswith('GetMultiTex')
	   or proto['command'].startswith('BindMultiTex')
	   or proto['command'].startswith('CompressedMultiTex')
	   or proto['command'].startswith('GetCompressedMultiTex')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Multi', '', 1)
		if (classic == 'BindTex'):
			classic = 'BindTexture'
		elif ('Renderbuffer' in classic):
			classic += 'NV'
		
		info['prologue'] = '_GLEXTEMU_ACTIVE_TEXTURE(texunit)'
		info['epilogue'] = 'GLEXTEMU_POP_ACTIVE_TEXTURE'
		info['command'] = classic
		info['args'] = fixup_internal_format(proto['command'], proto['args'][1:])
	elif (proto['command'].startswith('EnableClientState')
	   or proto['command'].startswith('DisableClientState')):
		# work out the classic command name
		classic = proto['command'][:proto['command'].find('State') + 5]
		
		info['prologue'] = '_GLEXTEMU_CLIENT_ACTIVE_TEXTURE(index)'
		info['epilogue'] = 'GLEXTEMU_POP_'
		info['command'] = classic
		info['args'] = proto['args'][:1]
		if (len(proto['args']) > 2):
			info['args'] += proto['args'][2:]
	elif (proto['command'].startswith('NamedBuffer')
	   or proto['command'].startswith('MapNamedBuffer')
	   or proto['command'].startswith('UnmapNamedBuffer')
	   or proto['command'].startswith('GetNamedBuffer')
	   or proto['command'].startswith('ClearNamedBuffer')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Named', '', 1)
		
		info['prologue'] = '_GLEXTEMU_BUFFER(buffer)'
		info['epilogue'] = 'GLEXTEMU_POP_BUFFER'
		info['command'] = classic
		info['args'] = proto['args'][1:]
		info['args'].insert(0, {'type' : 'GLenum', 'name': 'GL_ARRAY_BUFFER'})
	elif (proto['command'].startswith('ProgramUniform')
	   or proto['command'].startswith('NamedProgram')
	   or proto['command'].startswith('GetNamedProgram')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Named', '', 1)
		classic = classic.replace('ProgramUniform', 'Uniform', 1)
		if ('LocalParameterI' in classic or 'LocalParametersI' in classic):
			classic += 'NV'
		elif ('LocalParameters' in classic):
			classic += 'EXT'
		elif ('ProgramString' in classic or 'LocalParameter' in classic):
			classic += 'ARB'
		
		info['prologue'] = '_GLEXTEMU_PROGRAM(program)'
		info['epilogue'] = 'GLEXTEMU_POP_PROGRAM'
		info['command'] = classic
		info['args'] = proto['args'][1:]
	elif (proto['command'].startswith('NamedRenderbuffer')
	   or proto['command'].startswith('GetNamedRenderbuffer')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Named', '', 1)
		if ('MultisampleCoverage' in classic):
			classic += 'NV'
		
		info['prologue'] = '_GLEXTEMU_RENDERBUFFER(renderbuffer)'
		info['epilogue'] = 'GLEXTEMU_POP_RENDERBUFFER'
		info['command'] = classic
		info['args'] = proto['args'][1:]
		info['args'].insert(0, {'type' : 'GLenum', 'name': 'GL_RENDERBUFFER'})
	elif (proto['command'].startswith('NamedFramebuffer')
	   or proto['command'].startswith('CheckNamedFramebuffer')
	   or proto['command'].startswith('GetNamedFramebuffer')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Named', '', 1)
		if ('TextureFace' in classic):
			classic += 'EXT'
		
		info['prologue'] = '_GLEXTEMU_FRAMEBUFFER(framebuffer)'
		info['epilogue'] = 'GLEXTEMU_POP_FRAMEBUFFER'
		info['command'] = classic
		info['args'] = proto['args'][(classic.startswith('Check') and 0 or 1):]
		if ('Texture' in classic or 'Renderbuffer' in classic	\
			or 'AttachmentParameter' in classic):
			info['args'].insert(0, {'type': 'GLenum', 'name': 'GL_FRAMEBUFFER'})
	elif (proto['command'].startswith('GenerateTexture')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Texture', '', 1)
		
		info['prologue'] = '_GLEXTEMU_TEXTURE(texture, target)'
		info['epilogue'] = 'GLEXTEMU_POP_TEXTURE(target)'
		info['command'] = classic
		info['args'] = proto['args'][1:]
	elif (proto['command'].startswith('GenerateMultiTex')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('MultiTex', '', 1)
		
		info['prologue'] = '_GLEXTEMU_ACTIVE_TEXTURE(texunit)'
		info['epilogue'] = 'GLEXTEMU_POP_ACTIVE_TEXTURE'
		info['command'] = classic
		info['args'] = proto['args'][1:]
	elif (proto['command'].startswith('Framebuffer')
	   or proto['command'].startswith('GetFramebuffer')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Framebuffer', '', 1)
		
		info['prologue'] = '_GLEXTEMU_FRAMEBUFFER(framebuffer)'
		info['epilogue'] = 'GLEXTEMU_POP_FRAMEBUFFER'
		info['command'] = classic
		info['args'] = proto['args'][1:]
	elif (proto['command'].startswith('NamedCopyBuffer')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Named', '', 1)
		
		info['prologue'] = '_GLEXTEMU_BUFFER_COPY(readBuffer, writeBuffer)'
		info['epilogue'] = 'GLEXTEMU_POP_BUFFER_COPY'
		info['command'] = classic
		info['args'] = [
			{'type' : 'GLenum', 'name': 'GL_COPY_READ_BUFFER'},
			{'type' : 'GLenum', 'name': 'GL_COPY_WRITE_BUFFER'}
		] + proto['args'][2:]
	elif (proto['command'].startswith('VertexArray')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('VertexArray', '', 1)
		classic = classic.replace('Offset', 'Pointer', 1)
		multitex = 'MultiTex' in classic
		if (multitex):
			classic = classic.replace('MultiTex', 'Tex', 1)
		
		info['prologue'] = '_GLEXTEMU_VERTEX_ARRAY(vaobj)\n\t' +	\
						   '_GLEXTEMU_BUFFER(buffer)'
		info['epilogue'] = 'GLEXTEMU_POP_BUFFER\n\t' + 		\
						   'GLEXTEMU_POP_VERTEX_ARRAY'
		info['command'] = classic
		info['args'] = proto['args'][2:]
		if (multitex):
			info['prologue'] += '\n\t_GLEXTEMU_ACTIVE_TEXTURE(texunit)'
			info['epilogue'] += '\n\tGLEXTEMU_POP_ACTIVE_TEXTURE'
			info['args'] = info['args'][1:]
		if (info['args'][-1]['type'] == 'GLintptr'):
			info['args'][-1] = {'type': 'void *', 'name': '(void *)' + info['args'][-1]['name']}
	elif (proto['command'].startswith('EnableVertexArray')
	   or proto['command'].startswith('DisableVertexArray')
	   or proto['command'].startswith('GetVertexArray')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('VertexArrayAttrib',
												'VertexAttribArray', 1)
		attrib = False
		if (classic.startswith('Get')):
			if ('Pointer' in classic and classic.endswith('i_v')):
				attrib = True
				classic = classic.replace('VertexArray', 'VertexAttrib', 1)
				classic = classic.replace('i_v', 'v', 1)
			else:
				classic = classic.replace('VertexArray', '', 1)
		else:
			classic = classic.replace('VertexArray', 'ClientState', 1)
		
		info['prologue'] = '_GLEXTEMU_VERTEX_ARRAY(vaobj)'
		info['epilogue'] = 'GLEXTEMU_POP_VERTEX_ARRAY'
		info['command'] = classic
		info['args'] = proto['args'][1:]
	elif (proto['command'].startswith('FlushMappedNamed')
	   or proto['command'].startswith('MapNamed')):
		# work out the classic command name
		classic = proto['command'][:-3].replace('Named', '', 1)
		
		info['prologue'] = '_GLEXTEMU_BUFFER(buffer)'
		info['epilogue'] = 'GLEXTEMU_POP_BUFFER'
		info['command'] = classic
		info['args'] = proto['args'][1:]
		info['args'].insert(0, {'type' : 'GLenum', 'name': 'GL_ARRAY_BUFFER'})
	elif (proto['command'].startswith('Enable')
	   or proto['command'].startswith('Disable')):
		# work out the classic command name
		# FIXME!!! glEnablei/glDisablei calls need to be forwarded for some caps
		classic = proto['command'][:(max(proto['command'].find('I'),
										 proto['command'].find('i')))]
		
		info['prologue'] = '_GLEXTEMU_ACTIVE_TEXTURE(index)'
		info['epilogue'] = 'GLEXTEMU_POP_ACTIVE_TEXTURE'
		info['command'] = classic
		info['args'] = proto['args'][1:]
	else:
		sys.exit('I don\'t know how to handle {0} gl{1}({2})!'.format(
			proto['return_type'], proto['command'],
			get_args_string(proto['args'])))
	
	return info

extension = 'EXT_direct_state_access'
prototypes = glext_emu.load_prototypes('GL_' + extension)
tf = open(path.join('templates', extension + '.h.in'), 'r')
template = tf.read().replace('{', '{{').replace('}', '}}').replace('GLEXTEMU_AUTOGEN', '{0}')
tf.close()

# Special cases where commands need to be handled manually.
manual = [
	'ClientAttribDefaultEXT',
	'PushClientAttribDefaultEXT',
	'EnableClientStateIndexedEXT',
	'DisableClientStateIndexedEXT',
	'EnableClientStateiEXT',
	'DisableClientStateiEXT',
	'GetBooleanIndexedvEXT',
	'GetIntegerIndexedvEXT',
	'GetFloatIndexedvEXT',
	'GetDoubleIndexedvEXT',
	'GetPointerIndexedvEXT',
	'GetBooleani_vEXT',
	'GetIntegeri_vEXT',
	'GetFloati_vEXT',
	'GetDoublei_vEXT',
	'GetPointeri_vEXT',
	'IsEnabledIndexedEXT',
	'IsEnabledi',
	'GetFramebufferParameterivEXT',
	# FIXME: NV_gpu_program4 madness
	'GetNamedProgramLocalParameterIivEXT',
	'GetNamedProgramLocalParameterIuivEXT'
]

definitions = ''
for p in prototypes:
	if (p['command'] in manual):
		continue
	indirect = get_indirect_info(p)
	statement = 'return '
	if (p['return_type'] == 'void'):
		statement = ''
	definitions += """_GLEXTEMU_CMD
(
{0}, {1}, ({2}),
{{
	{3}
	{4}_GLEXTEMU_PFN_PREFIXED({5})({6});
	{7}
}}
)

""".format(p['return_type'], p['command'], get_args_string(p['args']),
		indirect['prologue'], statement, indirect['command'],
		get_args_string(indirect['args'], False), indirect['epilogue'])

header_content = template.format(definitions)
header_content = """// GENERATED AUTOMATICALLY - DO NOT MODIFY!!!
// Run ../generators/EXT_direct_state_access.py to regenerate the actual header.

""" + header_content[header_content.find('/*'):]
header = open(path.join('..', 'include', 'GL', 'glext-emu', extension + '.h'), 'w')
header.write(header_content)
header.close()
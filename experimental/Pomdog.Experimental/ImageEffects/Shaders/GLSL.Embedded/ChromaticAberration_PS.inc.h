﻿//
//  Copyright (C) 2013-2014 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

char const* Builtin_GLSL_ChromaticAberration_PS =
"#version 330\n"
"in QuadVertexShaderOutput{\n"
"vec2 TextureCoord;}In;\n"
"uniform Constants{\n"
"vec2 RenderTargetPixelSize;};\n"
"uniform sampler2D AlbedoSampler;\n"
"out vec4 FragColor;\n"
"float CircleVignette(in vec2 textureCoord,in float radius,in float softness){\n"
"vec2 position=In.TextureCoord.xy-vec2(0.5);\n"
"float len=length(position);\n"
"float vignette=smoothstep(radius,radius-softness,len);\n"
"return vignette;}\n"
"vec3 ChromaticAberration(in vec2 texCoord,in vec2 red,in vec2 green,in vec2 blue){\n"
"const float radius=0.998;\n"
"const float softness=0.95;\n"
"float amount=1.0-CircleVignette(texCoord,radius,softness);\n"
"float r=texture(AlbedoSampler,texCoord+red*amount).r;\n"
"float g=texture(AlbedoSampler,texCoord+green*amount).g;\n"
"float b=texture(AlbedoSampler,texCoord+blue*amount).b;\n"
"return vec3(r,g,b);}\n"
"void main(){\n"
"vec2 inverseScreenSize=1.0/RenderTargetPixelSize;\n"
"vec2 red=vec2(-3.0,-3.0)*inverseScreenSize;\n"
"vec2 green=vec2(0.0,0.0)*inverseScreenSize;\n"
"vec2 blue=vec2(3.0,3.0)*inverseScreenSize;\n"
"vec3 color=ChromaticAberration(In.TextureCoord.xy,red,green,blue);\n"
"FragColor=vec4(color.xyz,1.0);}\n";
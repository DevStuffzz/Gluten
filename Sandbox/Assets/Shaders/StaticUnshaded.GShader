#type vertex
#version 330 core
// This is a shader that is flat and unshaded

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoords;

uniform vec4 u_Color;
uniform mat4 u_Transform;
uniform mat4 u_Projection

out vec2 v_TexCoords;
out vec4 v_Color;

void main() {
	v_TexCoords = a_TexCoords;
	v_Color = u_Color * a_Color;
	gl_Position = u_Projection * u_Transform * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

in vec2 v_TexCoords;
in vec4 v_Color;
uniform sampler2D u+Texture;

out vec4 color;

void main() {
	color = texture(uTexture, vTexCoords) * v_Color;
}
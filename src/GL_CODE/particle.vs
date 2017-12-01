#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aOffset;
layout (location = 2) in vec4 color;

out vec4 o_color;

uniform float size;

void main()
{
		o_color = color;
    gl_Position = vec4((aPos * size) + aOffset, 1.0);
}

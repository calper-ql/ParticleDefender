#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aOffset;

uniform float size;

void main()
{
    gl_Position = vec4((aPos * size) + aOffset, 1.0);
}

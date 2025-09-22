#version 330 core
//NOTE: light doesn't have a color attribute like the other objects, as it is drawn as a single color
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}

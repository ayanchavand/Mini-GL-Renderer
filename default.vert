#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vertexColor;   // pass color to fragment shader
out vec2 texCoord;      // pass texcoord to fragment shader

uniform float scale;

void main()
{
    gl_Position = vec4(aPos * scale, 1.0);
    vertexColor = aColor;
    texCoord = aTexCoord;
}

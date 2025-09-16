#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vertexColor;   // pass color to fragment shader
out vec2 texCoord;      // pass texcoord to fragment shader

uniform float scale;

//MVP matricies
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{   
    // Since this is matrix multiplication the order matters
    gl_Position = projection * view * model * vec4(aPos * scale, 1.0);
    vertexColor = aColor;
    texCoord = aTexCoord;
}

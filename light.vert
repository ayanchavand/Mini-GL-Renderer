#version 330 core
layout (location = 0) in vec3 aPos;    // vertex position
layout (location = 1) in vec3 aColor;  // vertex color


out vec3 vertexColor;   // pass color to fragment shader

//uniform float scale;

// MVP matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{   
    // Transform vertex position
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    // Pass color to fragment shader
    vertexColor = aColor;
}

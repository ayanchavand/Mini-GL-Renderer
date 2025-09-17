#version 330 core
out vec4 FragColor;

in vec3 vertexColor; // this comes from your vertex shader

void main()
{
    // Just use the color that was passed from the vertex shader
    FragColor = vec4(vertexColor, 1.0);
}

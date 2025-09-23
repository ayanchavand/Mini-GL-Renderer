#version 330 core
layout (location = 0) in vec3 aPos;    // vertex position
layout (location = 1) in vec3 aColor;  // vertex color
layout (location = 2) in vec3 aNormal; // vertex normal)

out vec3 vertexColor;   // pass color to fragment shader
out vec3 Normal;      // pass normal to fragment shader
out vec3 FragPos;    // pass fragment position to fragment shader
//uniform float scale;

// MVP matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{   
    // Transform vertex position
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    FragPos = vec3(model * vec4(aPos, 1.0));
    // Pass color to fragment shader
    vertexColor = aColor;

    //TODO: Understand what these two lines do that make the lighting work correctly with rotation and scaling
    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 normal = normalize(normalMatrix * aNormal);


    // Pass normal to fragment shader
    Normal = normal;
}

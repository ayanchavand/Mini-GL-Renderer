#version 330 core
out vec4 FragColor;

in vec3 vertexColor; // from vertex shader
in vec3 Normal;      // transformed normal
in vec3 FragPos;     // world-space position

uniform vec3 lightColor;
uniform vec3 lightPos;   // position of the light in world space
uniform vec3 viewPos;    // camera position for specular later

void main()
{
    // --- Ambient ---
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;

    // --- Diffuse ---
    vec3 norm = normalize(Normal);                  // make sure normal is unit length
    vec3 lightDir = normalize(lightPos - FragPos);  // direction from fragment to light
    float diff = max(dot(norm, lightDir), 0.0);     // cosine of angle between normal and light
    vec3 diffuse = diff * lightColor;

    // --- Specular ---
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);    // direction from fragment to viewer
    vec3 reflectDir = reflect(-lightDir, norm);     // direction of reflected light
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 256); // shininess factor
    vec3 specular = specularStrength * spec * lightColor;

    // --- Combine ---
    vec3 result = (ambient + diffuse + specular) * vertexColor; 

    FragColor = vec4(result, 1.0);
}

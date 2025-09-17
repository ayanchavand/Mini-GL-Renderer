#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Camera.h"
#include "VAO.h"
#include "shader.h"
#include "glm/gtc/type_ptr.hpp"
class Renderer {
public:
    Renderer(int width, int height);

    void Init();                         // Initialize OpenGL state
    void BeginFrame(const glm::vec3& bg); // Clear screen with background color
    void Render(VAO& vao, Shader& shader, const glm::mat4& model, Camera& camera); // Draw a mesh
    void EndFrame(GLFWwindow* window);   // Swap buffers and poll events
    //void SetWireframe(bool enable);

private:
    int width;
    int height;
    bool wireframeMode;
};

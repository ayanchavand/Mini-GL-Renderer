#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

GLfloat vertices[] = {
	// Outer triangle
	 0.0f,  0.5f, 0.0f,  // 0 top
	-0.5f, -0.5f, 0.0f,  // 1 bottom-left
	 0.5f, -0.5f, 0.0f,  // 2 bottom-right

	 // Midpoints (for the inner hole)
	 -0.25f,  0.0f, 0.0f, // 3 mid-left
	  0.25f,  0.0f, 0.0f, // 4 mid-right
	  0.0f,  -0.5f, 0.0f  // 5 mid-bottom
};

GLuint indices[] = {
	0, 3, 4,   // top small triangle
	3, 1, 5,   // bottom-left small triangle
	4, 5, 2    // bottom-right small triangle
};

int main() {

	// Initialize GLFWc
	glfwInit();
	// Set GLFW to use OpenGL version 3.3 and the core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	

	// Create a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(800, 600, "Mini OGL renderer", NULL, NULL);
	if(window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Load OpenGL function pointers using GLAD
	gladLoadGL();
	glViewport(0, 0, 800, 600);

	Shader shaderProgram("default.vert", "default.frag");
	
	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();



	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		
		glfwPollEvents();
	}
	//Cleanup
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
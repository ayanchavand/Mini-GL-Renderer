#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//Core Engine Modules ><
#include "shader.h"
#include "EngineGUI.h"
#include "Camera.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

GLfloat vertices[] = {
	// Position        // Color           // TexCoord
	-0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f, // 0 top-left
	 0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, // 1 top-right
	 0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f, // 2 bottom-right
	-0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 0.0f,  0.0f, 0.0f  // 3 bottom-left
};

GLuint indices[] = {
	0, 1, 2,   // first triangle
	0, 2, 3    // second triangle
};

GLfloat cubeVertices[] = {
	// Positions         // Colors
	-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, // 0
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, // 1
	 0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, // 2
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, // 3
	-0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, // 4
	 0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // 5
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, // 6
	-0.5f,  0.5f,  0.5f,  0.3f, 0.7f, 0.5f  // 7
};

GLuint cubeIndices[] = {
	0,1,2, 2,3,0, // back face
	4,5,6, 6,7,4, // front face
	4,5,1, 1,0,4, // bottom face
	7,6,2, 2,3,7, // top face
	4,0,3, 3,7,4, // left face
	5,1,2, 2,6,5  // right face
};


bool wireframeMode = true; // default is wireframe, can start false if you like
float scale = 0.5f;
glm::vec3 backgroundColor = glm::vec3(0.2f, 0.3f, 0.3f);

int main() {
	//I love init
	// Initialize GLFW
	glfwInit();
	// Set GLFW to use OpenGL version 3.3 and the core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Camera camera(glm::vec3(1.0f, 0.0f, 3.0f), 800.0f / 600.0f);

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
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	Shader shaderProgram("default.vert", "default.frag");
	
	/*
	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();
	*/

	VAO cubeVAO;
	cubeVAO.Bind();

	VBO cubeVBO(cubeVertices, sizeof(cubeVertices));
	EBO cubeEBO(cubeIndices, sizeof(cubeIndices));

	cubeVAO.LinkAttrib(cubeVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0); // position
	cubeVAO.LinkAttrib(cubeVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float))); // color

	cubeVAO.Unbind();
	cubeVBO.Unbind();
	cubeEBO.Unbind();

	GLuint scaleID = glGetUniformLocation(shaderProgram.ID, "scale");

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true); // Flip the image vertically on load
	unsigned char* data = stbi_load("twitter-card.jpg", &width, &height, &nrChannels, 0);

	GLuint texture;
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);


	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint texUni = glGetUniformLocation(shaderProgram.ID, "ourTexture");
	shaderProgram.Activate();
	glUniform1i(texUni, 0);

	//Required Initialization for IMGUI BS
	EngineGUI::Init(window);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f); // alpha = 1.0
		glClear(GL_COLOR_BUFFER_BIT);

		EngineGUI::BeginFrame();

		if (wireframeMode)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		shaderProgram.Activate();

		// Get vertex shader uniform locations in the GPU
		GLuint modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		GLuint viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		GLuint projLoc = glGetUniformLocation(shaderProgram.ID, "projection");

		//model matrix : translate, rotate, scale
		glm::mat4 model = glm::mat4(1.0f);
		
		//upload the model data to the modelLoc 1 4x4 matrix and don't transpose the matrix
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		// ask the camera for the view and projection matrices based on it's config
		glm::mat4 view = camera.GetViewMatrix();
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glm::mat4 projection = camera.GetProjectionMatrix();
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glUniform1f(scaleID, scale);
		glBindTexture(GL_TEXTURE_2D, texture);
		cubeVAO.Bind();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


		EngineGUI::ShowDebugWindow(wireframeMode, scale, backgroundColor);
		EngineGUI::ShowCameraWindow(camera);

		EngineGUI::EndFrame();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	
	//Cleanup
	EngineGUI::ShutDown();

	// Cleanup cube resources
	cubeVAO.Delete();
	cubeVBO.Delete();
	cubeEBO.Delete();
	glDeleteTextures(1, &texture);
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
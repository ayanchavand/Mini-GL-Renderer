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
#include "Renderer.h"

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
	// Positions         // Colors           // Normals
	// Back face
	-0.5f, -0.5f, -0.5f,  1.0f,0.0f,0.0f,   0.0f,0.0f,-1.0f, // 0
	 0.5f, -0.5f, -0.5f,  0.0f,1.0f,0.0f,   0.0f,0.0f,-1.0f, // 1
	 0.5f,  0.5f, -0.5f,  0.0f,0.0f,1.0f,   0.0f,0.0f,-1.0f, // 2
	-0.5f,  0.5f, -0.5f,  1.0f,1.0f,0.0f,   0.0f,0.0f,-1.0f, // 3

	// Front face
	-0.5f, -0.5f,  0.5f,  1.0f,0.0f,1.0f,   0.0f,0.0f,1.0f,  // 4
	 0.5f, -0.5f,  0.5f,  0.0f,1.0f,1.0f,   0.0f,0.0f,1.0f,  // 5
	 0.5f,  0.5f,  0.5f,  1.0f,1.0f,1.0f,   0.0f,0.0f,1.0f,  // 6
	-0.5f,  0.5f,  0.5f,  0.3f,0.7f,0.5f,   0.0f,0.0f,1.0f,  // 7

	// Left face
	-0.5f, -0.5f, -0.5f,  1.0f,0.0f,0.0f,  -1.0f,0.0f,0.0f,  // 8
	-0.5f,  0.5f, -0.5f,  1.0f,1.0f,0.0f,  -1.0f,0.0f,0.0f,  // 9
	-0.5f,  0.5f,  0.5f,  0.3f,0.7f,0.5f,  -1.0f,0.0f,0.0f,  // 10
	-0.5f, -0.5f,  0.5f,  1.0f,0.0f,1.0f,  -1.0f,0.0f,0.0f,  // 11

	// Right face
	 0.5f, -0.5f, -0.5f,  0.0f,1.0f,0.0f,   1.0f,0.0f,0.0f,  // 12
	 0.5f,  0.5f, -0.5f,  0.0f,0.0f,1.0f,   1.0f,0.0f,0.0f,  // 13
	 0.5f,  0.5f,  0.5f,  1.0f,1.0f,1.0f,   1.0f,0.0f,0.0f,  // 14
	 0.5f, -0.5f,  0.5f,  0.0f,1.0f,1.0f,   1.0f,0.0f,0.0f,  // 15

	 // Bottom face
	 -0.5f, -0.5f, -0.5f,  1.0f,0.0f,0.0f,   0.0f,-1.0f,0.0f, // 16
	  0.5f, -0.5f, -0.5f,  0.0f,1.0f,0.0f,   0.0f,-1.0f,0.0f, // 17
	  0.5f, -0.5f,  0.5f,  0.0f,1.0f,1.0f,   0.0f,-1.0f,0.0f, // 18
	 -0.5f, -0.5f,  0.5f,  1.0f,0.0f,1.0f,   0.0f,-1.0f,0.0f, // 19

	 // Top face
	 -0.5f,  0.5f, -0.5f,  1.0f,1.0f,0.0f,   0.0f,1.0f,0.0f,  // 20
	  0.5f,  0.5f, -0.5f,  0.0f,0.0f,1.0f,   0.0f,1.0f,0.0f,  // 21
	  0.5f,  0.5f,  0.5f,  1.0f,1.0f,1.0f,   0.0f,1.0f,0.0f,  // 22
	 -0.5f,  0.5f,  0.5f,  0.3f,0.7f,0.5f,   0.0f,1.0f,0.0f   // 23
};



GLuint cubeIndices[] = {
	0,1,2, 2,3,0,       // back
	4,5,6, 6,7,4,       // front
	8,9,10, 10,11,8,    // left
	12,13,14, 14,15,12, // right
	16,17,18, 18,19,16, // bottom
	20,21,22, 22,23,20  // top
};


//default shit
bool wireframeMode = true; // default is wireframe, can start false if you like
float scale = 0.5f;
glm::vec3 backgroundColor = glm::vec3(0.2f, 0.3f, 0.3f);
glm::vec3 defaultScale = glm::vec3(0.5f, 0.5f, 0.5f);


int main() {
	//I love BOILERPLATECODE :D
	// Initialize GLFW
	glfwInit();
	// Set GLFW to use OpenGL version 3.3 and the core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f), 800.0f / 600.0f);

	// Create a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(800, 600, "omg 3d????????", NULL, NULL);
	if(window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Load OpenGL function pointers using GLAD
	Renderer renderer(800, 600);
	renderer.Init();
	
	// Build and compile our shader program
	Shader shaderProgram("default.vert", "default.frag");
	Shader lightShader("default.vert", "light.frag");

	shaderProgram.SetVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	VAO cubeVAO;
	cubeVAO.Bind();

	VBO cubeVBO(cubeVertices, sizeof(cubeVertices));
	EBO cubeEBO(cubeIndices, sizeof(cubeIndices));

	cubeVAO.LinkAttrib(cubeVBO, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0); // position
	cubeVAO.LinkAttrib(cubeVBO, 1, 3, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float))); // color
	cubeVAO.LinkAttrib(cubeVBO, 2, 3, GL_FLOAT, 9 * sizeof(float), (void*)(6 * sizeof(float))); // color

	cubeVAO.Unbind();
	cubeVBO.Unbind();
	cubeEBO.Unbind();

	GLuint scaleID = glGetUniformLocation(shaderProgram.ID, "scale");


	//Required Initialization for IMGUI BS
	EngineGUI::Init(window);

	glEnable(GL_DEPTH_TEST);


	float deltaTime = 0.0f;	// Time between current frame and last frame
	float lastFrame = 0.0f;

	while (!glfwWindowShouldClose(window)) {
		//Frame rate calculation
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		float fps = 1.0f / deltaTime;
		float msPerFrame = deltaTime * 1000.0f;


		// Start the GUI frame
		EngineGUI::BeginFrame();
		renderer.BeginFrame(backgroundColor);

		EngineGUI::ShowStatsWindow(fps, msPerFrame);

		//model matrix : translate, rotate, scale
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::scale(model, defaultScale);
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
		renderer.Render(cubeVAO, shaderProgram, model, camera);

		// Second cube
		glm::mat4 model2 = glm::mat4(1.0f);
		model2 = glm::translate(model2, glm::vec3(1.5f, 0.0f, 0.0f));
		model2 = glm::scale(model2, defaultScale);
		model2 = glm::rotate(model2, (float)glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
		renderer.Render(cubeVAO, shaderProgram, model2, camera);

		glm::mat4 model3 = glm::mat4(1.0f);
		model3 = glm::translate(model3, glm::vec3(-1.5f, 0.0f, 0.0f));
		model3 = glm::scale(model3, defaultScale);
		model3 = glm::rotate(model3, (float)glfwGetTime(), glm::vec3(.2f, 0.7f, 1.0f));
		renderer.Render(cubeVAO, shaderProgram, model3, camera);

		glm::mat4 lightModel = glm::mat4(1.0f);
		lightModel = glm::scale(lightModel, defaultScale);
		lightModel = glm::translate(lightModel, glm::vec3(0.0f, 1.0f, 0.0f));
		//lightModel = glm::rotate(lightModel, (float)glfwGetTime(), glm::vec3(.4f, .6f, 1.0f));
		renderer.Render(cubeVAO, lightShader, lightModel, camera);

		//TODO: Remove scale in favour of model matrix scaling
		//glUniform1f(scaleID, scale);
		//Draw our kawaii UI
		EngineGUI::ShowDebugWindow(wireframeMode, scale, backgroundColor);
		EngineGUI::ShowCameraWindow(camera);

		//End the GUI frame
		EngineGUI::EndFrame();
		renderer.EndFrame(window);
	}

	
	//Exit Cleanup
	EngineGUI::ShutDown();
	cubeVAO.Delete();
	cubeVBO.Delete();
	cubeEBO.Delete();
	//glDeleteTextures(1, &texture);
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
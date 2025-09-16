#include "Renderer.h"
Renderer::Renderer(int width , int height){
	this->width = width;
	this->height = height;
	this->wireframeMode = false; // default to filled mode
}

void Renderer::Init() {
	gladLoadGL();
	gladLoadGL();
	glViewport(0, 0, 800, 600);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::BeginFrame(const glm::vec3& bg) {
	glClearColor(bg.r, bg.g, bg.b, 1.0f); // alpha = 1.0
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (wireframeMode) {
		glDisable(GL_CULL_FACE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Renderer::EndFrame(GLFWwindow* window) {
	glfwSwapBuffers(window);
	glfwPollEvents();
}
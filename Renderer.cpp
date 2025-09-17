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
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Renderer::Render(VAO& vao, Shader& shader, const glm::mat4& model, Camera& camera) {
	shader.Activate();

	// Get vertex shader uniform locations in the GPU
	GLuint modelLoc = glGetUniformLocation(shader.ID, "model");
	GLuint viewLoc = glGetUniformLocation(shader.ID, "view");
	GLuint projLoc = glGetUniformLocation(shader.ID, "projection");

	//upload the model data to the modelLoc 1 4x4 matrix and don't transpose the matrix
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	
	glm::mat4 view = camera.GetViewMatrix();
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	glm::mat4 projection = camera.GetProjectionMatrix();
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	vao.Bind();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	vao.Unbind();
}

void Renderer::EndFrame(GLFWwindow* window) {
	glfwSwapBuffers(window);
	glfwPollEvents();
}
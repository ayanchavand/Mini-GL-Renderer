#pragma once
#include <GLFW/glfw3.h> 
#include <glm/glm.hpp>
namespace EngineGUI {

	void Init(GLFWwindow* window);
	void BeginFrame();
	void EndFrame();
	void ShutDown();

	void ShowDebugWindow(bool& wireframeMode, float& scale, glm::vec3& backgroundColor);
	//void Render();
}

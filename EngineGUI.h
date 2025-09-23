#pragma once
#include <GLFW/glfw3.h> 
#include <glm/glm.hpp>
#include "Camera.h"
namespace EngineGUI {

	void Init(GLFWwindow* window);
	void BeginFrame();
	void EndFrame();
	void ShutDown();

	void ShowDebugWindow(glm::vec3& backgroundColor);
	void ShowCameraWindow(Camera& camera);
	void ShowStatsWindow(float fps, float msPerFrame);
	//void Render();
}

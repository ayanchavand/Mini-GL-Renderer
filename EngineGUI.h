#pragma once
#include <GLFW/glfw3.h> 
namespace EngineGUI {

	void Init(GLFWwindow* window);
	void BeginFrame();
	void EndFrame();
	void ShutDown();

	void ShowDebugWindow(bool& wireframeMode, float& scale);
	//void Render();
}

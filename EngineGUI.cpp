#include "EngineGUI.h"
#include "Camera.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <glm/gtc/type_ptr.hpp>

// This function initializes the ImGui context and sets up the necessary bindings for GLFW and OpenGL3.
// there's no logic here, just straight up initialization
void EngineGUI::Init(GLFWwindow* window) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void EngineGUI::BeginFrame() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void EngineGUI::EndFrame() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void EngineGUI::ShutDown() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

}

void EngineGUI::ShowDebugWindow(bool& wireframeMode, float& scale, glm::vec3& backgroundColor) {
	ImGui::Begin("Render Settings");
		//ImGui::Text("This is some useful text.");
		ImGui::Checkbox("Wireframe Mode", &wireframeMode);
		ImGui::SliderFloat("Scale", &scale, 0.1f, 2.0f);
		ImGui::ColorEdit3("Background Color", (float*)&backgroundColor);
		ImGui::End();
}
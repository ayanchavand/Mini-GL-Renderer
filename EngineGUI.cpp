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

//Actual GUI Code

void EngineGUI::ShowDebugWindow(bool& wireframeMode, float& scale, glm::vec3& backgroundColor) {
	ImGui::Begin("Render Settings");
		//ImGui::Text("This is some useful text.");
		ImGui::Checkbox("Wireframe Mode", &wireframeMode);
		ImGui::SliderFloat("Scale", &scale, 0.1f, 2.0f);
		ImGui::ColorEdit3("Background Color", (float*)&backgroundColor);
		ImGui::End();
}

void EngineGUI::ShowCameraWindow(Camera& camera) {
	ImGui::Begin("Camera Settings");

	// Editable vectors
	ImGui::DragFloat3("Position", &camera.Position.x, 0.1f);
	ImGui::DragFloat3("Front", &camera.Front.x, 0.1f);
	ImGui::DragFloat3("Up", &camera.Up.x, 0.1f);

	// Editable scalar values
	ImGui::SliderFloat("FOV", &camera.Fov, 1.0f, 90.0f);
	ImGui::SliderFloat("Aspect Ratio", &camera.AspectRatio, 0.1f, 4.0f);
	ImGui::SliderFloat("Near Plane", &camera.NearPlane, 0.01f, 10.0f);
	ImGui::SliderFloat("Far Plane", &camera.FarPlane, 10.0f, 1000.0f);

	ImGui::End();
}

void EngineGUI::ShowStatsWindow(float fps, float msPerFrame) {
	ImGui::SetNextWindowPos(ImVec2(10, 10));
	ImGui::Begin("Performance Stats", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
	ImGui::Text("FPS: %.1f", fps);
	ImGui::Text("Frame Time: %.3f ms", msPerFrame);
	ImGui::End();
}

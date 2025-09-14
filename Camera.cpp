#include "Camera.h"

// such a kawai constructor
Camera::Camera(glm::vec3 startPos, float aspectRatio) {
	Position = startPos;
	Front = glm::vec3(0.0f, 0.0f, -1.0f);
	Up = glm::vec3(0.0f, 1.0f, 0.0f);
	Fov = 45.0f;
	AspectRatio = aspectRatio;
	NearPlane = 0.1f;
	FarPlane = 100.0f;
}

// Returns the view matrix that transforms world coordinates into the camera's view space.
// This uses the camera's Position as the eye, Position + Front as the target (center),
// and Up as the upward direction, effectively placing the "world" relative to the camera.
glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(Position, Position + Front, Up);
}
// Returns the projection matrix that defines how 3D points are projected onto a 2D screen.
// Math magic wooo skeri horror 
// Todo: Learn the actual fucking math of this shit
glm::mat4 Camera::GetProjectionMatrix() {
	return glm::perspective(glm::radians(Fov), AspectRatio, NearPlane, FarPlane);
}
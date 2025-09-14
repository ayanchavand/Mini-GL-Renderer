#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;

	float Fov;
	float AspectRatio;
	float NearPlane;
	float FarPlane;

	Camera(glm::vec3 startPos, float aspectRatio);

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
};

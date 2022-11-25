#pragma once

#include <Eigen/Dense>

class Camera
{
public:
	Eigen::Vector3f pos, rotation, scale;
	float far, near, fov;
	Camera(float fov, float near, float far);
	Eigen::Vector2f getProjectedPoint(Eigen::Vector3f pos);
};


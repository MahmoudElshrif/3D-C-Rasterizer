#pragma once

#include <Eigen/Dense>
#include <SFML/System/Vector3.hpp>
#include "Convert.h"

class Camera
{
public:
	sf::Vector3f pos, rot, scale;
	float far, near, fov;
	Camera(float fov, float near, float far);
	Eigen::Vector3f getProjectedPoint(Eigen::Vector3f pos);
};


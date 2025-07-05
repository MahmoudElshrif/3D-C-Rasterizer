#pragma once

#include <Eigen/Dense>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics.hpp>
#include "Convert.h"
#include "Vertex.h"
#include "Mesh.h"

class Camera
{
public:
	sf::Vector3f pos, rot, scale;
	std::vector<Mesh>* meshes;
	std::vector<triData> buffer;
	int winSize[2];
	float far, near, fov;
	Camera(float fov, float near, float far, int winSize[2]);
	Eigen::Vector3f getProjectedPoint(Eigen::Vector3f pos);
	void Render(sf::RenderWindow& window);
};


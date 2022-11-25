#pragma once
#include "Vertex.h"
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Convert.h"
#include "Camera.h"

struct triData{
	sf::ConvexShape shape;
	float depth;
	bool operator < (const triData &dat) {
		return depth > dat.depth;
	}
};

class Triangle
{
public:
	std::vector<Vertex> vertices;
	sf::Vector3f pos;
	sf::Vector3f rot;
	sf::Vector3f scale;
	Triangle();
	Triangle(std::vector<Vertex> vertx);
	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);
	void setPosition(Vector3f pos);
	void Draw(sf::RenderWindow& window);
	float getNormal();
	void ApplyTransform(sf::RenderWindow& window, std::vector<triData>& buffer,Camera cam);
};


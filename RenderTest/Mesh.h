#pragma once
#include <SFML/System.hpp>
#include <vector>
#include "Triangle.h"
#include <SFML/Graphics.hpp>
#include "Vertex.h"

using namespace std;

class Mesh
{
public:
	sf::Vector3f pos;
	sf::Vector3f rot;
	sf::Vector3f scale;
	vector<Triangle> faces;
	Mesh();
	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);
	void setScale(float x);
	void Draw(sf::RenderWindow& window, std::vector<triData>& buffer,Camera cam);

};


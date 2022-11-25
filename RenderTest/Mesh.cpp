#include "Mesh.h"


Mesh::Mesh() {
	vector<Vertex> vertices = { 
		 Vertex(0, 0, 0),
		 Vertex(1, 0, 0),
		 Vertex(1, 1, 0),
		 Vertex(0, 1, 0),
		 Vertex(0, 1, 1),
		 Vertex(1, 1, 1),
		 Vertex(1, 0, 1),
		 Vertex(0, 0, 1)
	};
	vector<vector<int>> facesindex{
		{0, 2, 1}, //face front
		{0, 3, 2},
		{2, 3, 4}, //face top
		{2, 4, 5},
		{1, 2, 5}, //face right
		{1, 5, 6},
		{0, 7, 4}, //face left
		{0, 4, 3},
		{5, 4, 7}, //face back
		{5, 7, 6},
		{0, 6, 7}, //face bottom
		{0, 1, 6}
	};
	for (auto face : facesindex) {
		faces.push_back(Triangle({ vertices[face[0]], vertices[face[1]], vertices[face[2]] }));
	}
}

void Mesh::setPosition(float x, float y, float z) {
	pos = sf::Vector3f(x, y, z);
	for (int i = 0; i < faces.size(); i++) {
		faces[i].setPosition(x, y, z);
	}
}

void Mesh::setScale(float x, float y, float z) {
	scale = sf::Vector3f(x, y, z);
	for (int i = 0; i < faces.size();i++) {
		faces[i].setScale(x, y, z);
	}
}

void Mesh::setScale(float x) {
	scale = sf::Vector3f(x, x, x);
	for (int i = 0; i < faces.size(); i++) {
		faces[i].setScale(x, x, x);
	}
}

void Mesh::setRotation(float x, float y, float z) {
	rot = sf::Vector3f(x, y, z);
	for (int i = 0; i < faces.size(); i++) {
		faces[i].setRotation(x, y, z);
	}
}

void Mesh::Draw(sf::RenderWindow& window, std::vector<triData>& buffer,Camera cam) {
	for (int i = 0; i < faces.size(); i++) {
		faces[i].ApplyTransform(window,buffer,cam);
	}
}
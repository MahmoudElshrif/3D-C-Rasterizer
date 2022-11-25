#include "Triangle.h"


Triangle::Triangle() {
	vertices.push_back(Vertex(-1, 1, 0));
	vertices.push_back(Vertex(1, 1, 0));
	vertices.push_back(Vertex(1, -1, 0));
}

Triangle::Triangle(std::vector<Vertex> vertx) {
	vertices = vertx;
}

void Triangle::setRotation(float x, float y, float z) {
	rot = sf::Vector3f(x,y,z);

	for (int i = 0; i < vertices.size(); i++) {
		vertices[i].setRotation(x, y, z);
	}
}

void Triangle::setScale(float x, float y, float z) {
	scale = sf::Vector3f(x, y, z);

	for (int i = 0; i < vertices.size(); i++) {
		vertices[i].setScale(x, y, z);
	}
}

void Triangle::setPosition(float x, float y, float z) {
	pos = sf::Vector3f(x, y, z);

	for (int i = 0; i < vertices.size(); i++) {
		vertices[i].setTranslation(x, y, z);
	}
}

void Triangle::ApplyTransform(sf::RenderWindow& window, std::vector<sf::ConvexShape>& buffer,Camera cam) {
	sf::ConvexShape vertx(vertices.size());
	Vector3f av;
	av.setZero();
	std::vector<Vector3f> poses;
	for (int i = 0; i < 3; i++) {
		Vector4f p = vertices[i].Transform();
		Vector3f pos = Vector3f(p.x(), p.y(), p.z());
		av += pos;
		poses.push_back(pos);
		vertx.setPoint(i,Eigen2SFML(cam.getProjectedPoint(pos)));
	}
	av /= 3;
	Eigen::Vector3f cross = (poses[0] - poses[1]).cross(poses[0] - poses[2]);
	cross = cross.normalized();
	float dot = cross.dot((cam.pos - av).normalized());
	if (dot <= 0)
		return;
	dot *= 255;
	vertx.setFillColor(sf::Color(dot, dot, dot,255));
	buffer.push_back(vertx);
}

#include "Camera.h"
#include <iostream>
//#include "Mesh.cpp"a

Camera::Camera(float fov,float near,float far,int winSize[2]) {
	this->fov = fov / 2;
	this->near = near;
	this->far = far;
	this->pos = sf::Vector3f(0.f, 0.f, 0.f);
	this->rot = sf::Vector3f(0.f, 0.f, 0.f);
	this->scale = sf::Vector3f(1.f,1.f,1.f);
	this->buffer = {};
	this->meshes = {};
	this->winSize[0] = winSize[0];
	this->winSize[1] = winSize[1];
	
}

void Camera::Render(sf::RenderWindow& window) {
	buffer = {};

	for (int i = 0; i < meshes->size(); i++) {
		//this->meshes[i].setRotation(x * 2 + cubes[i].pos.x * cubes[i].pos.y, (x + cubes[i].pos.x * cubes[i].pos.y) / 2.4, (x + cubes[i].pos.x * cubes[i].pos.y) * 1.4);
		//cubes[i].setPosition(cubes[i].pos.x,cubes[i].pos.y,x * 10);
		(*meshes)[i].Draw(window, buffer, this);
	}

	sort(buffer.begin(), buffer.end());


	std::vector<sf::Vertex> verts;

	int num = 0;
	//cubes.back().setPosition(0, 0, mp.y * 10);
	for (auto i : buffer) {
		for (int x = 0; x < 3; x++) {
			auto point = i.shape.getPoint(x);
			verts.push_back(sf::Vertex(sf::Vector2f(point.x * winSize[0] * 2 + winSize[0] / 2, point.y * winSize[1] * 2 + winSize[1] / 2), i.shape.getFillColor()));
			//i.shape.setPoint(x, sf::Vector2f(point.x * winSize[0] * 2 + winSize[0] / 2, point.y * winSize[1] * 2 + winSize[1] / 2));
			//cout << i.getPoint(x).x << " " << i.getPoint(x).y << endl;
		}
		//cout << endl;
	}
	window.draw(&verts[0],verts.size(),sf::Triangles);
}

Eigen::Vector3f Camera::getProjectedPoint(Eigen::Vector3f pos) {
	Eigen::Vector3f projected(0.f, 0.f,0.f);
	Eigen::Vector3f transform(pos.x(), pos.y(), pos.z());
	transform -= S2E(this->pos);
	Eigen::Matrix3f matrot = RotationMatrix::XRotation(-rot.x);
	matrot *= RotationMatrix::YRotation(-rot.y);
	matrot *= RotationMatrix::ZRotation(-rot.z);
	transform = matrot * transform;
	//std::cout << transform << std::endl;
	projected.x() = (near * transform.x()) / transform.z();
	projected.y() = (near * transform.y()) / transform.z();
	projected /= near * tanf(this->fov);
	projected.z() = transform.z();
	if (transform.z() <= near || transform.z() >= far)
		return Eigen::Vector3f(5,5,5);
	return projected;
}
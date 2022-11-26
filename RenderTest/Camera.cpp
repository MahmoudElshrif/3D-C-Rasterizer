#include "Camera.h"
#include <iostream>

Camera::Camera(float fov,float near,float far) {
	this->fov = fov / 2;
	this->near = near;
	this->far = far;
	this->pos = sf::Vector3f(0.f, 0.f, 0.f);
	this->rot = sf::Vector3f(0.f, 0.f, 0.f);
	this->scale = sf::Vector3f(1.f,1.f,1.f);
	
}

Eigen::Vector3f Camera::getProjectedPoint(Eigen::Vector3f pos) {
	Eigen::Vector3f projected(0.f, 0.f,0.f);
	Eigen::Vector3f transform(pos.x(), pos.y(), pos.z());
	transform -= S2E(this->pos);
	Eigen::Matrix3f matrot{
		{1,0,0},
		{0,cos(-rot.x),-sin(-rot.x)},
		{0,sin(-rot.x),cos(-rot.x)}
	}; 
	matrot *= Eigen::Matrix3f{
		{cosf(-rot.y),0,sin(-rot.y)},
		{0,1,0},
		{-sin(-rot.y), 0 ,cos(-rot.y)}
	};
	matrot *= Eigen::Matrix3f{
		{cosf(-rot.z),sin(-rot.z),0},
		{-sin(-rot.z),cos(-rot.z),0 },
		{ 0,0,1 }
	};
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
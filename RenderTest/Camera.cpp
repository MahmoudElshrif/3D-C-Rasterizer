#include "Camera.h"


Camera::Camera(float fov,float near,float far) {
	this->fov = fov / 2;
	this->near = near;
	this->far = far;
	this->pos.setZero();
	this->rotation.setZero();
	this->scale.setOnes();
	
}

Eigen::Vector2f Camera::getProjectedPoint(Eigen::Vector3f pos) {
	Eigen::Vector2f projected(0.f,0.f);
	projected.x() = (near * pos.x()) / pos.z();
	projected.y() = (near * pos.y()) / pos.z();
	projected /= near * tanf(this->fov);
	return projected;
}
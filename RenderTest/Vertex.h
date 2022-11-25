#pragma once

#include "Eigen/Dense"

using namespace Eigen;

class Vertex
{
public:
	Matrix4f transform;
	Matrix4f rotation;
	Matrix4f scale;
	Matrix4f translation;
	Vector4f identity;
	Vertex(Vector4f id);
	Vertex(Vector4f id,Matrix4f rotation,Matrix4f scale,Matrix4f translation);
	Vertex(float x, float y, float z);
	void Reset();
	void setRotation(float x, float y, float z);
	void setTranslation(float x, float y, float z);
	void setScale(float x, float y, float z);
	Vector4f Transform();
	Matrix4f getRotation();
	Matrix4f getScale();
	Matrix4f getTranslation();
	Matrix4f getTransform();
	
};


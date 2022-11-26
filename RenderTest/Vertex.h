#pragma once

#include "Eigen/Dense"

using namespace Eigen;

struct RotationMatrix {
	static Eigen::Matrix4f ZRotation4(float z) {
		return Matrix4f{
			{cosf(z),-sinf(z) ,0,0},
			{sinf(z),cos(z),0,0},
			{0,0,1,0},
			{0,0,0,1}

		};
	}

	static Eigen::Matrix4f YRotation4(float y) {
		return Matrix4f{
			{cosf(y), 0, sinf(y),0},
			{ 0,1,0,0},
			{ -sinf(y),0,cos(y),0},
			{0,0,0,1}
		};
	}
	static Eigen::Matrix4f XRotation4(float x) {
		return Matrix4f{
				{1,	0, 0, 0},
				{0,	cosf(x),-sinf(x),0},
				{0,sinf(x),cos(x),0},
				{0,0,0,1}
		};
	}
	static Eigen::Matrix3f ZRotation(float z) {
		return Matrix3f{
			{cosf(z),-sinf(z) ,0},
			{sinf(z),cos(z),0},
			{0,0,1},

		};
	}

	static Eigen::Matrix3f YRotation(float y) {
		return Matrix3f{
			{cosf(y), 0, sinf(y)},
			{ 0,1,0},
			{ -sinf(y),0,cos(y)},
		};
	}

	static Eigen::Matrix3f XRotation(float x) {
		return Matrix3f{
				{1,	0, 0},
				{0,	cosf(x),-sinf(x)},
				{0,sinf(x),cos(x)},
		};
	}
};

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


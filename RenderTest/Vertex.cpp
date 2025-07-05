#include "Vertex.h"


Vertex::Vertex(Vector4f id) {
	identity = id;
	Reset();
}

Vertex::Vertex(float x, float y, float z) {
	identity = Vector4f(x, y, z, 1);
	Reset();
}

Vertex::Vertex(Vector4f id, Matrix4f rotation, Matrix4f scale, Matrix4f translation) {
	identity = id;
	this->rotation = rotation;
	this->scale = scale;
	this->translation = translation;
	 
}

Vector4f Vertex::Transform() {
	Matrix4f t = rotation * scale;
	transform = t + translation;

	return transform * identity;
}

void Vertex::setRotation(float x, float y, float z) {
	rotation = Matrix4f::Identity();
	//rotation *= Matrix4f{
	//	{cosf(z),-sinf(z) ,0,0},
	//	{sinf(z),cos(z),0,0},
	//	{0,0,1,0},
	//	{0,0,0,1}

	//};
	rotation *= RotationMatrix::ZRotation4(z);
	rotation *= RotationMatrix::YRotation4(y);
	rotation *= RotationMatrix::XRotation4(x);
	//rotation *= Matrix4f{
	//	{cosf(y), 0, sinf(y),0},
	//	{ 0,1,0,0},
	//	{ -sinf(y),0,cos(y),0},
	//	{0,0,0,1}
	//};
	//rotation *= Matrix4f{
	//	{1,	0, 0, 0},
	//	{0,	cosf(x),-sinf(x),0},
	//	{0,sinf(x),cos(x),0},
	//	{0,0,0,1}
	//};
}

void Vertex::setTranslation(float x, float y, float z) {
	translation(0, 3) = x;
	translation(1, 3) = y;
	translation(2, 3) = z;
}

void Vertex::setScale(float x, float y, float z) {
	scale = Matrix4f{
		{x,0,0,0},
		{0,y,0,0},
		{0,0,z,0},
		{0,0,0,1}
	};
}

void Vertex::Reset() {
	transform = Matrix4f::Identity();
	rotation = Matrix4f::Identity();
	scale = Matrix4f::Identity();
	translation = Matrix4f::Zero();
}

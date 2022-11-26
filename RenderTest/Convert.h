#pragma once
#include <SFML/System.hpp>
#include <Eigen/Dense>


inline Eigen::Vector4f S2E4(sf::Vector3f vec) {
	return Eigen::Vector4f(vec.x, vec.y, vec.z,0);
}


inline sf::Vector3f E42S(Eigen::Vector4f vec) {
	return sf::Vector3f(vec.x(), vec.y(),vec.z());
}

inline sf::Vector3f E2S(Eigen::Vector3f vec) {
	return sf::Vector3f(vec.x(), vec.y(), vec.z());
}

inline Eigen::Vector3f S2E(sf::Vector3f vec) {
	return Eigen::Vector3f(vec.x, vec.y, vec.z);
}


inline sf::Vector2f E2S(Eigen::Vector2f vec) {
	return sf::Vector2f(vec.x(), vec.y());
}

inline Eigen::Vector2f S2E(sf::Vector2f vec) {
	return Eigen::Vector2f(vec.x, vec.y);
}
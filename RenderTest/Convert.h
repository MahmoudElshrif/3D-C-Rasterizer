#pragma once
#include <SFML/System.hpp>
#include <Eigen/Dense>


inline Eigen::Vector4f SFML2Eigen4(sf::Vector3f vec) {
	return Eigen::Vector4f(vec.x, vec.y, vec.z,0);
}


inline sf::Vector3f Eigen2SFML(Eigen::Vector4f vec) {
	return sf::Vector3f(vec.x(), vec.y(),vec.z());
}

inline sf::Vector3f Eigen42SFML(Eigen::Vector3f vec) {
	return sf::Vector3f(vec.x(), vec.y(), vec.z());
}

inline Eigen::Vector3f SFML2Eigen(sf::Vector3f vec) {
	return Eigen::Vector3f(vec.x, vec.y, vec.z);
}


inline sf::Vector2f Eigen2SFML(Eigen::Vector2f vec) {
	return sf::Vector2f(vec.x(), vec.y());
}

inline Eigen::Vector2f SFML2Eigen(sf::Vector2f vec) {
	return Eigen::Vector2f(vec.x, vec.y);
}
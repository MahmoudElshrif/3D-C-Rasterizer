#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include "Eigen/Dense"
#include "Convert.h"
#include "Vertex.h"
#include "Mesh.h"
#include <fstream>
#include <string>
#include <strstream>
#include "Camera.h"

using namespace std;





int main()
{
	int size[2] = {800,800};
	sf::RenderWindow window(sf::VideoMode(size[0],size[1]), "hello world", sf::Style::Titlebar | sf::Style::Close);
	window.setMouseCursorVisible(false);
	Camera cam(90,0.1,500,size);
	sf::Event ev;
	sf::Clock clock;
	sf::Font font;
	std::vector<triData> buffer;
	font.loadFromFile("arial.ttf");
	//if(!font.loadFromFile("arial.ttf"))
	float lasttime = 0;
	vector<Mesh> cubes;
	cam.meshes = &cubes;

	bool paused = false;

	vector<Vertex> vertices;
	vector<Triangle> tris;

	/*ifstream f("monkey.obj");

	while (!f.eof()) {
		char c[128];
		f.getline(c, 128);

		strstream s;
		s << c;
		char junk;

		if (c[0] == 'v') {
			float x, y, z;
			s >> junk >> x >> y >> z;
			vertices.push_back(Vertex(x,y,z));
		}

		if (c[0] == 'f') {
			int f[3];
			s >> junk >> f[0] >> f[1] >> f[2];
			tris.push_back(Triangle({vertices[f[0] - 1],vertices[f[1] - 1] ,vertices[f[2] - 1] }));
		}

	}*/
	
	for (int i = 0; i < 30; i++) 
		for (int j = 0; j < 30;j++){
		Mesh cube;
		//cube.faces = tris;
		//cube.setPosition(rand() % 560 - 280, rand() % 650 + 25, rand() % 650 + 25);
		//cube.setPosition(i, sinf((float)(i+j) / (30.f*30.f) * 6.28f * 20.f) * 1,j);
		cube.setPosition((rand() % (size[0] / 2)) - size[0] / 20, (rand() % (size[1] / 2)) - size[1] / 20, (rand() % (600 / 2)) - 300 / 40);
		//cube.setScale(rand() % 3 + 5);
		cube.setRotation((rand() % 100) / 100.0 * 3.141 * 2, (rand() % 100) / 100.0 * 3.141 * 2, (rand() % 100) / 100.0 * 3.141 * 2);
		cube.setScale(1);
		cubes.push_back(cube);
	}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);

	float x = 0;

	float fps = 0;

	float delta = 0;

	float update = 0;

	while (window.isOpen()) {
		
		while (window.pollEvent(ev)) {
			switch(ev.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					break;
				case sf::Event::KeyPressed:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
						paused = !paused;
					}
			}
		}
		delta = (clock.restart().asSeconds() - lasttime);
		update += delta;

		sf::Vector2f mp = sf::Vector2f(sf::Mouse::getPosition(window));
		if (!paused) {
			cam.rot.y += (mp.x - size[0] / 2) / 600;
			cam.rot.x -= (mp.y - size[1] / 2) / 600;
			cam.rot.x = max(-3.141f / 2, min(3.141f / 2, cam.rot.x));
			sf::Mouse::setPosition(sf::Vector2i(size[0] / 2, size[1] / 2), window);
		}

		//cam.rot.x = 3.141 / 4;

		float speed = 10;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			//cam.pos.x += 1000 * delta;
			cam.pos.x += speed * delta * cosf(cam.rot.y);
			cam.pos.z += speed * delta * -sinf(cam.rot.y);
			//cam.pos.y += 1000 * delta * sinf(cam.rot.y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			//cam.pos.x -= 1000 * delta;
			//cam.rot.y -= 1 * delta;
			cam.pos.x -= speed * delta * cosf(cam.rot.y);
			cam.pos.z -= speed * delta * -sinf(cam.rot.y);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			cam.pos.x += speed * delta * sinf(cam.rot.y);
			cam.pos.y += speed * delta * -sinf(cam.rot.x);
			cam.pos.z += speed * delta * cosf(cam.rot.y);
			//cam.pos.z += 1000 * delta;
			//cam.rot.x += 1 * delta;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			cam.pos.x -= speed * delta * sinf(cam.rot.y);
			cam.pos.y -= speed * delta * -sinf(cam.rot.x);
			cam.pos.z -= speed * delta * cosf(cam.rot.y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			cam.pos.y -= speed * delta;
			//cam.pos.z += 1000 * delta;
			//cam.rot.x += 1 * delta;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			cam.pos.y += speed * delta;
		}

		/*if (update >= 1 / 60.f) {
			update = 0;
		}*/
		cam.Render(window);

		fps = 1.f / delta;
		text.setString(to_string((int)fps));

		window.draw(text);
		window.display();
		window.clear();
	}

}

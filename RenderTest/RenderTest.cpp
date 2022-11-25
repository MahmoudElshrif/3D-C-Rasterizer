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
	int size[2] = {600,600};
	sf::RenderWindow window(sf::VideoMode(size[0],size[1]), "hello world", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	Camera cam(90,0.1,1000);
	sf::Event ev;
	sf::Clock clock;
	sf::Font font;
	vector<sf::ConvexShape> buffer;
	font.loadFromFile("arial.ttf");
	//if(!font.loadFromFile("arial.ttf"))
	float lasttime = 0;
	vector<Mesh> cubes;

	/*vector<Vertex> vertices;
	vector<Triangle> tris;

	ifstream f("monkey.obj");

	while (!f.eof()) {
		char c[128];
		f.getline(c, 128);

		strstream s;
		s << c;
		char junk;

		if (c[0] == 'v') {
			int x, y, z;
			s >> junk >> x >> y >> z;
			vertices.push_back(Vertex(x,y,z));
		}

		if (c[0] == 'f') {
			int f[3];
			s >> junk >> f[0] >> f[1] >> f[2];
			tris.push_back(Triangle({vertices[f[0] - 1],vertices[f[1] - 1] ,vertices[f[2] - 1] }));
		}

	}*/

	for (int i = 0; i < 30; i++) {
		Mesh cube;
		//cube.faces = tris;
		//cube.setPosition(rand() % 560 - 280, rand() % 650 + 25, rand() % 650 + 25);
		cube.setPosition((rand() % (size[0] - 50)) - size[0] / 2 + 30, (rand() % (size[1] - 50)) - size[1] / 2 + 30,800);
		cube.setScale(rand() % 30 + 100);
		cubes.push_back(cube);
	}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);

	float x = 0;

	float fps = 0;

	float delta = 0;

	while (window.isOpen()) {
		
		while (window.pollEvent(ev)) {
			switch(ev.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					break;
			}
		}
		delta = (clock.restart().asSeconds() - lasttime);
		x += delta;
		buffer = {};
		sf::Vector2f mp = sf::Vector2f(sf::Mouse::getPosition());
		cubes[0].setRotation((mp.x - 300) / 360 * 3.1419, (mp.y - 300) / 360 * 3.1419, 1000);
		cubes[0].setPosition(mp.x - 600, mp.y - 600, 1000);
		cubes[0].Draw(window,buffer,cam);

		//for (int i = 0; i < cubes.size(); i++) {
		//	//cubes[i].setRotation(x * 2 + cubes[i].pos.x * cubes[i].pos.y , (x + cubes[i].pos.x * cubes[i].pos.y) / 2.4, (x + cubes[i].pos.x * cubes[i].pos.y) * 1.4);
		//	//cubes[i].setPosition(cubes[i].pos.x,cubes[i].pos.y,x * 10);
		//	cubes[i].Draw(window,buffer,cam);
		//}
		for (auto i : buffer){
			for (int x = 0; x < 3;x++) {
				auto point = i.getPoint(x);
				i.setPoint(x,sf::Vector2f(point.x * size[0] * 2 + size[0] / 2,point.y * size[1] * 2 + size[1]/2));
				//cout << i.getPoint(x).x << " " << i.getPoint(x).y << endl;
			}
			//cout << endl;
			window.draw(i);
		}
		fps = 1.f / delta;
		text.setString(to_string((int)fps));

		window.draw(text);
		window.display();
		window.clear();
	}

}

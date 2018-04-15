#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "Particle.h"

using namespace std;
using namespace sf;

RenderWindow window;
//extern vector<behavior> behavior;
vector<Texture> textures;

int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "Particles");
	Clock clock;


	Texture texture1, texture2;
	textures.push_back(texture1);
	textures.push_back(texture2);
	textures[0].loadFromFile("fire1.png");
	textures[1].loadFromFile("fire2.png");

	Particle particle(Vector2f(400.f,300.f), Vector2f(0.1f, 0.1f), Vector2f(100.f, 100.f)/*, Vector2f(5.f, 10.f), 300*/, 2.0f, 0);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		Time elapsed = clock.restart();


			particle.update();

		window.clear();
		particle.draw(window);
		window.display();

	}

	return 0;
}










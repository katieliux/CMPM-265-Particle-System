#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "Particle.h"
#include "ParticleSystem.h"

using namespace std;
using namespace sf;

RenderWindow window;
//extern vector<behavior> behavior;
vector<Texture> textures;

int main()
{
	RenderWindow window(sf::VideoMode(1200, 800), "Particles");
	Clock clock;


	Texture texture1, texture2;
	textures.push_back(texture1);
	textures.push_back(texture2);
	textures[0].loadFromFile("fire1.png");
	textures[1].loadFromFile("fire2.png");

	//Particle particle(Vector2f(400.f,300.f), Vector2f(0.1f, 0.1f), Vector2f(100.f, 100.f)/*, Vector2f(5.f, 10.f), 300*/, 2.0f, 0);
	ParticleSystem particles(Vector2f(600.0f, 400.0f), 0.01f, 100.0f, 10.0f, 30.0f,/* 60.0f,*/ 0);
	//ParticleSystem(Vector2f emitter, float rate, float ParticleSize, float ang, float minVelocity, float maxVelocity, int texture)
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		Time elapsed = clock.restart();


			//particle.update();
		particles.update();

		window.clear();
		//particle.draw(window);
		particles.draw(window);
		window.display();

	}

	return 0;
}










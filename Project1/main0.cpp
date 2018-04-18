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


	Texture texture1, texture2, texture3, texture4;
	textures.push_back(texture1);
	textures.push_back(texture2);
	textures.push_back(texture3);
	textures.push_back(texture4);
	textures[0].loadFromFile("huaji.png");
	textures[1].loadFromFile("Doge.png");
	textures[2].loadFromFile("penshui.jpg");
	textures[3].loadFromFile("guai.jpg");

	//Particle particle(Vector2f(100.f,100.f), Vector2f(0.1f, 0.1f), Vector2f(100.f, 100.f)/*, Vector2f(5.f, 10.f)*/, 2.0f, 2.0f, 0);
	ParticleSystem particles(Vector2f(200.0f, 100.0f), 0.1f, 80.0f, 10.0f, 0.3f, 45.0f, 3, 0, 0);
	ParticleSystem particles2(Vector2f(800.0f, 100.0f), 0.3f, 60.0f, 30.0f, 0.08f, 10.0f, 2, 1, 1);
	ParticleSystem particles3(Vector2f(400.0f, 600.0f), 0.2f, 50.0f, 90.0f, 0.05f, 30.0f, 1, 2, 2);
	ParticleSystem particles4(Vector2f(800.0f, 600.0f), 0.05f, 70.0f, 0.0f, 0.5f, 90.0f, 4, 3, 3);
	//Particle(Vector2f start_position, Vector2f velocity, Vector2f size, float angle, float lifetime, float rotation, int behavior, int curves, int texture);

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
			particles2.update();
			particles3.update();
			particles4.update();

			window.clear();
			//particle.draw(window);
			particles.draw(window);
			particles2.draw(window);
			particles3.draw(window);
			particles4.draw(window);
			window.display();

		}

		return 0;
}










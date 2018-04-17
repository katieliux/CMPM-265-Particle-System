#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

using namespace std;
using namespace sf;

extern vector<Texture> textures;

class Particle
{
public:
	Particle(Vector2f start_position, Vector2f velocity, Vector2f size, float angle, float lifetime/*, float rotation, vector<behavior> behavior*/, int texture);
	~Particle();

	RectangleShape r;
	Vector2f velocity;
	Vector2f position;
	Vector2f size;
	float angle;
	Vector2f start_position; 
	Vector2f final_position;
	Vector2f start_velocity;
	Vector2f final_velocity;
	Vector2f start_size;
	Vector2f final_size;
	float lifetime;
	float m_lifetime;
	Clock clock;
	bool alive;
	//vector<behavior> behavior;

	void update();
	void draw(RenderWindow &window);
	//bool isDead();
};

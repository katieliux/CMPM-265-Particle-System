#pragma once
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


class  ParticleSystem
{
public:
	vector<Particle*> particles;
	Vector2f emitter;
	float ParticleSize;
	float rate;
	float m_lifetime;
	float start_Velocity;
	float ang;
	int texture;
	Clock clock;
	float KeyPressed;
	int count;
	int behavior;
	int curves;
	float rotation;


	 ParticleSystem(Vector2f emitter, float rate, float ParticleSize, float ang , float start_Velocity, float rotation, int behavior, int curves, int texture);
	~ ParticleSystem();


	Particle* addParticle();
	void update();
	void draw(RenderWindow& window);
	void clear();
};

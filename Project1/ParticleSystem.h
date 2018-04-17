#pragma once
#include <sfml/graphics.hpp>
#include <sfml/window.hpp>
#include <sfml/audio.hpp>
#include <sfml/network.hpp>
#include <sfml/system.hpp>
#include <sfml/opengl.hpp>
#include <sfml/main.hpp>
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
	float minVelocity;
	//float maxVelocity;
	float ang;
	int texture;
	Clock clock;
	float KeyPressed;


	 ParticleSystem(Vector2f emitter, float rate, float ParticleSize, float ang , float minVelocity, /*float maxVelocity,*/ int texture);
	~ ParticleSystem();


	Particle* addParticle();
	void update();
	void draw(RenderWindow& window);
	void clear();
};

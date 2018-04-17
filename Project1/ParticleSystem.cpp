#include "ParticleSystem.h"
#include "Particle.h"
ParticleSystem::ParticleSystem(Vector2f emitter, float rate, float ParticleSize, float ang ,float minVelocity,/* float maxVelocity,*/ int texture)
{
	this->emitter = emitter;
	this->rate = rate;
	this->ParticleSize = ParticleSize;
	this->texture = texture;
	this->minVelocity = minVelocity;
	//this->maxVelocity = maxVelocity;
	this->ang = ang;
	this->m_lifetime = 0;
	this->KeyPressed = 0;

}

ParticleSystem::~ParticleSystem()
{

}


Particle* ParticleSystem::addParticle()
{
	//float vel = rand() % (int)((maxVelocity * 10.0f) - (minVelocity * 10.0f)) / 10.0f + m_lifetime;
	float vel = rand() % 3 * 0.003f + minVelocity;
	Vector2f velocity = Vector2f(vel * cos(ang), vel * sin(ang));
	Vector2f size = Vector2f(ParticleSize, ParticleSize);
	 //float angle = ((rand() % 90) + ang) * 3.14f / 180.f;
	float angle =  rand() % 314 * 0.01f;
	float lifetime = rand() % 10 * 0.001f + 2.0f;

	return new Particle(this->emitter, velocity, size, angle, lifetime, texture);


	//p.push_back(particle);
}


void ParticleSystem::update()
{
	m_lifetime += clock.restart().asSeconds();
	KeyPressed += clock.restart().asSeconds();

	for (Particle* p : particles)
	{
		p->update();
	}

	if (m_lifetime >= rate)
	{
		particles.push_back(addParticle());
		m_lifetime = 0;
	}


	if (Keyboard::isKeyPressed(Keyboard::Right) && KeyPressed > 0.01f)
	{
		rate *= 100.0f;
		KeyPressed = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && KeyPressed > 0.01f)
	{
		rate *= 0.01f;
		KeyPressed = 0;
	}

	clear();
}

void ParticleSystem::draw(RenderWindow& window)
{
	for (Particle* p : particles)
	{
		p->draw(window);
	}
}

void ParticleSystem::clear() {
	for (auto it = particles.begin(); it != particles.end(); ++it)
	{
		if (!(*it)->alive)
		{
			Particle* p = *it;
			it = particles.erase(it);
			delete p;
			continue;
		}
	}
}
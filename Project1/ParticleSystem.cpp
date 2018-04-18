#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Vector2f emitter, float rate, float ParticleSize, float ang,float start_Velocity, float rotation, int behavior, int curves, int texture)
{
	this->emitter = emitter;
	this->rate = rate;
	this->ParticleSize = ParticleSize;
	this->texture = texture;
	this->start_Velocity = start_Velocity;
	this->ang = ang;
	this->m_lifetime = 0;
	this->KeyPressed = 0;
	this->count = 30;
	this->behavior = behavior;
	this->curves = curves;
	this->rotation = rotation;
}

ParticleSystem::~ParticleSystem()
{

}


Particle* ParticleSystem::addParticle()
{
	//float vel = rand() % (int)((maxVelocity * 10.0f) - (minVelocity * 10.0f)) / 10.0f + m_lifetime;
	Vector2f size = Vector2f(ParticleSize, ParticleSize);
	float angle = ((rand() % 360) + ang) * 3.14f / 180.f;
	float vel = rand() % 3 * 0.003f + start_Velocity;
	Vector2f velocity = Vector2f(vel * cos(angle), vel * sin(angle));
	//float angle =  rand() % 314 * 0.01f;
	float lifetime = rand() % 50 * 0.001f + 2.0f;
	float rotation = rand() % 360;

	return new Particle(this->emitter, velocity, size, angle, lifetime, rotation, behavior, curves, texture);
	//Particle(Vector2f start_position, Vector2f velocity, Vector2f size, float angle, float lifetime, float rotation, int behavior, int curves, int texture)

	//p.push_back(particle);
}


void ParticleSystem::update()
{
	float dt = clock.restart().asSeconds();
	m_lifetime += dt;
	KeyPressed += dt;
	

	if (Keyboard::isKeyPressed(Keyboard::Right) && KeyPressed > 0.5f)
	{
		rate *= 0.9f;
		//particles.push_back(addParticle());
		KeyPressed = 0;
		count++;
		cout << "+++" << endl;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && KeyPressed > 0.5f && count > 1)
	{
		rate *= 1.1f;
		//particles.pop_back();
		KeyPressed = 0;
		count--;
		cout << "---" << endl;
	}
	

	for (Particle* p : particles)
	{
		p->update();
	}

	if (m_lifetime >= rate && particles.size() < count)
	{
		particles.push_back(addParticle());
		m_lifetime = 0;
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
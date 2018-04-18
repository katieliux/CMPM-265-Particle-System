#include "Particle.h"

Particle::Particle(Vector2f start_position, Vector2f velocity, Vector2f size, float angle, float lifetime, float rotation, int behavior, int curves, int texture)
{
	this->start_position = this->position = start_position;
	this->start_velocity = this->velocity = velocity;
	this->start_size = this->size = size;
	this->angle = angle;
	this->lifetime = lifetime;
	this->alive = true;

	r.setSize(size);
	r.setPosition(start_position);
	r.setTexture(&textures[texture]);
	r.setOrigin(size.x / 2, size.y / 2);
	//r.setFillColor(sf::Color::Green); 
	this->m_lifetime = 0;
	this->behavior = behavior;
	this->curves = curves;
	this->rotation = rotation;

	//this->final_size = size * 2.0f;
	//this->final_velocity = velocity * 4.0f;

	switch (behavior)
	{
	case 1: 
		this->final_size = size * 2.0f;
		this->final_velocity = velocity * 4.0f;
		break;
	case 2:
		this->final_size = size * 5.0f;
		this->final_velocity = velocity * 10.0f;
		break;
	case 3:
		this->final_size = size * 0.5f;
		this->final_velocity = velocity * 0.8f;
		break;
	case 4:
		this->final_size = size * 0.1f;
		this->final_velocity = velocity * 1.5f;
		break;	
	}
}


Particle::~Particle()
{

}



float easeInOutSine(float t, float b, float c, float d)
{
	return -c / 2 * (cos(3.14 * t / d) - 1) + b;
};


float easeInOutCirc(float t, float b, float c, float d)
{
	t /= d / 2;
	if (t < 1) return -c / 2 * (sqrt(1 - t*t) - 1) + b;
	t -= 2;
	return c / 2 * (sqrt(1 - t*t) + 1) + b;
};


float easeInQuart(float t, float b, float c, float d)
{
	t /= d;
	return c*t*t*t*t + b;
};

float easeOut(float t, float b, float c, float d) 
{
	return c*t / d + b;
}


void Particle::update()
{
	//float scale = start_size + ((m_lifetime.asSeconds() - m_particles[i].lifetime.asSeconds()) / m_lifetime.asSeconds()) * (final_size - start_size);
	////			m_particles[i].r.setSize(Vector2f(scale, scale));
	float dt = clock.restart().asSeconds();
	m_lifetime += dt;


	switch (curves)
	{
	case 0:
		//Vector2f scale = start_size + (m_lifetime - lifetime / m_lifetime) * /*(final_size - start_size)*/final_size;
		size = start_size + (/*lifetime - */m_lifetime / lifetime) * (final_size - start_size)/*final_size*/;
		velocity = start_velocity + (/*lifetime - */m_lifetime / lifetime) * (final_velocity - start_velocity)/*final_velocity*/;
		break;
	case 1:
		size.x = easeInOutCirc(m_lifetime, start_size.x, final_size.x, lifetime);
		size.y = easeInOutCirc(m_lifetime, start_size.y, final_size.y, lifetime);
		velocity.x = easeInOutCirc(m_lifetime, start_velocity.x, final_velocity.x, lifetime);
		velocity.y = easeInOutCirc(m_lifetime, start_velocity.y, final_velocity.y, lifetime);
		break;
	case 2:
		size.x = easeInOutSine(m_lifetime, start_size.x, final_size.x, lifetime);
		size.y = easeInOutSine(m_lifetime, start_size.y, final_size.y, lifetime);
		velocity.x = easeInOutSine(m_lifetime, start_velocity.x, final_velocity.x, lifetime);
		velocity.y = easeInOutSine(m_lifetime, start_velocity.y, final_velocity.y, lifetime);
		break;
	case 3:
		size.x = easeInQuart(m_lifetime, start_size.x, final_size.x, lifetime);
		size.y = easeInQuart(m_lifetime, start_size.y, final_size.y, lifetime);
		velocity.x = easeInQuart(m_lifetime, start_velocity.x, final_velocity.x, lifetime);
		velocity.y = easeInQuart(m_lifetime, start_velocity.y, final_velocity.y, lifetime);
	}

	r.setSize(size);
	position += velocity;
	r.setPosition(position);
	rotation = easeOut(m_lifetime, 0, 180, lifetime);
	r.setRotation(rotation);

	if (m_lifetime >= lifetime)
	{

		m_lifetime = 0;
		position = start_position;
		size = start_size;
		velocity = start_velocity;
		alive = false;
	}
}

void Particle::draw(RenderWindow &window)
{
	window.draw(r);
}
//
//bool Particle::isDead()
//{
//	return !alive;
//}

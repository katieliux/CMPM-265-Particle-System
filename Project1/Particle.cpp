#include "Particle.h"

Particle::Particle(Vector2f start_position, Vector2f velocity, Vector2f size/*, Vector2f angle*/, float lifetime/*, float rotation, vector<behavior> behavior*/, int texture)
{
	this->start_position = this->position = start_position;
	this->start_velocity = this->velocity = velocity;
	this->start_size = this->size = size;
	this->angle = angle;
	this->lifetime = lifetime;
	//this->isdead = false;
	r.setSize(size);
	r.setPosition(start_position);
	r.setTexture(&textures[texture]);
	r.setOrigin(size.x / 2, size.y / 2);
	//r.setFillColor(sf::Color::Green); 
	m_lifetime = 0;

	this->final_size = size * 2.0f;
	this->final_velocity = velocity * 4.0f;
}


Particle::~Particle()
{

}



void Particle::update()
{
	//float scale = start_size + ((m_lifetime.asSeconds() - m_particles[i].lifetime.asSeconds()) / m_lifetime.asSeconds()) * (final_size - start_size);
	////			m_particles[i].r.setSize(Vector2f(scale, scale));
	m_lifetime += clock.restart().asSeconds();
	//Vector2f scale = start_size + (m_lifetime - lifetime / m_lifetime) * /*(final_size - start_size)*/final_size;
	Vector2f scale = start_size + (/*lifetime - */m_lifetime / lifetime) * /*(final_size - start_size)*/final_size;
	r.setSize(scale);

	Vector2f speed = start_velocity + (/*lifetime - */m_lifetime / lifetime) * (final_velocity - start_velocity)/*final_velocity*/;
	//cout << velocity.x << endl;
	position += speed;
	//cout << position.x << endl;
	r.setPosition(position);

	if (m_lifetime > lifetime)
	{
		m_lifetime = 0;
		position = start_position;
		size = start_size;
		velocity = start_velocity;
	}
}

void Particle::draw(RenderWindow &window)
{
	window.draw(r);
}

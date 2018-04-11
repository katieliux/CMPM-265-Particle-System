#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace std;
using namespace sf;

Texture emittertexture1;
Texture emittertexture2;

struct Particle
{
	sf::Vector2f velocity;
	sf::Time lifetime;
};

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
	int m_angle;
	int m_speed;

	ParticleSystem(unsigned int count, int angle, int speed, int lifetime) :
		m_particles(count),
		m_vertices(sf::Quads, count),
		m_lifetime(sf::seconds(3)),
		m_emitter(0, 0),
		m_angle(angle),
		m_speed(speed)

	{
	}

	void setEmitter(sf::Vector2f position)
	{
		m_emitter = position;
	}

	void update(sf::Time elapsed)
	{
		for (std::size_t i = 0; i < m_particles.size(); ++i)
		{
			// update the particle lifetime
			Particle& p = m_particles[i];
			p.lifetime -= elapsed;

			// if the particle is dead, respawn it
			if (p.lifetime <= sf::Time::Zero)
				resetParticle(i);

			// update the position of the corresponding vertex
			m_vertices[i].position += p.velocity * elapsed.asSeconds();

			// update the alpha (transparency) of the particle according to its lifetime
			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
			m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
		}
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// our particles don't use a texture
		states.texture = NULL;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

private:

	void resetParticle(std::size_t index)
	{
		// give a random velocity and lifetime to the particle
		float angle = (m_angle / 2 - std::rand() % m_angle + 90) * 3.14f / -180.f;
		float speed = (std::rand() % m_speed) + m_speed;
		m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

		// reset the position of the corresponding vertex
		m_vertices[index].position = m_emitter;
	}

};


int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Particles");

	// create the particle system
	ParticleSystem particles1(500, 100, 50, 1);
	ParticleSystem particles2(200, 100, 20, 3);

	// create a clock to track the elapsed time
	sf::Clock clock;

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				particles1 = ParticleSystem(1000, 100, 50, 1);
				particles2 = ParticleSystem(500, 100, 40, 3);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				
			}


		}

		//// make the particle system emitter follow the mouse
		//sf::Vector2i mouse = sf::Mouse::getPosition(window);
		//particles.setEmitter(window.mapPixelToCoords(mouse));
		particles1.setEmitter(Vector2f(200, 600));
		particles2.setEmitter(Vector2f(600, 600));

		//emittertexture1.loadFromFile("fire1.png");
		//particles1.setTexture(emittertexture1);

		// update it
		sf::Time elapsed = clock.restart();
		particles1.update(elapsed);
		particles2.update(elapsed);

		// draw it
		window.clear();
		window.draw(particles1);
		window.draw(particles2);
		window.display();
	}

	return 0;
}
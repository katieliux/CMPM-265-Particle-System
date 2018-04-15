//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/OpenGL.hpp>
//#include <SFML/Main.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace sf;
//
//struct Particle
//{
//	sf::Vector2f velocity;
//	sf::Time lifetime;
//	RectangleShape r;
//	float angle;
//};
//
//class ParticleSystem : public sf::Drawable, public sf::Transformable
//{
//public:
//
//	ParticleSystem(unsigned int count, int angle, int speed, int lifetime, Texture texture) :
//		m_particles(count),
//		//m_vertices(sf::Points, count),
//		m_lifetime(sf::seconds(lifetime)),
//		m_emitter(0, 0),
//		m_angle(angle),
//		m_speed(speed)
//
//	{
//		texture1 = texture;
//		texture2 = texture;
//	}
//
//
//	void setEmitter(sf::Vector2f position)
//	{
//		m_emitter = position;
//	}
//
//	void update(sf::Time elapsed)
//	{
//		for (std::size_t i = 0; i < m_particles.size(); ++i)
//		{
//			// update the particle lifetime
//			Particle& p = m_particles[i];
//			p.lifetime -= elapsed;
//
//			// if the particle is dead, respawn it
//			if (p.lifetime <= sf::Time::Zero)
//				resetParticle(i);
//
//
//
//
//			// update the position of the corresponding vertex
//			//m_particles[i].velocity += p.velocity * elapsed.asSeconds();
//			m_particles[i].r.move(m_particles[i].velocity * elapsed.asSeconds());
//
//			// update the alpha (transparency) of the particle according to its lifetime
//			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
//			//m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
//
//			float scale = start_size + ((m_lifetime.asSeconds() - m_particles[i].lifetime.asSeconds()) / m_lifetime.asSeconds()) * (final_size - start_size);
//			m_particles[i].r.setSize(Vector2f(scale, scale));
//				//size = start_size + ((lifetime-current_time)/lifetime)*final_size)
//
//				//float speed = start_speed + ((m_lifetime.asSeconds() - m_particles[i].lifetime.asSeconds()) / m_lifetime.asSeconds()) * (final_speed - start_speed);
//				////std::cout << speed << std::endl;
//				//m_particles[i].velocity.x = std::cos(m_particles[i].angle) * speed;
//				//m_particles[i].velocity.y = std::sin(m_particles[i].angle) * speed;
//
//			p.velocity.x = p.velocity.x * 1.01f;
//			p.velocity.y = p.velocity.y * 1.01f;
//			p.velocity = Vector2f(p.velocity.x, p.velocity.y);
//
//		}
//	}
//
//private:
//
//	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
//	{
//		// apply the transform
//		states.transform *= getTransform();
//
//		// our particles don't use a texture
//		states.texture = NULL;
//
//		// draw the vertex array
//		for(int i = 0; i< m_particles.size(); i++)
//		{
//			target.draw(m_particles[i].r);
//		}
//	}
//
////private:
//public:
//	//struct Particle
//	//{
//	//	sf::Vector2f velocity;
//	//	sf::Time lifetime;
//
//	//};
//
//	void resetParticle(std::size_t index)
//	{
//		// give a random velocity and lifetime to the particle
//		float angle = (m_angle / 2 - std::rand() % m_angle + 90) * 3.14f / -180.f;
//		float speed = (std::rand() % m_speed) + m_speed;
//		m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
//		m_particles[index].lifetime = m_lifetime - milliseconds((std::rand() % 2000));
//		m_particles[index].angle = angle;
//		// reset the position of the corresponding vertex
//		//m_vertices[index].position = m_emitter;
//
//		m_particles[index].r.setSize(Vector2f(50, 50));
//		m_particles[index].r.setPosition(m_emitter);
//		m_particles[index].r.setTexture(&texture1);
//
//
//	}
//	std::vector<Particle> m_particles;
//	//sf::VertexArray m_vertices;
//	sf::Time m_lifetime;
//	sf::Vector2f m_emitter;
//	sf::Texture texture1;
//	sf::Texture texture2;
//	int m_angle;
//	int m_speed;
//	float start_size = 10;
//	float final_size = 50;
//	float start_speed = 30;
//	float final_speed = 200;
//};
//
//
//int main()
//{
//	// create the window
//	sf::RenderWindow window(sf::VideoMode(800, 600), "Particles");
//
//	Texture texture1;
//	Texture texture2;
//
//	texture1.loadFromFile("fire1.png");
//	texture2.loadFromFile("fire2.png");
//
//	// create the particle system
//	ParticleSystem particles1(200, 200, 10, 5, texture1);
//	ParticleSystem particles2(300, 100, 30, 3, texture2);
//
//	//position
//	particles1.setEmitter(Vector2f(200, 400));
//	particles2.setEmitter(Vector2f(600, 400));
//
//	// create a clock to track the elapsed time
//	sf::Clock clock;
//
//	// run the main loop
//	while (window.isOpen())
//	{
//		// handle events
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//			{
//				vector<Particle> addparticles1 = vector<Particle>(100);
//				particles1.m_particles.insert(particles1.m_particles.end(), addparticles1.begin(), addparticles1.end());
//				vector<Particle> addparticles2 = vector<Particle>(100);
//				particles2.m_particles.insert(particles2.m_particles.end(), addparticles2.begin(), addparticles2.end());
//			}
//
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//			{
//
//				if (particles1.m_particles.size() > 100)
//				{
//					particles1.m_particles.erase(particles1.m_particles.end() - 100, particles1.m_particles.end());
//				}
//				if (particles2.m_particles.size() > 100)
//				{
//					particles2.m_particles.erase(particles2.m_particles.end() - 100, particles2.m_particles.end());
//				}
//
//			}
//
//		}
//
//		//// make the particle system emitter follow the mouse
//		//sf::Vector2i mouse = sf::Mouse::getPosition(window);
//		//particles.setEmitter(window.mapPixelToCoords(mouse));
//
//
//		// update it
//		sf::Time elapsed = clock.restart();
//		particles1.update(elapsed);
//		particles2.update(elapsed);
//
//		// draw it
//		window.clear();
//		window.draw(particles1);
//		window.draw(particles2);
//		window.display();
//	}
//
//	return 0;
//}
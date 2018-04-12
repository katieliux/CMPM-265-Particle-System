//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/OpenGL.hpp>
//#include <SFML/Main.hpp>
//#include <math.h>
//
//using namespace std;
//using namespace sf;
//
//int counter1;
//int counter2;
//
//
//class ParticleSystem : public sf::Drawable, public sf::Transformable
//{
//public:
//
//	ParticleSystem(unsigned int count) :
//		m_particles(count),
//		m_vertices(sf::Quads, 4),
//		m_lifetime(sf::seconds(3)),
//		m_emitter(200, 300)
//
//	{
//
//		//// define it as a rectangle, located at (10, 10) and with size 100x100
//		//m_vertices[0].position = sf::Vector2f(0, 0);
//		//m_vertices[1].position = sf::Vector2f(100, 0);
//		//m_vertices[2].position = sf::Vector2f(100, 100);
//		//m_vertices[3].position = sf::Vector2f(0, 100);
//
//		//// define its texture area to be a 25x50 rectangle starting at (0, 0)
//		//m_vertices[0].texCoords = sf::Vector2f(0, 0);
//		//m_vertices[1].texCoords = sf::Vector2f(100, 0);
//		//m_vertices[2].texCoords = sf::Vector2f(100, 100);
//		//m_vertices[3].texCoords = sf::Vector2f(0, 100);
//
//		texture.loadFromFile("fire1.png");
//	}
//
//	void setEmitter(sf::Vector2f position)
//	{
//		m_emitter = position;
//	}
//
//	void update(sf::Time elapsed)
//	{
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//		{
//			m_particles.resize(m_particles.size() + 10);
//			m_vertices.resize(m_particles.size());
//			counter1++;
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//		{
//			m_particles.resize(m_particles.size() - 10);
//			m_vertices.resize(m_particles.size());
//			counter1--;
//		}
//
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
//			// update the position of the corresponding vertex
//			m_vertices[i].position += p.velocity * elapsed.asSeconds();
//
//			p.velocity.y += 1;
//
//			//m_vertices[i].position += p.velocity * elapsed.asSeconds();
//			p.vrtxArr[0].position += p.velocity * elapsed.asSeconds();
//			p.vrtxArr[1].position += p.velocity * elapsed.asSeconds();
//			p.vrtxArr[2].position += p.velocity * elapsed.asSeconds();
//			p.vrtxArr[3].position += p.velocity * elapsed.asSeconds();
//			
//			p.vrtxArr[0].texCoords = Vector2f(400, 400);
//			p.vrtxArr[1].texCoords = Vector2f(400, 0);
//			p.vrtxArr[2].texCoords = Vector2f(0, 0);
//			p.vrtxArr[3].texCoords = Vector2f(0, 400);
//
//			// update the alpha (transparency) of the particle according to its lifetime
//			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
//			//m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
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
//		states.texture = &texture;
//
//		// draw the vertex array
//		target.draw(m_vertices, states);
//
//		//for (int i = 0; i < m_particles.size(); i++) {
//		//	target.draw(m_particles[i].vrtxArr, states);
//	}
//
//
//
//private:
//
//	struct Particle
//	{
//		sf::Vector2f velocity;
//		sf::Time lifetime;
//		VertexArray vrtxArr;
//	};
//
//	void resetParticle(std::size_t index)
//	{
//		// give a random velocity and lifetime to the particle
//		float angle = (std::rand() % 360) * 3.14f / 180.f;
//		float speed = (std::rand() % 50) + 50.f;
//		m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
//		m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);
//
//		// reset the position of the corresponding vertex
//		//m_vertices[index].position = m_emitter;
//
//				m_particles[index].vrtxArr = VertexArray(Quads, 4);
//				m_particles[index].vrtxArr[0] = m_emitter + Vector2f(4, 4);
//				m_particles[index].vrtxArr[1] = m_emitter + Vector2f(4, -4);
//				m_particles[index].vrtxArr[2] = m_emitter + Vector2f(-4, -4);
//				m_particles[index].vrtxArr[3] = m_emitter + Vector2f(-4, 4);
//
//	}
//
//	std::vector<Particle> m_particles;
//	sf::VertexArray m_vertices;
//	sf::Time m_lifetime;
//	sf::Vector2f m_emitter;
//	sf::Texture texture;
//};
//
//int main()
//{
//	// create the window
//	sf::RenderWindow window(sf::VideoMode(800, 600), "Particles");
//
//	// create the particle system
//	ParticleSystem particles1(1000);
//	//ParticleSystem particles2(500);
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
//		}
//
//		// make the particle system emitter follow the mouse
//		//sf::Vector2i mouse = sf::Mouse::getPosition(window);
//		//particles.setEmitter(window.mapPixelToCoords(mouse));
//
//		// update it
//		sf::Time elapsed = clock.restart();
//		particles1.update(elapsed);
//		//particles2.update(elapsed);
//
//		// draw it
//		window.clear();
//		window.draw(particles1);
//		//window.draw(particles2);
//		window.display();
//	}
//
//	return 0;
//}
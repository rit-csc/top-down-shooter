#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// 16 ms tick time
const long TICK = 16;

int main(int argc, char *argv[])
{
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Window");

	app.setFramerateLimit(60);

	sf::Clock clock;
	sf::Time prevTime = clock.getElapsedTime();
	sf::Time now = clock.getElapsedTime();

	sf::Color cornflowerBlue(100, 149, 237);

	sf::Text txtMessage("Hello World!", sf::Font::getDefaultFont(), 20);

	long accum = 0;
	while (app.isOpen())
	{
		now = clock.getElapsedTime();

		accum += (now - prevTime).asMilliseconds();

		while (accum >= TICK)
		{
			accum -= TICK;

			sf::Event event;
			while (app.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					app.close();
				}

				if ((event.type == sf::Event::KeyPressed) &&
						(event.key.code == sf::Keyboard::Escape))
				{
					app.close();
				}
			}
		}

		app.clear(cornflowerBlue);
		app.draw(txtMessage);
		app.display();
	}

	return EXIT_SUCCESS;
}

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <sstream>

#include "helpers/faststring.hpp"

// 16 ms tick time
const long TICK = 16;

// Quick-n-dirty FPS function
static const sf::Text& getFPS()
{
	static sf::Text txtFPS("", sf::Font::getDefaultFont(), 30);
	static sf::Clock clock;
	static sf::Time prevTime = clock.getElapsedTime();
	static sf::Time now = clock.getElapsedTime();
	static int frames = 0;
	static std::stringstream ss;

	now = clock.getElapsedTime();
	if ((now - prevTime).asMilliseconds() >= 1000)
	{
		prevTime = now;
		ss.str("");
		ss << frames;
		txtFPS.setString(ss.str());
		//txtFPS.setString(itostr(frames));
		frames = 0;
	}
	++frames;

	return txtFPS;
}

int main(int argc, char *argv[])
{
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Window");

	app.setFramerateLimit(60);

	sf::Clock clock;
	sf::Time prevTime = clock.getElapsedTime();
	sf::Time now = clock.getElapsedTime();

	sf::Color cornflowerBlue(100, 149, 237);

	sf::Text txtMessage("Hello World!", sf::Font::getDefaultFont(), 20);
	txtMessage.setPosition(400, 0);

	long accum = 0;
	while (app.isOpen())
	{
		now = clock.getElapsedTime();
		accum += (now - prevTime).asMilliseconds();
		prevTime = now;

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
		app.draw(getFPS());
		app.display();
	}

	return EXIT_SUCCESS;
}

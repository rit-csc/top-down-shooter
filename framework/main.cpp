#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "TCPServer.h"

// 16 ms tick time
const long TICK = 16;

int main(int argc, char *argv[])
{
	//Setup Window
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Window");
	app.setFramerateLimit(60);

	//Setup Clock
	sf::Clock clock;
	sf::Time prevTime = clock.getElapsedTime();
	sf::Time now = clock.getElapsedTime();

	//Prep elements
	sf::Color cornflowerBlue(100, 149, 237);
	sf::Text txtMessage("Hello World!", sf::Font::getDefaultFont(), 20);

    //Start the networking thread
    TCPServer server(44452);
    sf::Thread t(&TCPServer::run, &server);
    t.launch();

	//Begin the game loop
	long accum = 0;
	while (app.isOpen())
	{
		//Adjust the times and the accumulator
		now = clock.getElapsedTime();
		accum += (now - prevTime).asMilliseconds();
		prevTime = now;

		//Prevent sync issues by doing the game loop multiple times, if necessary.
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

		//Clear and redraw the screen
		app.clear(cornflowerBlue);
		app.draw(txtMessage);
		app.display();
	}

	return EXIT_SUCCESS;
}

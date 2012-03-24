#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "network/network.hpp"

// 16 ms tick time
const long TICK = 16;

int main(int argc, char *argv[])
{
    //Setup networking -- this will be moved somewhere more appropriate later
    
    if(argc > 1)
    {
        printf("Starting server...\n");
        setupServer();
        serverThread->launch();
    }
    else
    {
        printf("Starting client...\n");
        setupClient();

        ((TCPClient*)client)->connect("127.0.0.1", SERVER_LISTEN_PORT, sf::seconds(30.0f));
        clientThread->launch();
    }

    //Setup Window
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Window");
	app.setFramerateLimit(60);

    //Setup clock
	sf::Clock clock;
	sf::Time prevTime = clock.getElapsedTime();
	sf::Time now = clock.getElapsedTime();

    //Prep Elements
	sf::Color cornflowerBlue(100, 149, 237);
	sf::Text txtMessage("Hello World!", sf::Font::getDefaultFont(), 20);

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
			
			server->tick();
			client->tick();
		}

        //Clear and redraw the screen
		app.clear(cornflowerBlue);
		app.draw(txtMessage);
		app.display();
	}

    //Cleanup step
    teardownServer();
    teardownClient();

	return EXIT_SUCCESS;
}

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Icon.h"
#include "ButtonsPack.h"
#include "IconsPack.h"
#include "TextsPack.h"
#include "GUI.h"

#define W_HEIGHT 640
#define W_WIDTH 480

int main() {
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "SFML window", sf::Style::Titlebar | sf::Style::Close  );
	window.setFramerateLimit(60);

	EventsManager ev;
	ButtonsPack bp;
	IconsPack ip;
	GUI gui;
	sf::Clock clock;
	TextsPack tp;

	// Start the loop
	while (window.isOpen()) {
		// Process events
		sf::Event event;

		ev.trackMousePositionOnWindow(window);

		bp.eventListener(&ev);

		while (window.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear screen
		window.clear();
        window.draw(gui.drawBackground());

		if(!ev.serialIsOpen()){
            window.draw(gui.drawErrorScreen());
            window.draw(tp.getConnectionErrorText());
            window.draw(ip.drawConnectionIcon(ev.serialIsOpen()));
            ev.openConnection();
        }
		else{
            window.draw(tp.getActualTempText(ev.readTemperatureFromSerial()));
            window.draw(tp.getDegreesText());
			window.draw(bp.drawLightButton(2, sf::Vector2f(W_WIDTH/4.5, W_HEIGHT/1.5 - 140)));
			window.draw(bp.drawLightButton(1, sf::Vector2f(W_WIDTH/1.8, W_HEIGHT/1.5 - 140)));
			window.draw(bp.drawLightButton(0, sf::Vector2f(W_WIDTH/4.5, W_HEIGHT/1.5)));
			window.draw(bp.drawLightButton(4, sf::Vector2f(W_WIDTH/1.8, W_HEIGHT/1.5)));
			window.draw(ip.drawConnectionIcon(ev.serialIsOpen()));
		}
//		window.draw(text);

		window.display();
		//	break;
	}
	return EXIT_SUCCESS;
}

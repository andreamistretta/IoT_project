#ifndef BUTTONSPACK_H
#define BUTTONSPACK_H

#define MAX_LIGHT_NUMBER 5

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "EventsManager.h"

class ButtonsPack {
public:
	ButtonsPack();
	virtual ~ButtonsPack();

	void initLightButtons();
	sf::RectangleShape  drawLightButton(int id, sf::Vector2f pos);

	void eventListener(EventsManager *ev);

protected:

private:
	Button light[MAX_LIGHT_NUMBER];

    void ButtonListener(Button &b);

    EventsManager *event;

    bool buttonIsClicked(Button b);

    sf::Clock clock;


};

#endif // BUTTONSPACK_H

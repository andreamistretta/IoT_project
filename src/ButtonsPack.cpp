#include "ButtonsPack.h"

ButtonsPack::ButtonsPack() {
	initLightButtons();
	initLightManagerButton();
}

ButtonsPack::~ButtonsPack() {
	//dtor
}

void ButtonsPack::eventListener(EventsManager *ev) {
	event = ev;
}

void ButtonsPack::initLightButtons() {
	for(int i = 0; i < MAX_LIGHT_NUMBER; i++) {
		light[i].setTexures("img/lightOff.png", "img/lightOn.png");
	}
}

sf::RectangleShape ButtonsPack::drawLightButton(int id, sf::Vector2f pos) {
	if(id < MAX_LIGHT_NUMBER) {
		lightButtonListener(light[id]);
		light[id].setPosition(pos);
		return light[id].getRectangle();
	} else {
		printf("Impossible to create more than %i buttons\n", MAX_LIGHT_NUMBER);
		return light[4].getRectangle();
	}
}

void  ButtonsPack::initLightManagerButton() {
	lightManager.setTexures("img/lightManagerUp.png", "img/lightManagerDown.png");
	lightManager.setSize(sf::Vector2f(200,200));
}

sf::RectangleShape ButtonsPack::drawLightManagerButton(sf::Vector2f pos) {
	lightManager.setPosition(pos);
	lightManagerButtonListener();
	return lightManager.getRectangle();
}

bool ButtonsPack::buttonIsClicked(Button b) {
	bool click = sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime()>sf::seconds(0.2f);
	bool onButton = b.getRectangle().getGlobalBounds().contains(event->getClickedPoint());
	return click && onButton;
}

void ButtonsPack::lightButtonListener(Button &b) {

	if(buttonIsClicked(b)) {
		b.changeTexture();
		event->changeLightStatus(b.getId());
		clock.restart();
	}
}

void ButtonsPack::lightManagerButtonListener() {
	if(buttonIsClicked(lightManager)) {
		event->changeShowLightButtons();
		clock.restart();
	}
}







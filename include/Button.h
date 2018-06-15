#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "EventsManager.h"


class Button{
    public:
        Button();
        virtual ~Button();

        int getId();

        sf::RectangleShape getRectangle();

        void setTexures(std::string textureName1, std::string textureName2);
        void setPosition(sf::Vector2f pos);
        void changeTexture();

    protected:

    private:
        int idx;
        int generateID();

        bool state;

        sf::RectangleShape rect;
        sf::Texture texture[2];

};

#endif // BUTTON_H

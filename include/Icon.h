#ifndef ICON_H
#define ICON_H
#include <SFML/Graphics.hpp>
#include "EventsManager.h"


class Icon
{
    public:
        Icon();
        virtual ~Icon();

        sf::RectangleShape getRect();

        void setTexures(std::string textureName1, std::string textureName2);
        void setPosition(sf::Vector2f pos);
        void changeTexture(bool state = false);
        bool getStatus();
        void setStatus(bool s);

    protected:

    private:
         sf::RectangleShape rect;
         sf::Texture texture[2];
         bool status;

};

#endif // ICON_H

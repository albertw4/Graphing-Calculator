#include "sidebar.h"
#include "../../TwoBalls/constants.h"

Sidebar::Sidebar()
{

}

Sidebar::Sidebar(float left, float width):_left(left), _width(width){
    items.reserve(50);

    rect.setFillColor(sf::Color(105,105,105)); //(192,192,192)); //silver

    rect.setPosition(sf::Vector2f(600, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));


    sinx.setSize(sf::Vector2f(100,60));

    sinx.setPosition(sf::Vector2f(625,10));

    sinx.setFillColor(sf::Color::Red);


    cosx.setSize(sf::Vector2f(100,60));

    cosx.setPosition(sf::Vector2f(625,90));

    cosx.setFillColor(sf::Color::Blue);


    tanx.setSize(sf::Vector2f(100,60));

    tanx.setPosition(sf::Vector2f(625,170));

    tanx.setFillColor(sf::Color::Yellow);


    over_sin.setSize(sf::Vector2f(100,60));

    over_sin.setPosition(sf::Vector2f(625,250));

    over_sin.setFillColor(sf::Color::Green);

}

void Sidebar::draw(sf::RenderWindow& window){
    window.draw(rect);

    window.draw(sinx);

    window.draw(cosx);

    window.draw(tanx);

    window.draw(over_sin);


}



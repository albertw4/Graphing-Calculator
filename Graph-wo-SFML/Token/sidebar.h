//sidebar class to create a sidebar
#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//sidebar class to create a sidebar
class Sidebar
{
public:
    //constructor
    Sidebar();
    Sidebar(float left, float width);

    //function to draw sidebar on the window
    void draw(sf::RenderWindow& window);

private:
    //initilize rectangle for the sidebar
    sf::RectangleShape rect;

    //initilize rectangle for the sinx button
    sf::RectangleShape sinx;

    //initilize rectangle for the cosx button
    sf::RectangleShape cosx;

    //initilize rectangle for the tanx button
    sf::RectangleShape tanx;

    //initilize rectangle for the sin(1/x) button
    sf::RectangleShape over_sin;

    //vector to hold strings
    vector<string> items;

    //float to keep the size of side bar
    float _left;

    //float to keep the size of side bar
    float _width;

};

#endif // SIDEBAR_H

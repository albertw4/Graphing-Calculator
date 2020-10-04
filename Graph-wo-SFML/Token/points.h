//point class to use points
#ifndef POINTS_H
#define POINTS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../LinkClass_include/Queue/my_queue.h"

using namespace std;

//point class to use points
class Points
{
public:
    //constructor
    Points();

    Points(double left, double right);

    //return the x value
    double get_x();

    //return the y value
    double get_y();

    //print out the points
    friend ostream& operator <<(ostream& outs, Points* print_me);

    //function to display x and y
    void show();


private:

    //double value for x
    double _x;

    //double value for y
    double _y;
};

#endif // POINTS_H

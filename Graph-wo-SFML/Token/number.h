//Number class to use number
#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"
#include <iostream>

using namespace std;

//Number class is a child class of Token class
class Number :public Token
{
public:
    //constructor
    Number();

    Number(double value);

    //virtual function to display the number
    virtual void show();

    //virtual function to return the number
    virtual double get_value();

    //virtual function to return is number is a variable
    virtual bool is_variable();

    //virtual function to set variable to a number
    virtual void set_value(double value);

private:

    //double value
    double _value;

    //bool - if number is a variable
    bool _is_variable;

};

#endif // NUMBER_H

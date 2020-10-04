//class to use operator
#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"

//OPerator class is a child class of token
class Operator: public Token
{
public:
    //constructors
    Operator();

    Operator(char face);

    //virtual function to display the precedence of operator
    virtual int get_preceden();

    //virtual function to display the operator
    virtual void show();

    //virtual function to return the value
    virtual double get_value();

    //virtual function to display the operator face
    virtual char get_face();

    //virtual function to tell if a number is a variable
    virtual bool is_variable();

    //virtual function to set value of the number
    virtual void set_value(double value);

private:

    //char to tell which operator it is
    char _face;

    //int precedence to do operation order
    int _preceden;
};

#endif // OPERATOR_H

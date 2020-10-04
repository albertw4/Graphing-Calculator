//Token class as base class
#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "../../LinkClass_include/nodes/node_template.h"
#include "../../LinkClass_include/LinkList_functions/linklist_template_function.h"
#include "../../LinkClass_include/Queue/my_queue.h"
#include "../../LinkClass_include/Stacks/my_stack.h"
#include "points.h"

using namespace std;

//Token class as base class
class Token
{
public:
    //constructor
    Token();

    //virtual function to display the operator or number
    virtual void show();

    //virtual function to return the value
    virtual double get_value();

    //virtual function to display the operator face
    virtual char get_face();

    //virtual function to display the precedence of operator
    virtual int get_preceden();

    //virtual function to tell if a number is a variable
    virtual bool is_variable();

    //virtual function to set value of the number
    virtual void set_value(double value);

    //display the tokens
    friend ostream& operator <<(ostream& outs, Token* print_me);

    //return the result from a Queue of token pointers
    double RPN(Queue<Token*> q);

    //return a queue of token pointers in reverse polish
    Queue<Token*> Shunt(Queue<Token*> q);

    //return a queue of token pointer after initiling it from a input
    Queue<Token*> input();

    //return a queue of token pointer after initiling it from a string input
    Queue<Token*> input_infile(string input);

    //prerequsite: takes in a queue of token pointers and x value
    //postcondition: calculates y from the input and x
    double get_point(const Queue<Token*> & q, double x);

    //returns a double from a string of numbers
    double string_to_double(string numbers);

private:


};

#endif // TOKEN_H

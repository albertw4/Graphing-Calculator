//Program uses struct Poly_node

#ifndef POLY_NODE_H
#define POLY_NODE_H
#include <iostream>

using namespace std;
// struct Poly_node
struct Poly_node
{
public:
    //const
    Poly_node();

    Poly_node(int coef, int power);

    Poly_node(int coef);

    friend ostream& operator <<(ostream& outs, const Poly_node& print_me);


private:

    // power of the node
    int _power;

    //coefficient of the node
    int _coef;

    //point to the next node
    Poly_node* _next;
};

#endif // POLY_NODE_H

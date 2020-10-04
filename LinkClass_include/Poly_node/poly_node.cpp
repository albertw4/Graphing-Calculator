#include "poly_node.h"
#include <iostream>

//deafult constr
Poly_node::Poly_node():_power(0),_coef(0),_next(NULL){

    //left blank

}

Poly_node::Poly_node(int coef, int power){

    _coef = coef;

    _power = power;

    _next = NULL;

}

Poly_node::Poly_node(int coef){

    _coef = coef;

    _power = 0;

    _next = NULL;
}

ostream& operator <<(ostream& outs, const Poly_node& print_me){
    outs<< print_me._coef << "x^" << print_me._power;

    return outs;
}


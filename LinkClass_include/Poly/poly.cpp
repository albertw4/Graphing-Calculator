#include "poly.h"
#include <iostream>
#include <string>

//construc
Poly::Poly(vector<int> coef):head_ptr(NULL)
{
    //left blank
}

Poly::Poly(int coef){

    //first node is a constant coef with a power 0
    head_ptr = new Poly_node(coef);
}

Poly::Poly(int coef, int power){

    //first node is coef with power
    head_ptr = new Poly_node(coef,power);
}

//takes polynomial from user
void Poly::input_poly(){

}

//Big Three
//Destructor
Poly::~Poly(){

    //delete head_ptr
    delete head_ptr;
}

//copy
Poly::Poly(const Poly &left){

    head_ptr = left.head_ptr;
}



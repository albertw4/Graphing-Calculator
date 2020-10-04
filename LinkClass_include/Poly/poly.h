#ifndef POLY_H
#define POLY_H
#include "../../LinkClass_include/Poly_node/poly_node.h"
#include <iostream>

using namespace std;

class Poly
{
public:
    //const
    Poly();
    //Initializes the head_ptr to NULL

    Poly(int coef);
    //Initilizes the polynomial with its coefficient with a power of 0

    Poly(int coef, int power);
    //Initilizes the polynomial with its coefficient and power

    //Big Three
    ~Poly();
    //destructor to delete

    Poly(const Poly& left);
    //copy constrc

    const Poly operator =(const Poly& left);
    //assignment

    //input & output
    void input_poly();

    void ouput_poly();

    //Calculation
    friend Poly operator +(const Poly& left, const Poly& right);
    //Precondition: Poly left and right have been given values
    //Postcondition: returns the sum of the values of left and right

    friend Poly operator -(const Poly& left, const Poly& right);
    //Precondition: Poly left and right have been given values
    //Postcondition: returns the difference of the values of left and right

    friend Poly operator *(const Poly& left, const Poly& right);
    //Precondition: Poly left and right have been given values
    //Postcondition: returns the product of the values of left and right

    friend ostream& operator << (ostream& outs, const Poly& print_me);
    //Precondition: Fraction print_me have been given values
    //Postcondition: output the values of print_me

private:
    Poly_node* head_ptr;
};

#endif // POLY_H

#include <iostream>
#include <vector>
#include "../../LinkClass_include/nodes/node_template.h"
#include "../../LinkClass_include/LinkList_functions/linklist_template_function.h"
#include "../../LinkClass_include/lists/list_templated.h"
#ifndef POLY_TEMPLATED_H
#define POLY_TEMPLATED_H
//templating
template<typename T>

//struct Term to be used as T item that has a coefficient and an exponent
struct Term{

    //double for coefficient
    double _coef;

    //int power aka exponent
    int _exp;
};

//templating
template<typename T>

//class for Polynomial
class Poly{

public:

    //default constructor
    Poly();
    //Initilize _coef and exp to 0

    //constructor
    Poly(double coef);
    //Initilize _coef to coef and exp to 0

    Poly(const vector<int>& coef);
    //Initilize Term to be each Polynomial

    //Big Three
    ~Poly();
    //destructor to delete

    Poly(const Poly& left);
    //copy constrc

    const Poly operator =(const Poly& left);
    //assignment

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

    List<T> Polynomial;
};

template<typename T>
Poly::Poly(){

}


Poly::Poly(double coef){


}



ostream& operator << (ostream& outs, const Poly& print_me){

}

#endif // POLY_TEMPLATED_H

#include "number.h"

Number::Number():_is_variable(true), _value(1)
{

    //left blank
}

Number::Number(double value):_value(value), _is_variable(false){
    //left blank
}

void Number::show(){

    cout<< _value;
}

double Number::get_value(){

    return _value;
}

bool Number:: is_variable(){

    return _is_variable;
}

void Number::set_value(double value){

    _value = value;
}




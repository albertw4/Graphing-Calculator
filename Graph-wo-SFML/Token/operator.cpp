#include "operator.h"

Operator::Operator()
{
    //left blank
}


Operator::Operator(char face):_face(face){
    if(face == '+'){
        _preceden = 2;
    }

    if(face == '-'){
        _preceden = 2;
    }

    if(face == '*'){
        _preceden = 3;
    }

    if(face == '/'){
        _preceden = 3;
    }

    if(face == '^'){
        _preceden = 4;
    }

    if(face == '('){
        _preceden = 0;
    }

    //sin
    if(face == 's'){
        _preceden = 3;
    }

    //cos
    if(face == 'c'){
        _preceden = 3;
    }

    //tan
    if(face == 't'){
        _preceden = 3;
    }

    //csc
    if(face == 'S'){
        _preceden = 3;
    }

    //sec
    if(face == 'C'){
        _preceden =3;
    }

    //cot
    if(face == 'T'){
        _preceden =3;
    }
}

int Operator::get_preceden(){

    return _preceden;
}


void Operator::show(){
    cout<<  _face;
}

double Operator::get_value(){

}

bool Operator::is_variable(){

    return false;

}

void Operator::set_value(double value){

}



char Operator::get_face(){
    return _face;
}



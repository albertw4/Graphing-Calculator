#include "points.h"

Points::Points(double left, double right):_x(left),_y(right)
{
    //left blank
}

double Points::get_x(){
    return _x;
}

double Points::get_y(){
    return _y;
}


ostream& operator <<(ostream& outs, Points* print_me){

    print_me->show();

    return outs;

}

void Points::show(){

    cout<<"(" <<_x<< ")"<<" "<<"("<<_y<<")";
}




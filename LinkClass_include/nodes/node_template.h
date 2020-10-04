//  Program to use node struc that is templated
#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

//templating with typename T to use different types
template <typename T>

//struct for node to create each node and linked list
struct node
{
public:
    //ctors
    node();
    //Initilizes the _next to NULL

    node(T item);
    //Initilizes the _item to item and _next to NULL


    //Precondition: if outs is a file output stream, then outs has already been
    //connected to a file. print_me have been given values
    //Postcondition: returns the outs
    friend ostream& operator <<(ostream& outs, const node<T> print_me){

        //print item
        outs<<print_me._item;

        //return outs
        return outs;
    }

    // member varables
    //item that is T type
    T _item;

    //pointer to next node
    node* _next;


};

//Initilizes the _next to NULL
template <typename T> //templating
node<T>::node():_item(T()), _next(NULL)
{
    //empty

}


//Initilizes the _item to item and _next to NULL
template <typename T> //templating
node<T>::node(T item):_item(item),_next(NULL){

    //empty
}

#endif // NODE_H

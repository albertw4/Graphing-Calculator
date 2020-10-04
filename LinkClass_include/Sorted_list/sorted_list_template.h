//program to use class Sorted_list

#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <iostream>
//include link_list functions
#include "../../LinkClass_include/LinkList_functions/linklist_template_function.h"
//includes nodes struct
#include "../../LinkClass_include/nodes/node_template.h"

//template for type T
template<typename T>

//class for Sorted_list
class Sorted_list
{
public:
    //const
    Sorted_list();
    //Initilizes head_ptr to NULL

    void insert(T item);
    //Precondition: item has been given value
    //Postcondition: insert item in order

    //template TT
    template<typename TT>
    friend ostream& operator <<(ostream& outs, const Sorted_list<TT>& print_me);
    //Precondition: if outs is a file output stream, then outs has already been
    //connected to a file. print_me have been given values
    //Postcondition: returns the outs

private:

    //node pointer head_ptr
    node<T>* head_ptr;
};

//template
template<typename T>
//Initilizes head_ptr to NULL
Sorted_list<T>::Sorted_list():head_ptr(NULL){

}


//template
template<typename T>\
//insert item in order
void Sorted_list<T>::insert(T item){
    //calls _insert_sorted and pass in head_ptr and item
    _insert_sorted(head_ptr,item);
}

//template
template<typename TT>
//prints sorted_list
ostream& operator <<(ostream& outs, const Sorted_list<TT>& print_me){

    //return _print with print_me's head_ptr
    return _print(outs,print_me.head_ptr);
}


#endif // SORTED_LIST_H

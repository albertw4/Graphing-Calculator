//program to use class List

#ifndef LIST_H
#define LIST_H
#include <iostream>
//includes link_list functions
#include "../../LinkClass_include/LinkList_functions/linklist_template_function.h"
//includes node struc
#include "../../LinkClass_include/nodes/node_template.h"

//template for type T
template <typename T>

// class for Lists
class List
{
public:
    //construc
    List();
    //Initilize head_ptr to NULL

    //function
    node<T> *&begin();
    //returns head_ptr

    node<T>* insert_head(T item);
    //Precondition: item has been given value
    //Postcondition: returns the node that has been inserted at the head

    node<T>* insert_after(node<T>* after_me, T item);
    //Precondition: after_me is declared and valid, and item has been given value
    //Postcondition: returns the node that has been inserted after after_me

    node<T>* insert_before(node<T>* before_me, T item);
    //Precondition: before_me is declared and valid, and item has been given value
    //Postcondition: returns the node that has been inserted before before me


    node<T>* insert_sorted(T item);
    //Precondition: item has been given value
    //Postcondition: returns the node that has been inserted in order


    node<T>* search_sorted(T item);
    //Precondition: item has been given value
    //Postcondition: returns the node that has the value item, return NULL if not found


    node<T>* search_nsorted(T item);
    //Precondition: item has been given value
    //Postcondition: returns the node that has the value item, return NULL if not found

    node<T>* copy(List<T> copy_me);
    //Precondition: copy_me is declared
    //Postcondition: returns a new copy of copy_me


    node<T>* previous(node<T>* previous_to_this);
    //Precondition: previous_to_this is decalred and valid
    //Postcondition: returns the node that is previous to previous_to_this


    node<T>* where_this_goes(T item);
    //Precondition: item has been given value
    //Postcondition: returns the node that is one before where the item belongs

    T _delete(node<T>* delete_me);
    //Precondition: head_ptr is declared, and delete_me is declared and valid
    //Postcondition: returns the item that is in delete_me and calls _remove to get
    //the node then delete it

    node<T>* remove(T item);
    //Precondition: item has been given value
    //Postcondition: returns the node that has the value item, must work on head_ptr

    void clear_all();
    //Postcondition: removes every node in clear_me


    //Big Three
    //Destructor
    ~List();

    //copy
    List<T>(List<T>& to_copy);
    //Precondition: List copy have been given values
    //Postcondition: returns a new List with a new head_ptr that is the same
    // as equal


    //assignment
    List<T>& operator =(const List<T>& equal);
    //Precondition: List equal have been given values
    //Postcondition: returns a new List with a new head_ptr that is the same
    // as equal

    template<typename TT>
    friend ostream& operator <<(ostream& outs, const List<TT>& print_me);
    //Precondition: if outs is a file output stream, then outs has already been
    //connected to a file. print_me have been given values
    //Postcondition: returns the outs


private:

    //node pointer head_ptr
    node<T>* head_ptr;
};


template<typename T>
//Initilize head_ptr to NULL
List<T>::List():head_ptr(NULL){
    //left blank
}

template<typename T>
//returns the node that has been inserted at the head
node<T>*  List<T>::insert_head(T item){
    //return _insert_head with head_ptr and item
    return _insert_head(head_ptr, item);
}

template<typename T>
//returns the node that has been inserted after after_me
node<T>* List<T>::insert_after(node<T>* after_me, T item){
    //return _insert_after with node pointer after_me and item
    return _insert_after(after_me,item);
}

template<typename T>
//returns the node that has been inserted before before me
node<T>* List<T>::insert_before(node<T>* before_me, T item){
    //return _insert_before with node pointer before_me and item
    return _insert_before(before_me,item);
}

template<typename T>
//returns the node that has been inserted in order
node<T>* List<T>::insert_sorted(T item){
    //return _insert_sorted with head_ptr and item
    return _insert_sorted(head_ptr,item);
}

template<typename T>
//returns the node that has the value item, return NULL if not found
node<T>* List<T>::search_sorted(T item){
    //return _search_sorted with head_ptr and item
    return _search_sorted(head_ptr, item);
}

template<typename T>
//returns the node that has the value item, return NULL if not found
node<T>* List<T>::search_nsorted(T item){
    //return _search_nsorted with head_ptr and item
    return _search_nsorted(head_ptr, item);
}

template<typename T>
//returns a new copy of copy_me
node<T>* List<T>::copy(List<T> copy_me){
    //return _copy with copy_me's head_ptr
    return _copy(copy_me.head_ptr);
}

template<typename T>
//returns the node that is previous to previous_to_this
node<T>* List<T>::previous(node<T>* previous_to_this){
    //return _previous with head_ptr and previous_to_this
    return _previous(head_ptr, previous_to_this);
}

template<typename T>
//returns the node that is one before where the item belongs
node<T>* List<T>::where_this_goes(T item){
    //return _where_this_goes with head_ptr and item
    return _where_this_goes(head_ptr, item);
}

template<typename T>
//returns the item that is in delete_me and calls _remove to get
//the node then delete it
T List<T>::_delete(node<T>* delete_me){
    //return _delete_ with head_ptr and delete_me
    return _delete_(head_ptr, delete_me);
}

template<typename T>
//returns the node that has the value item, must work on head_ptr
node<T>* List<T>::remove(T item){
    //return _remove with head_ptr and item
    return _remove(head_ptr, item);
}

template<typename T>
//removes every node in clear_me
void List<T>::clear_all(){
    //return _clear_all with head_ptr
    _clear_all(head_ptr);
}





template <typename T>
//destructor
List<T>::~List()
{
    //call _clear_all to clear head_ptr
    _clear_all(head_ptr);

    //set head_ptr to NULL
    head_ptr = NULL;
}

//Copy
template <typename T>
//returns a new List with a new head_ptr that is the same
// as equal
List<T>::List(List<T>& to_copy){

    //if empty node
    if(to_copy.head_ptr == NULL){

        //return new node
        this->head_ptr= NULL ;
    }

    //created new_head_ptr that is a new node that has the head_ptr's _item
    node<T>* new_head_ptr = new node<T>(to_copy.head_ptr->_item);

    //Initilize node pointer here to point at head_ptr
    node<T>* here = to_copy.head_ptr;

    //Initilize node pointer there to point at new_head_ptr
    node<T>* there = new_head_ptr;

    //while here is not at last node
    while(here->_next != NULL){
        //set here to next node
        here = here->_next;

        //create a new node at there's _next that has here's _item
        there->_next = new node<T>(here->_item);

        //set there to next node
        there = there->_next;
    }

    //set last node to point at NULL
    there->_next = NULL;

    //return new_head_ptr
    head_ptr = new_head_ptr;

}



////Assignment
template <typename T>
//returns a new List with a new head_ptr that is the same
// as equal
List<T>& List<T>:: operator =(const List<T>& equal)
{
    //if self assignment
    if(this->head_ptr == equal.head_ptr){
        cout<< "assigning your self";

        //return *this
        return *this;
    }

    //if assigning to an empty list
    if(equal.head_ptr == NULL){
        //set head_ptr to NULL
        this->head_ptr = NULL;

        //return *this
        return *this;
    }

    else{

    //created new_head_ptr that is a new node that has the equal's head_ptr's _item
    node<T>* new_head_ptr = new node<T>(equal.head_ptr->_item);

    //Initilize node pointer here to point at equal's head_ptr
    node<T>* here = equal.head_ptr;

    //Initilize node pointer there to point at new_head_ptr
    node<T>* there = new_head_ptr;

    //while here is not at last node
    while(here->_next != NULL){

        //set here to next node
        here = here->_next;

        //create a new node at there's _next that has here's _item
        there->_next = new node<T>(here->_item);

        //set there to next node
        there = there->_next;
    }

    //set last node to point at NULL
    there->_next = NULL;

    //set head_ptr to new_head_ptr
    this->head_ptr = new_head_ptr;

    //return *this
    return *this;
}
}

template<typename TT>
//prints print_me
ostream& operator <<(ostream &outs, const List<TT>& print_me){

    //return _print with print_me's head_ptr
    return _print(outs, print_me.head_ptr);
}

template <typename T>
//returns the head_ptr
node<T>*& List<T>::begin()
{
    //return head_ptr
    return head_ptr;
}


#endif // LIST_H

// program to use class Queue

#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#include <iostream>
//includes struct node
#include "../../LinkClass_include/nodes/node_template.h"
//includes link_list functions
#include "../../LinkClass_include/LinkList_functions/linklist_template_function.h"

//template for type T
template<typename T>

//class for Queue
class Queue{

public:
    //construc
    Queue();
    //Initilize head_ptr to NULL and tail_ptr to NULL

    //big three
    //copy constr
    Queue<T>(const Queue<T>& to_copy);
    //Precondition: Queue to_copy have been given values
    //Postcondition: returns a new Queue with a new head_ptr and tail_ptr that
    //is the same as to_copy

    //destruc
    ~Queue();

    //assignment
    Queue<T>& operator =(const Queue<T>& equal);
    //Precondition: Queue equal have been given values
    //Postcondition: returns a new Queue with a new head_ptr and tail_ptr that
    //is the same as equal

    //functions
    //add from back
    void push(T item);
    //Precondition: item has been given value
    //Postcondition: inserts item from back

    //delete from front
    T pop();
    //Postcondition: delete top number aka head_ptr and return the item

    bool empty();
    //Postcondition: check if Queue is empty, returns true if it is, false if not


    T top();
    //Postcondition: return the top number aka head_ptr

    template<typename TT>
    friend ostream& _print(ostream& outs, const Queue<TT>& print_me);
    //Precondition: if outs is a file output stream, then outs has already been
    //connected to a file. print_me have been given values
    //Postcondition: returns the outs


    template<typename TT>
    friend ostream& operator <<(ostream& outs, const Queue<TT>& print_me);
    //Precondition: if outs is a file output stream, then outs has already been
    //connected to a file. print_me have been given values
    //Postcondition: returns the outs

private:

    //delete items here
    node<T>* head_ptr;

    //add items here
    node<T>* tail_ptr;
};


template<typename T>
//Initilize head_ptr to NULL and tail_ptr to NULL
Queue<T>::Queue():head_ptr(NULL),tail_ptr(NULL){
    //left blank
}

template<typename T>
//inserts item from back
void Queue<T>::push(T item){
    //If empty Queue
    if(head_ptr == NULL && tail_ptr == NULL){

        //calls insert_head with head_ptr and item
        _insert_head(head_ptr, item);

        //set tail_ptr to head_ptr
        tail_ptr = head_ptr;
    }

    //if not empty
    else{
        //insert from the back with _insert_after with tail_ptr and item
        tail_ptr = _insert_after(tail_ptr, item);
    }
}

template<typename T>
T Queue<T>::pop(){
    return _delete_(head_ptr,head_ptr);
}

template<typename T>
//delete top number aka head_ptr and return the item
T Queue<T>::top(){
    //if empty Queue
    if(head_ptr == NULL){
        //Ouput it is empty
//        cout<<"no item in this Queue.";

        //return NULL/0
        return NULL;
    }

    //If not empty
    else{
    //return head_ptr's _item
    return head_ptr->_item;
    }
}

template<typename T>
//clear Queue
bool Queue<T>::empty(){
    //check if Queue is empty
    //if list is empty
    if(head_ptr == nullptr){

        //Ouput that its empty
//        cout<<"Queue_list is empty"<<endl;

        return true;
    }

    //if its not empty
    else{

        //Output that its not empty
//        cout<<"Queue_list is not empty"<<endl;

        return false;
    }
}


template<typename TT>
//prints the Queue
ostream& _print(ostream& outs, const Queue<TT>& print_me){
    //returns _print with print_me's head_ptr
    return _print(outs,print_me.head_ptr);
}

template<typename TT>
//prints the Queue
ostream& operator <<(ostream& outs, const Queue<TT>& print_me){
    //returns _print with print_me's head_ptr
    return _print(outs,print_me.head_ptr);
}

//big three
//destructor
template<typename T>
Queue<T>::~Queue(){
    //calls _clear_all with head_ptr
    _clear_all(head_ptr);

    //set head_ptr to NULL
    head_ptr = NULL;

    //set tail_ptr to NULL
    tail_ptr = NULL;
}

//copy
template<typename T>
//returns a new Queue with a new head_ptr and tail_ptr that
//is the same as to_copy
Queue<T>::Queue(const Queue<T>& to_copy){
    //set head_ptr to call _copy with to_copy's head_ptr
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

    //Initilize node pointer here to head_ptr
    node<T>* next = head_ptr;

    //go through the Queue till the end
    while(next->_next != NULL){
        next= next->_next;
    }

    //set tail_ptr to last node
    tail_ptr = next;
}

//assignment
template<typename T>
//returns a new Queue with a new head_ptr and tail_ptr that
//is the same as equal
Queue<T>& Queue<T>::operator =(const Queue<T>& equal){
    //if self assignment
    if(equal.head_ptr == this->head_ptr){
        cout<<"self assignment";
    }

    //if assigning to an empty list
    if(equal.head_ptr == NULL){

        //set head_ptr to NULL
        this->head_ptr = NULL;

        //set tail_ptr to NULL
        this->tail_ptr = NULL;

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

    //Initilize node pointer tail to point at new_head_ptr
    node<T>* tail = new_head_ptr;

    //run through the Queue till the last node
    while(tail->_next != NULL){
        tail= tail->_next;
    }

    //set tail_ptr to last node
    this->tail_ptr = tail;

    //return *this
    return *this;
    }

}

#endif // MY_QUEUE_H

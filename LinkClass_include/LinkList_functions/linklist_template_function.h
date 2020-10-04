// Program to use node as linked list

#ifndef LINKLIST_FUNCTION_H
#define LINKLIST_FUNCTION_H
#include <cassert>
//include caseert to end program if violated

#include "../../LinkClass_include/nodes/node_template.h"
#include <iostream>

using namespace std;

//template
template <typename T>
node<T> * _insert_head(node<T>* &head_ptr, T item);
//Precondition: head_ptr is declared, and item has been given value
//Postcondition: returns the node that has been inserted at the head

//template
template <typename T>
node<T> * _insert_after(node<T>* &after_me, T item);
//Precondition: after_me is declared and valid, and item has been given value
//Postcondition: returns the node that has been inserted after after_me

//template
template <typename T>
node<T> * _insert_before(node<T>* &before_me, T item);
//Precondition: before_me is declared and valid, and item has been given value
//Postcondition: returns the node that has been inserted before before me

//template
template <typename T>
node<T>* _insert_sorted(node<T>* &head_ptr, T item);
//Precondition: head_ptr is declared, and item has been given value
//Postcondition: returns the node that has been inserted in order

//template
template <typename T>
node<T>* _search_sorted(node<T>* &head_ptr, T item);
//Precondition: head_ptr is declared, and item has been given value
//Postcondition: returns the node that has the value item, return NULL if not found

//template
template <typename T>
node<T>* _search_nsorted(node<T>* &head_ptr, T item);
//Precondition: head_ptr is declared, and item has been given value
//Postcondition: returns the node that has the value item, return NULL if not found

//template
template <typename T>
node<T>* _copy(node<T>* &head_ptr);
//Precondition: head_ptr is declared
//Postcondition: returns a new copy of the head_ptr

//template
template <typename T>
node<T>* _previous(node<T>* head_ptr, node<T>* previous_to_this);
//Precondition: head_ptr is declared, and previous_to_this is decalred and valid
//Postcondition: returns the node that is previous to previous_to_this

//template
template <typename T>
node<T>* _where_this_goes(node<T>* &head_ptr, T item);
//Precondition: head_ptr is declared, and item has been given value
//Postcondition: returns the node that is one before where the item belongs

//template
template <typename T>
T _delete_(node<T>*& head_ptr, node<T>* delete_me);
//Precondition: head_ptr is declared, and delete_me is declared and valid
//Postcondition: returns the item that is in delete_me and calls _remove to get
//the node then delete it


//template
template <typename T>
node<T>* _remove(node<T>*& head_ptr, T item);
//Precondition: head_ptr is declared, and item has been given value
//Postcondition: returns the node that has the value item, must work on head_ptr

//template
template <typename T>
ostream& _print(ostream& outs, const node<T>* head_ptr);
//Precondition: if outs is a file output stream, then outs has already been
//connected to a file. head_ptr have been given values
//Postcondition: returns the outs

//template
template <typename T>
void _clear_all(node<T>* &clear_me);
//Precondition: clear_me is declared
//Postcondition: removes every node in clear_me

//template
template <typename T>
//returns the node that has been inserted at the head
node<T> *_insert_head(node<T> *&head_ptr, T item){
    //three step

    //first, create a new node
    node<T>* temp = new node<T>(item);

    //second, temp's next position to where head_ptr is pointing
    temp->_next = head_ptr;
    //temp->_next = temp._next

    //third, point head_ptr to where temp is pointing
    head_ptr = temp;

    return head_ptr; // or temp
}

//template
template <typename T>
//returns the node that has been inserted after after_me
node<T> *_insert_after(node<T> *&after_me, T item){
        //three steps
        //assert if after_me is NULL
        assert(after_me!= NULL);

        //first, create a new node
        node<T>* temp = new node<T>(item);

        //second, point temp's _next to after_me's _ next
        temp->_next = after_me ->_next;

        //third, point after_me's _next to temp;
        after_me->_next = temp;

        //return temp
        return temp;
}

//template
template <typename T>
node<T>* _insert_before(node<T>* &before_me, T item){
    //check if before_me exist
    assert(before_me!= NULL);

    //three steps
    //first, create a new node that is the same item as before_me
    node<T>* temp = new node<T>(before_me->_item);

    //second, point temp's _next to before_me's _next
    temp->_next = before_me->_next;

    //third, point before_me's next to temp
    before_me->_next = temp;

    //fourth, set before_me's item to T item
    before_me->_item = item;

    //return before_me
    return before_me;
}

//template
template <typename T>
//returns the node that has been inserted before before me
node<T> *_insert_sorted(node<T>* &head_ptr, T item){
    //Initilize node where
    node<T>* where;

    //where is where the item should be inserted
    where = _where_this_goes(head_ptr, item);

    //If empty list
    if(where == NULL && head_ptr == NULL)
    {
        //insert item at head
        return _insert_head(head_ptr, item);
    }

    //If second node
    if(where == NULL && head_ptr!=NULL){

        //insert item after head_ptr
        return _insert_after(head_ptr, item);
    }

    //If item is less than head_ptr
    if(where == head_ptr && item < head_ptr->_item){

        //insert item at head
        return _insert_head(head_ptr, item);
    }

    //If item is after head
    if(where == head_ptr && item >= head_ptr->_item){

        //insert itemm after head
        return _insert_after(head_ptr, item);
    }

    //If anywhere else of the list
    else{

    //Create a new node temp that has the item
    node<T>* temp = new node<T>(item);

    //Set temp's _next to where's _next
    temp->_next = where->_next;

    //Set where's _next to temp
    where->_next = temp;

    //return temp
    return temp;
    }
}


template <typename T>
//returns the node that is one before where the item belongs
node<T>* _where_this_goes(node<T>* &head_ptr, T target){
    //Initilizes node here
    node<T>* here;

    //Initilizes node next
    node<T>* next;

    //set here to head_ptr
    here = head_ptr;

    //set next to head_ptr
    next = head_ptr;

    //return null if empty
    if(head_ptr == NULL){

        return NULL;
    }

    //return null if second node is after first node
    if(head_ptr->_item <= target && head_ptr->_next ==NULL ){
        return NULL; //return NULL
    }

    //return head_ptr if target belongs after head_ptr
    if(head_ptr->_item > target){

        return head_ptr; // or head_ptr or here
    }

    //While next's _item is less than or equal to target value
    while(next->_item <= target){

        //Set next to next node
        next = next->_next;

        //If next's _item is greater than or equal to target value
        if(next->_item >= target){
            //return here
            return here;
        }

        //If at last node and its value is greater than target
        if(next->_next == NULL && next->_item > target ){
            //return NULL
            return NULL;
        }

        //if its the last node and its value is less than target
        if(next->_next == NULL && next->_item < target){
            //return next
            return next;
        }

        else{
            //here is next node
            here = here->_next;
        }
    }
}

//template
template <typename T>
//returns the node that has the value item, return NULL if not found
node<T> *_search_sorted(node<T> *&head_ptr, T item){

    //Initilizes node here
    node<T>* here;

    //here points to head_ptr
    here= head_ptr;

    // if node is empty
    if(here == NULL){
        //return NULL
        return NULL;
    }

    //if its head_ptr's _item
    if(here->_item == item){
        //return head_ptr
        return head_ptr;
    }

    //other_wise
    else{

    //While here's _item is not the value looking for and its not the last node
    while(here->_item != item && here->_next !=NULL)
        //set here to next node
        here = here ->_next;

        //If here's _item is the value looking for
        if(here->_item == item){
            //return here
            return here;
        }

        //If here's _item is the value looking for and its the last node
        if(here->_item == item && here->_next == NULL){
            //return here
            return here;
        }

        else{
            //return NULL if not found
            return NULL;
        }
    }
}

//template
template <typename T>
//returns the node that has the value item, return NULL if not found
node<T> *_search_nsorted(node<T> *&head_ptr, T item){
    //Initilizes node here
    node<T>* here;

    //here points to head_ptr
    here= head_ptr;

    // if node is empty
    if(here == NULL){
        //return NULL
        return NULL;
    }

    //if its head_ptr's _item
    if(here->_item == item){
        //return head_ptr
        return head_ptr;
    }

    //other_wise
    else{

    //While here's _item is not the value looking for and its not the last node
    while(here->_item != item && here->_next !=NULL)

        //set here to next node
        here = here ->_next;

        //If here's _item is the value looking for
        if(here->_item == item){
            //return here
            return here;
        }

        //If here's _item is the value looking for and its the last node
        if(here->_item == item && here->_next == NULL){
            //return here
            return here;
        }

        else{
            //return NULL if not found
            return NULL;
        }
    }
}

//template
template <typename T>
//returns the node that is previous to previous_to_this
node<T>* _previous(node<T>* head_ptr, node<T>* previous_to_this){
    //Initilize node pointer here
    node<T>* here;

    //set here to head_ptr
    here= head_ptr;

    //while here's _next is not the address of previous_to_this
    while(here->_next != previous_to_this){
        //set here to next node
        here = here->_next;
    }

    //return here when found
    return here;
}

//template
template <typename T>
//returns a new copy of the head_ptr
node<T> *_copy(node<T> *&head_ptr){

    //if empty node
    if(head_ptr == NULL){
        //created a new node thats also empty
        node<T>* new_head_ptr = NULL;

        //return new node
        return new_head_ptr;
    }

    //created new_head_ptr that is a new node that has the head_ptr's _item
    node<T>* new_head_ptr = new node<T>(head_ptr->_item);

    //Initilize node pointer here to point at head_ptr
    node<T>* here = head_ptr;

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
    return new_head_ptr;
}

//template
template <typename T>
//returns the node that has the value item, must work on head_ptr
node<T>* _remove(node<T>*& head_ptr, T item){
    //Initilize node pointer here
    node<T>* here;

    //here is set to where the item is located by calling _search_nsorted
    here = _search_nsorted(head_ptr,item);

    //If its at head_ptr
    if(here == head_ptr)
    {
        //Initilize node pointer temp to point at here, or head_ptr
        node<T>* temp = here;

        //point head_ptr to next node
        head_ptr = head_ptr->_next;

        //set temp's _next to NULL
        temp->_next = NULL;

        //return temp
        return temp;
    }

    else{
    //if cant find the item, error message
    assert(here!= NULL);

    //Initilize node pointer before
    node<T>* before;

    //before is pointing at the located before here
    before = _previous(head_ptr,here);

    //set before's _next to here's _next
    before->_next = here->_next;

    //set here's _next to NULL
    here->_next = NULL;

    //return here
    return here;
    }
}

//template
template <typename T>
//returns the item that is in delete_me and calls _remove to get the node then
//delete it
T _delete_(node<T>*& head_ptr, node<T>* delete_me){
    //exit program if delete_me is NULL
    assert(delete_me != NULL);

    //Initilizes pointer here
    node<T>* here;

    //set here to the node thats pulled out
    here = _remove(head_ptr, delete_me->_item);

    //set temp T to delete_me's _item
    T temp = delete_me->_item;

    //delete here
    delete here;

    //return temp
    return temp;
}

//template
template <typename T>
//removes every node in clear_me
void _clear_all(node<T> *&clear_me){
    //Initilizes node pointer destroy_me to NULL
    node<T>* destroy_me = NULL;

    //If clear_me is empty
    if(clear_me == NULL){

//        cout<<"List is empty" <<endl;
    }
    //if its not empty, run while its not empty
    while(clear_me != NULL){
        //set destroy_me to clear_me's _next
        destroy_me = clear_me->_next;

        //delete the head_ptr of clear_me
        _delete_(clear_me,clear_me);

        //set clear_me to destroy_me
        clear_me = destroy_me;
    }
}

//template
template <typename T>
//print thee nodes
ostream& _print(ostream& outs, const node<T>* head_ptr){
    //no change to walker that is pointing to head_ptr
    const node<T>* walker = head_ptr;

    outs <<"Head pointer ->";

    //while there is still nodes
    while (walker){
        //outs its item
        outs << "[" << walker->_item << "] ->";

        //set walker to next node
        walker = walker->_next;
    }
    cout << "||";

    //return outs
    return outs;
}



#endif // LINKLIST_FUNCTION_H

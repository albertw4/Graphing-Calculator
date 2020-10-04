#ifndef LINKLIST_FUNCTION_H
#define LINKLIST_FUNCTION_H
#include "node.h"
#include <iostream>

using namespace std;

template <typename T>
node<T> * _insert_head(node<T>* &head_ptr, T item);

template <typename T>
node<T> * _insert_after(node<T>* &head_ptr, node<T>* &after_me, T item);

template <typename T>
node<T>* _insert_sorted(node<T>* head_ptr, T item);

template <typename T>
node<T>* _search_sorted(node<T>* &head_ptr, int target);

template <typename T>
node<T>* _search_nsorted(node<T>* &head_ptr, int target);

template <typename T>
node<T>* _copy(node<T>* &head_ptr);

template <typename T>
node<T>* _previous(node<T>* head_ptr, node<T>* previous_to_this);

template <typename T>
node<T>* _where_this_goes(node<T>* &head_ptr, T item);

template <typename T>
T _delete(node<T>*& head_ptr, T item);

template <typename T>
node<T>* remove(node<T>* head_ptr, T item);

template <typename T>
ostream& _print(ostream& outs, const node<T>* head_ptr);

template <typename T>
void _clear_all(node<T>* clear_me);


//Big Three
template <typename T>
ostream& operator << (ostream& outs, const node<T>*& head_ptr);


template <typename T>
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


template <typename T>
node<T> *_insert_after(node<T> *&head_ptr, node<T> *&after_me, T item){
    node<T>* where;

    where = _where_this_goes(head_ptr, item);

    node<T>* temp = new node<T>(item);

    temp->_next = where->_next;

    where->_next = temp;

    //three steps
    //first, create a new node
//    node* temp = new node(item);

    //second, point temp's _next to after_me's _ next
//    temp->_next = after_me ->_next;

    //third, point after_me's _next to temp;
//    after_me->_next = temp;

//    return temp;
}


template <typename T>
node<T> *_insert_sorted(node<T> *head_ptr, T item){
    node<T>* where = _where_this_goes(head_ptr, item);

    node<T>* temp = new node<T>(item);

    temp->_next = where->_next;

    where->_next = temp;
}


template <typename T>
node<T>* _where_this_goes(node<T>* &head_ptr, int target){
    node<T>* here;

    node<T>* next;

    here = head_ptr;

    next = head_ptr;

    if(next->_item > target){
        return head_ptr; // or head_ptr or here
    }

    while(next->_item <= target){

        next = next->_next;


        if(next->_item >= target){
            return here;
        }

        if(next->_next == NULL && next->_item > target ){
            return NULL;
        }

        //if its the last node
        if(next->_next == NULL && next->_item < target){
            return next;
        }

        else{
            here = here->_next;
        }
    }
}


template <typename T>
node<T> *_search_sorted(node<T> *&head_ptr, int target){
   // if node is empty
    node<T>* here;

    here= head_ptr;

    if(here == NULL){
        return NULL;
    }

    while(here->_item != target && here->_next !=NULL){

        here = here ->_next;

        if(here->_item == target){
            return here;
        }

        else{
            return NULL;
        }
    }

    if(here->_item == target && here->_next == NULL){
        return here;
    }
}


template <typename T>
node<T> *_search_nsorted(node<T> *&head_ptr, int target){
    // if node is empty
    node<T>* here;

    here= head_ptr;

    if(here == NULL){
        return NULL;
    }


    while(here->_item != target && here->_next !=NULL){

        here = here ->_next;

        if(here->_item == target){
            return here;

            cout<< here->_item << endl;
        }

        else{
            return NULL;
        }
    }

    if(here->_item == target && here->_next == NULL){
        return here;
    }
}


template <typename T>
node<T>* _previous(node<T>* head_ptr, node<T>* previous_to_this){
    node<T>* here;

    here= head_ptr;

    while(here->_next != previous_to_this){
        here = here->_next;
    }

    return here;
}


template <typename T>
node<T> *_copy(node<T> *&head_ptr){
    node<T>* new_head_ptr = new node<T>(head_ptr->_item);

    node<T>* here = head_ptr;

    node<T>* there = new_head_ptr;

    while(here->_next != NULL){
        here = here->_next;

        there->_next = new node<T>(here->_item);

        there = there->_next;
    }

    there->_next = NULL;

    return new_head_ptr;
}


template <typename T>
node<T>* remove(node<T>* head_ptr, T item){
    node<T>* here;

    here = _search_nsorted(head_ptr,item);

    assert(here!= NULL);






}


template <typename T>
ostream& _print(ostream& outs, const node<T>* head_ptr){
    //no change to walker that is pointing to head_ptr
    const node<T>* walker = head_ptr;

    outs <<"Head pointer ->";

    while (walker){
        outs << "[" << walker->_item << "] ->";

        walker = walker->_next;
    }

    cout << "||";
}


template <typename T>
ostream& operator << (ostream& outs, const node<T> *&head_ptr)
{
    const node<T>* walker = head_ptr;

    outs <<"Head pointer ->";

    while (walker){
        outs << "[" << walker->_item << "] ->";

        walker = walker->_next;
    }

    outs << "||";

    return outs;
}


#endif // LINKLIST_FUNCTION_H

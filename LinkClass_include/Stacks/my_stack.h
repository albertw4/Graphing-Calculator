//program to use Stack class

#ifndef STACK_H
#define STACK_H
#include <iostream>
//includes list class
#include "../../LinkClass_include/lists/list_templated.h"
//includes link_list functions
#include "../../LinkClass_include/LinkList_functions/linklist_template_function.h"
//includes struct nodes
#include "../../LinkClass_include/nodes/node_template.h"

//template for type T
template <typename T>

//class for Stack
class Stack
{
public:

    //construc
    Stack();
    //Initilize a List with a NULL

    //functions
    //add from front
    void push(T item);
    //Precondition: item has been given value
    //Postcondition: inserts item from head

    //delete from front
    T pop();
    //Postcondition: delete top number aka head_ptr and return the item

    bool empty();
    //Postcondition: check if stack_list is empty returns true if it is, false if not

    T top();
    //Postcondition: return the top number aka head_ptr

    void print();
    //Postcondition: prints the Stack_list

    template <typename TT>
    friend ostream& operator <<(ostream& outs, Stack<TT>& print_me);


private:

    //Stack_list is of class List
    List<T> Stack_list;
};

template <typename T>
//const
 Stack<T>::Stack(){
     //left blank
 }

template <typename T>
//inserts item from head
void Stack<T>::push(T item){
    //insert_head with item from Stack_list
    Stack_list.insert_head(item);
}

template <typename T>
//delete top number aka head_ptr and return the item
T Stack<T>::pop(){
    //return _delete with Stack_list's headptr
    return Stack_list._delete(Stack_list.begin());
}

template <typename T>
//return the top number aka head_ptr
T Stack<T>::top(){
    //return Stack_list's head_ptr's item
    return Stack_list.begin()->_item;
}

template <typename T>
//clear Stack_list
bool Stack<T>::empty(){
    //if list is empty
    if(Stack_list.begin() == nullptr){

        //Ouput that its empty
//        cout<<"Stack_list is empty"<<endl;

        return true;
    }

    //if its not empty
    else{

        //Output that its not empty
//        cout<<"Stack_list is not empty"<<endl;

        return false;
    }
}

template <typename T>
//prints the Stack_list
void Stack<T>::print(){
//        cout << "printing stack" << endl;

        //Calls << operator and prints
        cout << Stack_list << endl;
}

template <typename TT>
ostream& operator <<(ostream& outs, Stack<TT>& print_me){

    print_me.print();

    return outs;
}

#endif // STACK_H

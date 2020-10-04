#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

template <typename T>

struct node
{
public:
    node();

    node(T item);

    T _item;

    node* _next;


};

template <typename T>
node<T>::node():_item(T()), _next(NULL)
{
    //empty
}

template <typename T>
node<T>::node(T item):_item(item),_next(NULL){

    //empty
}

#endif // NODE_H

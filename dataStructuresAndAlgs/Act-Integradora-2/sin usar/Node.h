#ifndef NODE_H
#define NODE_H

#include<iostream>

template <class T>
class Node { 
public: 
    T data; 
    Node<T>* next;
    Node<T>* prev;
    Node();
    Node(T);
}; 

template<class T>
Node<T>::Node(){
    data = 0;
    next = NULL;
}
template<class T>
Node<T>::Node(T val){
    data = val;
}

#endif // NODE_H
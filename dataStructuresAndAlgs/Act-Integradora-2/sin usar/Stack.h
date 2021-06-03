#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <class T>
  class Stack {
      private:
        Node<T>* top;
        Node<T>* back;
        int numElements;

      public:
        Stack();
        Stack(T);
        ~Stack();
        void push(T);
        T pop();
        void clean();
        int getNumElements();
      
  };

template<class T>
Stack<T>::Stack() {
    top = NULL;
    back = NULL;
    numElements = 0;
}

template<class T>
Stack<T>::Stack(T _val) {
    top = new Node<T>;
    top->data=_val;
    back = top;
    numElements = 1;
}

template<class T>
Stack<T>::~Stack(){
    clean();
    top = 0;
    back=0; 
}

template<class T>
void Stack<T>::clean(){
    Node<T>* current = top;
    while( current != 0 ) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    top = NULL;
    back=NULL;
    numElements=0;
}

template<class T>
void Stack<T>::push(T _val) {
    Node<T>* newnode = new Node<T>;
    newnode->data=_val;
    //newnode->next=NULL;
    if (top==NULL){
        top=newnode;
        back=newnode;
    }
    else{
        newnode->next=top;
        top->prev=newnode;
        top=newnode;
    }
    numElements+=1;
}

template<class T>
T Stack<T>::pop(){
    if(numElements==0){
        std::cout<<"Empty List"<<std::endl;
        return top->data;
    }
    else{
        Node<T> * popped=top;
        top=top->next;
        T dato=popped->data;
        delete popped;
        return dato;
    }
}


template<class T>
int Stack<T>::getNumElements() {
return numElements;
}

#endif
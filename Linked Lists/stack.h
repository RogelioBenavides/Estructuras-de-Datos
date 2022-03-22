// Clase Stack

#ifndef Stack_h
#define Stack_h
#include <iostream>
using namespace std;
#include "node.h"

template <class T>
class Stack {
    private:
        Node<T> *first; 
        Node<T> *last;
        int size;
    public:
        Stack();
        ~Stack();
        void push(T data);
        T pop();
        T top() {return last -> data;};
        int getSize() {return size;};
        void print();
        void clear();
        bool isEmpty();
};

// M‚todo constructor
template <class T>
Stack<T>::Stack(){
    first = nullptr;
    last = nullptr;
    size = 0;
}

// M‚todo destructor
template <class T>
Stack<T>::~Stack(){
    clear();
}

// M‚todo que checa si el stack est  vac¡o
template <class T>
bool Stack<T>::isEmpty(){
    return size == 0;
}

// M‚todo que limpia el stack
template <class T>
void Stack<T>::clear(){
    if(!isEmpty()){
        Node<T> *aux = first;
        for (int i = 0; i < size; i++)
        {
            first = aux -> next;
            delete aux;
            aux = first;
        }
        size = 0;
    }
}

// M‚todo que imprime el stack
template <class T>
void Stack<T>::print(){
    Node<T> *aux = first;
    for (int i = 0; i < size; i++)
    {
        if(i != size-1)
            cout << aux -> data << ", ";
        else
            cout << aux -> data;
        aux = aux -> next;
    }
    cout << endl;
}

// M‚todo que borra el £ltimo dato puesto y lo retorna
template <class T>
T Stack<T>::pop(){
    T dato = last -> data;
    Node<T> *auxF = first;
    while(auxF -> next != last){
        auxF = auxF -> next;
    }
    last = auxF;
    auxF = auxF -> next;
    delete auxF;
    size--;
    return dato;
}

// M‚todo que a¤ade un elemento al final del stack
template <class T>
void Stack<T>::push(T data){
    if(isEmpty()){
        first = new Node<T>(data);
        last = first;
    } else{
        Node<T> *aux = first;
        while(aux -> next != nullptr){
            aux = aux-> next;
        }
        aux -> next = new Node<T>(data);
        last = aux -> next; 
    }
    size++;
}

#endif
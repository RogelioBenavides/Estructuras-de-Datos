// Clase Queue

#ifndef Queue_h
#define Queue_h
#include <iostream>
using namespace std;
#include "node.h"

template <class T>
class Queue {
    private:
        Node<T> *first;
        Node<T> *last;
        int size;
    public:
        Queue();
        ~Queue();
        T front();
        T dequeue();
        T back() {return last -> data;};
        void enqueue(T data);
        int getSize() {return size;};
        void print();
        void clear();
        bool isEmpty();
};

// M‚todo constructor
template <class T>
Queue<T>::Queue(){
    first = nullptr;
    last = nullptr;
    size = 0;
}

// M‚todo destructor
template <class T>
Queue<T>::~Queue(){
    clear();
}

// M‚todo que checa si el queue est  vac¡o
template <class T>
bool Queue<T>::isEmpty(){
    return size == 0;
}

// M‚todo que limpia el queue
template <class T>
void Queue<T>::clear(){
    if(!isEmpty()){
        Node<T> *aux = first;
        while(aux != nullptr){
            first = aux -> next;
            delete aux;
            aux = first;
        }
        size = 0;
    }
}

// M‚todo que a¤ade un elemento al final del queue
template <class T>
void Queue<T>::enqueue(T data){
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

// M‚todo que imprime la queue
template <class T>
void Queue<T>::print(){
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

// M‚todo que encuentra un dato en el queue dada su posici¢n
template<class T>
T Queue<T>::front(){
    return first -> data;
}

// M‚todo que borra el primer dato del queue y retorna el valor
template <class T>
T Queue<T>::dequeue(){
    Node<T> *aux = first;
    T inicial = first -> data;
    first = aux -> next;
    delete aux;
    size--;
    return inicial;
}

#endif
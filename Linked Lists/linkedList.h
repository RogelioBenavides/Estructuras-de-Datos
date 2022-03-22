// Clase Linked List

#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
using namespace std;
#include "node.h"

template <class T>
class LinkedList {
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void addLast(T data);
        void addFirst(T data);
        T findAt(int pos);
        bool deleteData(T data);
        bool deleteAt(int pos);
        int getSize() {return size;};
        void print();
        void clear();
        bool isEmpty();
        int findData(T data);
        void updateAt(int pos, T data);
        void updateData(T data, T dataNew);
};

// M‚todo constructor
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

// M‚todo destructor
template <class T>
LinkedList<T>::~LinkedList(){
    clear();
}

// M‚todo que checa si la lista est  vac¡a
template <class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

// M‚todo que limpia la lista
template <class T>
void LinkedList<T>::clear(){
    if(!isEmpty()){
        Node<T> *aux = head;
        while(aux != nullptr){
            head = aux -> next;
            delete aux;
            aux = head;
        }
        size = 0;
    }
}

// M‚todo que a¤ade un elemento al inicio de la lista
template <class T>
void LinkedList<T>::addFirst(T data){
    if(isEmpty()){
        head = new Node<T>(data);
    } else{
        Node<T> *aux = new Node<T>(data);
        aux -> next = head;
        head = aux;
    }
    size++;
}

// M‚todo que a¤ade un elemento al final de la lista
template <class T>
void LinkedList<T>:: addLast(T data){
    if(isEmpty()){
        head = new Node<T>(data);
    } else{
        Node<T> *aux = head;
        while(aux -> next != nullptr){
            aux = aux-> next;
        }
        aux -> next = new Node<T>(data);
    }
    size++;
}

// M‚todo que imprime la lista
template <class T>
void LinkedList<T>::print(){
    Node<T> *aux = head;
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

// M‚todo que encuentra un dato en la lista y devuelve la posici¢n
template <class T>
int LinkedList<T>::findData(T data){
    if(!isEmpty()){
        Node<T> *aux = head;
        int pos = 0;
        while(aux -> data != data && aux != nullptr){
            aux = aux -> next;
            pos++;
            if (aux -> data == data)
            {
                return pos;
            }   
        }
    }
    return -1;
}

// M‚todo que encuentra un dato en la lista dada su posici¢n
template<class T>
T LinkedList<T>::findAt(int pos){
    Node<T>* aux = head;
    if(pos<size){
        for(int i=0; i<pos;i++){
            aux = aux->next;
        }
        return aux->data;
    }
    return aux -> data;
}

// M‚todo que borra un dato de la lista dado el valor
template <class T>
bool LinkedList<T>::deleteData(T data){
    if(!isEmpty()){
        Node<T> *aux = head;
        Node<T> *auxPrev = head;
        while(aux -> data != data && aux != nullptr){
            auxPrev = aux;
            aux = aux -> next;
        }
        if(aux != nullptr){
            if(aux == head){
                head = aux -> next;
            }
            auxPrev -> next = aux -> next;
            delete aux;
            size--;
            return true;
        } else
            return false;
    }
    return false;
}


// M‚todo que borra un dato de la lista dada la posici¢n
template <class T>
bool LinkedList<T>::deleteAt(int pos){
    if(size > pos){
        Node<T> *aux = head;
        Node<T> *auxPrev = head;
        if(pos == 0){
            head = head -> next;
            delete aux;
            // auxPrev = aux;
            // aux = aux -> next;
            // head = aux;
            // delete auxPrev;
        } else{
            for (int i = 0; i < pos; i++)
            {
                auxPrev = aux;
                aux = aux -> next;
            }
            auxPrev -> next = aux -> next;
            delete aux;
        }
        size--;
        return true;
    }
    return false;
}

// M‚todo que actualiza un dato dada la posici¢n
template <class T>
void LinkedList<T>::updateAt(int pos, T data){
    if(size > pos){
        Node<T> *aux = head;
        for (int i = 0; i < pos; i++)
        {
            aux = aux -> next;
        }
        aux -> data = data;
    } else{
        cout << "La posici¢n ingresada no es v lida" << endl;
    }
}

// M‚todo que actualiza un dato dado el valor
template <class T>
void LinkedList<T>::updateData(T data, T dataNew){
    if(!isEmpty()){
        Node<T> *aux = head;
        while(aux -> data != data && aux != nullptr){
            aux = aux -> next;
        }
        if(aux != nullptr){
            if(aux -> data == data)
                aux -> data = dataNew;
        } else{
            cout << "El dato ingresado no se encuentra en la lista" << endl;
        }
    }
}
#endif
// Clase Nodo

template<class T> class LinkedList;
template<class T> class Queue;
template<class T> class Stack;
template<class T>
class Node {
    friend class LinkedList<T>; // clase amiga
    friend class Queue<T>; // clase amiga
    friend class Stack<T>; // clase amiga
    public:
        Node(T e) {data=e; next = nullptr;}; // constructor
    private:
        T data; // datos almacenados en este nodo
        Node<T>* next; // ptr a otro objeto del mismo tipo
};
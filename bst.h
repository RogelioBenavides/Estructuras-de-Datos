#ifndef BST_h
#define BST_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "nodeT.h"

template <class T>
class BST
{
private:
    NodeT<T> *root;
    NodeT<T>* predecesor(NodeT<T>* aux);
    int numChildren(NodeT<T>* nodo);
    void printTree(NodeT<T>* aux, int level);
    void preorder(NodeT<T>* nodo);
    void inorder(NodeT<T>* nodo);
    void postorder(NodeT<T>* nodo);
    int height(NodeT<T>* nodo);

public:
    BST() {root = nullptr;}; // constructor
    bool search(T valor);
    bool insert(T valor);
    void print();
    void borrar(T dato);
    void visit();
    void findHeight();
    void ancestors(T valor);
    void whatlevelamI(T valor);
    void levelByLevel(NodeT<T>* root);
    void actualLevel(NodeT<T>* root, int level);
};

template <class T>
bool BST<T>::search(T valor)
{
    NodeT<T> *aux = root;
    while (aux != nullptr)
    {
        if (aux->data == valor)
            return true;
        else if (aux->data > valor)
            aux = aux->left;
        else
            aux = aux->right;
    }
    return false;
}

template <class T>
bool BST<T>::insert(T valor)
{
    if (root == nullptr)
    {
        root = new NodeT<T>(valor);
        cout << "El valor de la ra¡z es: " << root->data << endl;
        return true;
    }
    NodeT<T> *aux = root;
    NodeT<T> *prev = nullptr;
    while (true)
    {
        if (aux == nullptr)
        {
            if(valor > prev -> data){
                prev -> right = new NodeT<T>(valor);
                cout << "Se ingres¢ el valor " << prev -> right -> data << " al  rbol" << " del lado derecho" << endl;
            } else{
                prev -> left = new NodeT<T>(valor);
                cout << "Se ingres¢ el valor " << prev -> left -> data << " al  rbol" << " del lado izquierdo" << endl;
            }
            return true;
        }
        else if (aux->data == valor)
        {
            cout << "El valor que se intent¢ ingresar ya se encuentra en el  rbol" << endl;
            return false;
        }
        else if (aux->data > valor)
        {
            prev = aux;
            aux = aux->left;
        }
        else
        {
            prev = aux;
            aux = aux->right;
        }
    }
}

template <class T>
int BST<T>::numChildren(NodeT<T>* nodo){
    int contador = 2;
    if(nodo -> left == nullptr){
        contador--;
    }
    if(nodo -> right == nullptr){
        contador--;
    }
    return contador;
}

template<class T>
NodeT<T>* BST<T>::predecesor(NodeT<T>* aux){
    aux = aux->left;
    while (aux->right!= nullptr){
        aux= aux->right;
    }
    return aux;
}

template <class T>
void BST<T>::borrar(T dato){
    NodeT<T>* aux = root;
    NodeT<T>* father = aux;
    while(aux -> data != dato){
        father = aux;
        if(dato < aux -> data){
            aux = aux -> left;
        } else{
            aux = aux -> right;
        }
    }
    if(aux == root){
        switch(numChildren(aux)){
            case 0:
                delete aux;
                root = nullptr;
                break;
            case 1:
                if(aux->left != nullptr){
                    root = aux->left;
                } else{
                    root = aux->right;
                }
                delete aux;
                break;
            case 2:
                NodeT<T>* pred = aux->left;
                int level = 0;
                while(pred -> right != nullptr){
                    father = pred;
                    pred = pred->right;
                    level++;
                }
                aux->data = pred->data;
                if(level == 0){
                    father -> left = pred -> left;
                } else{
                    father-> right = pred-> left;
                }
                delete pred;
                break;   
        }
    } else{
        if(aux -> data == dato){
            switch (numChildren(aux))
            {
            case 0:
                if(father -> left == aux){
                    father-> left = nullptr;
                } else{
                    father -> right = nullptr;
                }
                delete aux;
                break;
            case 1:
                if(aux -> left != nullptr){
                    if(father -> left == aux){
                        father -> left = aux->left;
                    } else{
                        father -> right = aux->left;
                    }
                } else{
                    if(father -> left == aux){
                        father -> left = aux -> right;
                    } else{
                        father -> right = aux -> right;
                    }
                }
                delete aux;
                break;
            case 2:
                NodeT<T>* pred = predecesor(aux);
                T datoTemp = pred -> data;
                borrar(pred -> data);
                aux -> data = datoTemp;
                break;
            }
        }
    }
}

template<class T>
void BST<T>::printTree(NodeT<T>* aux, int level){
    if (aux != nullptr){
        printTree(aux->right, level+1);
        for (int i = 0; i < level; i++)
        {
            cout << "   ";
        }
        cout << aux->data << endl;
        printTree(aux->left, level + 1);
    }
}

template <class T>
void BST<T>::print(){
    if (root != nullptr){
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else{
        cout << "El  rbol est  vacio" << endl;
    }
}

template <class T>
void BST<T>::visit(){
    int opcion;
    do{
        cout << "Men£ de impresi¢n del  rbol" << endl;
        cout << "1) Imprimir  rbol preorden" << endl;
        cout << "2) Imprimir  rbol inorden" << endl;
        cout << "3) Imprimir  rbol postorden" << endl;
        cout << "4) Imprimir  rbol nivel por nivel" << endl;
        cout << "5) Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "El orden del recorrido en preorden es: ";
            preorder(root);
            cout << endl << endl;
            break;
        case 2:
            cout << "El orden del recorrido en inorden es: ";
            inorder(root);
            cout << endl << endl;
            break;
        case 3:
            cout << "El orden del recorrido en postorden es: ";
            postorder(root);
            cout << endl << endl;
            break;
        case 4:
            cout << "El orden del recorrido en nivel por nivel es: ";
            levelByLevel(root);
            cout << endl << endl;
            break;
        case 5:
            break;
        default:
            cout << "Por favor ingresar un opci¢n v lida" << endl << endl;
            break;
        }
    }while(opcion != 5);
}

template <class T>
void BST<T>::preorder(NodeT<T>* nodo){
    if(nodo == NULL)
        return;
    cout << nodo -> data << ", ";
    preorder(nodo -> left);
    preorder(nodo -> right);
}

template <class T>
void BST<T>::inorder(NodeT<T>* nodo){
    if(nodo == NULL)
        return;
    inorder(nodo -> left);
    cout << nodo -> data << ", ";
    inorder(nodo -> right);
}

template <class T>
void BST<T>::postorder(NodeT<T>* nodo){
    if(nodo == NULL)
        return;
    postorder(nodo -> left);
    postorder(nodo -> right);
    cout << nodo -> data << ", ";
}

template <class T>
void BST<T>::findHeight(){
    cout << "La altura del  rbol es: "<< height(root) << endl << endl;
}

template <class T>
int BST<T>::height(NodeT<T>* nodo){
    if(nodo == NULL)
        return 0;
    else{
        int alturaIzq = height(nodo -> left);
        int alturaDer = height(nodo -> right);
        if(alturaIzq > alturaDer)
            return (alturaIzq + 1);
        else
            return(alturaDer + 1);
    }
}

template <class T>
void BST<T>::levelByLevel(NodeT<T>* nodo){
    int altura = height(nodo);
    for (int i = 1; i <= altura; i++)
        actualLevel(nodo, i);
}

template <class T>
void BST<T>::actualLevel(NodeT<T>* root, int level){
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << ", ";
    else if (level > 1) {
        actualLevel(root->left, level - 1);
        actualLevel(root->right, level - 1);
    }
}

template <class T>
void BST<T>::ancestors(T valor){
    NodeT<T> *aux = root;
    vector<T> ancestor;
    while (aux != nullptr)
    {
        if (aux->data == valor){
            cout << "Los ancestros del elemento " << valor <<  " son: ";
            for (int i = 0; i < ancestor.size(); i++)
            {
                if(i != ancestor.size()-1)
                    cout << ancestor[i] << ", ";
                else
                    cout << ancestor[i] << endl << endl;
            }
            
            return;
        }
        else if (aux->data > valor){
            ancestor.push_back(aux -> data);
            aux = aux->left;
        }
        else{
            ancestor.push_back(aux -> data);
            aux = aux->right;
        }
    }
    cout << "El valor no se pudo encontrar en el  rbol";
    return;
}

template <class T>
void BST<T>::whatlevelamI(T valor){
    NodeT<T> *aux = root;
    int contador = 1;
    while (aux != nullptr)
    {
        if (aux->data == valor){
            cout << "El dato ingresado se encuentra en el nivel " << contador;
            return;
        }
        else if (aux->data > valor){
            aux = aux->left;
            contador++;
        }
        else{
            aux = aux->right;
            contador++;
        }
    }
    cout << "El dato ingresado no existe en el  rbol";
}

#endif
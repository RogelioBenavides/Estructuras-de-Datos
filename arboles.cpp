/*
Rogelio Eduardo Benavides De La Rosa
Fecha de £ltima modificaci¢n: 11/03/2022
Programa para el manejo de  rboles binarios.
Doy mi palabra de que he realizado esta actividad con integridad acad‚mica
*/

#include "bst.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    BST<int> arbol;
    bool R = arbol.insert(10);
    R = arbol.insert(5);
    R = arbol.insert(20);
    R = arbol.insert(5);
    R = arbol.insert(3);
    R = arbol.insert(6);
    R = arbol.insert(43);
    R = arbol.insert(12);
    R = arbol.insert(32);
    R = arbol.insert(21);
    R = arbol.insert(1);
    R = arbol.insert(7);
    R = arbol.insert(35);
    arbol.print();
    int nodoBorrar;
    nodoBorrar = 5;
    arbol.borrar(nodoBorrar);
    cout << "Se ha borrado el nodo " << nodoBorrar << " del  rbol" << endl;
    arbol.print();
    nodoBorrar = 21;
    arbol.borrar(nodoBorrar);
    cout << "Se ha borrado el nodo " << nodoBorrar << " del  rbol" << endl;
    arbol.print();
    nodoBorrar = 10;
    arbol.borrar(nodoBorrar);
    cout << "Se ha borrado el nodo " << nodoBorrar << " del  rbol" << endl;
    arbol.print();
    nodoBorrar = 43;
    arbol.borrar(nodoBorrar);
    cout << "Se ha borrado el nodo " << nodoBorrar << " del  rbol" << endl;
    arbol.print();
    arbol.visit();
    arbol.findHeight();
    arbol.ancestors(35);
    arbol.whatlevelamI(12);
}

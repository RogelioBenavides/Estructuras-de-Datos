/*
Rogelio Eduardo Benavides De La Rosa
Fecha de £ltima modificaci¢n: 01/03/2022
Programa de b£squeda y ordenamiento de Enteros, Doubles, Caracteres y Strings
Doy mi palabra de que he realizado esta actividad con integridad acad‚mica
*/

#include "stack.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    Stack<int> pila;
    cout << "Se a¤aden los elementos a la pila";
    for (int i = 2; i < 5000; i*=2)
    {
        pila.push(i);
    }
    cout << endl << "La pila resultante: ";
    pila.print();
    cout << "Se eliminan elementos de la pila: ";
    for (int i = 0; i < 5; i++)
    {
        if(i != 4)
            cout << pila.pop() << ", ";
        else
            cout << pila.pop() << " ";
    }
    cout << endl<< "La pila resultante: ";
    pila.print();
    cout << "El £ltimo elemento de la pila es: ";
    cout << pila.top() << endl;
    cout << "El tama¤o de la pila es: " << pila.getSize() << endl;
    pila.clear();
    cout << "Se elimin¢ la pila" << endl;
    cout << "La pila resultante: " << endl;
    pila.print();
    return 0;
}
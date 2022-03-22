/*
Rogelio Eduardo Benavides De La Rosa
Fecha de £ltima modificaci¢n: 01/03/2022
Programa de b£squeda y ordenamiento de Enteros, Doubles, Caracteres y Strings
Doy mi palabra de que he realizado esta actividad con integridad acad‚mica
*/

#include "queue.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    Queue<int> fila;
    cout << "Se a¤aden los elementos a la fila";
    for (int i = 2; i < 5000; i*=2)
    {
        fila.enqueue(i);
    }
    cout << endl << "La fila resultante: ";
    fila.print();
    cout << "Se eliminan elementos de la fila: ";
    for (int i = 0; i < 5; i++)
    {
        if(i != 4)
            cout << fila.dequeue() << ", ";
        else
            cout << fila.dequeue() << " ";
    }
    cout << endl<< "La fila resultante: ";
    fila.print();
    cout << "El primer elemento de la fila es: ";
    cout << fila.front() << endl;
    cout << "El £ltimo elemento de la fila es: ";
    cout << fila.back() << endl;
    cout << "La fila resultante: ";
    fila.print();
    cout << "El tama¤o de la fila es: " << fila.getSize() << endl;
    fila.clear();
    cout << "Se elimin¢ la fila" << endl;
    cout << "La fila resultante: " << endl;
    fila.print();
    return 0;
}

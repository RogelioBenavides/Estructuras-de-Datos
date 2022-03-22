/*
Rogelio Eduardo Benavides De La Rosa
Fecha de £ltima modificaci¢n: 01/03/2022
Programa de b£squeda y ordenamiento de Enteros, Doubles, Caracteres y Strings
Doy mi palabra de que he realizado esta actividad con integridad acad‚mica
*/

#include "linkedList.h"
#include <iostream>
#include <string>

using namespace std;

// M‚todo del men£ de las listas
template<class T>
void menuLista(LinkedList<T> lista){
    T dato,  datoD, datoNuevo;
    int opcion, posicion, posicionD;
    bool borrado;
    do{
        cout << "Men£ de listas" << endl;
        cout << "1)  A¤adir un elemento al inicio de la lista" << endl;
        cout << "2)  A¤adir un elemento al final de la lista" << endl;
        cout << "3)  Eliminar un elemento de la lista por valor" << endl;
        cout << "4)  Eliminar un elemento de la lista por posici¢n" << endl;
        cout << "5)  Buscar un elemento de la lista por valor" << endl;
        cout << "6)  Buscar un elemento de la lista por posici¢n" << endl;
        cout << "7)  Cambiar un elemento de la lista por valor" << endl;
        cout << "8)  Cambiar un elemento de la lista por posici¢n" << endl;
        cout << "9)  Imprimir la lista" << endl;
        cout << "10) Borrar la lista" << endl;
        cout << "11) Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        // Ingresar datos al inicio
        case 1:
            cout << "Ingresa el dato que deseas a¤adir: ";
            cin >> dato;
            lista.addFirst(dato);
            cout << "La lista resultante es: ";
            lista.print();
            break;
        // Ingresar datos al final
        case 2:
            cout << "Ingresa el dato que deseas a¤adir: ";
            cin >> dato;
            lista.addLast(dato);
            cout << "La lista resultante es: ";
            lista.print();
            break;
        // Borrar alg£n dato por valor
        case 3:
            cout << "Ingresa el dato que deseas borrar: ";
            cin >> dato;
            borrado = lista.deleteData(dato);
            if(borrado)
                cout << "Se ha borrado el dato con ‚xito";
            else
                cout << "No se ha encontrado el dato en la lista";
            cout << endl;
            cout << "La lista resultante es: ";
            lista.print();
            break;
        // Borrar alg£n dato por posici¢n
        case 4:
            cout << "Ingresa la posici¢n del dato que deseas borrar: ";
            cin >> posicion;
            borrado = lista.deleteAt(posicion-1);
            if(borrado)
                cout << "Se ha borrado el dato con ‚xito";
            else
                cout << "No se ha encontrado el dato en la lista";
            cout << endl;
            cout << "La lista resultante es: ";
            lista.print();
            break;
        // Buscar alg£n dato por valor
        case 5:
            cout << "Ingresa el dato que deseas buscar: ";
            cin >> dato;
            posicionD = lista.findData(dato);
            cout << "El dato se encuentra en la posici¢n: " << posicionD + 1;
            cout << endl;
            cout << "La lista resultante es: ";
            lista.print();
            break;
        // Buscar alg£n dato por posici¢n
        case 6:
            cout << "Ingresa la posici¢n del dato que deseas buscar: ";
            cin >> posicion;
            datoD = lista.findAt(posicion-1);
            cout << "El dato en la posici¢n " << posicion << " es: " << datoD;
            cout << endl;
            cout << "La lista resultante es: ";
            lista.print();
            break;
        // Actualizar alg£n dato por valor
        case 7:
            cout << "Ingresa el dato a cambiar: ";
            cin >> dato;
            cout << "Ingresa el nuevo valor del dato: ";
            cin >> datoNuevo;
            lista.updateData(dato, datoNuevo);
            cout << "La lista resultante es: ";
            lista.print();
            break;
        case 8:
        // Actualizar alg£n dato por posici¢n
            cout << "Ingresa la posici¢n del dato a cambiar: ";
            cin >> posicion;
            cout << "Ingresa el nuevo valor del dato: ";
            cin >> datoNuevo;
            lista.updateAt(posicion-1, datoNuevo);
            cout << "La lista resultante es: ";
            lista.print();
            break;
        // Imprimir la lista
        case 9:
            cout << "La lista es: " << endl;
            lista.print();
            break;
        // Borrar los elementos de la lista
        case 10:
            lista.clear();
            cout << "Se han borrado todos los elementos de la lista";
            break;
        case 11:
            break;
        // Si eligen un valor no v lido
        default:
            cout << "Por favor ingresar 1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, o 11";
            break;
        }
        cout << endl << endl;
    } while(opcion != 11);
}

// M‚todo de men£ para escoger el tipo de dato
void menuTipoListas(){
    int opcion;
    LinkedList<int> listaInt;
    LinkedList<string> listaStr;
    do{
        cout << "Men£ de tipos de datos" << endl;
        cout << "1) Crear lista de enteros" << endl;
        cout << "2) Crear lista de strings" << endl;
        cout << "3) Salir" << endl;
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:
            menuLista(listaInt);
            break;
        case 2:
            menuLista(listaStr);
            break;
        case 3:
            break;
        default:
            cout << "Por favor ingresar 1, 2 o 3" << endl;
            break;
        }
    } while(opcion != 3);
}

// M‚todo main
int main()
{
    menuTipoListas();
    return 0;
}

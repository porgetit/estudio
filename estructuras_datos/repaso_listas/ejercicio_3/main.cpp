#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utilities.h>
#define MAX 11

using namespace std;

int main() {
    srand(time(nullptr));
    int option;

    ListTools<int> myList;

    while (option != 6) {
        cout << "\t   LISTAS SIMPLEMENTE ENLAZADAS" << endl;
        cout << "\t-------------- Menú --------------" << endl;
        cout << "1. Insertar números aleatorios al inicio" << endl;
        cout << "2. Insertar números aleatorios al final" << endl;
        cout << "3. Insertar ordenado" << endl;
        cout << "4. Borrar un elemento" << endl;
        cout << "5. Ver lista" << endl;
        cout << "6. Salir" << endl;
        cout << endl;
        cout << "Opción: "; cin >> option; fflush(stdin);

        switch (option)
        {
        case 1:
            myList.insert(0, (rand() % MAX));
            break;
        case 2:
            myList.append((rand() % MAX));
            break;
        case 3:
            myList.append((rand() % MAX));
            myList.bubbleSort('<');
            break;
        case 4:
            for (auto i : myList.completeList()) {
                cout << i << " ";
            }
            cout << endl;

            int value;
            cout << "Valor a eliminar: "; cin >> value; fflush(stdin);
            
            myList.remove(value);
            cout << "Primera coincidencia eliminada" << endl;
            break;
        case 5:
            cout << "Lista: ";
            for (auto i : myList.completeList()) {
                cout << i << " ";
            }
            cout << endl;
            cout << endl;
            break;
        case 6:
            cout << "Adios" << endl;
            break;    
        default:
            cerr << "Error, opción incorrecta" << endl;
            break;
        }
    }
}
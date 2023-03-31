/*
Implementación paralela de pilas dinámicas del mismo tipo: Implemente una solución que imprima los números enteros del 1 al 10 y viceversa. Utilice la librería de tipado dinámico para pilas "stak_tools.h".
*/
#include <iostream>
#include <cstdlib>
#include "./stack_tools.h"

using namespace std;

int main() { 
    stack_tools<int> miInstancia; // Instanciamos un objeto de la clase stack_tools
    
    stack_tools<int>::Stack miPilaUno = miInstancia.init_stack(); // Creamos una nueva pila
    stack_tools<int>::Stack miPilaDos = miInstancia.init_stack(); // Creamos otra nueva pila

    // Insertamos los 10 enteros en la pila UNO
    for (int i = 10; i >= 1; i--) {
        miInstancia.push(&miPilaUno, i);
    }

    // Insertamos los 10 enteros en la pila DOS
    for (int i = 1; i <= 10; i++) {
        miInstancia.push(&miPilaDos, i);
    }

    // Mostramos el contenido de la pila UNO, desempilando los elementos
    while (!miInstancia.empty(&miPilaUno)) {
        cout << miInstancia.pop(&miPilaUno) << " ";
    }

    cout << endl;

    // Mostramos el contenido de la pila DOS, desempilando los elementos
    while (!miInstancia.empty(&miPilaDos)) {
        cout << miInstancia.pop(&miPilaDos) << " ";
    }

    cout << endl;

    return 0;
}

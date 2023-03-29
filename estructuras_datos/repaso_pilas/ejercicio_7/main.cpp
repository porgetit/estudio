#include <iostream>
#include <cstdlib>
#include "./stack_tools.h"

using namespace std;

int main() { 
    stack_tools<int> miInstancia; // Instanciamos un objeto de la clase stack_tools
    stack_tools<int>::Stack miPila = miInstancia.init_stack();
    miPila.top = NULL;

    

    // Insertamos los 10 enteros en la pila
    for (int i = 10; i > 0; i--) {
        miInstancia.push(&miPila, i);
    }

    // Mostramos el contenido de la pila, desempilando los elementos
    for (int i = 1; i <= 10; i++) {
        cout << miInstancia.pop(&miPila) << " ";
    }

    cout << endl;

    return 0;
}

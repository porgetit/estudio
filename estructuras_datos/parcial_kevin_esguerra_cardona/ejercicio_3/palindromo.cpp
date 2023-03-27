#include "pila.h"
#include "pila.cpp"
#include <iostream>
#include <cstring>


using namespace std;

int main() {
    char cadena[] = "alila";
    Pila auxiliar;
    int len = strlen(cadena);

    // Se ha modificado el tipo de dato nativo de la pila int -> char

    // Crear la pila
    crearPila(&auxiliar);

    // Insertar elementos en la pila
    for (int index = 0; index < len; index++) {
        insertar(&auxiliar, cadena[index]);
    }

    // Verificamos palíndromo
    for (int index = 0; index < len; index++) {
        if ((cadena[index] != quitar(&auxiliar))||(pilaVacia(auxiliar))) {
            cout << "No es un palindromo." << endl;
            exit(1);
        }

        cout << "La cadena es palindromo" << endl;
    }
    
    return 0;
}
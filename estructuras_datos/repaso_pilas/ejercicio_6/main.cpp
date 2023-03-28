/*
Implemente una solución (usando pilas) que le permita evaluar expresiones en notación prefija.
*/

#include <iostream>
#include <cstdlib>
#include "pilas.h"

using namespace std;

int main() {
    Stack expresion_invertida;
    Stack contenedor;


    return 0;
}

/*
Definición del algoritmo.

Recorer la cadena de atrás hacia adelante.

Si encuentra un número, añadalo a la pila.
Si encuentra un operador, extraiga los últimos dos elementos de la pila, evalue y añada el resultado a la pila.
*/
/*
Implemente una solución (usando pilas) que le permita evaluar expresiones en notación prefija.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "./utilidades/pilas.h"
#include "./utilidades/utilidades.h"

using namespace std;

int main() {
    Stack expresion_invertida;
    Stack contenedor; // Espacio en el que se almacenarán los resultados

    char expresion[] = "/ + * 5 3 - 81 23 100";

    expresion_invertida = string_tools::splitPrefixExpression(expresion);

    // Desempilar y evaluar
    while(!empty(&expresion_invertida)) {
        if () // Evaluar si es número y almacenarlo sino, si es operador y almacenar el resultado
    }

    return 0;
}

/*
Definición del algoritmo.

Recorer la cadena de atrás hacia adelante.

Si encuentra un número, añadalo a la pila.
Si encuentra un operador, extraiga los últimos dos elementos de la pila, evalue y añada el resultado a la pila.
*/
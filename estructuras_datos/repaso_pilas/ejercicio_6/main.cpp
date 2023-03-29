/*
Implemente una solución (usando pilas) que le permita evaluar expresiones en notación prefija.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "./pilas/pilas.h"
#include "./utilidades/utilidades.h"

using namespace std;

int main() {
    Stack expresion_invertida;
    expresion_invertida.top = NULL;
    Stack contenedor;
    contenedor.top == NULL;

    string input = "* 10 * 2 ^ 2 3";
    vector<string> output;

    output = string_tools::splitString(input, ' ');

    // Empilamos la cadena para evaluarla.
    for (int index = 0; index < output.size(); index++) {
        DataType atom = (DataType) output[index];
        push(&expresion_invertida, atom);
    }

    // Desempilamos y evaluamos
    while (!empty(&expresion_invertida)) {
        string atom = (string) pop(&expresion_invertida);
        
        if (string_tools::isNumber(atom)) {
            push(&contenedor, atom);
        } else if (string_tools::isBinaryOperator(atom)) {
            int subAtom_1 = stoi(pop(&contenedor));
            int subAtom_2 = stoi(pop(&contenedor));
            int temp = 0;

            if (atom[0] == '+') {
                temp = subAtom_1 + subAtom_2;
            } else if (atom[0] == '-') {
                temp = subAtom_1 - subAtom_2;
            } else if (atom[0] == '*') {
                temp = subAtom_1 * subAtom_2;
            } else if (atom[0] == '/') {
                temp = subAtom_1 / subAtom_2;
            } else if (atom[0] == '^') {
                temp = 1;
                for (int i = 0; i < subAtom_2; i++)  {
                    temp *= subAtom_1;
                }
            }

            DataType result = to_string(temp);
            push(&contenedor, result);
        }
    }

    cout << "Resultado: " << pop(&contenedor) << endl;
    return 0;
}

/*
Definición del algoritmo.

Recorer la cadena de atrás hacia adelante.

Si encuentra un número, añadalo a la pila.
Si encuentra un operador, extraiga los últimos dos elementos de la pila, evalue y añada el resultado a la pila.
*/
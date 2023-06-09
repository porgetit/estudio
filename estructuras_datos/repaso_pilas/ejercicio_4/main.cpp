/*
Palindromo: Implemente una solución que le permita decidir si una cadena dada es o no es un palindromo. Utilice pilas.
*/

/*
Mi implementación es de complejidad temporal O(n^2)
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "pilas.h"

using namespace std;

int main() {
    Stack my_stack;
    my_stack.top = NULL;

    // Pedimos la cadena
    char my_string[] = "alila alilla";

    // Empilamos cada caracter
    int len = strlen(my_string);
    for (int index = 0; index < len; index++) {
        DataType atom = (DataType) my_string[index];
        push(&my_stack, atom);
    }

    // Desempilamos y comparamos
    int index = 0;
    while (true) {
        if (!empty(&my_stack)) {
            if (my_string[index] == (char) pop(&my_stack)) {
                index++;
            } else {
                cout << my_string << " no es palíndromo" << endl;
                clear(&my_stack);
            }
        } else {
            break;
        }
    }

    if (index == len) {
        cout << my_string << " es un palíndromo" << endl;
    }

    return 0;
}
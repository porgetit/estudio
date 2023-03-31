/*
Palindromo: Implemente una solución que le permita decidir si una cadena dada es o no es un palindromo. Utilice la clase stack_tools de la librería del mismo nombre.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "stack_tools.h"

using namespace std;

int main() {

    stack_tools<char> controlador; // Instanciamos un objeto de la clase stack_tools para char
    stack_tools<char>::Stack Cadena = controlador.init_stack();

    // Pedimos la cadena
    char my_string[] = "alila alila alila";

    // Empilamos cada caracter
    int len = strlen(my_string);
    for (int index = 0; index < len; index++) {
        char atom = my_string[index];
        controlador.push(&Cadena, atom);
    }

    // Desempilamos y comparamos
    int index = 0;
    while (true) {
        if (!controlador.empty(&Cadena)) {
            if (my_string[index] == controlador.pop(&Cadena)) {
                index++;
            } else {
                cout << my_string << " no es palíndromo" << endl;
                controlador.clear(&Cadena);
            }
        } else {
            break;
        }
    }

    if (index == len) {
        cout << "\"" << my_string << "\"" << " es un palíndromo" << endl;
    }

    return 0;
}

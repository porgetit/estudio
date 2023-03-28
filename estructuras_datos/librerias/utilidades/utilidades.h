#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <cstring>
#include <cctype>
#include "pilas.h"

class string_tools {
public:
    static Stack splitPrefixExpression(char*);
};

// Usar clear con la pila devuelta al terminar de usarla
Stack string_tools::splitPrefixExpression(char* expresion) {
    Stack cadena;
    cadena.top = NULL;

    int len = strlen(expresion);
    for (int index = 0; index < len; index++) {
        if (isspace(expresion[index]) != 0) {

            std::string transference_buffer = ""; // Buffer de transferencia
            int subIndex = index;

            while(isspace(expresion[subIndex]) != 0 || expresion[index] == '\0') { // Recorremos la subcadena encontrada
                transference_buffer.append(1, expresion[subIndex]);
            }

            index = subIndex; // Saltamos a la próxima subcadena
            
            DataType atom = (DataType) transference_buffer.c_str();
            push(&cadena, atom);
        }
    }

    return cadena;
}

#endif

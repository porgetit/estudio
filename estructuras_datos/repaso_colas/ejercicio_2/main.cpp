/*
Número capicúa: Construir una solución que le permita determinar si un número dado es o no un número capicúa. Debe implementar pilas y colas para su solución.
*/
#include <iostream>
#include <string>
#include <utilities.h>

using namespace std;

int main() {

    // Definimos el número candidato a capicúa e insertamos los dígitos en las estructuras.
    string number = "1221";

    StackTools<char> stack;
    QueueTools<char> queue;

    for (auto i: number) {
        stack.push(i);
        queue.push(i);
    }

    int len = 0;
    // Retornamos el contenido de las estructuras y comparamos.
    for (int i = 0, j = 0; i < stack.size(), j < queue.size(); i++, j++) {
        if (stack.return_stack()[i] == queue.return_queue()[i]) {
            len++;
        } else {
            cerr << number << " no es un número capicúa." << endl;
            exit(1);
        }
    }

    if (len == number.size()) {
        cout << number << " es un número capicúa." << endl;
    }
    
    return 0;
}
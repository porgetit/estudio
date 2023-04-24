#include <iostream>
#include "../../utilities.h"

using namespace std;

int main() {
    TreeTools<int> miArbol;

    miArbol.insert(10); // Inserción de nodos en el árbol
    miArbol.insert(5);
    miArbol.insert(15);
    miArbol.insert(3);
    miArbol.insert(7);
    miArbol.insert(13);
    miArbol.insert(17);

    /*
    Las inserciones realizadas anteriormente son hechas de forma manual. Si se busca ingresar datos aleatorios se tendría que modificar el documento así:
        - Establecer la raíz para generar los números aleatorios.
        - En cada inserción, cambiar el argumento por una llamada a la función rand(). Acotada en el rango deseado. 
    Por razones de comodidad y legivilidad del código dicho procedimiento no es realizado en esta solución, pero se deja constancia de las modificaciones
    necesarias para su implementación.
    */

    cout << "Recorrido en orden: ";
    for (auto i : miArbol.inorderTraversal()) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Recorrido en preorden: ";
    for (auto i : miArbol.preorderTraversal()) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Recorrido en postorden: ";
    for (auto i : miArbol.postorderTraversal()) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Recorrido en amplitud: ";
    for (auto i : miArbol.amplitudeTraversal()) {
        for (auto j : i) {
            cout << j << " ";
        }
    }
    cout << endl;

    cout << "El menor elemento del árbol: " << miArbol.leastOf() << endl;
    cout << "El mayor elemento del árbol: " << miArbol.greatestOf() << endl;

    cout << "Tamaño del árbol: " << miArbol.size() << endl;
    cout << "Altura del árbol: " << miArbol.height() << endl;

    int eliminado = 5;
    miArbol.pop(eliminado); // Eliminar un elemento del árbol
    cout << "Valor del nodo eliminado: " << eliminado << endl;

    cout << "Recorrido en orden después de eliminar el nodo: ";
    for (auto i : miArbol.inorderTraversal()) {
        cout << i << " ";
    }
    cout << endl;

    if (miArbol.find(15)) { // Buscar un elemento en el árbol
        cout << "15 encontrado en el árbol" << endl;
    } else {
        cout << "15 no encontrado en el árbol" << endl;
    }

    if (miArbol.find(20)) {
        cout << "20 encontrado en el árbol" << endl;
    } else {
        cout << "20 no encontrado en el árbol" << endl;
    }

    return 0;

}

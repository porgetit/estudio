#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Clase que representa un Árbol Binario de Búsqueda (ABB).
 */
class ABB {
private:
    /**
     * @brief Estructura de un nodo del árbol.
     */
    struct Node {
        int data; /**< Valor almacenado en el nodo. */
        Node* left; /**< Puntero al hijo izquierdo. */
        Node* right; /**< Puntero al hijo derecho. */

        /**
         * @brief Constructor de la estructura Node.
         * @param value Valor a almacenar en el nodo.
         */
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root; /**< Puntero a la raíz del árbol. */

    /**
     * @brief Función recursiva para insertar un valor en el árbol.
     * @param node Puntero al nodo actual.
     * @param value Valor a insertar.
     * @return Puntero al nodo actualizado.
     */
    Node* insertarNodo(Node* nodo, int valor) {
        if (nodo == nullptr) {
            return new Node(valor);
        }

        if (valor < nodo->data) {
            nodo->left = insertarNodo(nodo->left, valor);
        } else if (valor > nodo->data) {
            nodo->right = insertarNodo(nodo->right, valor);
        }

        return nodo;
    }

    /**
     * @brief Función recursiva para buscar un valor en el árbol.
     * @param nodo Puntero al nodo actual.
     * @param valor Valor a buscar.
     * @return Puntero al nodo encontrado (nullptr si no se encuentra).
     */
    Node* buscarNodo(Node* nodo, int valor) {
        if (nodo == nullptr || nodo->data == valor) {
            return nodo;
        }

        if (valor < nodo->data) {
            return buscarNodo(nodo->left, valor);
        } else {
            return buscarNodo(nodo->right, valor);
        }
    }

    /**
     * @brief Función para encontrar el nodo mínimo en un subárbol.
     * @param nodo Puntero al nodo raíz del subárbol.
     * @return Puntero al nodo mínimo.
     */
    Node* encontrarNodoMin(Node* nodo) {
        while (nodo->left != nullptr) {
            nodo = nodo->left;
        }

        return nodo;
    }

    /**
     * @brief Función recursiva para eliminar un valor del árbol.
     * @param nodo Puntero al nodo actual.
     * @param valor Valor a eliminar.
     * @return Puntero al nodo actualizado.
     */
    Node* eliminarNodo(Node* nodo, int valor) {
        if (nodo == nullptr) {
            return nullptr;
        }

        if (valor < nodo->data) {
            nodo->left = eliminarNodo(nodo->left, valor);
        } else if (valor > nodo->data) {
            nodo->right = eliminarNodo(nodo->right, valor);
        } else {
            if (nodo->left == nullptr && nodo->right == nullptr) {
                delete nodo;
                nodo = nullptr;
            } else if (nodo->left == nullptr) {
                Node* temp = nodo;
                nodo = nodo->right;
                delete temp;
            } else if (nodo->right == nullptr) {
                Node* temp = nodo;
                nodo = nodo->left;
                delete temp;
            } else {
                Node* minRight = encontrarNodoMin(nodo->right);
                nodo->data = minRight->data;
                nodo->right = eliminarNodo(nodo->right, minRight->data);
            }
        }

        return nodo;
    }

    /**
     * @brief Función recursiva para realizar el recorrido en preorden.
     * @param nodo Puntero al nodo actual.
     * @param resultado Vector para almacenar los valores del recorrido.
     */
    void recorridoPreorden(Node* nodo, vector<int>& resultado) {
        if (nodo != nullptr) {
            resultado.push_back(nodo->data);
            recorridoPreorden(nodo->left, resultado);
            recorridoPreorden(nodo->right, resultado);
        }
    }

    /**
     * @brief Función recursiva para realizar el recorrido en inorden.
     * @param nodo Puntero al nodo actual.
     * @param resultado Vector para almacenar los valores del recorrido.
     */
    void recorridoInorden(Node* nodo, vector<int>& resultado) {
        if (nodo != nullptr) {
            recorridoInorden(nodo->left, resultado);
            resultado.push_back(nodo->data);
            recorridoInorden(nodo->right, resultado);
        }
    }

    /**
     * @brief Función recursiva para realizar el recorrido en postorden.
     * @param nodo Puntero al nodo actual.
     * @param resultado Vector para almacenar los valores del recorrido.
     */
    void recorridoPostorden(Node* nodo, vector<int>& resultado) {
        if (nodo != nullptr) {
            recorridoPostorden(nodo->left, resultado);
            recorridoPostorden(nodo->right, resultado);
            resultado.push_back(nodo->data);
        }
    }

public:
    /**
     * @brief Constructor de la clase ABB.
     */
    ABB() : root(nullptr) {}

    /**
     * @brief Inserta un valor en el árbol.
     * @param valor Valor a insertar.
     */
    void insertar(int valor) {
        root = insertarNodo(root, valor);
    }

    /**
     * @brief Busca un valor en el árbol.
     * @param valor Valor a buscar.
     * @return Verdadero si el valor está presente, falso de lo contrario.
     */
    bool buscar(int valor) {
        return buscarNodo(root, valor) != nullptr;
    }

    /**
     * @brief Elimina un valor del árbol.
     * @param valor Valor a eliminar.
     */
    void eliminar(int valor) {
        root = eliminarNodo(root, valor);
    }

    /**
     * @brief Realiza el recorrido en preorden del árbol.
     * @return Vector con los valores del recorrido en preorden.
     */
    vector<int> recorridoPreorden() {
        vector<int> resultado;
        recorridoPreorden(root, resultado);
        return resultado;
    }

    /**
     * @brief Realiza el recorrido en inorden del árbol.
     * @return Vector con los valores del recorrido en inorden.
     */
    vector<int> recorridoInorden() {
        vector<int> resultado;
        recorridoInorden(root, resultado);
        return resultado;
    }

    /**
     * @brief Realiza el recorrido en postorden del árbol.
     * @return Vector con los valores del recorrido en postorden.
     */
    vector<int> recorridoPostorden() {
        vector<int> resultado;
        recorridoPostorden(root, resultado);
        return resultado;
    }
};

int main() {
    ABB arbol;

    // Insertar valores en el árbol
    arbol.insertar(8);
    arbol.insertar(3);
    arbol.insertar(10);
    arbol.insertar(1);
    arbol.insertar(6);
    arbol.insertar(14);
    arbol.insertar(4);
    arbol.insertar(7);
    arbol.insertar(13);

    // Realizar el recorrido en preorden
    cout << "Recorrido en Preorden: ";
    vector<int> preorden = arbol.recorridoPreorden();
    for (int valor : preorden) {
        cout << valor << " ";
    }
    cout << endl;

    // Realizar el recorrido en inorden
    cout << "Recorrido en Inorden: ";
    vector<int> inorden = arbol.recorridoInorden();
    for (int valor : inorden) {
        cout << valor << " ";
    }
    cout << endl;

    // Realizar el recorrido en postorden
    cout << "Recorrido en Postorden: ";
    vector<int> postorden = arbol.recorridoPostorden();
    for (int valor : postorden) {
        cout << valor << " ";
    }
    cout << endl;

    return 0;
}

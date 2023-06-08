#include <iostream>
#include <string>

using namespace std;

template <typename L>
class SimpleList {
public:
    struct Node { // Definimos la naturaleza de los nodos de la estructura
        L data;
        Node* next;
    };

    struct List { // Definimos la estructura Lista
        Node* head;
    };

    List* list;

    SimpleList() {
        list = new List;
        list->head = nullptr; 
    }

    ~SimpleList() {
        if (!empty()) clear();
        delete list;
    }

    /**
     * El método empty() retorna un valor verdadero en caso de que la lista esté vacía.
     * @return Booleano que indica el estado de la lista entre vacío (1) y con contenido (0)
    */
    bool empty() {
        return list->head == nullptr;
    }

    /**
     * El método size() retorna un valor entero que representa la cantidad de nodos que contiene la lista.
     * @return Entero que representa la cantidad de nodos que contiene la lista. 
    */
    int size() {
        int amount = 0;
        if (empty()) return amount;

        Node* auxiliarCurrentNode = list->head;
        while (auxiliarCurrentNode != nullptr) {
            amount += 1;
            auxiliarCurrentNode = auxiliarCurrentNode->next;
        }

        return amount;
    }

    class CreationMethods {
    public:
        /**
         * El método append() recibe un argumento del mismo tipo de datos de la lista y lo añade a la misma al final de la estructura.
         * @param data parámetro del método append cuyo tipado debe coincidir con el definido para la lista.
         * @return El método no tiene ningún tipo de retorno.
        */
        void append(L data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;

            if (empty())
                list->head = newNode;
            else {
                Node* auxiliarCurrentNode = list->head;
                while (auxiliarCurrentNode->next != nullptr) {
                    auxiliarCurrentNode = auxiliarCurrentNode->next;
                }
                auxiliarCurrentNode->next = newNode;
            }
        }

        /**
         * El método insert() recibe un valor del mismo tipo de datos de la lista y una posición en la cual se desea añadir el nuevo dato dentro de la lista.
         * @param data parámetro del método insert cuyo tipado debe coincidir con el definido para la lista
         * @param pos parámetro del método insert de tipo entero cuyo rango de valores está definido en [0, size()].
         * @exception Index is out of range se dispara cuando se intenta añadir un valor a la lista y el argumento pos está fuera del rango [0, size()].
         * @return El método no tiene ningún tipo de retorno.
        */
        void insert(L data, int pos) {
            if (pos < 0 || pos > size())
                throw out_of_range("Index is out of range");

            Node* newNode = new Node;
            newNode->data = data;

            if (pos == 0) {
                newNode->next = list->head;
                list->head = newNode;
            } else if (pos == size()) {
                append(data);
            } else {
                Node* auxiliarPreviousNode = nullptr;
                Node* auxiliarCurrentNode = list->head;

                for (int i = 0; i < pos; i++) {
                    auxiliarPreviousNode = auxiliarCurrentNode;
                    auxiliarCurrentNode = auxiliarCurrentNode->next;
                }

                auxiliarPreviousNode->next = newNode;
                newNode->next = auxiliarCurrentNode;
            }
        }
    };

    CreationMethods creationMethods;
};

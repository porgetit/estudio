#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <vector>

template <typename L>
class LinkedList {
public:
    struct Node {
        L data;
        Node* next;
    };

    Node* head;

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        if (!empty()) clear();
    }

    class Creation {
    public:
        /**
         * @brief Agrega un elemento al final de la lista.
         *
         * Crea un nuevo nodo con el valor especificado y lo agrega al final de la lista.
         * Si la lista está vacía, el nuevo nodo se convierte en la cabeza de la lista.
         *
         * @param data El valor del elemento a agregar.
         * @return N/A
         */
        void append(L data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;

            if (empty()) {
                head = newNode;
            } else {
                Node* auxiliaryCurrentNode = head;
                while (auxiliaryCurrentNode->next != nullptr) {
                    auxiliaryCurrentNode = auxiliaryCurrentNode->next;
                }
                auxiliaryCurrentNode->next = newNode;
            }
        }

        /**
         * @brief Inserta un elemento en una posición específica de la lista.
         *
         * Inserta un nuevo nodo con el valor especificado en la posición dada de la lista.
         * Si la posición es 0, el nuevo nodo se convierte en la cabeza de la lista.
         * Si la posición es igual al tamaño de la lista, el nuevo nodo se agrega al final de la lista.
         * Si la posición está fuera del rango [0, size()], se lanza una excepción de tipo `std::out_of_range`.
         *
         * @param data El valor del elemento a insertar.
         * @param pos La posición en la cual se desea insertar el nuevo elemento.
         * @throws std::out_of_range Si la posición está fuera del rango [0, size()].
         * @return N/A
         */
        void insert(L data, int pos) {
            if (pos < 0 || pos >= size())
                throw std::out_of_range("Index is out of range");

            Node* newNode = new Node;
            newNode->data = data;

            if (pos == 0) {
                newNode->next = head;
                head = newNode;
            } else if (pos == size()) {
                append(data);
            } else {
                Node* auxiliaryPreviousNode = nullptr;
                Node* auxiliaryCurrentNode = head;

                for (int i = 0; i < pos; i++) {
                    auxiliaryPreviousNode = auxiliaryCurrentNode;
                    auxiliaryCurrentNode = auxiliaryCurrentNode->next;
                }

                auxiliaryPreviousNode->next = newNode;
                newNode->next = auxiliaryCurrentNode;
            }
        }
    };

    class Retrieval {
    public:
        /**
        * Comprueba si la lista está vacía.
        * Este método verifica si la lista está vacía al verificar si el puntero head apunta a nullptr, lo que indica que no hay ningún nodo en la lista.
        * @return true si la lista está vacía, false en caso contrario.
        */
        bool empty() {
            return head == nullptr;
        }

        /**
        * Obtiene el tamaño de la lista.
        * Este método cuenta la cantidad de nodos en la lista y devuelve el resultado como un entero.
        * Si la lista está vacía, retorna 0.
        @return El número de nodos en la lista.
        */
        int size() {
            int amount = 0;
            if (empty()) return amount;

            Node* auxiliaryCurrentNode = head;
            while (auxiliaryCurrentNode != nullptr) {
                amount += 1;
                auxiliaryCurrentNode = auxiliaryCurrentNode->next;
            }

            return amount;
        }

        /**
        * Obtiene el valor almacenado en la posición especificada de la lista.
        * Este método recibe como parámetro la posición del elemento que se desea obtener.
        * Si la posición está fuera del rango válido [0, size()-1], se lanza una excepción std::out_of_range.
        * @param pos La posición del elemento que se desea obtener.
        * @return El valor almacenado en la posición especificada.
        * @throws std::out_of_range si la posición está fuera del rango válido.
        */
        L get(int pos) {
            if (pos < 0 || pos >= size())
                throw std::out_of_range("Index is out of range");

            Node* auxiliaryCurrentNode = head;
            for (int i = 0; i < pos; i++) {
                auxiliaryCurrentNode = auxiliaryCurrentNode->next;
            }

            return auxiliaryCurrentNode->data;
        }
        
        /**
        * Obtiene el valor almacenado en el primer nodo de la lista.
        * Si la lista está vacía, se lanza una excepción std::runtime_error.
        * @return El valor almacenado en el primer nodo de la lista.
        * @throws std::runtime_error si la lista está vacía.
        */
        L front() {
            if (empty())
                throw std::runtime_error("List is empty");

            return head->data;
        }

        /**
        * Obtiene el valor almacenado en el último nodo de la lista.
        * Si la lista está vacía, se lanza una excepción std::runtime_error.
        * @return El valor almacenado en el último nodo de la lista.
        * @throws std::runtime_error si la lista está vacía.
        */
        L back() {
            if (empty())
                throw std::runtime_error("List is empty");

            Node* auxiliaryCurrentNode = head;
            while (auxiliaryCurrentNode->next != nullptr) {
                auxiliaryCurrentNode = auxiliaryCurrentNode->next;
            }

            return auxiliaryCurrentNode->data;
        }

        /**
         * Obtiene todos los valores almacenados en la lista y los devuelve en un vector.
         * Este método recorre la lista y agrega cada valor encontrado al final de un vector.
         * El orden de los valores en el vector será el mismo en el que aparecen en la lista.
         * @return Un vector que contiene todos los valores almacenados en la lista.
         */
        std::vector<L> getAllValues() {
            std::vector<L> values;
            Node* auxiliaryCurrentNode = head;
            
            while (auxiliaryCurrentNode != nullptr) {
                values.push_back(auxiliaryCurrentNode->data);
                auxiliaryCurrentNode = auxiliaryCurrentNode->next;
            }
            
            return values;
        }
    };

    class Update {
    public:
        void set() {
            // método para actualizar un valor de un nodo
        }
    };
};

#endif // LINKEDLIST_H

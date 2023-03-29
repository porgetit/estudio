#ifndef STACK_TOOLS_H
#define STACK_TOOLS_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>

/**
 * @class stack_tools contiene estructuras y métodos que le permiten definir una pila de cualquier tipo de dato.
 * 
 * @defgroup stack_tools
 * 
 * @section Instancia de clase:
 * Para instanciar un objeto stack_tools debe hacerlo así: 
 *      stack_tools<DataType> miPila;
 * Dónde DataType es el tipo de dato que heredará la pila y,
 * miPila es el objeto que heredará todos los métodos de la clase.
 * 
 * @section Tipos de datos recomendados para trabajar con la clase:
 * Tipos de datos numéricos: int, float, double, long, etc.
 * Tipos de datos booleanos: bool.
 * Tipos de datos de caracteres: char, std::string, etc;
 * Tipos de datos estructurados simples: struct.
*/
class stack_tools {
public:
    typedef T DataType; // Tipo de dato de la pila

    /**
     * @brief Esta estructura define la naturaleza de los nodos de una pila.
    */
    typedef struct Node {
        DataType data;
        Node* next;
    } Node;

    /**
     * @brief Esta estructura define una pila.
    */
    typedef struct Stack { 
        Node* top;
    } Stack;

    static int size_ = 0; // Contador de nodos de la pila

    /**
     * @brief Este método inserta/empila un nuevo nodo.
     * 
     * @param atom es el elemento que se insertará a la pila. 
    */
    void push(DataType atom) {
        Node* newNode = new Node;
        newNode->data = atom;
        newNode->next = this->top;
        this->top = newNode;
        size_++;
    }

    /**
     * @brief Este método devuelve/desempila el nodo cabecera de la pila.
     * 
     * @throw Si la pila está vacía el método arrojará una excepción: (runtime_error) 
    */
    DataType pop() {
        if (empty(this)) {
            throw std::runtime_error("Pila vacia");
        }

        Node* eliminatedNode = this->top;
        DataType data = eliminatedNode->data;
        this->top = eliminatedNode->next;
        delete eliminatedNode;

        size_--;

        return data;
    }

    /**
     * @brief Este método verifica si la pila está vacía.
    */
    bool empty() {
        if (this->top == NULL) {
            return true;
        }

        return false;
    }

    /**
     * @brief Este método vacía/límpia por completo al pila.
     * 
     * @throw Si la pila está vacía el método arrojará una excepción: (runtime_error)
    */
    void clear() {
        if (this.empty()) {
            throw std::runtime_error("Pila vacia");
        }

        while (!this.empty()) {
            this.pop();
        }
    }

    /**
     * @brief Este método devuelve el contenido de la cabecera de la pila.
    */
    DataType peek() {
        return this->top->data;
    }

    /**
     * @brief Este método retorna el largo de la pila.
    */
    int size() {
        return size_;
    }
};

#endif
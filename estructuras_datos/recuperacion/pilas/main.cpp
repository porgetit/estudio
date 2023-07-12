#include <iostream>
#include <stdexcept>

/**
 * @brief Implementación de una pila dinámica.
 *
 * Esta clase proporciona una estructura de datos de pila dinámica con métodos
 * para insertar, extraer, obtener el tamaño y verificar si está vacía.
 *
 * @tparam T El tipo de elementos almacenados en la pila.
 */
template<typename T>
class DynamicStack {
public:
    /**
     * @brief Una estructura que representa un nodo en la pila.
     */
    typedef struct Node {
        T data;         ///< Los datos almacenados en el nodo.
        Node* next;     ///< Puntero al siguiente nodo en la pila.
    } Node;

private:
    Node* top; ///< Puntero al nodo superior de la pila.

public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa una pila vacía.
     */
    DynamicStack() {
        top = nullptr;
    }

    /**
     * @brief Destructor.
     *
     * Limpia la pila liberando la memoria de todos los nodos.
     */
    ~DynamicStack() {
        clear();
    }

    /**
     * @brief Inserta un elemento en la pila.
     *
     * Crea un nuevo nodo con el elemento dado e lo inserta en la parte superior
     * de la pila.
     *
     * @param element El elemento que se va a insertar en la pila.
     */
    void insert(T element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = top;
        top = newNode;
    }

    /**
     * @brief Extrae y devuelve el elemento superior de la pila.
     *
     * Elimina el nodo superior de la pila y devuelve su valor.
     *
     * @return El elemento superior de la pila.
     *
     * @throw std::runtime_error Si la pila está vacía.
     */
    T pop() {
        if (empty()) {
            throw std::runtime_error("No se puede extraer de una pila vacía");
        }

        Node* poppedNode = top;
        T poppedData = poppedNode->data;
        top = top->next;
        delete poppedNode;

        return poppedData;
    }

    /**
     * @brief Obtiene el tamaño de la pila.
     *
     * Calcula y devuelve el número de nodos en la pila.
     *
     * @return El tamaño de la pila.
     */
    int size() const {
        int count = 0;
        Node* currentNode = top;
        while (currentNode != nullptr) {
            count++;
            currentNode = currentNode->next;
        }
        return count;
    }

    /**
     * @brief Verifica si la pila está vacía.
     *
     * Verifica si la pila está vacía comprobando si el puntero al nodo
     * superior es nulo.
     *
     * @return `true` si la pila está vacía, `false` en caso contrario.
     */
    bool empty() const {
        return (top == nullptr);
    }

    /**
     * @brief Limpia la pila.
     *
     * Elimina todos los nodos de la pila y libera la memoria de cada nodo.
     */
    void clear() {
        while (!empty()) {
            pop();
        }
    }
};


int main() {
    DynamicStack<int> stack;

    int opcion;
    do {
        std::cout << "---------- MENU ----------" << std::endl;
        std::cout << "1. Insertar elemento" << std::endl;
        std::cout << "2. Extraer elemento" << std::endl;
        std::cout << "3. Obtener tamaño" << std::endl;
        std::cout << "4. Verificar si está vacía" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int elemento;
                std::cout << "Ingrese el elemento a insertar: ";
                std::cin >> elemento;
                stack.insert(elemento);
                std::cout << "Elemento insertado correctamente." << std::endl;
                break;
            }
            case 2: {
                if (!stack.empty()) {
                    int elemento = stack.pop();
                    std::cout << "Elemento extraído: " << elemento << std::endl;
                } else {
                    std::cout << "La pila está vacía. No se puede extraer ningún elemento." << std::endl;
                }
                break;
            }
            case 3: {
                int tamano = stack.size();
                std::cout << "El tamaño de la pila es: " << tamano << std::endl;
                break;
            }
            case 4: {
                bool estaVacia = stack.empty();
                if (estaVacia) {
                    std::cout << "La pila está vacía." << std::endl;
                } else {
                    std::cout << "La pila no está vacía." << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            }
            default:
                std::cout << "Opción inválida. Por favor, ingrese una opción válida." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcion != 5);

    return 0;
}

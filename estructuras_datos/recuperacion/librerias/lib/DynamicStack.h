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
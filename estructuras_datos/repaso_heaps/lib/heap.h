#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
#include <algorithm>


/**
 * @brief Clase que representa un montículo máximo.
 *
 * Un montículo máximo es una estructura de datos que mantiene la propiedad de montículo máximo,
 * donde el valor de cada nodo es mayor o igual que los valores de sus hijos.
 *
 * @tparam max_heap El tipo de dato de los elementos del montículo.
 */
template <typename max_heap>
class MaxHeap {
public:
    typedef struct Node {
        max_heap info;
        Node* left;
        Node* right;
        Node* parent;
    } Node;

private:
    Node* root;

public:


    MaxHeap() {
        root = nullptr;
    }


    ~MaxHeap() {
        destroyHeap(root);
    }
    /**
     * @brief Inserta un elemento en el montículo manteniendo la propiedad de montículo máximo.
     * 
     * @param value El valor a insertar en el montículo.
     * 
     * La función inserta un nuevo elemento en el montículo manteniendo la propiedad de montículo máximo.
     * Si el montículo está vacío, el nuevo elemento se convierte en la raíz.
     * Si el montículo no está vacío, el nuevo elemento se agrega como hijo izquierdo o derecho del último nodo disponible en el recorrido en anchura del montículo,
     * y luego se ajusta el montículo para asegurar que la propiedad de montículo máximo se cumpla.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.insert(42);
     * 
     * @note La complejidad de tiempo de esta función es O(log n), donde n es el número de elementos en el montículo.
     */
    void insert(const max_heap& value) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr; // Inicializar el puntero al padre como nullptr

        if (empty()) {
            root = newNode;
        } else {
            Node* currentNode = root;
            std::queue<Node*> queue;
            queue.push(currentNode);

            while (!queue.empty()) {
                currentNode = queue.front();
                queue.pop();

                if (currentNode->left == nullptr) {
                    currentNode->left = newNode;
                    newNode->parent = currentNode;
                    break;
                } else {
                    queue.push(currentNode->left);
                }

                if (currentNode->right == nullptr) {
                    currentNode->right = newNode;
                    newNode->parent = currentNode;
                    break;
                } else {
                    queue.push(currentNode->right);
                }
            }

            // Ajustar el montículo después de la inserción
            heapifyUp(newNode);
        }
    }

    /**
     * @brief Elimina el elemento raíz del montículo manteniendo la propiedad de montículo máximo.
     * 
     * La función elimina el elemento raíz del montículo, manteniendo la propiedad de montículo máximo.
     * Si el montículo está vacío, no se realiza ninguna acción.
     * Si el montículo tiene solo un elemento (raíz), se elimina y el montículo queda vacío.
     * Si el montículo tiene más de un elemento, se reemplaza el valor de la raíz por el valor del último nodo disponible en el recorrido en anchura del montículo,
     * se elimina dicho nodo y luego se ajusta el montículo para asegurar que la propiedad de montículo máximo se cumpla.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.remove();
     * 
     * @note La complejidad de tiempo de esta función es O(log n), donde n es el número de elementos en el montículo.
     */
    void remove() {
        if (empty()) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            return;
        }

        Node* currentNode = root;
        std::queue<Node*> queue;
        std::vector<Node*> nodes; // Almacena todos los nodos del último nivel

        queue.push(currentNode);

        while (!queue.empty()) {
            currentNode = queue.front();
            queue.pop();

            if (currentNode->left != nullptr) {
                queue.push(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                queue.push(currentNode->right);
            }

            if (currentNode->left == nullptr || currentNode->right == nullptr) {
                nodes.push_back(currentNode);
            }
        }

        Node* lastNode = nodes.back();
        nodes.pop_back();

        if (lastNode->parent->left == lastNode) {
            lastNode->parent->left = nullptr;
        } else {
            lastNode->parent->right = nullptr;
        }

        root->info = lastNode->info;

        delete lastNode;

        // Ajustar el montículo después de la eliminación
        heapifyDown(root);
    }

    /**
     * @brief Verifica si el montículo está vacío.
     * 
     * @return true si el montículo está vacío, false en caso contrario.
     * 
     * La función verifica si el montículo está vacío, es decir, si no tiene ningún elemento.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     if (heap.empty()) {
     *         cout << "El montículo está vacío." << endl;
     *     }
     */
    bool empty() const {
        return (root == nullptr);
    }

    
    /**
     * @brief Recorrido en anchura (breadth-first traversal) del montículo.
     * 
     * La función realiza un recorrido en anchura (breadth-first traversal) del montículo
     * y muestra los elementos en el orden en que se encuentran en el montículo.
     * 
     * @return Un vector que contiene los elementos del montículo en el orden de recorrido en anchura.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.insert(42);
     *     heap.insert(10);
     *     heap.insert(35);
     *     std::vector<int> result = heap.breadthFirstTraversal();
     *     // result: {42, 10, 35}
     */
    std::vector<max_heap> breadthFirstTraversal() const {
        std::vector<max_heap> result;

        if (empty()) {
            return result;
        }

        std::queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node* currentNode = queue.front();
            queue.pop();

            result.push_back(currentNode->info);

            if (currentNode->left != nullptr) {
                queue.push(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                queue.push(currentNode->right);
            }
        }

        return result;
    }


    /**
     * @brief Recorrido en preorden del montículo.
     * 
     * La función realiza un recorrido en preorden del montículo
     * y devuelve los elementos en el orden correspondiente.
     * 
     * @return Un vector que contiene los elementos del montículo en el orden de recorrido en preorden.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.insert(42);
     *     heap.insert(10);
     *     heap.insert(35);
     *     std::vector<int> result = heap.preorderTraversal();
     *     // result: {42, 10, 35}
     */
    std::vector<max_heap> preorderTraversal() const {
        std::vector<max_heap> result;
        preorderTraversal(root, result);
        return result;
    }


    /**
     * @brief Recorrido en inorden del montículo.
     * 
     * La función realiza un recorrido en inorden del montículo
     * y devuelve los elementos en el orden correspondiente.
     * 
     * @return Un vector que contiene los elementos del montículo en el orden de recorrido en inorden.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.insert(42);
     *     heap.insert(10);
     *     heap.insert(35);
     *     std::vector<int> result = heap.inorderTraversal();
     *     // result: {10, 35, 42}
     */
    std::vector<max_heap> inorderTraversal() const {
        std::vector<max_heap> result;
        inorderTraversal(root, result);
        return result;
    }

private:
    

    void heapifyUp(Node* node) {
        Node* currentNode = node;

        while (currentNode->parent != nullptr && currentNode->info > currentNode->parent->info) {
            std::swap(currentNode->info, currentNode->parent->info);
            currentNode = currentNode->parent;
        }
    }


    void heapifyDown(Node* node) {
        Node* currentNode = node;

        while (true) {
            Node* maxNode = currentNode;

            if (currentNode->left != nullptr && currentNode->left->info > maxNode->info) {
                maxNode = currentNode->left;
            }

            if (currentNode->right != nullptr && currentNode->right->info > maxNode->info) {
                maxNode = currentNode->right;
            }

            if (maxNode == currentNode) {
                break;
            }

            std::swap(currentNode->info, maxNode->info);
            currentNode = maxNode;
        }
    }


    void preorderTraversal(Node* node, std::vector<max_heap>& result) const {
        if (node == nullptr) {
            return;
        }

        result.push_back(node->info);
        preorderTraversal(node->left, result);
        preorderTraversal(node->right, result);
    }


    void inorderTraversal(Node* node, std::vector<max_heap>& result) const {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left, result);
        result.push_back(node->info);
        inorderTraversal(node->right, result);
    }

    
    void destroyHeap(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroyHeap(node->left);
        destroyHeap(node->right);

        delete node;
    }
};


/**
 * @brief Clase que representa un montículo mínimo.
 *
 * Un montículo mínimo es una estructura de datos que mantiene la propiedad de montículo mínimo,
 * donde el valor de cada nodo es menor o igual que los valores de sus hijos.
 *
 * @tparam min_heap El tipo de dato de los elementos del montículo.
 */
template <typename min_heap>
class MinHeap {
public:
    typedef struct Node {
        min_heap info;
        Node* left;
        Node* right;
        Node* parent;
    } Node;

private:
    Node* root;

public:


    MinHeap() {
        root = nullptr;
    }


    ~MinHeap() {
        destroyHeap(root);
    }
    /**
     * @brief Inserta un elemento en el montículo manteniendo la propiedad de montículo máximo.
     * 
     * @param value El valor a insertar en el montículo.
     * 
     * La función inserta un nuevo elemento en el montículo manteniendo la propiedad de montículo máximo.
     * Si el montículo está vacío, el nuevo elemento se convierte en la raíz.
     * Si el montículo no está vacío, el nuevo elemento se agrega como hijo izquierdo o derecho del último nodo disponible en el recorrido en anchura del montículo,
     * y luego se ajusta el montículo para asegurar que la propiedad de montículo máximo se cumpla.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.insert(42);
     * 
     * @note La complejidad de tiempo de esta función es O(log n), donde n es el número de elementos en el montículo.
     */
    void insert(const min_heap& value) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr; // Inicializar el puntero al padre como nullptr

        if (empty()) {
            root = newNode;
        } else {
            Node* currentNode = root;
            std::queue<Node*> queue;
            queue.push(currentNode);

            while (!queue.empty()) {
                currentNode = queue.front();
                queue.pop();

                if (currentNode->left == nullptr) {
                    currentNode->left = newNode;
                    newNode->parent = currentNode;
                    break;
                } else {
                    queue.push(currentNode->left);
                }

                if (currentNode->right == nullptr) {
                    currentNode->right = newNode;
                    newNode->parent = currentNode;
                    break;
                } else {
                    queue.push(currentNode->right);
                }
            }

            // Ajustar el montículo después de la inserción
            heapifyUp(newNode);
        }
    }

    /**
     * @brief Elimina el elemento raíz del montículo manteniendo la propiedad de montículo máximo.
     * 
     * La función elimina el elemento raíz del montículo, manteniendo la propiedad de montículo máximo.
     * Si el montículo está vacío, no se realiza ninguna acción.
     * Si el montículo tiene solo un elemento (raíz), se elimina y el montículo queda vacío.
     * Si el montículo tiene más de un elemento, se reemplaza el valor de la raíz por el valor del último nodo disponible en el recorrido en anchura del montículo,
     * se elimina dicho nodo y luego se ajusta el montículo para asegurar que la propiedad de montículo máximo se cumpla.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.remove();
     * 
     * @note La complejidad de tiempo de esta función es O(log n), donde n es el número de elementos en el montículo.
     */
    void remove() {
        if (empty()) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            return;
        }

        Node* currentNode = root;
        std::queue<Node*> queue;
        std::vector<Node*> nodes; // Almacena todos los nodos del último nivel

        queue.push(currentNode);

        while (!queue.empty()) {
            currentNode = queue.front();
            queue.pop();

            if (currentNode->left != nullptr) {
                queue.push(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                queue.push(currentNode->right);
            }

            if (currentNode->left == nullptr || currentNode->right == nullptr) {
                nodes.push_back(currentNode);
            }
        }

        Node* lastNode = nodes.back();
        nodes.pop_back();

        if (lastNode->parent->left == lastNode) {
            lastNode->parent->left = nullptr;
        } else {
            lastNode->parent->right = nullptr;
        }

        root->info = lastNode->info;

        delete lastNode;

        // Ajustar el montículo después de la eliminación
        heapifyDown(root);
    }

    /**
     * @brief Verifica si el montículo está vacío.
     * 
     * @return true si el montículo está vacío, false en caso contrario.
     * 
     * La función verifica si el montículo está vacío, es decir, si no tiene ningún elemento.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     if (heap.empty()) {
     *         cout << "El montículo está vacío." << endl;
     *     }
     */
    bool empty() const {
        return (root == nullptr);
    }

    
    /**
     * @brief Recorrido en anchura (breadth-first traversal) del montículo.
     * 
     * La función realiza un recorrido en anchura (breadth-first traversal) del montículo
     * y muestra los elementos en el orden en que se encuentran en el montículo.
     * 
     * @return Un vector que contiene los elementos del montículo en el orden de recorrido en anchura.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.insert(42);
     *     heap.insert(10);
     *     heap.insert(35);
     *     std::vector<int> result = heap.breadthFirstTraversal();
     *     // result: {42, 10, 35}
     */
    std::vector<min_heap> breadthFirstTraversal() const {
        std::vector<min_heap> result;

        if (empty()) {
            return result;
        }

        std::queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node* currentNode = queue.front();
            queue.pop();

            result.push_back(currentNode->info);

            if (currentNode->left != nullptr) {
                queue.push(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                queue.push(currentNode->right);
            }
        }

        return result;
    }


    /**
     * @brief Recorrido en preorden del montículo.
     * 
     * La función realiza un recorrido en preorden del montículo
     * y devuelve los elementos en el orden correspondiente.
     * 
     * @return Un vector que contiene los elementos del montículo en el orden de recorrido en preorden.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.insert(42);
     *     heap.insert(10);
     *     heap.insert(35);
     *     std::vector<int> result = heap.preorderTraversal();
     *     // result: {42, 10, 35}
     */
    std::vector<min_heap> preorderTraversal() const {
        std::vector<min_heap> result;
        preorderTraversal(root, result);
        return result;
    }


    /**
     * @brief Recorrido en inorden del montículo.
     * 
     * La función realiza un recorrido en inorden del montículo
     * y devuelve los elementos en el orden correspondiente.
     * 
     * @return Un vector que contiene los elementos del montículo en el orden de recorrido en inorden.
     * 
     * Ejemplo de uso:
     *     Heap<int> heap;
     *     heap.insert(42);
     *     heap.insert(10);
     *     heap.insert(35);
     *     std::vector<int> result = heap.inorderTraversal();
     *     // result: {10, 35, 42}
     */
    std::vector<min_heap> inorderTraversal() const {
        std::vector<min_heap> result;
        inorderTraversal(root, result);
        return result;
    }

private:
    

    void heapifyUp(Node* node) {
        Node* currentNode = node;

        while (currentNode->parent != nullptr && currentNode->info < currentNode->parent->info) {
            std::swap(currentNode->info, currentNode->parent->info);
            currentNode = currentNode->parent;
        }
    }


    void heapifyDown(Node* node) {
        Node* currentNode = node;

        while (true) {
            Node* maxNode = currentNode;

            if (currentNode->left != nullptr && currentNode->left->info < maxNode->info) {
                maxNode = currentNode->left;
            }

            if (currentNode->right != nullptr && currentNode->right->info < maxNode->info) {
                maxNode = currentNode->right;
            }

            if (maxNode == currentNode) {
                break;
            }

            std::swap(currentNode->info, maxNode->info);
            currentNode = maxNode;
        }
    }


    void preorderTraversal(Node* node, std::vector<min_heap>& result) const {
        if (node == nullptr) {
            return;
        }

        result.push_back(node->info);
        preorderTraversal(node->left, result);
        preorderTraversal(node->right, result);
    }


    void inorderTraversal(Node* node, std::vector<min_heap>& result) const {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left, result);
        result.push_back(node->info);
        inorderTraversal(node->right, result);
    }

    
    void destroyHeap(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroyHeap(node->left);
        destroyHeap(node->right);

        delete node;
    }
};
#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <random>
#include <fstream>
#include <stdexcept>

using namespace std;

template<typename T>
class StackTools {
public:

    struct Node {
        T data;
        Node* next;
    };

    struct Stack {
        Node* top;
    };

    Stack* stack;

    // // Declaración del operador de inserción de flujo como función amiga
    // friend std::ostream& operator<<(std::ostream& os, const StackTools<T>& stack) {

    //     vector<T> content = stack.return_stack();

    //     for (const T& item : content) {
    //         os << item << " ";
    //     }

    //     return os;
    // }

    // Constructor
    // StackTools(string filename = "") {
    StackTools() {
        stack = new Stack;
        stack->top = nullptr;

        // if (filename != "") {
        //     // Indicar el manejo de archivos internamente
        //     is_binary = true;

        //     // Verificar la extensión del archivo
        //     if (filename.substr(filename.find_last_of(".") +1) != "bin") {
        //         throw runtime_error("La extensión del archivo debe ser \".bin\"");
        //     }

        //     vector<T> content = read_from_file(filename);

        //     for (auto i = content.rbegin(); i != content.rend(); i++) {
        //         push(*i);
        //     }
        // }
    }

    // Destructor
    ~StackTools() {
        if (!empty()) {
            // if (is_binary) {
            //     write_to_file("temp.bin");
            //     rename("temp.bin", "data.bin");
            // }

            clear();
        }
        delete stack;
    }

    void push(T atom) {
        Node* newNode = new Node;
        newNode->data = atom;
        newNode->next = stack->top;
        stack->top = newNode;
    }

    T pop() {
        if (empty()) {
            throw runtime_error("No puede extraer elementos de una pila vacía");
        } else {
            Node* eliminatedNode = stack->top;
            T data = eliminatedNode->data;
            stack->top = eliminatedNode->next;
            delete eliminatedNode;

            return data;
        }
    }

    int size() {
        int len = 0;
        
        Node* currentNode = stack->top;

        while (currentNode != nullptr) {
            len++;
            currentNode = currentNode->next;
        }
        
        return len;
    }

    bool empty() {
        if (size() != 0) {
            return false;
        }

        return true;
    }

    void clear() {
        if (empty()) {
            throw runtime_error("No puede limpiar una pila vacía");
        } else {
            while (!empty()) {
                pop();
            }
        }
    }

    T peek() {
        return stack->top->data;
    }

    vector<T> return_stack() const  { 
        vector<T> content;

        Node* currentNode = stack->top;

        while (currentNode != nullptr) {
            content.push_back(currentNode->data);
            currentNode = currentNode->next;
        }

        return content;
    }

private:
    bool is_binary = false;

    // void write_to_file(string filename) {
    //     ofstream outfile(filename, ios::out | ios::binary);

    //     if (!outfile) {
    //         cerr << "Error al abrir el archivo " << filename << " para escritura binaria." << endl;
    //         return;
    //     }

    //     // Escribir la cantidad de elementos de la pila en el archivo
    //     int n = size();
    //     outfile.write(reinterpret_cast<char*>(&n), sizeof(n));

    //     // Escribir cada elemento de la pila en el archivo
    //     Node* currentNode = stack->top;
    //     while (currentNode != nullptr) {
    //         T data = currentNode->data;
    //         outfile.write(reinterpret_cast<char*>(&data), sizeof(T));
    //         currentNode = currentNode->next;
    //     }

    //     outfile.close();
    // }

    // vector<T> read_from_file(string filename) {
    //     vector<T> content;

    //     ifstream infile(filename, ios::in | ios::binary);

    //     if (!infile) {
    //         cerr << "Error al abrir el archivo " << filename << " para lectura binaria." << endl;
    //         return content;
    //     }

    //     // Leer la cantidad de elementos de la pila del archivo
    //     int n;
    //     infile.read(reinterpret_cast<char*>(&n), sizeof(n));

    //     // Leer cada elemento de la pila del archivo y agregarlo al vector
    //     for (int i = 0; i < n; i++) {
    //         T data;
    //         infile.read(reinterpret_cast<char*>(&data), sizeof(T));
    //         content.push_back(data);
    //     }

    //     infile.close();

    //     return content;
    // }
};


template<typename U>
class QueueTools {
public:
    struct Node {
        U data;
        Node* next;
    };

    struct Queue {
        Node* front;
        Node* back;
    };

    Queue* queue;

    // // Declaración del operador de inserción de flujo como función amiga
    // friend std::ostream& operator<<(std::ostream& os, const QueueTools<U>& queue) {

    //     vector<U> content = queue.return_queue();

    //     for (const U& item : content) {
    //         os << item << " ";
    //     }

    //     return os;
    // }

    // Constructor
    // QueueTools(string filename = "") {
    QueueTools() {
        queue = new Queue;
        queue->front = nullptr;
        queue->back = nullptr;

        // if (filename != "") {
        //     // Indicar el manejo de archivo internamente
        //     is_binary = true;

        //     // Verificar la extensión del archivo
        //     if (filename.substr(filename.find_last_of(".") +1) != "bin")  {
        //         throw runtime_error("La extensión del archivo debe ser \".bin\"");
        //     }

        //     vector<U> content = read_from_file(filename);

        //     for (auto i = content.rbegin(); i != content.rend(); i++) {
        //         push(*i);
        //     }
        // }
    }

    // Destructor
    ~QueueTools() {
        if (!empty()) {
            // if (is_binary) {
            //     write_to_file("temp.bin");
            //     rename("temp.bin", "data.bin");
            // }

            clear();
        }
        delete queue;
    }

    void push(U data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (empty()) {
            queue->front = newNode;
            queue->back = newNode;
        } else {
            queue->back->next = newNode;
            queue->back = newNode;
        }
    }

    U pop() {
        if (empty()) {
            throw runtime_error("No se puede extraer de una cola vacía.");
        } else {
            Node* currentNode = queue->front;
            U data = currentNode->data;

            if (queue->front == queue->back) { // La cola tiene un solo elemento
                queue->front = NULL;
                queue->back = NULL;
            } else {
                queue->front = currentNode->next;
            }

            delete currentNode;

            return data;
        }        
    }

    int size() {
        int count = 0;
        if (empty()) return count;
        else {
            Node* currentNode = queue->front;
        
            while (currentNode != NULL) {
                count++;
                currentNode = currentNode->next;
            }

            return count;
        }
    }

    bool empty() {
        if (queue->back == NULL) {
            return true;
        }

        return false;
    }

    void clear() {
        if (empty()) {
            throw runtime_error("No puede limpiar una cola vacía");
        } else {
            while(!empty()) {
                pop();
            }
        }
    }

    vector<U> return_queue() const { 
        vector<U> content;

        Node* currentNode = queue->front;

        while (currentNode != nullptr) {
            content.push_back(currentNode->data);
            currentNode = currentNode->next;
        }

        return content;
    }

    U firstIn() {
        U data = queue->front->data;
        return data;
    }
    
    U lastIn() {
        U data = queue->back->data;
        return data;
    }

private:
    bool is_binary = false;

    // void write_to_file(string filename) {
    //     ofstream outfile(filename, ios::out | ios::binary);

    //     if (!outfile) {
    //         cerr << "Error al abrir el archivo " << filename << " para escritura binaria." << endl;
    //         return;
    //     }

    //     // Escribir la cantidad de elementos de la cola en el archivo
    //     int n = size();
    //     outfile.write(reinterpret_cast<char*>(&n), sizeof(n));

    //     // Escribir cada elemento de la cola en el archivo
    //     Node* currentNode = queue->front;
    //     while (currentNode != nullptr) {
    //         U data = currentNode->data;
    //         outfile.write(reinterpret_cast<char*>(&data), sizeof(U));
    //         currentNode = currentNode->next;
    //     }

    //     outfile.close();
    // }

    // vector<U> read_from_file(string filename) {
    //     vector<U> content;

    //     ifstream infile(filename, ios::in | ios::binary);

    //     if (!infile) {
    //         cerr << "Error al abrir el archivo " << filename << " para lectura binaria." << endl;
    //         return content;
    //     }

    //     // Leer la cantidad de elementos de la cola del archivo
    //     int n;
    //     infile.read(reinterpret_cast<char*>(&n), sizeof(n));

    //     // Leer cada elemento de la cola del archivo y agregarlo al vector
    //     for (int i = 0; i < n; i++) {
    //         U data;
    //         infile.read(reinterpret_cast<char*>(&data), sizeof(U));
    //         content.push_back(data);
    //     }

    //     infile.close();

    //     return content;
    // }
};


template<typename V>
class ListTools {
public:

    struct Node {
        V data;
        Node* next;
    };

    struct List {
        Node* head;
    };

    List* list;

    // // Declaración del operador de inserción de flujo como función amiga
    // friend std::ostream& operator<<(std::ostream& os, const ListTools<V>& list) {

    //     vector<V> content = list.completeList();

    //     for (const V& item : content) {
    //         os << item << " ";
    //     }

    //     return os;
    // }

    // Constructor de clase
    ListTools(string filename = "") {
        list = new List;
        list->head = nullptr;

        if (filename != "") {
            // Verificar la extensión del archivo
            if (filename.substr(filename.find_last_of(".") +1) != "bin") {
                throw runtime_error("La extensión del archivo debe ser \".bin\"");
            }

            // Indicar el manejo de archivos internamente
            is_binary = true;
            cout << "Trabajando con archivos" << endl;

            vector<V> content = read_from_file(filename);

            std::reverse(content.begin(), content.end());

            for (auto i = content.rbegin(); i != content.rend(); i++) {
                append(*i);
            }
        }

        
    }

    // Destructor de clase
    ~ListTools() {
        if (!empty()) {
            if (is_binary) {
                write_to_file("temp.bin");
                rename("temp.bin", "data.bin");
            }

            clear();
        }
        delete list;
    }

    void append(V data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (empty()) {
            list->head = newNode;
        } else {
            Node* currentNode = list->head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    void insert(int index, V data) {
        if (index < 0 || index > size()) {
            throw out_of_range("Índice fuera de rango");
        }

        Node* newNode = new Node;
        newNode->data = data;

        if (index == 0) {
            newNode->next = list->head;
            list->head = newNode;
        } else {
            Node* prevNode = nullptr;
            Node* currentNode = list->head;

            for (int i = 0; i < index; i++) {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }

            prevNode->next = newNode;
            newNode->next = currentNode;
        }
    }

    V pop(int index = -1) {
        if (empty()) {
            throw runtime_error("No puede extraer elementos de una lista vacía");
        } else if (index < -1 || index >= size()) {
            throw out_of_range("Índice fuera de rango");
        } else {
            Node* eliminatedNode = nullptr;
            V data;

            if (index == -1) {
                // Extraer el último elemento
                Node* prevNode = nullptr;
                Node* currentNode = list->head;

                while (currentNode->next != nullptr) {
                    prevNode = currentNode;
                    currentNode = currentNode->next;
                }
                eliminatedNode = currentNode;
                data = eliminatedNode->data;
                
                if (prevNode != nullptr) {
                    prevNode->next = nullptr;
                } else {
                    list->head = nullptr;
                }
            } else if (index == 0) {
                // Extraer el primer elemento
                eliminatedNode = list->head;
                data = eliminatedNode->data;
                list->head = eliminatedNode->next;
            } else {
                // Extraer un elemento intermedio
                Node* prevNode = nullptr;
                Node* currentNode = list->head;
                for (int i = 0; i < index; i++) {
                    prevNode = currentNode;
                    currentNode = currentNode->next;
                }
                eliminatedNode = currentNode;
                data = eliminatedNode->data;
                prevNode->next = eliminatedNode->next;
            }

            delete eliminatedNode;
            return data;
        }
    }

    void remove(V data) {
        Node* prevNode = nullptr;
        Node* currentNode = list->head;

        while (currentNode != nullptr) {
            if (currentNode->data == data) {
                if (prevNode == nullptr) {
                    pop(0);
                } else if (currentNode->next == nullptr) {
                    pop();
                } else {
                    prevNode->next = currentNode->next;
                    delete currentNode;
                }
                return;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        throw runtime_error("Elemento no encontrado");
    }

    bool empty() {
        return list->head == nullptr;
    }

    void clear() {
        if (empty()) throw runtime_error("No se puede limpiar un lista vacía");
        else {
            while (!empty()) {
                pop();
            }
        }
    }

    void extend(List* newData) {
        Node* currentExtendedNode = newData->head;
        while(currentExtendedNode != nullptr) {
            V data = currentExtendedNode->data;
            append(data);
            currentExtendedNode = currentExtendedNode->next;
        }
    }

    int index(V value) {
        int i = 0;
        bool wit = false;
        Node* currentNode = list->head;

        while (currentNode != nullptr && wit == false) {
            i++;
            if (currentNode->data == value) {
                wit = true;
            } else {
                currentNode = currentNode->next;
            }
        }

        if (!wit) {
            throw runtime_error("Elemento no encontrado");
        } else {
            return i;
        }
    }

    int count(V value) {
        int times = 0;
        Node* currentNode = list->head;

        while (currentNode != nullptr) {
            times = currentNode->data == value ? times +1: times;
            currentNode = currentNode->next;
        }

        return times;
    }

    void reverse() {
        StackTools<V> reversedList;
        Node* currentNode = list->head;

        while (!empty()) {
            reversedList.push(pop(0));
        }

        while (!reversedList.empty()) {
            append(pop());
        }
    }

    int size() {
        int amount = 0;
        Node* currentNode = list->head;

        while (currentNode != nullptr) {
            amount++;
            currentNode = currentNode->next;
        }

        return amount;
    }

    vector<V> completeList() {
        vector<V> content;
        Node* currentNode = list->head;

        while (currentNode != nullptr) {
            content.push_back(currentNode->data);
            currentNode = currentNode->next;
        }

        return content;
    }

    void bubbleSort(char order) {
        if (empty() || list->head->next == nullptr) return;

        bool swapped;
        Node *ptr1 = list->head, *lptr = nullptr;
        int n = size();

        do {
            swapped = false;
            ptr1 = list->head;

            for (int i = 0; i < n - 1; i++) {
                Node *ptr2 = ptr1->next;

                if (order == '<' ? ptr1->data > ptr2->data : ptr1->data < ptr2->data) {
                    // intercambio de nodos
                    if (ptr1 == list->head) {
                        list->head = ptr2;
                    } else {
                        lptr->next = ptr2;
                    }

                    ptr1->next = ptr2->next;
                    ptr2->next = ptr1;

                    // actualizar punteros
                    lptr = ptr2;
                    ptr2 = ptr1->next;
                    swapped = true;
                } else {
                    lptr = ptr1;
                    ptr1 = ptr2;
                }
            }
            n--;
        } while (swapped);
    }

private:
    bool is_binary = false;

    void write_to_file(string filename) {
        ofstream outfile(filename, ios::out | ios::binary);

        if (!outfile) {
            cerr << "Error al abrir el archivo " << filename << " para escritura binaria." << endl;
            return;
        }

        // Escribir la cantidad de elementos de la lista en el archivo
        int n = size();
        outfile.write(reinterpret_cast<char*>(&n), sizeof(n));

        // Escribir cada elemento de la lista en el archivo
        Node* currentNode = list->head;
        while (currentNode != nullptr) {
            V data = currentNode->data;
            outfile.write(reinterpret_cast<char*>(&data), sizeof(V));
            currentNode = currentNode->next;
        }

        outfile.close();
    }

    vector<V> read_from_file(string filename) {
        vector<V> content;

        ifstream infile(filename, ios::in | ios::binary);

        if (!infile) {
            cerr << "Error al abrir el archivo " << filename << " para lectura binaria." << endl;
            return content;
        }

        // Leer la cantidad de elementos de la lista del archivo
        int n;
        infile.read(reinterpret_cast<char*>(&n), sizeof(n));

        // Leer cada elemento de la lista del archivo y agregarlo al vector
        for (int i = 0; i < n; i++) {
            V data;
            infile.read(reinterpret_cast<char*>(&data), sizeof(V));
            content.push_back(data);
        }

        infile.close();

        return content;
    }
};


template<typename P>
class BSTreeTools {
public:
    struct Node {
        P data;
        Node* left;
        Node* right;
    };

    struct Tree {
        Node* root;
    };

    Tree* tree;

    // // Declaración del operador de inserción de flujo como función amiga
    // friend std::ostream& operator<<(std::ostream& os, const TreeTools<P>& tree) {

    //     vector<P> content = tree.preorderTraversal();

    //     for (const P& item : content) {
    //         os << item << " ";
    //     }

    //     return os;
    // }

    // Constructor de clase
    // TreeTools(string filename = "") {
    BSTreeTools(string filename = "") {
        tree = new Tree;
        tree->root = nullptr;

        // if (filename != "") {
        //     // Indicar el manejo de archivos internamente
        //     is_binary = true;

        //     // Verificar la extensión del archivo
        //     if (filename.substr(filename.find_last_of(".") +1) != "bin") {
        //         throw runtime_error("La extensión del archivo debe ser \".bin\"");
        //     }

        //     vector<P> content = read_from_file(filename);

        //     for (auto i = content.rbegin(); i != content.rend(); i++) {
        //         insert(*i);
        //     }
        // }
    }

    // Destructor de clase
    ~BSTreeTools() {
        if (!empty()) {
            // if (is_binary) {
            //     write_to_file("temp.bin");
            //     rename("temp.bin", "data.bin");
            // }

            clear();
        }
        delete tree;
    }

    void insert(P data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (empty()) {
            tree->root = newNode;
        } else {
            Node* currentNode = tree->root;
            while (true) {
                if (data < currentNode->data) {
                    if (currentNode->left == nullptr) {
                        currentNode->left = newNode;
                        break;
                    } else {
                        currentNode = currentNode->left;
                    }
                } else if (data > currentNode->data) {
                    if (currentNode->right == nullptr) {
                        currentNode->right = newNode;
                        break;
                    } else {
                        currentNode = currentNode->right;
                    }
                } else {
                    delete newNode;
                    break;
                }
            }
        }
    }

    void pop(P value) {
        if(!find(value)) {
            throw runtime_error("No puede extraer un elemento que no existe");
        }

        vector<P> result = preorderTraversal();

        clear();

        for (auto i : result) {
            if (i != value) insert(i);
        }
    }

    bool find(P value) {
        vector<P> result = inorderTraversal();
        auto it = std::find(result.begin(), result.end(), value);
        return it != result.end() ? true : false;
    }

    bool empty() {
        return tree->root == nullptr ? true : false;
    }

    void clear(Node* node = nullptr) {
        if (node == nullptr) {
            node = tree->root;
        }

        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) clear(node->left);
        if (node->right != nullptr) clear(node->right);

        delete node;

        tree->root = nullptr;
    }


    int height(Node* node = nullptr) {
        if (node == nullptr) {
            node = tree->root;
        }
        
        int height = 0;
        int number_nodes = size(node);
        while (maxSize(height) < number_nodes) {
            height++;
        }

        return height;
    }

    int size(Node* node = nullptr) {
        if (node == nullptr) {
            node = tree->root;
        }

        int size = 0;
        vector<P> result = inorderTraversal(node);
        size = result.size();
        return size;
    }

    vector<P> preorderTraversal(Node* node = nullptr) {
        if (node == nullptr) {
            node = tree->root;
        }

        vector<P> result;

        if (empty()) {
            return result;
        }

        preorderTraversal(node, result);
        return result;
    }

    vector<P> inorderTraversal(Node* node = nullptr) {
        if (node == nullptr) {
            node = tree->root;
        }

        vector<P> result;

        if (empty()) {
            return result;
        }

        inorderTraversal(node, result);
        return result;
    }

    vector<P> postorderTraversal(Node* node = nullptr) {
        if (node == nullptr) {
            node = tree->root;
        }

        vector<P> result;

        if (empty()) {
            return result;
        }

        postorderTraversal(node, result);
        return result;
    }

    vector<vector<P>> amplitudeTraversal(Node* node = nullptr) {
        if (node == nullptr) {
            node = tree->root;
        }

        vector<vector<P>> result;

        if (empty()) {
            return result;
        }

        QueueTools<Node*> q;
        q.push(node);

        while (!q.empty()) {
            int size = q.size();
            vector<P> level;
            for (int i = 0; i < size; i++) {
                Node* current = q.firstIn();
                q.pop();
                level.push_back(current->data);
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            result.push_back(level);
        }

        return result;
    }

    P leastOf() {
        if (empty()) {
            throw runtime_error("El árbol está vacío");
        }

        return leastOf(tree->root)->data;
    }

    P greatestOf() {
        if (empty()) {
            throw runtime_error("El árbol está vacío");
        }

        return greatestOf(tree->root)->data;
    }

private:
    void preorderTraversal(Node* node, vector<P>& result) {
        if (node == nullptr) {
            return;
        }

        result.push_back(node->data);
        preorderTraversal(node->left, result);
        preorderTraversal(node->right, result);
    }

    void inorderTraversal(Node* node, vector<P>& result) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) inorderTraversal(node->left, result);
        result.push_back(node->data);
        if (node->right != nullptr) inorderTraversal(node->right, result);
    }

    void postorderTraversal(Node* node, vector<P>& result) {
        if (node == nullptr) {
            return;
        }

        postorderTraversal(node->left, result);
        postorderTraversal(node->right, result);
        result.push_back(node->data);
    }

    bool leaf(Node* node) {
        if (node->left == nullptr && node->right == nullptr) return true;
        return false;
    }

    int maxSize(int h) {
        int value = pow(2, h) -1;
        return value;
    }

    Node* leastOf(Node* node) {
        if (node->left == nullptr) {
            return node;
        }

        return leastOf(node->left);
    }

    Node* greatestOf(Node* node) {
        if (node->right == nullptr) {
            return node;
        }

        return greatestOf(node->right);
    }

    bool is_binary = false;

    // void write_to_file(string filename) {
    //     ofstream file(filename, ios::binary);

    //     if (!file.is_open()) {
    //         throw runtime_error("No se puede abrir el archivo");
    //     }

    //     vector<P> content = preorderTraversal();

    //     for (const P& item : content) {
    //         file.write(reinterpret_cast<const char*>(&item), sizeof(item));
    //     }

    //     file.close();
    // }


    // vector<P> read_from_file(string filename) {
    //     vector<P> content;
    //     std::ifstream input(filename, std::ios::binary);
    //     if (input) {
    //         while (true) {
    //             P value;
    //             input >> value;
    //             if (input.eof()) {
    //                 break;
    //             }
    //             content.push_back(value);
    //         }
    //         input.close();
    //     } else {
    //         throw runtime_error("Error al abrir el archivo");
    //     }

    //     return content;
    // }
};


class StringTools {
public:

    void filterString(string& input, const vector<char>& allowed_chars) {
        for (int index = input.size() - 1; index >= 0; index--) {
            char element = input[index];
            
            if (!inVectorFindElement(element, allowed_chars)) {
                input.erase(index, 1);
            }
        }
    }

    vector<string> splitString(const string& input, char splitter) {
        vector<string> output;
        string temp = "";

        for (int index = 0; index < input.size(); index++) {
            if (input[index] == splitter) {
                if (!temp.empty()) {
                    output.push_back(temp);
                    temp = "";
                }
            } else {
                temp += input[index];
            }
        }

        if (!temp.empty()) {
            output.push_back(temp);
        }

        return output;
    }

    /*
    La función "isNumber" solo verifica si la cadena es un número con un punto decimal opcional. Esto significa que no detectará números en notación científica o números con comas en lugar de puntos decimales. Si se desea una función más robusta para verificar si una cadena es un número, se puede considerar usar la biblioteca Boost para expresiones regulares o usar una biblioteca de análisis numérico.
    */
    bool isNumber(string input) {
        regex number_regex("^[+-]?[0-9]+([.][0-9]+)?$");
        return regex_match(input, number_regex);
    }

    bool isBinaryOperator(string input) {
        vector<string> binary_operators = {"+", "-", "*", "/", "^", "==", "!=", "<", ">", "<=", ">=", "&&", "||"};
        return find(binary_operators.begin(), binary_operators.end(), input) != binary_operators.end();
    }

    // Convierte la cadena a mayúsculas
    void toUpperCase(string& input) {
        transform(input.begin(), input.end(), input.begin(), ::toupper);
    }

    // Convierte la cadena a minúsculas
    void toLowerCase(string& input) {
        transform(input.begin(), input.end(), input.begin(), ::tolower);
    }

private:
    bool inVectorFindElement(char element, const vector<char>& container) {
        for (int i = 0; i < container.size(); i++) {
            if (container[i] == element) {
                return true;
            }
        }
        return false;
    }

    // Elimina los espacios en blanco al inicio y al final de la cadena
    void trim(string& input) {
        // Elimina los espacios en blanco al inicio
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }));

        // Elimina los espacios en blanco al final
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end());
    }

     // Reemplaza todas las ocurrencias de una subcadena por otra en la cadena de entrada
    void replaceAll(string& input, const string& search, const string& replace) {
        size_t pos = 0;
        while ((pos = input.find(search, pos)) != string::npos) {
            input.replace(pos, search.length(), replace);
            pos += replace.length();
        }
    }
};
#endif
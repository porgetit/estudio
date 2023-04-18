#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <random>

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

    // Constructor
    StackTools() {
        stack = new Stack;
        stack->top = nullptr;
    }

    // Destructor
    ~StackTools() {
        if (!empty()) clear();
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

    vector<T> return_stack() { 
        vector<T> content;

        Node* currentNode = stack->top;

        while (currentNode != nullptr) {
            content.push_back(currentNode->data);
            currentNode = currentNode->next;
        }

        return content;
    }
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

    // Constructor
    QueueTools() {
        queue = new Queue;
        queue->front = nullptr;
        queue->back = nullptr;
    }

    // Destructor
    ~QueueTools() {
        if (!empty()) clear();
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

    vector<U> return_queue() { 
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

    // Constructor de clase
    ListTools() {
        list = new List;
        list->head = nullptr;
    }

    // Destructor de clase
    ~ListTools() {
        if (!empty()) clear();
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
                prevNode->next = eliminatedNode->next
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

    void quickSort(char order) {
        if (order != '>' && order != '<') {
            throw std::invalid_argument("El parámetro de ordenamiento debe ser '<' o '>'");
        }
        if (list->head != nullptr) {
            Node* lastNode = list->head;
            while (lastNode->next != nullptr) {
                lastNode = lastNode->next;
            }
            quickSortList(list->head, lastNode, order);
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

private:

    void swapData(Node* a, Node* b) {
        V temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node* partition(Node* low, Node* high, char order) {
        V pivot = high->data;
        Node* i = low->prev;
        for (Node* j = low; j != high; j = j->next) {
            if ((order == '<' && j->data <= pivot) || (order == '>' && j->data >= pivot)) {
                i = (i == nullptr) ? low : i->next;
                swapData(i, j);
            }
        }
        i = (i == nullptr) ? low : i->next;
        swapData(i, high);
        return i;
    }

    void quickSortList(Node* low, Node* high, char order) {
        if (high != nullptr && low != high && low != high->next) {
            Node* pivot = partition(low, high, order);
            quickSortList(low, pivot->prev, order);
            quickSortList(pivot->next, high, order);
        }
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


class RandomTools {
public:
    RandomTools() : engine_(rd_()) {}

    int randomInt(int cota_a, int cota_b = 0) {
        std::uniform_int_distribution<int> dist(cota_a, cota_b);
        return dist(engine_);
    }

    std::vector<int> randomIntVector(int len, int cota_a, int cota_b = 0) {
        std::vector<int> vec;

        for (int i = 0; i < len; i++) {
            vec.push_back(randomInt(cota_a, cota_b));
        }

        return vec;
    }

    float randomFloat(float cota_a, float cota_b) {
        std::uniform_real_distribution<float> dist(cota_a, cota_b);
        return dist(engine_);
    }

    std::vector<float> randomFloatVector(int len, float cota_a, float cota_b) {
        std::vector<float> vec;

        for (int i = 0; i < len; i++) {
            vec.push_back(randomFloat(cota_a, cota_b));
        }

        return vec;
    }

    char randomChar() {
        std::uniform_int_distribution<int> dist(97, 122);
        char atom = (char) (dist(engine_));
        return atom;
    }

    std::string randomString(int len) {
        std::string data = "";

        for (int i = 0; i < len; i++) {
            data.push_back(randomChar());
        }

        return data;
    }

    bool randomBool() {
        std::uniform_int_distribution<int> dist(0, 1);
        bool truth = dist(engine_) == 1 ? true : false;
        return truth;
    }

private:
    std::random_device rd_;
    std::mt19937 engine_;
};
#endif
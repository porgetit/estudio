#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

template <typename max_priority_queue_type>
class MaxPriorityQueue {
public:
    typedef struct Data {
        max_priority_queue_type info;
        int priority;
    } Data;

    typedef struct Node {
        Data data;
        Node* left;
        Node* right;
        Node* parent;
    } Node;

private:
    Node* root;

public:
    MaxPriorityQueue() {
        root = nullptr;
    }

    ~MaxPriorityQueue() {
        destroyPirorityQueue(root);
    }

    
    void insert(const max_priority_queue_type& value, int priority) {
        Node* newNode = new Node;
        newNode->data.info = value;
        newNode->data.priority = priority;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr;

        if (empty()) {
            root = newNode;
        } else {
            Node* currentNode = root;
            queue<Node*> queue;
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

    
    max_priority_queue_type remove() {
        if (empty()) {
            throw out_of_range("Empty priority queue.");
        }

        max_priority_queue_type temp;

        if (root->left == nullptr && root->right == nullptr) {
            temp = root->data.info;
            delete root;
            root = nullptr;
            return temp;
        }

        if (root->left != nullptr || root->right != nullptr) {
            temp = root->data.info;
            vector<Data> tempData;
            Node* currentNode = root;
            queue<Node*> queue;
            queue.push(currentNode);

            // Almacenar todos los elementos en tempData excepto el elemento a eliminar
            while (!queue.empty()) {
                currentNode = queue.front();
                queue.pop();

                if (currentNode->left != nullptr) {
                    if (currentNode->left != currentNode) {
                        tempData.push_back(currentNode->left->data);
                    }
                    queue.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    if (currentNode->right != currentNode) {
                        tempData.push_back(currentNode->right->data);
                    }
                    queue.push(currentNode->right);
                }
            }

            // Limpiar la cola por completo
            destroyPirorityQueue(root);

            // Reconstruir la cola utilizando el vector tempData
            for (const auto& data : tempData) {
                insert(data.info, data.priority);
            }
        }


        return temp;
    }


    
    bool empty() const {
        return (root == nullptr);
    }

private:
    void heapifyUp(Node* node) {
        Node* currentNode = node;

        while (currentNode->parent != nullptr && currentNode->data.priority > currentNode->parent->data.priority) {
            std::swap(currentNode->data, currentNode->parent->data);
            currentNode = currentNode->parent;
        }
    }

    void heapifyDown(Node* node) {
        Node* currentNode = node;

        while (true) {
            Node* maxNode = currentNode;

            if (currentNode->left != nullptr && currentNode->left->data.priority > maxNode->data.priority) {
                maxNode = currentNode->left;
            }

            if (currentNode->right != nullptr && currentNode->right->data.priority > maxNode->data.priority) {
                maxNode = currentNode->right;
            }

            if (maxNode == currentNode) {
                break;
            }

            std::swap(currentNode->data, maxNode->data);
            currentNode = maxNode;
        }
    }

    
    void destroyPirorityQueue(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroyPirorityQueue(node->left);
        destroyPirorityQueue(node->right);
        delete node;
    }
};

int main() {
    MaxPriorityQueue<queue<int>> priorityQueue;
    vector<int> priorities = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        queue<int> taskQueue;
        for (int j = 0; j < 10; j++) {
            taskQueue.push((j + 1) * (i + 1));
        }
        priorityQueue.insert(taskQueue, priorities[i]);
    }

    while (!priorityQueue.empty()) {
        queue<int> taskQueue = priorityQueue.remove();
        while(!taskQueue.empty()) {
            cout << taskQueue.front() << " ";
            taskQueue.pop();
        }
        cout << endl;
    }
    
    return 0;
}

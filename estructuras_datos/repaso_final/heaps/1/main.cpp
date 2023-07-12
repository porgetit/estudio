#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Heap {
public:
    typedef struct Node {
        int info;
        Node* left;
        Node* right;
        Node* parent;
    } Node;

private:
    Node* root;

public:
    Heap() {
        root = nullptr;
    }

    ~Heap() {
        destroyHeap(root);
    }

    void insert(const int& value) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr;

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
                    queue.push(currentNode->left);
                }
            }

            // Ajustar el montículo
            heapifyUp(newNode);
        }
    }

    std::vector<int> preorderTraversal() const {
        std::vector<int> result;
        preorderTraversal(root, result);
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

    bool empty() const {
        return (root == nullptr);
    }

    void destroyHeap(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroyHeap(node->left);
        destroyHeap(node->right);

        delete node;
    }

    void preorderTraversal(Node* node, std::vector<int>& result) const {
        if (node == nullptr) {
            return;
        }

        result.push_back(node->info);
        preorderTraversal(node->left, result);
        preorderTraversal(node->right, result);
    }
};

int main() {
    Heap heap;

    // Insertar elementos en el montículo
    std::vector<int> data = {5, 9, 2, 1, 7};
    for (auto i : data) {
        heap.insert(i);
    }

    // Recorrido en preorden
    std::vector<int> preorderResult = heap.preorderTraversal();
    cout << "Recorrido en preorden: ";
    for (int value : preorderResult) {
        cout << value << " ";
    }
    cout << endl;
}
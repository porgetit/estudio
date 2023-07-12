#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

template <typename T>
class AVL {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        int height;

        Node(const T& k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }

    Node* balance(Node* node) {
        updateHeight(node);

        if (balanceFactor(node) < -1) {
            if (balanceFactor(node->right) > 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        if (balanceFactor(node) > 1) {
            if (balanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        return node;
    }

    Node* insert(Node* node, const T& key) {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;  // claves duplicadas no están permitidas

        return balance(node);
    }

    Node* findMin(Node* node) {
        if (node->left == nullptr)
            return node;
        return findMin(node->left);
    }

    Node* remove(Node* node, const T& key) {
        if (node == nullptr)
            return nullptr;

        if (key < node->key)
            node->left = remove(node->left, key);
        else if (key > node->key)
            node->right = remove(node->right, key);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMin(node->right);
                node->key = temp->key;
                node->right = remove(node->right, temp->key);
            }
        }

        if (node == nullptr)
            return nullptr;

        return balance(node);
    }

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->key << " ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(Node* node) {
        if (node != nullptr) {
            std::cout << node->key << " ";
            preorderTraversal(node->left);            
            preorderTraversal(node->right);
        }
    }

    void printGraphicalUtil(Node* node, int level) {
        if (node == nullptr)
            return;

        printGraphicalUtil(node->right, level + 1);

        if (level != 0) {
            std::cout << std::string(level - 1, '\t');
            std::cout << "|--";
        }

        std::cout << node->key << std::endl;

        printGraphicalUtil(node->left, level + 1);
    }

    void generateDotUtil(std::ofstream& file, Node* node) {
        if (node == nullptr)
            return;

        file << "  " << node->key << " [label=\"" << node->key << "\", shape=circle];" << std::endl;

        if (node->left != nullptr) {
            file << "  " << node->key << " -> " << node->left->key << ";" << std::endl;
            generateDotUtil(file, node->left);
        }

        if (node->right != nullptr) {
            file << "  " << node->key << " -> " << node->right->key << ";" << std::endl;
            generateDotUtil(file, node->right);
        }
    }

    int getNodeCount(Node* node) {
        if (node == nullptr)
            return 0;
        return 1 + getNodeCount(node->left) + getNodeCount(node->right);
    }

    bool isBalanced(Node* node) {
        if (node == nullptr)
            return true;

        int balanceFactorVal = balanceFactor(node);
        if (balanceFactorVal < -1 || balanceFactorVal > 1)
            return false;

        return isBalanced(node->left) && isBalanced(node->right);
    }

public:
    AVL() : root(nullptr) {}

    void insert(const T& key) {
        root = insert(root, key);
    }

    void remove(const T& key) {
        root = remove(root, key);
    }

    void printInorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
    
    void printPreorder() {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void printGraphical() {
        printGraphicalUtil(root, 0);
    }

    void generateDotFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        file << "digraph AVLTree {" << std::endl;
        generateDotUtil(file, root);
        file << "}" << std::endl;

        file.close();
    }

    void generateDotFileAndPNG(const std::string& dotFilename, const std::string& pngFilename) {
        generateDotFile(dotFilename);

        // Generar el archivo PNG usando el comando de GraphViz
        std::string command = "dot -Tpng " + dotFilename + " -o " + pngFilename;
        int result = std::system(command.c_str());
        if (result != 0) {
            std::cerr << "Error converting DOT file to PNG." << std::endl;
            return;
        }

        std::cout << "Generated PNG file: " << pngFilename << std::endl;
    }

    int getNodeCount() {
        return getNodeCount(root);
    }

    bool isBalanced() {
        return isBalanced(root);
    }
};

int main() {
    AVL<int> tree;

    std::srand(std::time(nullptr));

    for (int i = 0; i < 10000; i++) {
        int value = std::rand() % 556;  // Genera números aleatorios entre 0 y 555
        tree.insert(value);
    }

    std::cout << "Recorrido en orden del árbol AVL:" << std::endl;
    tree.printInorder();

    int nodeCount = tree.getNodeCount();
    std::cout << "Número de nodos en el árbol: " << nodeCount << std::endl;

    bool isBalancedBefore = tree.isBalanced();
    std::cout << "¿Es el árbol AVL equilibrado antes de la eliminación? " << (isBalancedBefore ? "Sí" : "No") << std::endl;

    // Eliminar al menos 10 nodos del árbol
    for (int i = 0; i < 100; i++) {
        int value = std::rand() % 556;
        tree.remove(value);
        std::cout << "Nodo eliminado con valor " << value << std::endl;
    }

    bool isBalancedAfter = tree.isBalanced();
    std::cout << "¿Es el árbol AVL equilibrado después de la eliminación? " << (isBalancedAfter ? "Sí" : "No") << std::endl;

    std::string dotFilename = "tree.dot";
    std::string pngFilename = "tree.png";

    tree.generateDotFileAndPNG(dotFilename, pngFilename);

    return 0;
}


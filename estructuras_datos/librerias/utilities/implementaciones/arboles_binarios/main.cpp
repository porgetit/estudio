#include <iostream>
#include "../../utilities.h"

int main() {
    TreeTools<int> myTree;

    myTree.insert(10);
    myTree.insert(5);
    myTree.insert(15);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(13);
    myTree.insert(17);

    std::cout << "Inorder traversal: ";
    for (auto i : myTree.inorderTraversal()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    for (auto i : myTree.preorderTraversal()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    for (auto i : myTree.postorderTraversal()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Tree size: " << myTree.size() << std::endl;
    std::cout << "Tree height: " << myTree.height() << std::endl;

    int popped = 5;
    myTree.pop(popped);
    std::cout << "Popped node value: " << popped << std::endl;

    std::cout << "Inorder traversal after popping node: ";
    for (auto i : myTree.inorderTraversal()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    if (myTree.find(15)) {
        std::cout << "15 found in tree" << std::endl;
    } else {
        std::cout << "15 not found in tree" << std::endl;
    }

    if (myTree.find(20)) {
        std::cout << "20 found in tree" << std::endl;
    } else {
        std::cout << "20 not found in tree" << std::endl;
    }

    return 0;
}

#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Node {
public:
    Node(int value, Node* left, Node* right) {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const {
        return value;
    }

    Node* getLeft() const {
        return left;
    }

    Node* getRight() const {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree {
public: 
    static bool contains(const Node& root, int value) {
        // throw std::logic_error("Waiting to be implemented");
        Node current = root;
        while (true) {
            if (current.getValue() == value) return true;
            else if (current.getValue() < value) {
                if (current.getRight() == NULL) return false;
                current = *current.getRight();
            }
            else {
                if (current.getLeft() == NULL) return false;
                current = *current.getLeft();
            }
        }
        return false;
    }
};

#ifndef RunTests
int main() {
    Node n1(1, NULL, NULL);
    Node n3(3, NULL, NULL);
    Node n2(2, &n1, &n3);

    std::cout << BinarySearchTree::contains(n2, 1) << endl;
    std::cout << BinarySearchTree::contains(n2, 3) << endl;
    std::cout << BinarySearchTree::contains(n2, 5) << endl;
}
#endif
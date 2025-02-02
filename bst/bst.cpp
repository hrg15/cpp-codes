#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    void printPreorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    void printPostorder(Node* node) {
        if (node == nullptr) return;
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }

    void printInorder(Node* node) {
        if (node == nullptr) return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    Node* findNode(Node* node, int value) {
        if (node == nullptr || node->data == value) return node;
        if (value < node->data) return findNode(node->left, value);
        return findNode(node->right, value);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        newNode->parent = parent;
        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    void printPreorder() {
        printPreorder(root);
        cout << endl;
    }

    void printPostorder() {
        printPostorder(root);
        cout << endl;
    }

    void printInorder() {
        printInorder(root);
        cout << endl;
    }

    void rightChild(int value) {
        Node* node = findNode(root, value);
        if (node == nullptr || node->right == nullptr) {
            cout << "Null" << endl;
        } else {
            cout << node->right->data << endl;
        }
    }

    void leftChild(int value) {
        Node* node = findNode(root, value);
        if (node == nullptr || node->left == nullptr) {
            cout << "Null" << endl;
        } else {
            cout << node->left->data << endl;
        }
    }

    void parentNode(int value) {
        Node* node = findNode(root, value);
        if (node == nullptr || node->parent == nullptr) {
            cout << "Null" << endl;
        } else {
            cout << node->parent->data << endl;
        }
    }
};

void processCommands(BinarySearchTree& bst, int numCommands) {
    for (int i = 0; i < numCommands; ++i) {
        string command;
        cin >> command;

        if (command == "add") {
            int value;
            cin >> value;
            bst.add(value);
        } else if (command == "right") {
            int value;
            cin >> value;
            bst.rightChild(value);
        } else if (command == "left") {
            int value;
            cin >> value;
            bst.leftChild(value);
        } else if (command == "MrUpHead") {
            int value;
            cin >> value;
            bst.parentNode(value);
        } else if (command == "print_preorder") {
            bst.printPreorder();
        } else if (command == "print_postorder") {
            bst.printPostorder();
        } else if (command == "print_inorder") {
            bst.printInorder();
        } else {
            cout << "Invalid command" << endl;
        }
    }
}

int main() {
    BinarySearchTree bst;

    int numCommands;
    cin >> numCommands;
    processCommands(bst, numCommands);

    return 0;
}

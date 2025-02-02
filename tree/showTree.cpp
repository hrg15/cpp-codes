#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node{
    int value; 
    Node* left;
    Node* right;

    Node(int val): value(val), right(nullptr), left(nullptr) {};
};

Node* findMin(Node* root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == nullptr) return root;

    if(key < root->value){
        root->left = deleteNode(root->left , key);
    }else if(key > root->value){
        root->right = deleteNode(root->right, key);
    }else{

        if(root->left == nullptr && root->right == nullptr){
            delete root; 
            return nullptr;
        }else if(root->left == nullptr){
            Node* right = root->right;
            delete root;
            return right;
        }else if(root->right == nullptr) {
            Node* left = root->left;
            delete root;
            return left;
        }else{
            Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    return root;
}

Node* insert(Node* root, int key){
    if(root == nullptr){
        return new Node(key);
    }
    Node* current = root;

    while (true){
        if(key < current->value){
            if(current->left == nullptr){
                current->left = new Node(key);
                break;
            }else{
                current = current->left;
            }
        }else if (key > current->value){
            if(current->right == nullptr){
                current->right = new Node(key);
                break;
            }else{
                current = current->right;
            }
        }else{
            break;
        }
    }

    return root;
}

Node* insertRecursive(Node* root, int key){
    if(root == nullptr){
        return new Node(key);
    }
    if(key < root->value){
        root->left = insert(root->left, key);
    }else if(key > root->value){
        root->right = insert(root->right, key);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

void deleteMin(Node* root){
    Node* r = root;
    Node* parent = nullptr;

    while (r->left){
        parent = r;
        r = r->left;
    }
    if(parent){
        parent->left = r->right;
    }else{
        root = r->right;
    }
    delete r;
}

int main(){
  Node* root = nullptr;
    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Original Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 50);
    cout << "After Deletion (Inorder): ";
    inorderTraversal(root);

    root = insertRecursive(root, 85);
    cout << "\nAfter Insert (Inorder): ";
    inorderTraversal(root);


    cout << endl;
    return 0;
}
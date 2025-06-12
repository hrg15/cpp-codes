#include <iostream>
using namespace std;
struct Node {
  int data;
  Node *next;

  // Node(int val):  data(val), next(nullptr) {};
};

Node *getNode() {
  Node *newNode;
  newNode = new Node;
  newNode->next = nullptr;
  return newNode;
};

class linkedList {
public:
  Node *head;
  linkedList() : head(nullptr) {};

  bool isEmpty() { return head == nullptr; };

  void insertAtBeginning(int val) {
    Node *newNode = getNode();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
  };

  void deleteBeginning() {
    Node *ptr;
    ptr = head;
    head = head->next;
    delete ptr;
  };

  void insertAtEnd(int val) {
    Node *newNode = getNode();
    newNode->data = val;
    if (isEmpty()) {
      head = newNode;
      return;
    };

    Node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    };
    current->next = newNode;
  };

  void deleteElement(int val) {
    if (isEmpty()) {
      cout << "Nothing to delete.";
    }
    if (val == head->data) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    };

    Node *current = head;
    while (current->next != nullptr && current->next->data != val) {
      current = current->next;
    }

    if (current != nullptr) {
      Node *temp = current->next;
      current->next = temp->next;
      delete temp;
    } else {
      cout << "Element not found.";
    }
  }
  bool search(int val) {
    Node *current = head;
    while (current != nullptr) {
      if (current->data == val) {
        return true;
      }
      current = current->next;
    }
    return false;
  }
  ~linkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
    head = nullptr;
  }
  void printList();
};

void linkedList::printList() {
  Node *current = head;
  while (current != nullptr) {
    cout << current->data << " -> ";
    current = current->next;
  }
}

void printRecursive(Node *l) {
  if (l != nullptr) {
    printRecursive(l->next);
    cout << l->data << " -> ";
  }
};

int main() {
  linkedList list;

  list.insertAtBeginning(3);
  list.insertAtBeginning(2);
  list.insertAtBeginning(1);
  list.insertAtEnd(85);
  list.printList();
  printRecursive(list.head);
  bool result = list.search(85);
  if (result) {
    cout << "Found!";
  } else {
    cout << "Not Found.";
  }
  return 0;
}

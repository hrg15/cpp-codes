#include <iostream>
#include <string>
using namespace std;

#define N 10

class Stack {
private:
  int myTop;
  int stack[N];

public:
  Stack() { myTop = -1; };

  bool isEmpty() { return myTop == -1; };
  bool isFull() { return myTop == N - 1; };
  void push(int val);
  int pop();
  void print();
};

void Stack::push(int val) {
  if (Stack::isFull()) {
    cout << "Stack is full!";
    return;
  }
  stack[++myTop] = val;
};

int Stack::pop() {
  if (Stack::isEmpty()) {
    cout << "Stack is empty!";
    return 0;
  };
  return stack[myTop--];
};

void Stack::print() {
  if (Stack::isEmpty()) {
    cout << "Stack is empty";
    return;
  };
  cout << "The stack elements:";
  for (int i = myTop; i >= 0; i--) {
    cout << stack[i] << ", ";
  }
};

int main() {
  Stack s;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  s.pop();
  s.print();

  return 0;
}

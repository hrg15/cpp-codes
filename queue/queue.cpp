#include <iostream>
using namespace std;
#define MAXQUEUE 50

class Queue {

private:
  int items[MAXQUEUE];
  int front, rear;

public:
  Queue() { front = rear = -1; };
  bool empty() { return rear == front; };
  void addQueue(int item);
  int delQueue();
  int process();
};

void Queue::addQueue(int item) {
  if (rear == MAXQUEUE - 1) {
    cout << "Queue is full";
    return;
  }
  items[++rear] = item;
};

int Queue::delQueue() {

  if (empty()) {
    cout << "Queue is empty";
    return;
  };

  return items[front++];
}

int main() { return 0; };
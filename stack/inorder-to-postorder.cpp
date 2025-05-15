#include <iostream>
using namespace std;

int precedence(char op) {
  if (op == '^') {
    return 3;
  }
  if (op == '*' || op == '/' || op == '%') {
    return 2;
  }
  if (op == '+' || op == '-') {
    return 1;
  }

  return 0;
}

bool isRightAssociative(char op) { return op == '^'; }

string infixToPostfix(string infix) {
  stack<char> s;
  string output;

  for (int i = 0; i < infix.length(); i++) {
    if (isalnum(infix[i])) {
      output += infix[i];
    } else if (infix[i] == '(') {
      s.push(infix[i]);
    } else if (infix[i] == ')') {
      while (!s.empty() && s.top() != '(') {
        output += s.top();
        s.pop();
      };
      s.pop();
    } else {
      while (!s.empty() && (precedence(s.top()) > infix[i]) ||
             (precedence(s.top()) == precedence(infix[i])) && s.top() != '(') {
        output += s.top();
        s.pop();
      }
      s.push(infix[i]);
    }
  }

  while (!s.empty()) {
    output += s.top();
    s.pop();
  }

  return output;
};

int main() { return 0; }
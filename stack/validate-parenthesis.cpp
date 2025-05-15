#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
  return (open == '(' && close == ')') || (open == '{' && close == '}') ||
         (open == '[' && close == ']');
};

bool isValidParenthesis(string expr) {
  stack<char> s;

  for (char ch : expr) {
    if (ch == '(' || ch == '{' || ch == '[') {
      s.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {

      if (s.empty() || !isMatching(s.top(), ch)) {
        return false;
      }
      s.pop();
    }
  }

  return s.empty();
};

int main() {
  string expr = "{[()]}";

  if (isValidParenthesis(expr)) {
    cout << "Valid" << endl;
  } else {
    cout << "Not Valid" << endl;
  }

  return 0;
}
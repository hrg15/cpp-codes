#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
    
    Node(char val): data(val), left(nullptr), right(nullptr) {};
};

int evaluate(Node* root){
    if(!root) return 0;

    if(!root->left && !root->right){
        return root->data - '0';
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    switch (root->data){
    case '+': return leftValue + rightValue;
    case '-': return leftValue + rightValue;
    case '*': return leftValue + rightValue;
    case '/': return leftValue + rightValue;
    default:
        break;
    }
    return 0;
};

Node* buildExpressionTree(const string& expression){
    stack<Node*> nodes;
    stack<char> operators;

    for(char ch : expression){
        if(ch == '('){
            continue;
        }else if(isalnum(ch)){
            nodes.push(new Node(ch));
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            operators.push(ch);
        }else if(ch == ')'){
            if(!operators.empty() && nodes.size() >= 2 ){
                char op = operators.top();
                operators.pop();

                Node* rightNode = nodes.top();
                nodes.pop();

                Node* leftNode = nodes.top();
                nodes.pop();

                Node* newNode = new Node(op);
                newNode->left = leftNode;
                newNode->right = rightNode;

                nodes.push(newNode);
            }
        }
    }

    return nodes.empty() ? nullptr : nodes.top();
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(const string& expression){
    stack<char> operators;
    string result;

    for(char ch : expression){
        if(isalnum(ch)){
            result += ch;
        }else if(ch == '('){
            operators.push(ch);
        }else if(ch == ')'){
            while (!operators.empty() && operators.top() != '('){   
                result += operators.top();
                operators.pop();
            }
            if(!operators.empty() && operators.top() == '('){
                operators.pop();
            }
        }else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)){
                result += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()){
        result += operators.top();
        operators.pop();
    }
    return result;
}
int main() {
    string expression = "((a+b)*(c-d))";
    Node* root = buildExpressionTree(expression);
    
    cout << "Preorder Traversal of Expression Tree: ";
    preorder(root);
    cout << endl;
    
    string postfix = infixToPostfix(expression);

    cout << "Postfix Expression: " << postfix << endl;
  
    return 0;
}

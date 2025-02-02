#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeEquals(const string& input) {
    stack<char> st;

    for (char ch : input) {
        if (ch != '=') {
            st.push(ch); 
    }
}
    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    string output = removeEquals(input);
    cout << "Output: " << output << endl;

    return 0;
}

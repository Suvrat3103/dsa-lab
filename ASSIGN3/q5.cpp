#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evalPostfix(string exp) {
    stack<int> st;
    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0'); // convert char to int
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp = "231*+9-";  // equivalent to 2 + 3*1 - 9
    cout << "Postfix: " << exp << endl;
    cout << "Evaluated Value: " << evalPostfix(exp) << endl;
}
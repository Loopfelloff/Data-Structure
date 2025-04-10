#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int precedence(char op) { // this function is to check the associativity although if we have simple expression like + - * / then we don't need this function we can just check if it is * or / and then pop it however if we have exponential function off conditoins then this function is used as it is expandable.
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;  // Lowest precedence
}

int main() {
    stack<char> st;
    string expression = "(A+B-C/D)*E+(F-G)/H";
    string postfix = "";

    for (int i = expression.length()-1; i >=0; i--) {
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z')) {
            postfix += expression[i];  // Append operand
        } 
        else if (expression[i] == ')') {
            st.push(expression[i]);  // Push opening parenthesis
        } 
        else if (expression[i] == '(') {
            // Pop operators until '(' is found
            while (!st.empty() && st.top() != ')') {
                postfix += st.top();
                st.pop();
            }
            st.pop();  // Remove '('
        }  
        else {
            // Pop operators with higher or equal precedence
            while (!st.empty() && (precedence(expression[i]) < precedence(st.top())) && st.top() != ')') { /// if smaller than or equal to ko satta smaller than matra rakhyo vane feri associativity follow hudaina btw ani associativity ko thakka ulto aauxa expression.
                postfix += st.top();
                st.pop();
            }
            st.push(expression[i]);  // Now push the current operator
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    reverse(postfix.begin() , postfix.end());
    cout << postfix << endl;
    return 0;
}

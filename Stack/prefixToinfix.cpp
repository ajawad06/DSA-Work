#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return -1;
}
bool isOperator(char op){
    return (op=='+' || op=='-' ||op=='*'||op=='^'||op=='/');
}

string infixToPostfix(string infix){
    string postfix;
    stack<char> s;
    for (int i=0;i<infix.length();i++){
        char c=infix[i];
        if (c==' ') continue;
        else if (isalnum(c)) postfix+=c;
        else if (c=='(') s.push(c);
        else if (c==')') {
            while (!s.empty() && s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // pop '('
        }
        else if (isOperator(c)){
            while (!s.empty() && precedence(c)<=precedence(s.top())){
                if (c == '^' && s.top() == '^') break; 
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}

string infixToPrefix(string infix){
    string postfix;
    // 1. Reverse infix
    reverse(infix.begin(),infix.end());
    // 2. Swap brackets
    for (int i=0;i<infix.length();i++){
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    // 3. Postfix
    postfix=infixToPostfix(infix);
    // 4. Reverse postfix
    reverse(postfix.begin(),postfix.end());
    return postfix;
}

int main() {
    string infix="(A + B) * C";
    string prefix = infixToPrefix(infix);
    cout << "Postfix expression: " << prefix << endl;
    return 0;
}
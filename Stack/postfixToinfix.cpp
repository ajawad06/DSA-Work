#include <iostream>
#include <stack>
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
        // 1. space
        if (c==' ') continue;
        // 2. alphabet or number
        else if (isalnum(c)) postfix+=c;
        // 3. opening bracket
        else if (c=='(') s.push(c);
        // 4. closing bracket
        else if (c==')') {
            while (!s.empty() && s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // pop '('
        }
        // 5. operator
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

int main() {
    string infix="A + B * C - D / E";
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
#include<iostream>
#include<stack>
#include<string>

using namespace std;

class calci {
public:
    int precedence(char op) {
        if(op=='+'||op=='-') return 1;
        if(op=='*'||op=='/') return 2;
        if(op=='^') return 3; 
        return 0;
    }

    bool isOperator(char ch) {
        return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='^');
    }

    string InToPost(string infix) {
        stack<char> s;
        string postfix="";

        for(char c:infix) {
            if(isalnum(c)) {
                postfix+=c;
            } 
            else if(c=='(') {
                s.push(c);
            } 
            else if(c==')') {
                while(!s.empty()&&s.top()!='(') {
                    postfix+=s.top();
                    s.pop();
                }
                s.pop();
            } 
            else if(isOperator(c)) {
                while(!s.empty()&&precedence(s.top())>=precedence(c)) {
                    postfix+=s.top();
                    s.pop();
                }
                s.push(c);
            }
        }

        while(!s.empty()) {
            postfix+=s.top();
            s.pop();
        }

        return postfix;
    }
};

int main() {
    calci c;
    string infix;
    cout<<"\nEnter infix expression: ";
    cin>>infix;

    string postfix=c.InToPost(infix);

    cout<<"\nPostfix expression is: "<<postfix<<endl;

    return 0;
}

#include<iostream>
#include<cctype>
#include<cstring>
#define MAX 100
using namespace std;

struct stack {
    int top=-1;
    char stack[MAX];
} ss;

class priyanka {
public:

    char pop() {
        if(ss.top==-1) {
            cout<<"UNDERFLOW"<<endl;
            return '\0';
        } else {
            return ss.stack[ss.top--];
        }
    }

    void push(char x) {
        if(ss.top==MAX-1) {
            cout<<"OVERFLOW"<<endl;
        } else {
            ss.top++;
            ss.stack[ss.top]=x;
        }
    }
};

bool isPalindrome(char s1[]) {
    priyanka p;
    char processed[MAX];
    int j=0;

    for(int i=0;i<strlen(s1);i++) {
        char c=s1[i];
        if(isalpha(c)) {
            processed[j++]=tolower(c);
            p.push(tolower(c));
        }
    }

    processed[j]='\0';

    for(int i=0;i<j;i++) {
        cout<<processed[i];
        if(processed[i]!=p.pop()) {
            return false;
        }
    }

    return true;
}

int main() {
    char s1[MAX];
    cout<<"Enter the string: ";
    cin.getline(s1,MAX);

    if(isPalindrome(s1)) {
        cout<<"\nThe string is a palindrome."<<endl;
    } else {
        cout<<"\nThe string is not a palindrome."<<endl;
    }

    return 0;
}

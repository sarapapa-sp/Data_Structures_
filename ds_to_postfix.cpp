//
// Created by sarapapa on 9/6/2021.
//
// Expression to Post fix notation

#include <iostream>
#include <bits/stdc++.h>              //to use the stack
using namespace std;

int valop(char c);                   // check the precedence of the operators
void intopost(string s);             // converting to postfix

int main(){
    cout<<"Infix to Postfix\n";
    string s;
    cout<<"Enter the expression :";
    cin>>s;
    intopost(s);
    return 0;
}
int valop(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return 0;
}
void intopost(string s){
    char ch;        // to read every character
    string opstr;   //for output
    stack<char> st; //declare the stack with variable st
    for(int i=0;i<s.length();i++){
        ch=s[i];
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
            opstr+=ch;
        else if(ch=='(')
            st.push('(');
        else if(ch==')'){
            while(st.top()!='('){
                opstr+=st.top();
                st.pop();
            }
        }else{
            if(st.empty())
                st.push(ch);
            else{
                while(!st.empty() && valop(ch)<=valop(st.top())){
                    opstr += st.top();
                    st.pop();
                }
                st.push(ch);
            }

        }
    }
    while(!st.empty()){
        if(st.top()!='(')
            opstr+=st.top();
        st.pop();
    }
    cout<<"Postfix expression is : "<<opstr;
}

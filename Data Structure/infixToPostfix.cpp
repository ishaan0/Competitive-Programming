#include<bits/stdc++.h>
using namespace std ;

int prec(char ch){
    switch(ch){
    case '^':
        return 3 ;
    case '*':
    case '/':
        return 2 ;
    case '+':
    case '-':
        return 1 ;
    }
}

string infixToPostfix(string str){
    stack<char> stk ;
    string postfix = "" ;
    stk.push('(') ;

    for(int i=0;i<str.size();i++){
        if(isalpha(str[i]))
            postfix += str[i] ;
        else if(str[i] == '(')
            stk.push('(') ;
        else if(str[i] == ')'){
            while( stk.top() != '('){
                postfix += stk.top() ;
                stk.pop() ;
            }

            stk.pop();
        }
        else{
            while(stk.top() != '(' && prec(str[i]) <= prec(stk.top())){
                postfix += stk.top() ;
                stk.pop() ;
            }
            stk.push(str[i]) ;
        }
    }
    while(stk.top() != '('){
        postfix += stk.top() ;
        stk.pop() ;
    }
    return postfix ;
}


int main(){

    string str ;
    cin>> str ;
    cout<< infixToPostfix(str) << endl;
    //cout<< prec('*') << " " <<prec('+' ) ;

    return 0 ;
}

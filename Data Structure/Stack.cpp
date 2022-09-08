#include<bits/stdc++.h>
using namespace std;

#define Max 100

/***** Stack Body *****/
class Stack{
    int top,arr[Max];
public:
    Stack(){top=0;}
    void push(int item);
    void pop();
    int peek();
    bool Empty();
    int length();
};

/***** Push *****/
void Stack:: push(int item){
    if(top < Max){
        arr[top] = item;
        top++;
    }
    else
        cout<< "Stack is full.." << endl;
}

/***** Pop *****/
void Stack:: pop(){
    if(top == 0)
        cout<< "Stack is empty.." << endl;
    else
        top--;
}

/***** Peek *****/
int Stack:: peek(){
    if(top == 0)
        cout<< "Stack is empty.." << endl;
    else
        return arr[top-1];
}

/***** Check Empty *****/
bool Stack:: Empty(){
    if(top == 0)
        return true;
    else
        return false;
}

/***** Stack Length *****/
int Stack:: length(){
    return top;
}

int main(){


    return 0;
}

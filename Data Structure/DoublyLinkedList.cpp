#include<bits/stdc++.h>
using namespace std;


/**** class body ****/

class node{
public:
    int data;
    node *next;
    node *prev;
};


class linkList{
    node* head,*tail;
public:
    linkList(){head = tail = NULL;}
    void pushBack(int data);
    void pushFront(int data);
    void insertAt(int pos,int data);
    void removeAt(int pos);
    void removeFront();
    void removeBack();
    void printFront();
    void printReverse();
};

/****  Push Back ****/
void linkList:: pushBack(int data){
    node* newNode = new node;

    newNode->data = data ;
    newNode->next = NULL ;

    if(head == NULL){
        newNode->prev = NULL ;
        head = newNode ;
        tail = newNode ;
    }
    else{
        newNode->prev = tail ;
        tail->next = newNode ;
        tail = newNode ;
    }
}

/**** Push Front ****/
void linkList:: pushFront(int data){
    node* newNode = new node ;

    newNode->data = data ;
    newNode->prev = NULL ;
    newNode->next = head ;
    head->prev = newNode ;

    head = newNode ;
    if(tail == NULL)
        tail = head ;
}

/**** Insert At ****/
void linkList:: insertAt(int pos,int data){
    node* newNode = new node ;
    node* currentNode = new node ;

    currentNode = head ;
    newNode->data = data ;

    int i(0) ;
    while(currentNode != NULL){
        if(++i == pos){
            currentNode->prev->next = newNode;
            newNode->prev = currentNode->prev ;
            newNode->next = currentNode ;
            currentNode->prev = newNode ;
            return ;
        }
        else currentNode = currentNode->next ;
    }

    if(i == 0)
        cout<< "List is empty !!!" << endl;
    else
        cout<< "Position is out of range ..." << endl;
}

/**** remove At ****/
void linkList:: removeAt(int pos){
    node* currentNode = new node ;
    int i(0) ;

    while(currentNode != NULL){
        if(++i == pos){
            currentNode->prev->next = currentNode->next ;
            currentNode->next->prev = currentNode->prev ;
            return  ;
        }
        else    currentNode = currentNode->next ;

    }

    if(i == 0)
        cout<< "List is empty !!!" << endl;
    else
        cout<< "Position is out of range ..." << endl;

}

/**** Remove Front ****/
void linkList:: removeFront(){
    if(head == NULL){
        cout<< "The list is empty..." << endl;
        return  ;
    }

    head = head->next ;
    head->prev = NULL ;

}

/**** Remove Back ****/
void linkList:: removeBack(){
    if(tail == NULL){
        cout<< "The list is empty... " << endl;
        return ;
    }

    tail = tail->prev ;
    tail->next = NULL ;
}

/**** Print Front ****/
void linkList:: printFront(){
    node* currentNode = head ;

    while(currentNode != NULL){
        cout<< currentNode->data << " ";
        currentNode = currentNode->next ;
    }
    cout<< endl;
}

/**** Print Reverse ****/
void linkList:: printReverse(){
    node* currentNode = tail ;

    while(currentNode != NULL){
        cout<< currentNode->data << " " ;
        currentNode = currentNode->prev ;
    }
    cout<< endl;
}


int main(){


    return 0;
}

#include<bits/stdc++.h>
using namespace std;


/**
    *** Linked list operation ***

    # insertion
            * Insert Front
            * Insert Back
            * Insert After A Node
    # deletion
            * delete Front
            * delete Back
            * delete A Position
    # print data
    # Search data
    # Mid data
    # Reverse linked list

**/



/**** class body ****/

class node{
public:
    int data;
    node *next;
};


class linklist{
    node* head,*tail;
public:
    linklist(){head = tail = NULL;}
    void pushback(int data);
    void pushfront(int data);
    void insert_after(int key,int data);
    void remove_item(int position);
    void remove_front();
    void remove_back();
    void mid_data();
    bool ispresent(int key);
    void print();
    void reverse_list();

};

/**** Linked list all functions ****/

/**** push front ****/
void linklist:: pushfront(int data){

    node* new_node = new node;

    new_node -> data = data;
    new_node -> next = head;

    head = new_node;

    if(tail == NULL)
        tail = head;
}

/**** push back ****/
void linklist:: pushback(int data){
    node* new_node = new node;

    new_node -> data = data;
    new_node -> next = NULL;

    if(head == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        tail -> next = new_node;
        tail = new_node;
    }
}

/**** insert after ****/
void linklist:: insert_after(int key,int data){
    node* current_node = new node;
    current_node = head ;
    while(current_node != NULL){
        if(current_node->data == key){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = current_node->next;
            current_node->next = new_node;
            return ;
        }
        else
            current_node = current_node->next;
    }

    cout<< "Key value not found..." << endl;
}

/**** remove item ****/
void linklist:: remove_item(int position){
    node* current_node = new node;
    node* previous_node = new node;
    current_node = head;
    previous_node = NULL;

    int i = 1 ;
    while(current_node != NULL){
        if(i == position){
            if(previous_node == NULL)
                head = current_node->next;
            else
                previous_node->next = current_node->next;
            return ;
        }
        else{
            previous_node = current_node;
            current_node = current_node->next;
        }
        i++ ;
    }

    if(previous_node == NULL)
        cout<< "No element present in the list ..." << endl;
    else
        cout<< "Selected position is out of range ..." << endl;

}

/**** remove front ****/
void linklist:: remove_front(){
    head = head->next;
}

/**** remove back ****/
void linklist:: remove_back(){
    if(tail == NULL){
        cout<< "List is empty.." << endl;
        return ;
    }

    node* current_node = new node;
    current_node = head;

    while(current_node->next != tail){
        current_node= current_node->next;
    }

    current_node -> next = NULL;
    tail = current_node ;

}

/**** is present ****/
bool linklist:: ispresent(int key){
    node* current_node = new node;
    current_node = head;

    while(current_node != NULL){
        if(current_node->data == key)
            return true;
        else
            current_node = current_node->next;
    }

    return false;
}

/**** Print ****/
void linklist:: print(){
    node* current_node = new node;
    current_node = head;

    while(current_node != NULL){
        cout<< current_node->data << " ";
        current_node = current_node->next;
    }
    if(head != NULL)
        cout<< endl;
    else
        cout<< "NO data to print.." << endl;

}

/**** Mid Data ****/
void linklist:: mid_data(){
    node* slow_ptr = new node ;
    node* fast_ptr = new node ;

    slow_ptr = fast_ptr = head ;

    if(head == NULL){
        cout<< "NO data in this list..."  << endl;
        return ;
    }

    while(fast_ptr != NULL && fast_ptr->next != NULL){
        fast_ptr = fast_ptr->next->next ;
        slow_ptr = slow_ptr->next ;
    }

    cout<< "Middle element data : " << slow_ptr->data << endl;

}

/**** Reverse Linked list ****/
void linklist:: reverse_list(){
    node* current_node = head ;
    node* previous_node = NULL ;
    tail = head ;

    while(current_node != NULL){
        head = current_node  ;
        node* old_current_node = current_node ;
        current_node = current_node->next ;
        old_current_node->next = previous_node ;
        previous_node = old_current_node ;
    }
}

int main(){
    ios::sync_with_stdio(false),cin.tie(false),cout.tie(false);

    linklist ob;
    ob.pushback(10);
    ob.pushfront(20);
    ob.pushback(30) ;
    ob.print();
    ob.reverse_list() ;
    ob.print() ;
    return 0;
}

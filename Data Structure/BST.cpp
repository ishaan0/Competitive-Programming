#include<bits/stdc++.h>
using namespace std ;

/**** Node ****/
class node{
public:
    int data ;
    node* parent ;
    node* left ;
    node* right ;
};

/**** Binary Search Tree class ****/
class bst{
    node* root ;
public:
    bst(){root = NULL;}
    node* createNode(int data) ;
    void addLeftChild(node* parent,node* child);
    void addRightChild(node* parent,node* child);
    void insertNode(int data) ;
    void inOrder(node* currentNode) ;
    void postOrder(node* currentNode) ;
    void preOrder(node* currentNode) ;
    bool isFound(int data) ;
    node* findMin(node* currentNode) ;
    node* findMax(node* currentNode) ;
    node* deleteNode(node* currentNode,int data) ;
};

/**** Create Node ****/
node* bst:: createNode(int data){
    node* newNode = new node ;
    newNode->data = data ;
    newNode->parent = NULL ;
    newNode->left = NULL ;
    newNode->right = NULL ;
}

/**** Add Left Child ****/
void bst:: addLeftChild(node* parent,node* child){
    parent->left = child ;

    if(child != NULL)
        child->parent = parent ;
}

/**** Add Right Child ****/
void bst:: addRightChild(node* parent,node* child){
    parent->right = child ;

    if(child != NULL)
        child->parent = parent ;
}

/**** Insert Node ****/
void bst:: insertNode(int data){
    node* newNode = createNode(data) ;
    if(root == NULL){
        root = newNode ;
        return ;
    }

    node* currentNode = root ;
    node* parentNode = NULL ;

    while(currentNode != NULL){
        parentNode = currentNode ;

        if(newNode->data < currentNode->data)
            currentNode = currentNode->left ;
        else
            currentNode = currentNode->right ;
    }

    if(newNode->data < parentNode->data)
        addLeftChild(parentNode,newNode) ;
    else
        addRightChild(parentNode,newNode) ;
}

/**** Pre Order Traversal ****/
void bst:: preOrder(node* currentNode){
    cout<< currentNode->data << " " ;
    if(currentNode->left != NULL)
        preOrder(currentNode->left) ;
    if(currentNode->right != NULL)
        preOrder(currentNode->right) ;
}

/**** In Order Traversal ****/
void bst:: inOrder(node* currentNode){
    if(currentNode->left != NULL)
        inOrder(currentNode->left) ;
    cout<< currentNode->data << " " ;
    if(currentNode->right != NULL)
        inOrder(currentNode->right) ;
}

/**** Post Order Traversal ****/
void bst:: postOrder(node* currentNode){
    if(currentNode->left != NULL)
        postOrder(currentNode->left) ;
    if(currentNode->right != NULL)
        postOrder(currentNode->right) ;
    cout<< currentNode->data << " " ;
}

/*** Search data ****/
bool bst:: isFound(int data){
    node* currentNode = root ;

    while(currentNode != NULL){
        if(currentNode->data == data)
            return true ;
        else if(data < currentNode->data)
            currentNode = currentNode->left ;
        else
            currentNode = currentNode->right ;
    }

    return false ;
}

/**** Find Minimum Node ****/
node* bst:: findMin(node* currentNode){
    if(currentNode->left == NULL)
        return currentNode ;
    return findMin(currentNode->left) ;
}

/**** Find Maximum Node ****/
node* bst:: findMax(node* currentNode){
    if(currentNode->right == NULL)
        return currentNode ;
    return findMax(currentNode->right) ;
}

/**** Delete Node *****/
node* bst:: deleteNode(node* currentNode,int data){
    if(currentNode == NULL)
        return currentNode ;
    else if(data < currentNode->data)
        currentNode->left = deleteNode(currentNode->left, data);
    else if(data > currentNode->data)
        currentNode->right = deleteNode(currentNode->right, data);
    else{

        if(currentNode->left == NULL && currentNode->right == NULL)
            currentNode = NULL;
        else if(currentNode->left == NULL)
            currentNode = currentNode->right;
        else if(currentNode->right == NULL)
            currentNode = currentNode->left;
        else{
            node* temp = findMin(currentNode->right);
            currentNode->data = temp->data;
            currentNode->right = deleteNode(currentNode->right, temp->data);
        }

    }
    return currentNode;
}

int main(){


    return 0 ;
}

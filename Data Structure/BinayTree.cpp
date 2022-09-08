#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;

/***** Tree Body *****/
struct node{
    int data;
    node* left;
    node* right;
};

/***** Create Node *****/
Node* create_node(int data){
    node* new_node = new node;

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

/***** add left child *****/
void add_left_child(Node *parent,Node* child){
    parent->left = child;
}

/***** add right child *****/
void add_right_child(Node *parent,Node* child){
    parent->right = child;
}


/***** Pre Order Traverse *****/
void pre_order(Node *node){
    cout<< node->data <<" ";

    if(node->left != NULL)
        pre_order(node->left);

    if(node->right != NULL)
        pre_order(node->right);
}

/***** Post Order Traverse *****/
void post_order(Node *node){

    if(node->left != NULL)
        post_order(node->left);

    if(node->right != NULL)
        post_order(node->right);

    cout<< node->data <<" ";
}

/***** In Order Traverse *****/
void in_order(Node *node){

    if(node->left != NULL)
        in_order(node->left);

    cout<< node->data <<" ";

    if(node->right != NULL)
        in_order(node->right);
}



int main(){


    return 0;
}

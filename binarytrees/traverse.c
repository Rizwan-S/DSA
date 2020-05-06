#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
    char data; 
    struct node* left; 
    struct node* right; 
}; 

struct node* newNode(char data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 

void printPostorder(struct node* node) 
{ 
    if (node){ 
    printPostorder(node->left); 
    printPostorder(node->right); 
    printf("%c ", node->data);
    } 
} 
  
void printInorder(struct node* node) 
{ 
    if (node){ 
    printInorder(node->left); 
    printf("%c ", node->data);   
    printInorder(node->right);
    } 
} 

void printPreorder(struct node* node) 
{ 
    if (node){ 
    printf("%c ", node->data);   
    printPreorder(node->left);   
    printPreorder(node->right);
    } 
}     

int main() 
{ 
    struct node *root  			= newNode('a'); 
    root->left         			= newNode('b'); 
    root->right        			= newNode('c'); 
    root->left->right  			= newNode('d');
    root->left->right->left 	= newNode('i');
    root->left->right->right 	= newNode('g'); 
    root->right->left  			= newNode('e');
    root->right->right 			= newNode('f');
    root->right->right->left 	= newNode('h');   
    printf("\nPreorder traversal of binary tree is \n"); 
    printPreorder(root); 
    printf("\nInorder traversal of binary tree is \n"); 
    printInorder(root);   
    printf("\nPostorder traversal of binary tree is \n"); 
    printPostorder(root); 
    printf("\n");
    return 0; 
}
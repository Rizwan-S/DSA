#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

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

void printPreorder(struct node* node)
{
	if(node)
	{
		struct node* stack[10];
		int top = -1;
		stack[++top] = node;
		while(top >= 0)
		{
			printf("%c ", stack[top]->data);
			node = stack[top--];
			if(node->right) stack[++top] = node->right;
			if(node->left) stack[++top] = node->left;
		}
	}
}

void printInorder(struct node* node)
{
	if(node)
	{
		struct node* stack[10];
		bool base[10];
		int top = -1;
		top++;
		stack[top] = node;
		base[top] = false;
		while(top >= 0)
		{
			if(base[top] == true) printf("%c ", stack[top--]->data);
			else
			{
				node = stack[top--];
				if(node->right)
				{
					stack[++top] = node->right;
					base[top] = false;
				}
				stack[++top] = node;
				base[top] = true;
				if(node->left)
				{
					stack[++top] = node->left;
					base[top] = false;
				}
			}
		}
	}
}

void printPostorder(struct node* node)
{
	if(node)
	{
		struct node* stack[10];
		bool base[10];
		int top = -1;
		top++;
		stack[top] = node;
		base[top] = false;
		while(top >= 0)
		{
			if(base[top] == true) printf("%c ", stack[top--]->data);
			else
			{
				node = stack[top--];
				stack[++top] = node;
				base[top] = true;
				if(node->right)
				{
					stack[++top] = node->right;
					base[top] = false;
				}
				if(node->left)
				{
					stack[++top] = node->left;
					base[top] = false;
				}
			}
		}
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
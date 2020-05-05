#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
	long long int key;
	struct BST* left, *right;
}BST;

BST* newNode(long long int key)
{
	BST* temp = (BST*)malloc(sizeof(BST));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

BST* insert(BST* node, long long int key)
{
	if(!node) return newNode(key);
	if(key < node->key) node->left = insert(node->left, key);
	else if (key > node->key) node->right = insert(node->right, key);
	return node;
}

void Inorder(BST* root)
{
	if(root)
	{
		Inorder(root->left);
		printf("%lld ", root->key);
		Inorder(root->right);
	}
}

BST* delete(BST* node, long long int x)
{
	if(!node) return node;
	if(node->key > x)
	{
		node->left = delete(node->left, x);
		return node;
	}
	else if(node->key < x)
	{
		node->right = delete(node->right, x);
		return node;
	}
	if(node->left && node->right)
	{
		BST* temp = node->left;
		while(temp->right) temp = temp->right;
		node->key = temp->key;
		node->left = delete(node->left, temp->key);
	}
	else
	{
		BST* child;
		if(!node->left) child = node->right;
		else child = node->left;
		free(node);
		return child;
	}
}

int main()
{
	long long int n;
	printf("Enter the number of values: ");
	scanf("%lld", &n);
	long long int val;
	BST* root = NULL;
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &val);
		root = insert(root, val);
	}
	Inorder(root);
	printf("\nEnter the number to delete: ");
	scanf("%lld", &n);
	BST* newroot = NULL;
	newroot = delete(root, n);
	Inorder(newroot);	
	printf("\n");
}
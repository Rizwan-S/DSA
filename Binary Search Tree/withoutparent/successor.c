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

BST* successor(BST* node, BST* root)
{
	if(!node) return node;
	if(node->right)
	{
		node = node->right;
		while(node->left) node = node->left;
		return node;
	}
	else
	{
		BST* succ = NULL;
		while(node != root)
		{
			if(node->key < root->key)
			{
				succ = root;
				root = root->left;
			} 
			else
			{
				root = root->right;
			} 
		}
		return succ;
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
	printf("\n");
	BST* suc = NULL;
	suc = successor(root, root);
	if(suc) printf("%lld\n", suc->key);
	else printf("No successor\n");
}
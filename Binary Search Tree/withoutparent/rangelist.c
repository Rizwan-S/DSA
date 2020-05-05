#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
	long long int key;
	struct BST* left, *right;
}BST;

typedef struct List
{
	struct BST *node;
	struct List *next;
} List;

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

void Rangelist (struct BST *node, long long int l, long long r, struct List **list)
{
	if (node)
    {
		if (node->key > r) Rangelist (node->left, l, r, &*list);
		else if (node->key < l) Rangelist (node->right, l, r, &*list);
	    else
		{
	  		Rangelist (node->right, l, r, &*list);
	  		List *temp = (List *)malloc(sizeof(List));
	  		temp->node = node;
	  		temp->next = *list;
	  		*list = temp;
	  		Rangelist (node->left, l, r, &*list);
		}
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
}
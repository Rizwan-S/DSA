#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BST
{
	long long int key;
	struct BST *left, *right, *parent;
} BST;

BST* newNode(long long int key)
{
	BST* temp = (BST*)malloc(sizeof(BST));
	temp->key = key;
	temp->left = temp->right = temp->parent = NULL;
	return temp;
}

void insert(BST** node, long long int key)
{
	if(!*node) *node = newNode(key);
	else
	{
		bool flag = true;
		BST* temp = *node;
		while(flag)
		{
			if(key < temp->key)
			{
				if(temp->left) temp = temp->left;
				else
				{
					temp->left = newNode(key);
					temp->left->parent = temp;
					flag = false;
				}
			}
			else if(key > temp->key)
			{
				if(temp->right) temp = temp->right;
				else
				{
					temp->right = newNode(key);
					temp->right->parent = temp;
					flag = false;
				}
			}
			else flag = false;
		}
	}
}

BST* predecessor(BST* node)
{
	if(!node) return node;
	if(node->left)
	{
		node = node->left;
		while(node->right) node = node->right;
		return node;
	}
	else
	{
		while(node->parent)
		{
			if(node->parent->right == node) return node->parent;
			else node = node->parent;
		}
		return node->parent;
	}
}

void Inorder(BST *node)
{
	if(node)
    {
      	Inorder (node->left);
      	printf ("%lld  ", node->key);
		Inorder (node->right);
    }
}

int main()
{
	long long int n;
	printf("Enter the number of elements: ");
	scanf("%lld", &n);
	long long int val;
	BST* root = NULL;
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &val);
		insert(&root, val);
	}
	Inorder(root);
	printf("\n");
	BST* pre = NULL;
	pre = predecessor(root);
	printf("%lld\n", pre->key);
}
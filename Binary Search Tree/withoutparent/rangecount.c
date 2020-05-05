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

long long int Rangecount (BST *node, long long int l, long long r)
{
	if (!node) return 0;
	if (node->key > r) return Rangecount (node->left, l, r);
	if (node->key < l) return Rangecount (node->right, l, r);
	return 1 + Rangecount (node->left, l, r) + Rangecount (node->right, l, r);
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
	long long int l, r;
	printf("Enter the two numbers: ");
	scanf("%lld %lld", &l, &r);
	printf("%lld\n", Rangecount(root, l, r));
}
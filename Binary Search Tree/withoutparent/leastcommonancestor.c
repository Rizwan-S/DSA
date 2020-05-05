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

BST* LCA(BST* node, long long int l, long long int r)
{
	if(!node || l > r) return NULL;
	if(node->key > r) return LCA(node->left, l, r);
	if(node->key < l) return LCA(node->right, l, r);
	return node;
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
	printf("Enter the two numbers: ");
	long long int l, r;
	scanf("%lld %lld", &l, &r);
	BST* lca = LCA(root, l, r);
	if(lca) printf("%lld\n", lca->key);
	else printf("No LCA\n");
}
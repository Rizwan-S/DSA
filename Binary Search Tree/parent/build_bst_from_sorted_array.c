#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
	long long int key;
	struct BST *left, *right, *parent;
} BST;

void Inorder(BST *node)
{
	if(node)
    {
      	Inorder (node->left);
      	printf ("%lld  ", node->key);
		Inorder (node->right);
    }
}

BST* CreateBBST(long long int a[], long long int l, long long int r)
{
	BST* node = NULL;
	if(l <= r)
	{
		long long int m = (l + r) / 2;
		node = (BST*)malloc(sizeof(BST));
		node->key = a[m];
		node->left = CreateBBST(a, l, m - 1);
		node->right = CreateBBST(a, m + 1, r);
		if(node->right) node->right->parent = node;
		if(node->left) node->left->parent = node;
	}
	return node;
}


int main()
{
	long long int n;
	printf("Enter the number of elements: ");
	scanf("%lld", &n);
	long long int a[n];
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	BST* root = NULL;
	root = CreateBBST(a, 0, n - 1);
	Inorder(root);
	printf("\n");
}

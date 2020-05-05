#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
	long long int key;
	struct BST *left, *right;

}BST;

BST* CreateBBST(long long int A[], long long int l, long long int r)
{
	BST *node = NULL;
  	if (l <= r)
    {
		long long int m = (l + r) / 2;
      	node = (BST *)malloc(sizeof(BST));
      	node->key = A[m];
      	node->left = CreateBBST (A, l, m - 1);
		node->right = CreateBBST (A, m + 1, r);
    }
  	return node;
}

void Inorder(BST* node)
{
  if (node)
    {
      Inorder (node->left);
      printf ("%lld  ", node->key);
      Inorder (node->right);
    }
}

int main()
{
	long long int n;
	printf("Enter the number of values: ");
	scanf("%lld", &n);
	long long int a[n];
	BST* root = NULL;
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	root = CreateBBST(a, 0, n - 1);
	Inorder(root);
	printf("\n");
}
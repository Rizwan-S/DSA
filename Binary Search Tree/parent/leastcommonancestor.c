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

void Inorder(BST *node)
{
	if(node)
    {
      	Inorder (node->left);
      	printf ("%lld  ", node->key);
		Inorder (node->right);
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
	printf("Enter the two numbers: ");
	long long int l, r;
	scanf("%lld %lld", &l, &r);
	BST* lca = LCA(root, l, r);
	if(lca) printf("%lld\n", lca->key);
	else printf("No LCA\n");

}
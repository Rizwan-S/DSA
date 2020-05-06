#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct BST
{
  long long int key;
  int height;
  long long int max, high;
  struct BST *left, *right;
}BST;

BST * newNode (long long int l, long long int r)
{
  BST *temp = (BST *)malloc(sizeof(BST));
  temp->key = l;
  temp->max = temp->high = r;
  temp->left = temp->right = NULL;
  temp->height = 0;
  return temp;
}

int Max(int x, int y)
{
  return x > y ? x : y;
}

int Height(BST *node)
{
  	if(node)
    {
      	if(node->left && node->right) return 1 + Max (node->left->height, node->right->height);
      	else if (node->left) return 1 + node->left->height;
      	else if (node->right) return 1 + node->right->height;
      	else return 0;
    }
  	else return -1;
}

void Updatemax(BST *node)
{
  	if(node)
  	{
      	node->max = node->high;
      	if(node->left && node->left->max > node->high) node->max = node->left->max;
      	if(node->right && node->right->max > node->max) node->max = node->right->max;
    }
}

bool AVL(BST *node)
{
  	if(abs(Height(node->left) - Height(node->right)) < 2) return true;
  	else return false;
}

BST *Rotate(BST *Z)
{
  	BST *X, *Y, *T1, *T2, *T3, *T4;
  	int c = 0;
  	if(Height (Z->left) + 1 == Z->height) Y = Z->left;
  	else
    {
      	Y = Z->right;
      	c++;
    }
  	c *= 2;
  	if(Height (Y->left) + 1 == Y->height) X = Y->left;
  	else
    {
      	X = Y->right;
      	c++;
    }

  	if (c == 0)
    {
    	T3 = Y->right;
      	Y->right = Z;
      	Z->left = T3;
      	Z->height = Height(Z);
      	X->height = Height(X);
      	Y->height = Height(Y);
      	Updatemax(Z);
      	Updatemax(X);
      	Updatemax(Y);
      	return Y;

    }
  	else if(c == 3)
    {
		T2 = Y->left;
      	Y->left = Z;
      	Z->right = T2;

      	Z->height = Height(Z);
      	X->height = Height(X);
      	Y->height = Height(Y);
      	Updatemax(Z);
      	Updatemax(X);
      	Updatemax(Y);
      	return Y;
    }
  	else if (c == 1)
    {
      	T2 = X->left;
      	T3 = X->right;
      	Y->right = T2;
      	Z->left = T3;
      	X->left = Y;
      	X->right = Z;

      	Z->height = Height(Z);
      	Y->height = Height(Y);
      	X->height = Height(X);
      	Updatemax(Z);
      	Updatemax(Y);
      	Updatemax(X);
      	return X;
    }
  	else
    {
      	T2 = X->left;
      	T3 = X->right;
      	Y->left = T3;
      	Z->right = T2;
      	X->left = Z;
      	X->right = Y;

      	Z->height = Height(Z);
      	Y->height = Height(Y);
      	X->height = Height(X);
      	Updatemax(Z);
      	Updatemax(Y);
      	Updatemax(X);
      	return X;
    }
}

BST *Insert(BST *node, long long int key, long long int r)
{
  	if(!node)return newNode(key, r);
  	if(key < node->key) node->left = Insert(node->left, key, r);
  	else if(key > node->key) node->right = Insert(node->right, key, r);
  	node->height = Height(node);
  	Updatemax(node);
  	if(!AVL(node)) node = Rotate(node);
  	return node;
}

void Inorder(BST *node)
{
	if(node)
    {
    	Inorder (node->left);
      	printf ("%lld: %lld %lld   ", node->key, node->high, node->max);
      	Inorder (node->right);
    }
}

BST *Delete(BST *node, long long int X)
{
    if(!node) return node;
    if(node->key > X)
    {
        node->left = Delete(node->left, X);
        node->height = Height(node);
        Updatemax(node);
        if(!AVL(node)) node = Rotate(node);
        return node;
    }
    else if(node->key < X)
    {
        node->right = Delete(node->right, X);
        node->height = Height(node);
        Updatemax(node);
        if(!AVL(node)) node = Rotate(node);
        return node;
    }
    if(node->left && node->right)
    {
        BST *temp = node->left;
        while(temp->right) temp = temp->right;
        node->key = temp->key;
        node->high = temp->high;
        node->left = Delete(node->left, temp->key);
        Updatemax(node);
    }
    else
    {
        BST *child;
        if(node->left) child = node->left;
        else child = node->right;
        free(node);
        return child;
    }
}

int main()
{
	int n;
	printf("Enter the number of values: ");
	scanf("%d", &n);
	long long int l, r;
	BST* root = NULL;
	for(int i = 0; i < n; i++)
	{
		scanf("%lld %lld", &l, &r);
		root = Insert(root, l, r);
	}
	Inorder(root);
	printf("\n");
  printf("Enter lower val to delete: ");
  scanf("%lld", &l);
  root = Delete(root, l);
  Inorder(root);
  printf("\n");
}
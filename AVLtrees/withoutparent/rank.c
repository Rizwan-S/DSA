#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct BST
{
    long long int key;
    int height;
    long long int count;
    struct BST *left, *right;
}BST;

BST* newNode(long long int key)
{
    BST *temp = (BST *)malloc(sizeof(BST));
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->height = 0;
    temp->count = 1;
    return temp;
}

int Max(int a, int b)
{
    return a > b ? a : b;
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

long long int Count(BST *node)
{
    if(node)
    {
        if (node->left && node->right) return 1 + node->left->count + node->right->count;
        else if (node->left) return 1 + node->left->count;
        else if (node->right) return 1 + node->right->count;
        else return 1;
    }
    else return 0;
}

BST *Rotate(BST *Z)
{
    BST *X, *Y, *T1, *T2, *T3, *T4;
    int c = 0;
    if (Height(Z->left) + 1 == Z->height) Y = Z->left;
    else
    {
        Y = Z->right;
      c++;
    }
    c *= 2;
    if(Height(Y->left) + 1 == Y->height) X = Y->left;
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
        Z->count = Count(Z);
        X->count = Count(X);
        Y->count = Count(Y);
        return Y;
    }
    else if (c == 3)
    {
        T2 = Y->left;
        Y->left = Z;
        Z->right = T2;
        Z->height = Height(Z);
        X->height = Height(X);
        Y->height = Height(Y);
        Z->count = Count(Z);
        X->count = Count(X);
        Y->count = Count(Y);
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
        Z->count = Count(Z);
        Y->count = Count(Y);
        X->count = Count(X);
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
        Z->count = Count(Z);
        Y->count = Count(Y);
        X->count = Count(X);
        return X;
    }
}

bool AVL(BST * node)
{
    if (abs(Height(node->left) - Height(node->right)) < 2) return true;
    else return false;
}

BST *Insert(BST *node, long long int key)
{
    if(!node) return newNode(key);
    if(key < node->key) node->left = Insert(node->left, key);
    else if (key > node->key) node->right = Insert(node->right, key);
    node->height = Height(node);
    node->count = Count(node);
    if(!AVL(node)) node = Rotate(node);
    return node;
}

void Inorder(struct BST *node)
{
    if(node)
    {
        Inorder (node->left);
        printf ("%lld  ", node->key);
        Inorder (node->right);
    }
}

long long int Rank(BST *node, long long int X)
{
    long long int rank = 1;
    while (node)
    {
        if(X == node->key)
        {
            if(node->right) rank += node->right->count;
            return rank;
        }
        else if(X < node->key)
        {
            rank++;
            if(node->right) rank += node->right->count;
            node = node->left;
        }
        else node = node->right;
    }
    return rank;
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
      root = Insert(root, val);
   }
   Inorder(root);
   printf("\n");
   printf("Enter the number to find rank: ");
   scanf("%lld", &n);
   n = Rank(root, n);
   printf("%lld\n", n);
}
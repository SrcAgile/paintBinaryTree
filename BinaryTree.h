#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <stdio.h>
struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* parent;
};

typedef struct TreeNode node;



void insertNode(node *parent,node *root,int val);
void deleteNode(node *root,int val,int *deleteNum);
static node* adjustDelete(node *root);

void initialTree(node **root);
void deleteTree();
void preOrder(node *root);
void inOrder();
void postOrder();
#endif
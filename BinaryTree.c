#include "BinaryTree.h"
#include <stdlib.h>
void insertNode(node *parent,node *root,int val){
	if(root){
		if(val>root->data)
			insertNode(parent,parent->right,val);
		else
			insertNode(parent,parent->left,val);
	}
	else{
		root=(node *)malloc(sizeof(node));
		root->data=val;
		root->left=NULL;
		root->right=NULL;
		root->parent=parent;
	}
}
/*void deleteNode(node *root,int val,int *deleteNum){
	if(root){
		if(root->data>val)
			deleteNode(root->left,val,deleteNum);
		if(root->data<val)
			deleteNode(root->right,val,deleteNum);
		if(root->data==val){
			(*deleteNum)++;
			if(node *master=root->left?adjustDelete(root->left):(root->right)){
				master->left=root->left;
				master->right=root->right;
			}
			if(node *parent=root->parent)
				parent->left==root?parent->left=master:parent->right=master;
			free(root);
		}
	}
}*/
static node* adjustDelete(node *root){
	if(root->right){
		adjustDelete(root->right);
	}else{
		root->parent->right=NULL;
		return root;
	}
}

void initialTree(node **root){
	int val;
	puts("please input:");
	while(scanf("%d",&val)!=1){
		scanf("%*[^\n]");
		getchar();
		puts("please reinput the number:");
	}
	if(val==-1)
		(*root)=NULL;
	else{
		(*root) = (node *)malloc(sizeof(node));
		(*root)->data=val;
		(*root)->left=NULL;
		(*root)->right=NULL;
		initialTree(&(*root)->left);
		initialTree(&(*root)->right);
	}
}
void preOrder(node *root){
	if(root){
		printf("%d\n",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
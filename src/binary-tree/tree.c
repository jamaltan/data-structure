#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

PBT
create(int val)
{
	PBT root;

	root = malloc(sizeof(BinaryTree));
	assert(root != NULL);

	root->val = val;
	root->left = NULL;
	root->right = NULL;
	
	return root;
}

void
add(PBT root, int val)
{
	PBT elt;

	elt = malloc(sizeof(BinaryTree));
	assert(elt != NULL);

	elt->val = val;
	elt->left = NULL;
	elt->right = NULL;

	for(;;){
		// 相等的情况如何处理
		if(val < root->val){
			if(root->left){
				root = root->left;
			}else{
				root->left = elt;	
				return;
			}
		}else{
			if(root->right){
				root = root->right;
			}else{
				root->right = elt;
				return;
			}
		}
	}
}

PBT
search(PBT root, int target)
{
	if(root == NULL) return;
	if(target == root->val){
		return root;
	}
	if(target < root->val){ 
		search(root->left, target);
	}
	if(target > root->val){
		search(root->right, target);
	}
}

PBT
searchIteratively(PBT root, int target)
{
	while(root){
		if(target == root->val) return root;
		if(target < root->val) root = root->left;
		if(target > root->val) root = root->right;
	}
}

int
height(PBT root)
{
	int lh;
	int rh;

	if(root == NULL){
		return -1;
	}else{
		lh = height(root->left);
		rh = height(root->right);
		return 1 + ( lh > rh ? lh : rh );
	}
}


int
del(PBT root, int val)
{

}

int
size(PBT root)
{
	if(root == NULL){
		return 0;
	}else{
		return 1 + size(root->left) + size(root->right);
	}	
}


void
preorder(PBT root)
{
	if(root == NULL)
		return;

	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}


void
inorder(PBT root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

void
postorder(PBT root)
{
	if(root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

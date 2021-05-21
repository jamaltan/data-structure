#ifndef __TREE_H_
#define __TREE_H_

#define TRUE 1
#define FALSE 0

typedef struct binaryTree {
	struct binaryTree *left;
	struct binaryTree *right;
	int val;
} BinaryTree;


typedef BinaryTree *PBT;

PBT create(int val);
void add(PBT root, int val);
int del(PBT root, int val);
PBT search(PBT root, int target);
PBT searchIteratively(PBT root, int target);
int size(PBT root);
int height(PBT root);
void preorder(PBT root);
void inorder(PBT root);
void postorder(PBT root);

#endif /* __TREE_H_ */

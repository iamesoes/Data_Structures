#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
}NODE;

NODE *createNode(int value){
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void printPreOrder(NODE *tree){
	if(tree!=NULL){
		printf("%d  ",tree->value);
		printPreOrder(tree->left);
		printPreOrder(tree->right);
	}
}

void printInOrder(NODE *tree){
	if(tree!=NULL){
		printInOrder(tree->left);
		printf("%d  ",tree->value);
		printInOrder(tree->right);
	}
}

void printPostOrder(NODE *tree){
	if(tree!=NULL){
		printPostOrder(tree->left);
		printPostOrder(tree->right);
		printf("%d  ",tree->value);
	}
}

int main(){
	NODE *root = NULL;
	root = createNode(19);
	root->left = createNode(3);
	root->right = createNode(1);
	root->left->right = createNode(8);
	root->right->left = createNode(21);
	root->left->left = createNode(13);
	printf("\nPREORDER  >>> ");
	printPreOrder(root);
	printf("\nPOSTORDER  >>> ");
	printPostOrder(root);
	printf("\nINORDER  >>> ");
	printInOrder(root);
	return 0;
}

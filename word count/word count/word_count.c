#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define MAX_SIZE 10


typedef struct node* treePointer;

typedef struct element {
	char key[MAX_SIZE];
	int cnt;
}element;



typedef struct node{
	element data;
	treePointer leftChild, rightChild;
}node;



treePointer *modifiedSearch(treePointer root, char k[])
{
	treePointer temp = root;
	while (root)
	{
		if (strcmp(root->data.key,k) < 0) {
			root = root->leftChild;
		}
		else if (strcmp(root->data.key, k) > 0) {
			root = root->rightChild;
		}
		else {
			return NULL;
		}		temp = root;

	}
	return temp;
}



void insert(treePointer node, char k[]) {
	treePointer ptr, temp = modifiedSearch(node, k);
	if (temp || !(node)) {
		ptr = (treePointer)malloc(sizeof(*ptr));
		strcpy(ptr->data.key, k);
		ptr->leftChild = NULL; ptr->rightChild = NULL;
		if (node) {
			if (strcmp(k, temp->data.key)<0) {
		
				temp->leftChild = ptr;
			}
			else {
				temp->rightChild = ptr;
			}
		}
		else {
			node = ptr;
		}
	}

}

void inorder(treePointer node) {
	if (node) {
		inorder(node->leftChild);
		printf("%s", node->data.key);
		printf("%d", node->data.cnt);
		inorder(node->rightChild);
	}
}

void main() {
	element temp;
	treePointer node = NULL;
	while (1) {
		printf("next word ? \n");
		scanf("%s", temp.key);
		insert(&node, temp.key);
		temp.cnt++;
		inorder(node);

	}

}
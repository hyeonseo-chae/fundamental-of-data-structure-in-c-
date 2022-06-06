#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct element {
	char word[MAX_SIZE];
	int cnt;
}element;

typedef struct node* treePointer;
typedef struct node{
	element key;
	treePointer leftChild, rightChild;

};



element *iterSearch(treePointer tree, char k[]) {
	while (tree) {
		if (k == tree->key.word) return &(tree->key.word);
		if (k < tree->key.word) {
			tree = tree->leftChild;
		}
		else {
			tree = tree->rightChild;
		}
	}


}


void main() {
	char temp_word[MAX_SIZE];
	while (1) {
		printf("next word ? ");
		scanf("%s", temp_word);

	}
	


}
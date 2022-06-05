#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct element {
	int key;
}element;

typedef struct node* treePointer;
typedef struct node{
    element word;
	treePointer leftChild, rightChild;

};



element *iterSearch(treePointer tree, char k[]) {
	while (tree) {
		if (k == tree->word.key) return &(tree->word);
		if (k < tree->word.key) {
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
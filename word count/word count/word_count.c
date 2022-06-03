#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_SIZE 10

typedef struct node* treePointer;
typedef struct {
	char word[MAX_SIZE];
	treePointer leftChild, rightChild;

}node;

node* iterSearch(treePointer tree, char k[]) {
	while (tree) {
		if (k == tree->word.key) return &(tree->word);
	}


}


void main() {
	char temp_word[MAX_SIZE];
	while (1) {
		printf("next word ? ");
		scanf("%s", temp_word);

	}
	


}
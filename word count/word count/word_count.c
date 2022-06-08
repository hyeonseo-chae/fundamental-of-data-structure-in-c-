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

treePointer modifiedSearch(treePointer root, int k)
{
	treePointer temp = root;
	while (root)
	{
		temp = root;
		if (k < root->data.key)
			root = root->leftChild;
		else if (k > root->data.key)
			root = root->rightChild;
		else
			return NULL;
	}
	return temp;
}


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

void insert(treePointer* node, element word, iType theItem) {
	treePointer ptr, temp = modifiedSearch(*node, k);
	if (temp || !(*node)) {
		MALLOC(ptr, sizeof(*ptr));
		ptr->key = k;
		ptr->word.item = theItem;
		ptr->leftChild = ptr->rightChild = NULL;
		if (*node) {
		
			if (k < temp->word.key) {
		
				temp->leftChild = ptr;
			}
			else {
				temp->rightChild = ptr;
			}
		}
		else {
			*node = ptr;
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
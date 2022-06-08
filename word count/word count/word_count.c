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



typedef struct node {
    element data;
    treePointer leftChild, rightChild;
}node;



element* modifiedSearch(treePointer root, char k[])
{
    treePointer temp = root;

    while (root)
    {
        temp = root;
        if (strcmp(k, root->data.key) < 0) {
            root = root->leftChild;
        }
        else if (strcmp(k, root->data.key) > 0) {
            root = root->rightChild;
        }
        else {
            root->data.cnt++;
            return NULL;
        }

    }
    return temp;
}



void insert(treePointer* node, char k[]) {
    treePointer ptr, temp = modifiedSearch(*node, k);
    if (temp || !(*node)) {
        ptr = (treePointer)malloc(sizeof(*ptr));
        strcpy(ptr->data.key, k);
        ptr->data.cnt = 1;
        ptr->leftChild = ptr->rightChild = NULL;

        if (*node) {
            if (strcmp(k, temp->data.key) < 0) {

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

void inorder(treePointer node) {
    if (node) {
        inorder(node->leftChild);
        printf("%s:%-4d", node->data.key, node->data.cnt);
        inorder(node->rightChild);
    }
}

void main() {
    char temp[MAX_SIZE];
    treePointer node = NULL;
    while (1) {

        printf("\n\n next word ? ");
        scanf("%s", temp);
        if (strcmp(temp, "END") == 0) {
            break;
        }
        insert(&node, temp);
        inorder(node);

    }

}
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_NAME 20 // name ������ ����
#define MAX_NUMBER 40 // number ������ ����

typedef struct list { // ���� ���� ����ü
    char name[MAX_NAME]; //�̸�
    char number[MAX_NUMBER]; //��ȭ��ȣ
}list;

typedef struct tree { // ��� ����ü
    list key; //���� ���� ����ü
    struct tree* left; // ��ũ
    struct tree* right; // ��ũ
}tree;

void insert(tree** root, list data) { // ���� �Լ�
    tree* p = NULL; //�θ� ���
    tree* t = *root; // �ڽ� ���

    while (t != NULL) { // t�� NULL�� �ƴϴ� -> ��Ʈ�� ������ Ž���� ������ �����̴�.
        if (strcmp(data.name, t->key.name) == 0) return; // Ű �ߺ� Ȯ��
        p = t; // ���� ���� ��ȸ�ϱ� ���� ����
        if (strcmp(data.name, t->key.name) < 0) t = t->left; // ��Ʈ Ű�� ���� ����, �������� �̵�
        else t = t->right; // ��Ʈ Ű�� ���� ŭ, ���������� �̵�
    }

    tree* newtree = (tree*)malloc(sizeof(tree)); // ���ο� ��� �����Ҵ����� ����
    newtree->key = data; // Ű�� ����
    newtree->left = newtree->right = NULL; // ��ũ �ʱ�ȭ

    if (p != NULL) { // p�� �����Ұ��� �θ� ��带 ����Ű�� ����
        if (strcmp(data.name, p->key.name) < 0) p->left = newtree; // Ű ���� ���ؼ� ������ ����
        else p->right = newtree; // Ű ���� ���ؼ� ũ�� ������
    }
    else *root = newtree;  // �� �ش� �ȵǸ� ó�� �����Ǵ� ��Ʈ ����̴�.
}

void print(tree* root) { // Ʈ�� ��� �Լ�
    if (root != NULL) { // ���� ��ȸ
        print(root->left);
        printf("\t %s : %s", root->key.name, root->key.number);
        printf("\t\t\t [");
        for (int i = 0; i <= MAX_NAME; i++) {
            if (root->key.name[i] == NULL)break;
            else printf("%d ", root->key.name[i]);
        } printf("]\n");
        print(root->right);
    }

}

tree* search(tree* root, list data) { // �˻� �Լ�

    while (root != NULL) {
        if (strcmp(data.name, root->key.name) == 0) return root; // Ű �� ��ġ�ϸ� root ����
        else if (strcmp(data.name, root->key.name) < 0) root = root->left; // Ű ���� ������ �������� �̵�
        else if (strcmp(data.name, root->key.name) > 0) root = root->right; // Ű ���� ũ�� ���������� �̵�
    }
}
void run() { // �ý��� ����

    list e; // ���� ����ü
    char str; // ����ġ������ �Է� ���� ����
    tree* root = NULL; // ���� Ʈ��
    tree* temp; // �˻� ��带 ��ȯ ���� ���

    while (1)
    {
        printf("����(i) Ž��(s) ���(p) ����(d)");
        scanf_s("%c", &str, sizeof(str));
        getchar();
        switch (str)
        {
        case 'i':
            printf("ģ���� �̸�:");
            gets(e.name);
            printf("ģ���� ��ȭ��ȣ:");
            gets(e.number);
            insert(&root, e);
            break;
        case 's':
            printf("�˻� �� ģ���� �̸�:");
            gets(e.name);
            temp = search(root, e);
            printf("ģ���� ��ȭ��ȣ:%s\n", temp->key.number);
            break;
        case 'p':
            printf("���:");
            print(root);
            break;
        case 'd':
            printf("���� �� ģ���� �̸�:");
            gets(e.name);
            delete(&root, e);
            break;
        default:
            printf("�ٽ� �Է�");
            break;

        }
    }
}
int main() {
    run(); // �ý��� ���� �Լ� ����
}
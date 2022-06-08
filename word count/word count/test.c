#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_NAME 20 // name 사이즈 정의
#define MAX_NUMBER 40 // number 사이즈 정의

typedef struct list { // 정보 저장 구조체
    char name[MAX_NAME]; //이름
    char number[MAX_NUMBER]; //전화번호
}list;

typedef struct tree { // 노드 구조체
    list key; //정보 저장 구조체
    struct tree* left; // 링크
    struct tree* right; // 링크
}tree;

void insert(tree** root, list data) { // 삽입 함수
    tree* p = NULL; //부모 노드
    tree* t = *root; // 자식 노드

    while (t != NULL) { // t가 NULL이 아니다 -> 루트가 있으며 탐색이 끝나면 말단이다.
        if (strcmp(data.name, t->key.name) == 0) return; // 키 중복 확인
        p = t; // 다음 값을 순회하기 위해 저장
        if (strcmp(data.name, t->key.name) < 0) t = t->left; // 루트 키값 보다 작음, 왼쪽으로 이동
        else t = t->right; // 루트 키값 보다 큼, 오른쪽으로 이동
    }

    tree* newtree = (tree*)malloc(sizeof(tree)); // 새로운 노드 동적할당으로 생성
    newtree->key = data; // 키값 삽입
    newtree->left = newtree->right = NULL; // 링크 초기화

    if (p != NULL) { // p는 삽입할곳에 부모 노드를 가리키고 있음
        if (strcmp(data.name, p->key.name) < 0) p->left = newtree; // 키 값을 비교해서 작으면 왼쪽
        else p->right = newtree; // 키 값을 비교해서 크면 오른쪽
    }
    else *root = newtree;  // 다 해당 안되면 처음 생성되는 루트 노드이다.
}

void print(tree* root) { // 트리 출력 함수
    if (root != NULL) { // 중위 순회
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

tree* search(tree* root, list data) { // 검색 함수

    while (root != NULL) {
        if (strcmp(data.name, root->key.name) == 0) return root; // 키 값 일치하면 root 리턴
        else if (strcmp(data.name, root->key.name) < 0) root = root->left; // 키 값이 작으면 왼쪽으로 이동
        else if (strcmp(data.name, root->key.name) > 0) root = root->right; // 키 값이 크면 오른쪽으로 이동
    }
}
void run() { // 시스템 구동

    list e; // 정보 구조체
    char str; // 스위치문에서 입력 받을 변수
    tree* root = NULL; // 최초 트리
    tree* temp; // 검색 노드를 반환 받을 노드

    while (1)
    {
        printf("삽입(i) 탐색(s) 출력(p) 삭제(d)");
        scanf_s("%c", &str, sizeof(str));
        getchar();
        switch (str)
        {
        case 'i':
            printf("친구의 이름:");
            gets(e.name);
            printf("친구의 전화번호:");
            gets(e.number);
            insert(&root, e);
            break;
        case 's':
            printf("검색 할 친구의 이름:");
            gets(e.name);
            temp = search(root, e);
            printf("친구의 전화번호:%s\n", temp->key.number);
            break;
        case 'p':
            printf("출력:");
            print(root);
            break;
        case 'd':
            printf("삭제 할 친구의 이름:");
            gets(e.name);
            delete(&root, e);
            break;
        default:
            printf("다시 입력");
            break;

        }
    }
}
int main() {
    run(); // 시스템 구동 함수 실행
}
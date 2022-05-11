#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_DEGREE 101

typedef struct {
    float coef;
    int expon;
}polynomial;


typedef struct term* ptrDterm;
typedef struct term {
    float coef;
    int expon;
    ptrDterm link;
};



ptrDterm D;

polynomial terms[MAX_DEGREE];

int avail = 1;


polynomial polynomial_read() {
    printf("다항식 A(x)를 입력하세요(1x0+2x2+4x3 형태로(오름차순)). 단, 항의 수는 3개로 하며, 지수 값은 0이상 9이하로 한다.\n");
    scanf("%fx%d%fx%d%fx%d", &terms[0].coef, &terms[0].expon, &terms[1].coef, &terms[1].expon, &terms[2].coef, &terms[2].expon);
    printf("다항식 B(x)를 입력하세요(1x0+2x2+4x3 형태로(오름차순)). 단, 항의 수는 3개로 하며, 지수 값은 0이상 9이하로 한다.\n");
    scanf("%fx%d%fx%d%fx%d", &terms[3].coef, &terms[3].expon, &terms[4].coef, &terms[4].expon, &terms[5].coef, &terms[5].expon);


}

ptrDterm createNode(float coef, int expon) {
    ptrDterm p = (ptrDterm)malloc(sizeof(D)*3);
    p->coef = coef;
    p->expon = expon;
    p->link = NULL;
    free(D);
    return p;
}

void addNode(ptrDterm* root, float coef, int expon) {
    ptrDterm p = *root;
    ptrDterm prev = NULL;

    if (*root == NULL) {
        *root = createNode(coef, expon);
        return;
    }
    while (p) {
        if (p->expon == expon) {
            p->coef += coef;
            break;
        }
        else if (p->expon < expon) {
            ptrDterm nnode = createNode(coef, expon);
            nnode->link = p;
            if (prev) {
                prev->link = nnode;
            }
            else {
                *root = nnode;
            } 
            break;
        }

        if (p->link == NULL) {
            ptrDterm nnode = createNode(coef, expon);
            p->link = nnode;
            break;
        }
        prev = p;
        p = p->link;
    }
}

ptrDterm p = NULL;

polynomial multiply() {
   
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 6; j++) {
            addNode(&p, terms[i].coef * terms[j].coef, terms[i].expon + terms[j].expon);
        }
    }

}

void polyPrint(ptrDterm poly) {

    ptrDterm p = poly;

    while (p) {
        while (p->coef == 0) {
            p = p->link;
        }
        if (p->coef > 0)
        {
            printf("+");
        }

        if (p->expon >= 0) {
            printf("%gx%d", p->coef, p->expon);
        }

        p = p->link;
    }
    printf("\n");
}


int main()
{
    polynomial_read();
    multiply();
    printf("A(x)= ");
    for (int i = 0; i < terms[0].expon; i++) {
        if (i != 0) {
            printf("+");
        }
        printf("0x%d", i);
    }
    if (terms[0].coef > 0) {
        printf("+");
    }
    printf("%.0fx%d", terms[0].coef, terms[0].expon);
    for (int i = terms[0].expon + 1; i < terms[1].expon; i++) {
        printf("+0x%d", i);
    }
    if (terms[1].coef > 0) {
        printf("+");
    }
    printf("%.0fx%d", terms[1].coef, terms[1].expon);
    for (int i = terms[1].expon + 1; i < terms[2].expon; i++) {
        printf("+0x%d", i);
    }
    if (terms[2].coef > 0) {
        printf("+");
    }
    printf("%.0fx%d", terms[2].coef, terms[2].expon);
    printf("\n");

    printf("B(x)= ");
    for (int i = 0; i < terms[3].expon; i++) {
        if (i != 0) {
            printf("+");
        }
        printf("0x%d", i);
    }
    if (terms[3].coef > 0) {
        printf("+");
    }
    printf("%.0fx%d", terms[3].coef, terms[3].expon);
    for (int i = terms[3].expon + 1; i < terms[4].expon; i++) {
        printf("+0x%d", i);
    }
    if (terms[4].coef > 0) {
        printf("+");
    }
    printf("%.0fx%d", terms[4].coef, terms[4].expon);
    for (int i = terms[4].expon + 1; i < terms[5].expon; i++) {
        printf("+0x%d", i);
    }
    if (terms[5].coef > 0) {
        printf("+");
    }
    printf("%.0fx%d", terms[5].coef, terms[5].expon);
    printf("\n");

    printf("D(x)= ");
    polyPrint(p);

   
}
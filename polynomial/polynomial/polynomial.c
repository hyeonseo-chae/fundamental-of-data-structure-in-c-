#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MAX_DEGREE 101

typedef struct {
    float coef;
    int expon;
}polynomial;

polynomial terms[MAX_DEGREE];
polynomial D[MAX_DEGREE]={0,};
int avail = 1;
int D_temp[9] = { 0, };

polynomial polynomial_read() {
    printf("다항식 A(x)를 입력하세요(1x0+2x2+4x3 형태로(오름차순)). 단, 항의 수는 3개로 하며, 지수 값은 0이상 9이하로 한다.\n");
    scanf("%fx%d%fx%d%fx%d",&terms[0].coef,&terms[0].expon,&terms[1].coef,&terms[1].expon,&terms[2].coef,&terms[2].expon);
    printf("다항식 B(x)를 입력하세요(1x0+2x2+4x3 형태로(오름차순)). 단, 항의 수는 3개로 하며, 지수 값은 0이상 9이하로 한다.\n");
    scanf("%fx%d%fx%d%fx%d", &terms[3].coef, &terms[3].expon, &terms[4].coef, &terms[4].expon, &terms[5].coef, &terms[5].expon);


}

polynomial polynomial_makeD() {
    int D_temp_A[3] = { 0, };
    int D_temp_B[3] = { 0, };
    
    int q = 0;
    for (int i = 0; i < 3; i++) {
        D_temp_A[i] = terms[q].expon;
        q++;
    }
    for (int j = 0; j < 3; j++) {
        D_temp_B[j] = terms[q].expon;
        q++;
    }
    int e = 0;
    for (int k = 0; k < 3; k++) {
        for (int n = 0; n < 3; n++) {
            D_temp[e] = D_temp_A[k] + D_temp_B[n];
            e++;
        }
    }

    int temp = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            if (D_temp[j] < D_temp[j + 1]) { //버블정렬
                temp = D_temp[j];
                D_temp[j] = D_temp[j + 1];
                D_temp[j + 1] = temp;
            }
        }
    }

    int set[9]={0,};
    set[0] = D_temp[0];

    for (int i = 0; i < 9; i++) { //중복 제거
        if (D_temp[i] != set[avail - 1]) {
            set[avail++] = D_temp[i];
        }
    }

    int* new_D = (int*)malloc(sizeof(int) * avail);
    

    for (int i = 0; i < avail; i++) {
        new_D[i] = set[i];
    }

  
    for (int i = 0; i < avail; i++) {
        D[i].expon = new_D[i];
        //printf("%d ", new_D[i]);
    }
    free(new_D);

}

polynomial multiply() {
    int pk = 0;
    for (int k = 0; k < 3; k++) {
        for (int n = 3; n < 6; n++) {
            pk = terms[k].expon + terms[n].expon;
            for (int u = 0; u < avail; u++) {
                if (D[u].expon == pk) {
                    D[u].coef = D[u].coef + (terms[k].coef * terms[n].coef);
                    
                }
            }
            
            
        }
    }
}


int main()
{
    polynomial_read();
    polynomial_makeD();
    multiply();
    printf("A(x)= ");
    for (int i = 0; i < terms[0].expon; i++) {
        if (i != 0) {
            printf("+");
        }
        printf("0x%d",i);
    }
    if (terms[0].coef > 0) {
        printf("+");
    }
    printf("%.0fx%d", terms[0].coef, terms[0].expon);
    for (int i = terms[0].expon+1; i < terms[1].expon; i++) {
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
    for (int i = 0; i < avail; i++) {
        if (i!=0 && D[i].coef > 0) {
            printf("+");
        }
        if (D[i].coef != 0) {
            printf("%.0fx%d", D[i].coef, D[i].expon);
        }
        
    }
    
    
}
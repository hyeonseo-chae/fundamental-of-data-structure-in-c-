#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
char name_binary_tree[16][15] = { "","Dusty","Honey","Brandy","Brunhide","Terry","Coyote","Nugget","Gill","Tansey","Tweed","Zoe","Crocus","Primrose","Nous","Belle" };

void preorder(int k)
{
	
	if (k > 15) {
		return;
	}
	printf("%s, ", name_binary_tree[k]);
	preorder(k * 2);
	preorder(k * 2 + 1);

}

void main()
{
	
	char s1[15]="";
	char s2[15]="";
	char a;

	

	while (1) {
		
		printf("?\n");
		scanf("%s",s1);
		if (strstr(s1, "END") != NULL) {
		break;
		}
		int c = 0;
		a = s1[0];
		for (int i = 2; i < strlen(s1)-1; i++) {
			s2[c] = s1[i];
			c++;
		}
		s2[c] = '\0';
		int jj;
		for (jj = 0; jj < 16; jj++) {
			if (strcmp(name_binary_tree[jj], s2)==0) {
				printf("%d\n", jj);
				break;
			}
		
		}

		

		if (a == 'A') {
			if (jj > 7 && jj < 16) {
				printf("UnKnown\n");
			}
			preorder(jj*2);
			preorder(jj * 2+1);
		}
		else if (a == 'D') {
			if (jj ==1) {
				printf("UnKnown");
			}
			while (jj>1.9) {
				jj = jj / 2;
				printf("%s, ", name_binary_tree[jj]);
			}
			printf("\n");
		}
		else if (a == 'R') {

		}
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
char name_binary_tree[16][15] = { "","Dusty","Honey","Brandy","Brunhide","Terry","Coyote","Nugget","Gill","Tansey","Tweed","Zeo","Crocus","Primrose","Nous","Belle" };
int preorderprint[16] = { 0, };
int preoirdernum = 0;

void preorder(int k)
{
	
	if (k > 15) {
		return;
	}
	preorderprint[preoirdernum] = k;
	preoirdernum++;
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
				break;
			}
		
		}

		
		char split[2][15];
		if (a == 'A') {
			for(int q = 0; q < 16; q++) {
				preorderprint[q] = 0;

			}
			preoirdernum = 0;
			if (jj > 7 && jj < 16) {
				printf("UnKnown\n");
			}
			preorder(jj*2);
			preorder(jj * 2+1);
			for(int e = 0; e < 16; e++) {
				if (preorderprint[e] != 0) {
					printf("%s", name_binary_tree[preorderprint[e]]);
					if (preorderprint[e + 1] != 0) {
						printf(", ");
					}
					else {
						printf("\n");
					}
				}
				
			}
		}
		else if (a == 'D') {
			if (jj ==1) {
				printf("UnKnown");
			}
			while (jj>1.9) {
				jj = jj / 2;
				printf("%s", name_binary_tree[jj]);
				if (jj != 1) {
					printf(", ");
				}
			}
			printf("\n");
		}


		else if (a == 'R') {
	
			char* num = NULL;
			num = strtok(s2, ",");
			int oq = 0;
			while (num != NULL) {
				strcpy(split[oq], num);
				oq++;
				num = strtok(NULL, ",");
			}
			int splitjj1 = 0;
			int splitjj2 = 0;
			for (splitjj1 = 0; splitjj1 < 16; splitjj1++) {
				if (strcmp(name_binary_tree[splitjj1], split[0]) == 0) {
					break;
				}

			}

			for (splitjj2 = 0; splitjj2 < 16; splitjj2++) {
				if (strcmp(name_binary_tree[splitjj2], split[1]) == 0) {
					break;
				}

			}

			char s_list[5];
			int yy = 0;
			while(splitjj2!= splitjj1) {
				s_list[yy] = splitjj2+'0'; //����ȯ
				yy++;
				if (splitjj2 % 2 == 1) {
					s_list[yy] = 'F';
				}
				else {
					s_list[yy] = 'M';
				}
				yy++;
				splitjj2 = splitjj2 / 2;
			}
			s_list[yy] = splitjj2 + '0';
			 
			for(int u = yy; u >= 0; u--) {
				if (u % 2 == 0) {
					printf("%s", name_binary_tree[(s_list[u]-'0')]);
				}
				else {
					printf("%c", s_list[u]);
				}

				if (u != 0) {
					printf(" -> ");
				}
			
			}
			printf("\n");
		}
	}
}

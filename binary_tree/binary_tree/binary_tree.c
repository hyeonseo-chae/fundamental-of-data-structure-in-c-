#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char name_binary_tree[16][11] = { NULL,"Dusty","Honey Bear","Brandy","Brunhide","Terry","Coyote","Nugget","Gill","Tansey","Tweed","Zoe","Crocus","Primrose","Nous","Belle" };
	char s1[15];

	while (1) {
		char s1[15];
		printf("?");
		scanf("%s", s1);

		if (strstr(s1, "A(") != NULL) {
			printf("A");
		}
		else if (strstr(s1, "D(") != NULL) {

		}
		else if (strstr(s1, "R(") != NULL) {

		}
		else if (strstr(s1, "END") != NULL) {
			break;
		}
	}

}

#include <stdio.h>
#include <stdlib.h>
#define ENTER 10

int main() {
	int digits, letters, others, c;
	digits = letters = others = c = 0;
	others--;
	printf("Enter a string: \n");
	while (c != ENTER){
		c = getchar();
		if(c >= '0' && c <= '9') digits++;
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <='Z')) letters++;
		else others++;
	}
	printf("Digits in string: %d\n", digits);
	printf("Letters in string: %d\n", letters);
	printf("Others in string: %d\n", others);
	return 0;
}

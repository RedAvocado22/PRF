#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool Prime_check(int n) {
	int i;
	if (n == 2) return true;
	for(i = 2; i < sqrt(n); i++) 
		if (n % i == 0) return false;
	return true;
}
int main() {
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	int i;
	printf("\n");
	for(i = 2; i <= n; i++)
		if(Prime_check(i) == true) printf("%d  ", i);
	return 0;
}

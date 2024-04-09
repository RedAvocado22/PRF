#include <stdio.h>
#include <stdlib.h>

int n; 
double x;
char c1;

int main() {
	int m;
	short s;
	long L;
	float y;
	printf("Code of main: %u\n", &main);
	printf("Variable n, address: %u, memory size: %d\n", &n, sizeof(n));
	printf("Variable x, address: %u, memory size: %d\n", &x, sizeof(x));
	printf("Variable c1, address: %u, memory size: %d\n", &c1, sizeof(c1));
	printf("Variable m, address: %u, memory size: %d\n", &m, sizeof(m));
	printf("Variable s, address: %u, memory size: %d\n", &s, sizeof(s));
	printf("Variable L, address: %u, memory size: %d\n", &L, sizeof(L));
	printf("Variable y, address: %u, memory size: %d\n", &y, sizeof(y));
	return 0;
	//Nguyen Minh Cuong//
}

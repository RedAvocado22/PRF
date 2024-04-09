#include <stdio.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  	int a, b;

  	printf("Enter two integers: ");
  	scanf("%d %d", &a, &b);

  	while (a != 0 && b != 0) {
    	swap(&a, &b);

    	printf("a = %d, b = %d\n", a, b);

    	printf("Enter two integers: ");
    	scanf("%d %d", &a, &b);
  	}
	//Nguyen Minh Cuong
  	return 0;
}

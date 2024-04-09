#include <stdio.h>

int main() {
	int inputValue, sum;
	sum = 0;
	
	printf("Enter an integer: ");
  	do {
    	scanf("%d", &inputValue);
    	sum += inputValue;
  	} while (inputValue != 0);
  	
	printf("The sum of the integers is: %d\n", sum);
	
	//Nguyen Minh Cuong
  	return 0;
}

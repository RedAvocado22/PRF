#include <stdio.h>
#include <conio.h>

void printFibonacci(int n) {
  	int a = 0, b = 1, c;
  	printf("The first %d Fibonacci numbers are: ", n);
  	int i;
  	for (i = 0; i < n; i++) {
    	printf("%d ", a);
    	c = a + b;
    	a = b;
    	b = c;
 	}
 	printf("\n");
}

int isValidDate(int day, int month, int year) {
  	if (year < 1) return 0;
  	if (month < 1 || month > 12) return 0;	
  	if (day < 1 || day > 31) return 0;
  	if (month == 2 && day > 29 && year % 4 != 0) return 0;
 	return 1;
} 

int main() {
 	int x, n;
 	int day, month, year;
 	printf("1- Fibonacci sequence\n");
   	printf("2- Check a date\n");
    printf("3- Quit\n");
    printf("Choose an operation: ");
    scanf("%d", &x);
  	while (x == 1 || x == 2) {
  		switch (x) {
			case 1:
        		n = 0;
        		printf("Enter a positive integral number: ");
       			scanf("%d", &n);
        		printFibonacci(n);
        		break;
      		case 2:
        		day = 0, month = 0, year = 0;
        		printf("Enter a date in the format dd/mm/yyyy: ");
        		scanf("%d/%d/%d", &day, &month, &year);
        		if (isValidDate(day, month, year)) printf("The date is valid.\n");
        			else printf("The date is not valid.\n");
        		break;
      		default:
      			break;
      	}
		printf("1- Fibonacci sequence\n");
   		printf("2- Check a date\n");
    	printf("3- Quit\n");
    	printf("Choose an operation: ");
    	scanf("%d", &x);
	}	
	printf("Goodbye!");
  	return 0;
}



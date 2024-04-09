#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

bool Process_Primes(int n){
	if (n == 0) return false; 

	if (n == 1 || n == 2 || n == 3) 
		return true;
		
	int i;
	for(i = 2; i <= n/2; i++)
		if(n % i == 0) {
			printf("Number %d is not a prime.\n",n);
			return false; 
		}
	printf("Number %d is a prime.\n",n);
	return true;
}

void min_max_digits(int n){
	int min = 9, max = 0, k;
  	while (n > 0) {
    k = n % 10;
    n /= 10;
    if (max < k) max = k;
    if (min > k) min = k;
  }
  printf("max = %d\n", max);
  printf("min = %d\n", min);
}

int main() {
 	int x, n = 0;
 	printf("1 - Process primes.\n");
 	printf("2 - Print min, max digit in a integer.\n");
 	printf("3 - Quit.\n");
 	printf("Select an operation: ");
  	scanf("%d", &x);
  	while (x == 1 || x == 2) {
  		switch (x) {
			case 1:
				printf("Enter integral number: ");
				scanf("%d", &n);
				if (Process_Primes(n)) printf("%d is a prime number.\n", n);
					else printf("%d is not a prime number.\n", n);
				break;
			case 2:
				printf("Enter integral number.\n",n);
				scanf("%d", &n);
				min_max_digits(n);	
				break;
			default:
				break;
		}
		printf("Select an operation: ");
  		scanf("%d", &x);
	}	
	printf("Goodbye!",n);
  	return 0;
}


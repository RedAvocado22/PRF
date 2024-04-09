#include <stdio.h>
#include <stdlib.h>

int main() {
	int ic, n, ti = 0;
	printf("Your income of this year: ");
	scanf("%d", &ic);
	printf("Number of dependent: ");
	scanf("%d", &n);
	printf("Tax-free income: %d\n", 12 * (9000000 + 3600000 * n));
	printf("Taxable income: %d\n", ic - 12 * (9000000 + 3600000 * n));
	ti = ic - 12 * (9000000 + 3600000 * n);
	if (ti <= 0) printf("Income tax: 0");
		else if (ti <= 5000000) printf("Income tax: %d", (ti / 100) * 5);
			else if (ti <= 10000000) printf("Income tax: %d", (ti / 100) * 10);
				else if (ti <= 18000000) printf("Income tax: %d", (ti / 100) * 15);
					else if (ti > 18000000) printf("Income tax: %d", (ti / 100) * 20);
	return 0;
	//Nguyen Minh Cuong
}

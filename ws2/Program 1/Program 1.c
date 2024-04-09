#include <stdio.h>
#include <stdlib.h>

int main() {
	double a, b;
	char  op;
	scanf( "%lf%c%lf", &a, &op, &b);
	switch (op) {	
     	case '+':
         	printf("%lf + %lf = %.2f", a, b, (double)a + b);
         	break;
     	case '-':
         	printf("%lf - %lf = %.2f", a, b, (double)a - b);
         	break;
     	case '*':
         	printf("%lf * %lf = %.2f", a, b, (double)a * b);
         	break;
     	case '/': 
         	if(b == 0) {
            printf("Cant divide by 0.");
         	}
				else {
             		printf("%.2f / %.2f = %.2f", a, b, (double)a / b);
         		}
         break;
   
     default:
     printf("%c is not supported!", op);
         break;
   }
	return 0;
	//Nguyen Minh Cuong
}

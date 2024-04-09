#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int gcd(int A, int B)
{
    while (A != B)
    {
        if (A > B)
            A -= B;
    	else
	    B -= A;
    }
    return A;
}
int lcm(int A, int B)
{
    return (A / gcd(A, B)) * B;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x >= 0 || y >= 0) {
       printf("the greatest common divisor of %d and %d is %d\n", x, y, gcd(x,y));
       printf("the least common multiple of %d and %d is %d", x, y, lcm(x,y));
    }

    return 0;
}

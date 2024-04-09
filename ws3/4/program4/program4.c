#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n;
    long long sum = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
        sum *= i;
    printf("Factorial of an integer: %d", sum);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int digits(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    int n;
    do {
        fflush(stdin);
        scanf("%d", &n);
        if(n > 0) {
            printf("The sum digits of %d is %d.\n", n, digits(n));
        }
    } while(n >= 0);
    return 0;
}

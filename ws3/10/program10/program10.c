#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void min_min_digit(int n) {
    int min = 10;
    int max = -1;
    int m = n;
    while (n > 0) {
        int digit = 0;
        digit = n % 10;
        if (min > digit) min = digit;
        if (max < digit) max = digit;
        n /= 10;
    }
    printf("the maximum digits of %d is %d\n", m, max);
    printf("the minimum digits of %d is %d", m, min);
}
int main() {
    int n;
    do {
        scanf("%d", &n);
        if(n > 0) {
            min_min_digit(n);
        }
    } while(n > 0);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double make_real_number(int x, int y) {
    double a = y;
    while (a >= 1) {
        a = a/10;
    }
    double b = 0;
    if(x < 0) {
        b = x - a;
        return b;
    }
        else {
            b = x + a;
            return b;
        }
}
int main() {
    int x, y;
    do {
        scanf("%d%d", &x, &y);
        if(y > 0) {
            printf("The real number make by 2 integers is: %lf\n", make_real_number(x,y));
        }
    } while (y > 0);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool checkfibonacci(int n){
    int a = 1;
    int b = 1;
    if (n == 1) return true;
    int c = a + b;
    while(c <= n){
        if(c == n) return true;
        a = b;
        b = c;
        c = a + b;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    if(checkfibonacci(n) == true) printf("%d is a Fibonacci element.", n);
        else printf("%d is not a Fibonacci element.", n);
    return 0;
}

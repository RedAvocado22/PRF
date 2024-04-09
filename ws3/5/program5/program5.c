#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

long long fibo ( int n) {
    int t1=1, t2=1, f=1, i;
    for (i= 3; i<=n; i++) {
      f= t1 + t2;
      t1= t2;
      t2=f;
   }
   return f;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("The %d number of fibonacci is %ld.", n, fibo(n));
    return 0;
}

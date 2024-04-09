#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int n;
int a[10001];

void check() {
    int count = n;
    for (int i = 1; i <= n/2; i++) {
        if(a[i] != a[count]) {
            printf("0");
            return;
        }
        count--;
    }
    printf("1");
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    check();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll checkISBN(ll n) {
    int a[12], c[12];
    int i, count = 2, result = 0;
    result += n%10;
    n /= 10;
    while (count < 11) {
        result += (n % 10)*count;
        n /= 10;
        count++;
    }
    if(result % 11 == 0) return 1;
        else return result;
}
int main()
{
    ll n;
    printf("============== ISBN Validator ==============");
    do {
        printf("\nISBN (0 to quit): ");
        scanf("%d", &n);
        if(n == 0) break;
        if(checkISBN(n) == 1) printf("This is a valid ISBN.\n");
            else printf("This is not a valid ISBN.\n");
    } while (n != 0);
    printf("Have a Nice Day!\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int main() {
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  int uoc = gcd(a, b);
  int boi = lcm(a, b);

  printf("The GCD of %d and %d is %d.\n", a, b, uoc);
  printf("The LCM of %d and %d is %d.\n", a, b, boi);

  return 0;
}

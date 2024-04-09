#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int Get_Pos_Of_Poi(double x, double y, double r) {
	double d = x*x + y*y;
	double r2 = r*r;
	if(d < r2) return 1;
		else if (d == r2) return 0;
	return -1;
}
int main() {
	double x, y, r;
	printf("Enter point p: ");
	scanf("%lf %lf", &x, &y);
	printf("\nEnter radius of circle: ");
	scanf("%lf", &r);
	if (Get_Pos_Of_Poi(x,y,r) == 1) printf("\nThe point is in the circle");
		else if (Get_Pos_Of_Poi(x,y,r) == 0) printf("\nThe point is on the circle");
			else printf("\nThe point is out of the circle");
	return 0;
}

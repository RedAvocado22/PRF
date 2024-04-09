#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool Valid_Date(int d, int m, int y) {
	int maxd = 31;
	if ( d < 1 || d > 31 || m < 1 || m > 12 || y < 0) return 0;
	if ( m == 4 || m == 6 || m == 9 || m == 11) maxd=30;
		else if (m == 2) {
            	if (y % 400 == 0 || ( y%4 == 0 && y % 100 != 0)) maxd=29;
            	else maxd=28;
       		}
	if (d <= maxd) return true;
	return false;
}

int main() {
	int d, m, y;
	printf("Enter a date following structure: dd/mm/yyyy\n");
	scanf("%d/%d/%d", &d, &m, &y);
	if(Valid_Date(d,m,y) == true) printf("A valid date!");
		else printf("This is not a valid date!");
}

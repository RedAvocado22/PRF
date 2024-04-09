#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n = -1;

int findnemo(int a[], int x) {
    int i = 0, result = 0;
    for(i = 0; i <= n; i++)
        if(a[i] == x) result++;
    return result;
}

void coutt(int a[]) {
    int i = 0;
    for(i = 0; i <= n; i++)
        printf("%d ", a[i]);
}

void max_min_value(int a[], int x, int y) {
    int i,check = 0;
    for(i = 0; i <= n; i++)
        if(a[i] >= x && a[i] <= y) {
            printf("%d ", a[i]);
            check++;
        }
    if(check == 0) printf("There not exist any value in array.");
}

void bubbleSort(int arr[]) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i ; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void printout_sorted(int a[]) {
    int b[n+1];
    int i;
    for(i = 0; i <= n; i++)
        b[i] = a[i];
    bubbleSort(b);
    for(i = 0; i <= n; i++)
        printf("%d ", b[i]);
}

int main()
{
    int a[100];
    int x, m, min_v, max_v;
    printf("=========================================================\n");
    printf("1 - Add  a value.\n");
 	printf("2 - Search a value.\n");
 	printf("3 - Print out the array.\n");
 	printf("4 - Print out values in a range.\n");
 	printf("5 - Print out the array in ascending order.\n");
 	printf("0 - Quit.\n");
 	printf("Select an operation: ");
  	scanf("%d", &x);
  	while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
  		switch (x) {
			case 1:
			    if(n == 100) {
                    printf("Full memory!");
                    printf("Choose the others operation to continue.");
                    break;
			    }
				printf("Enters a value then it is added to the array: ");
				scanf("%d", &m);
				n++;
				a[n] = m;
				break;
			case 2:
                printf("Enters a value then number of it is existences will be printed out: ");
                scanf("%d", &m);
                int meo = findnemo(a,m);
                if(meo == 0) printf("%d not existences in array.\n", m);
                    else printf("%d have been found %d times in array.\n", m, meo);
				break;
            case 3:
                printf("Values in the array will be printed out.\n");
                coutt(a);
                printf("\n");
                break;
            case 4:
                printf("Enter 2 value: ");
                scanf("%d %d", &min_v, &max_v);
                max_min_value(a,min_v,max_v);
                printf("\n");
                break;
            case 5:
                printf("Array will be printed out in ascending order: ");
                printout_sorted(a);
                printf("\n");
			default:
				break;
		}
		fflush(stdin);
		printf("\n=========================================================\n");
		printf("1 - Add  a value.\n");
        printf("2 - Search a value.\n");
        printf("3 - Print out the array.\n");
        printf("4 - Print out values in a range.\n");
        printf("5 - Print out the array in ascending order.\n");
        printf("Others - Quit.\n");
		printf("Select an operation: ");
  		scanf("%d", &x);
	}
	printf("Goodbye!",n);
    return 0;
}


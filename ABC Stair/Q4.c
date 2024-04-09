//Version. 1
#include <stdio.h>
#include <string.h>

int main(){
	int i, j, n, c=65;
	fflush(stdin);
	scanf("%d", &n);
	char s1[256], temp1[256], temp2[256];
	printf("\nOUTPUT:\n");
	s1[0]=(char) c;
	s1[1]='\0';
	printf("%s\n", s1);
	c++;
	for(i=1; i<n; i++){
		s1[i]=(char) c;
		for(j=0; j<=i; j++)
			temp1[j]=s1[j];
		temp1[j]='\0';

		for(j=0; j<=i-1; j++)
			temp2[j]=s1[j];
		temp2[j]='\0';

		strrev(temp2);
		strcat(temp1, temp2);
		printf("%s\n", temp1);
		c++;
	}

	getchar();
	return 0;
}

//Version. 2
/*#include<stdio.h>

int main() {
    int i, j, rows, count=0;

    printf("Enter the number of rows\n");
    scanf("%d", &rows);

    for (i = 0; i < 2*rows; i=i+2) {
        for (j = 0; j <= i; j++) {
            printf("%c", 'A'+count);
            if(j < i/2)
                count++;
            else
                count--;
        }
        count = 0;
        printf("\n");
    }
    return(0);
}*/


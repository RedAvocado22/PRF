#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputList(char *list[], int n){
	int i;
	for(i = 0; i < n; i++) {
        fflush(stdin);
        //scanf("%[^\n]s", list[i]);
        gets(list[i]);
	}
}
void outputList(char *list[], int n){
    int i;
    for(i = 0; i < n; i++) {
        puts(list[i]);
        printf("\n");
    }
}
void sortList(char *list[], int n){
    int i,j,min;
	for(i=0;i<n-1;i++){
		min=i;
		for (j=i+1;j<n;j++){
			if (strcmp(list[j],list[min])<0)
				min=j;
		}
		if (min!=i){
			char *tmp=malloc(50);
			strcpy(tmp,list[i]);
			strcpy( list[i],list[min]);
			strcpy( list[min],tmp);
		}
	}
}

int main()
{
    int n;
    scanf("%d", &n);
    char *s[50];
    int i;
    for(i = 0; i < n; i++)
        s[i] = malloc(50);
    inputList(s, n);
    sortList(s, n);
    outputList(s, n);
    return 0;
}

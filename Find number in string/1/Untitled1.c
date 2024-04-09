#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char s[100];
	int i;
	gets(s);
	int sum = 0;
	for(i=0; i<strlen(s); i++){
		if(s[i]>='0' && s[i]<='9'){
			if(s[i]%2!=0)
				sum +=  s[i]-'0';
		}
	}
	printf("%d", sum);
}

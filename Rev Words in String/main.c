#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char reverse_string(char s[], char* reverse) {
    reverse[0] = "\0";
    int i, j, n;
    n = strlen(s);
    for(i = n-1; i >= 0; --i) {
        char temp[50];
        for(j = 0; i >= 0 && s[i] != ' '; --i,++j)
            temp[j] = s[i];

        temp[j] = '\0';
        strrev(temp);

        strcat(reverse, temp);
        strcat(reverse, " ");
   }
   return reverse;
}

int main()
{
    char s[50];
    fflush(stdin);
    gets(s);
    char* rev[50];
    reverse_string(s, rev);
    puts(rev);
    return 0;
}

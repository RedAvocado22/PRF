#include <stdio.h>
#include <ctype.h>

int main() {
  char ch;
  int vowelCount = 0;
  int consonantCount = 0;
  int otherCount = 0;

  printf("Enter a string of characters: ");

  while ((ch = getchar()) != '\n') {
    ch = toupper(ch);

    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') vowelCount++;
    	else if (isalpha(ch)) consonantCount++;
    		else otherCount++;
  }

  printf("Number of vowels: %d\n", vowelCount);
  printf("Number of consonants: %d\n", consonantCount);
  printf("Number of others: %d\n", otherCount);

  return 0;
}

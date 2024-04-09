#include <stdio.h>

int main() {
	char char1, char2;

  	printf("Enter two characters: ");
  	scanf("%c %c", &char1, &char2);

  	int difference = char2 - char1;
	
  	char charactersBetween[difference];
  	
  	for (int i = 0; i < difference; i++) 
    	charactersBetween[i] = char1 + i + 1;

  	printf("ASCII code difference: %d\n", difference);
  	
  	if(difference <= 1) {
		printf("No characters between.");
		return 0;
	} 
	
  	printf("Characters between:\n");
  	for (int i = 0; i < difference; i++) 
    	printf("%c (decimal: %d, octal: %o, hexadecimal: %x)\n", charactersBetween[i], charactersBetween[i], charactersBetween[i], charactersBetween[i]);
    	
	// Nguyen Minh Cuong
 	return 0;
}

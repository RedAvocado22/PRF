#include <stdio.h>

int main() {
  	int asciiCode;

  	printf("ASCII code table:\n");

	for (asciiCode = 0; asciiCode < 256; asciiCode++) {
  	  printf("%c ", (char)asciiCode);
  	  printf("(%d)\n", asciiCode);
  	}
  	
  	//Nguyen Minh Cuong
  	return 0;
}

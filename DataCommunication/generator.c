#include <stdio.h>
#include <string.h>

int main() {
	char frame[50];		//1101011011
	char generator[50];	//10011
	scanf("%s", frame);		//read n-bit message
	scanf("%s", generator);	//k-bit polynomial

	printf("%s\n", frame);	//n+k-1
	printf("%s\n", generator);
	return 0;
}
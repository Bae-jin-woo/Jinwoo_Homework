#include <stdio.h>
#include <string.h>

int main(int argv) {
	int change = 4;
	char frame[50];		//1101011011
	char generator[50];	//10011
	scanf("%s", frame);		//read n-bit message
	printf("before : %s\n", frame);
	if (frame[change] == '0')
		frame[change] = '1';
	else frame[change] = '0';

	printf("after : %s\n", frame);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ex3.h"

int main()
{
	char c;

	read_record(fname);

	printf("*************¸í·É¾î*************\n");
	printf("P:Print all records \n");
	printf("S:Search record \n");
	printf("C:Change record \n");
	printf("W:Write record \n");
	printf("Q:Save and quit \n");

	while (1)
	{
		printf("\n Command >>");
		scanf("%c", &c);



		switch (c)
		{
		case 'P':
			print_record();
			break;
		case 'S':
			search_record();
			break;
		case 'C':
			change_record();
			break;
		case 'W':
			write_record(fname);
			break;
		case 'Q':
			printf("\n");
			exit(1);
			break;
		default:
			printf("Unknown Command !\n");
			break;
		}
	}

	return 0;
}
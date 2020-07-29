#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "ProjectHeader.h"

void main()
{
	char c, fname[20];
	char key[100];
	int	wcount = 0, judge;
	dcount = 0;
	ccount = 0;

	puts("\n\t\t * SIMPLE SEARCH ENGINE * \n");
	puts("\t   ************* Command *************");
	puts("\t     R: Read data, S: Search data");
	puts("\t     P: Print hash table, Q: Quit");
	puts("\t   ***********************************");

	while (1) 
	{
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) 
		{
		case 'R':
			printf("\n file name: ");
			scanf("%s", fname);
			wcount += build_table(fname);
			if (wcount == NULL)
			{
				continue;
			}
			printf(" Total number of documents : %d\n",dcount);
			printf(" Total number of indexed words : %d \n", wcount);
			printf(" Total number of comparison : %d\n",ccount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", key);
			num_comparison = 0;
			judge = hash_search(key);
			if(judge==0) 
				printf(" No such word ! \n");
			printf("\n Total number of comparison = %d \n", num_comparison);
			break;
		case 'P':
			printf("\n");
			hash_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: 
			break;
		}
	}
}
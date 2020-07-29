#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_dictionary.h"

void main()
{
	int	wcount;
	char c, fname[20];
	char key[100], *data;
	printf("*************Command*************\n");
	printf("R : Read data, S : Search Data\n");
	printf("P : Print hash table, Q : Quit\n");
	printf("**********************************\n");

		while (1) {
			printf("\nCommand> ");
			c = getch();
			putch(c);
			c = toupper(c);
			switch (c) {
			case 'R':
				printf("\n Dictionary file name: ");
				scanf("%s", fname);
				wcount = build_dictionary(fname);
				printf(" Total number of words: %d \n", wcount);
				break;
			case 'S':
				printf("\n Word: ");
				scanf("%s", key);
				num_comparison = 0;
				data = hash_search(key);
				if (data != NULL) printf(" Meaning: %s \n", data);
				else printf(" No such word ! \n");
					printf(" Total number of comparison = %d \n", num_comparison);
					break;
			case 'P':
				printf("\n");
				hash_show();
				break;
			case 'Q':
				printf("\n");
				exit(1);
			default: break;
			}
		}
}

int build_dictionary(char *fname)
{
	int	i = 0;			   // 데이터 수
	char key[100], data[200];
	FILE *ifp;

	if ((ifp = fopen(fname, "r")) == NULL) {
		printf("No such file ! \n");
		exit(1);
	}

	while (fscanf(ifp, "%s %s", key, data) == 2) {	   // (key data)를 읽어 해시테이블에 삽입
		i++;
		hash_insert(key, data);
	}
	fclose(ifp);

	return(i);
}
// 해시테이블에 (key, data) 자료 삽입
void hash_insert(char *key, char *data) {
	int i, hash_value;
	i = hash_value = hash(key);
	while (strlen(hash_table[i].key) != 0) {
		if (strcmp(hash_table[i].key, key) == 0) {
			printf("duplication\n"); return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			printf("table full\n"); return;
		}
	}
	strcpy(hash_table[i].data, data);
	strcpy(hash_table[i].key, key);
}
// 해시테이블에서 키값이 key인 자료를 검색, data를 반환
char * hash_search(char *key) {
	int i, hash_value;
	i = hash_value = hash(key);
	while (strlen(hash_table[i].key) != 0) {
		num_comparison++;
		if (strcmp(hash_table[i].key, key) == 0) {
			printf(" Hash value = %d\n", i); return hash_table[i].data;
		}

		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			printf("fail\n"); return NULL;
		}
	}
	printf(" Hash value = %d\n", hash_value); return NULL;

}
// 해시테이블의 key들을 차례로 출력 
void hash_show() {
	for (int i = 0; i < TABLE_SIZE; i++)
		printf("hash_table[%d] : <%s>\n", i, hash_table[i].key);
}

// 해시 함수 (folding + division (TABLE_SIZE로 나눈 나머지))
int hash(char *key) {
	return (transform(key) % TABLE_SIZE);
}
// folding (key의 각 character 값을 더함)
int transform(char *key) {
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}
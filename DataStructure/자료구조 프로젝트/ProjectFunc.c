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
			printf(" Total number of documents : %d\n", dcount);
			printf(" Total number of indexed words : %d \n", wcount);
			printf(" Total number of comparison : %d\n", ccount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", key);
			num_comparison = 0;
			judge = hash_search(key);
			if (judge == 0)
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

// 파일에서 단어들을 읽어 해시테이블 구성
int build_table(char *fname)
{
	int	i = 0;			   // 데이터 수
	int c = 0;
	char key[100], data[200];	//단어를 받을 key와 파일명을 저장할 data
	element word;	//위 변수들을 담는 구조체
	FILE *ifp;
	//파일 없으면 오류 출력
	if ((ifp = fopen(fname, "r")) == NULL) 
	{
		printf("No such file ! \n");
		return NULL;
	}

	strcpy(data, fname);
	dcount++;

	last = NULL;

	while (fscanf(ifp, "%s", key) == 1)  // (key)를 읽어 해시테이블에 삽입
	{	  
		strcpy(word.key, key);
		strcpy(word.data, data);
		word.num_word = 1;
		i += hash_insert(word);
	}
	fclose(ifp);

	return(i);
}
// 해시테이블에 (key, data) 자료 삽입
int hash_insert(element item) 
{
	int i, j = 0, k = 0;
	int hash_value;
	char w[100], tempW[100], leadW[100];
	list_ptr lead, temp, trail = NULL;

	fcount = 0;
	strcpy(tempW, item.key); // key값인 문자열 복사
	strlwr(tempW); // 소문자 변환

	while (tempW[j] != '\0') // temp가 공백일 때 까지
	{
		if (is_word_alpha(tempW[j]) == true) // 영문자이면
		{
			w[k++] = tempW[j];
		}
		j++;
	}
	w[k] = '\0';
	//문장부호없고 대문자없는 w로 해싱함수에 넣어 해쉬값을 받음
	i = hash(w);

	for (lead = hash_table[i]; lead; trail = lead, lead = lead->link)
	{
		if (lead->item.key != NULL)
		{
			strcpy(tempW, lead->item.key);
			strlwr(tempW);
			k = 0, j = 0;
			while (tempW[j] != '\0')
			{
				if (is_word_alpha(tempW[j]) == true)
				{
					leadW[k++] = tempW[j];
				}
				j++;
			}
			leadW[k] = '\0';
		}
		if (fcount == 0) {
			//txt파일이 다른데 단어는 같으면 파일명과 단어를 또 저장함
			if (strcmp(leadW, w) == 0 && strcmp(lead->item.data, item.data) == 0)
			{
				fcount++;
				ccount++;
				lead->item.num_word += 1;		//같은 파일에 같은 단어가 있으면 1씩 증가
			}
		}
	}

	temp = (list_ptr)malloc(sizeof(list));
	temp->item = item; // item값 저장
	temp->link = NULL; // link 값 초기화
	temp->left_word = NULL; // left 값 초기화
	temp->right_word = NULL; // left 값 초기화
	// list로 모든 단어 연결
	if (trail != NULL) // trail이 NULL일 때까지 
	{
		trail->link = temp; // link로 연결
		if (last != NULL) 
		{
			last->right_word = trail->link;
			trail->link->left_word = last;
		}
		last = trail->link;
		return 1;
	}
	else 
	{
		hash_table[i] = temp;
		if (last != NULL)
		{
			last->right_word = hash_table[i];
			hash_table[i]->left_word = last;
		}
		last = hash_table[i];
		return 1;
	}
}
// 해시테이블에서 키값이 key인 자료를 검색, data를 반환
int * hash_search(char *key) 
{
	int i, j = 0, k = 0, c = 0, p = 0, a = 0, pp=-1;//변수 p의 값이 바뀌었는지 검사할 변수
	int hash_value;
	char w[100], tempW[100], numW[100] = {'\0'};
	list_ptr temp, before=NULL;

	strlwr(key); 
	strcpy(tempW, key); // 키 값 복사
	num_comparison = 0;

	while (tempW[j] != '\0')  // 공백이 나올 때까지 문자 비교
	{
		if (is_word_alpha(tempW[j]) == true)
		{
			w[k++] = tempW[j];
		}
		j++;
	}
	w[k] = '\0';

	strcpy(key, w);
	i = hash(key);
	hash_value = i;

	while (hash_table[i] != NULL)
	{
		link_num = 0;
		temp = hash_table[i];
		printf(" Hash value = %d\n", hash_value); 
		while (temp)
		{
			strcpy(tempW, temp->item.key);
			j = 0, k = 0;
			strlwr(tempW); // 소문자 변환
			while (tempW[j] != '\0')
			{
				if (is_word_alpha(tempW[j]) == true)
				{
					w[k++] = tempW[j];
				}
				j++;
			}
			w[k] = '\0';

			if (strcmp(w, key) == 0)
			{
				num_comparison++;
				num_word = temp->item.num_word;

				if(before != NULL&&strcmp(temp->item.data,before->item.data)!=0)
				{
					p++;
					a = 0;	//파일명이 바뀌었으면 a를 1로 초기화
				}
				sorting_list[p].hash_table_a[a] = temp;
				//p의 값이 바뀌었으면 아래 if문 실행
				if (p != pp) 
				{
					//파일당 한번만 re_n_word저장
					sorting_list[p].re_n_word = temp->item.num_word;
				}
				pp = p;	//p가 바뀌었는지 검사하기위해 전 p값을 받음
				a++;	//단어를 다음 index에 저장하기 위해 증가시킴
				before = temp;	//이전 단어와 비교해 파일명이 바뀌었는지 검사하기위해 전 단어를 잠시 저장
			}
			
			temp = temp->link;
			if (numW[0] != '\0'&&temp != NULL && (strcmp(numW, temp->item.data) == 0))
			{
				c++;
			}
			else
			{
				c = 0;
			}
			link_num++;
			if (temp == NULL)
			{
				in_sorting();	//단어를 다 찾았으면 텍스트를 정렬함
				return 1;
			}
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value)
		{
			printf(" Hash value = %d\n", hash_value);
			return 0;
		}
		num_comparison++;
	}
	printf(" Hash value = %d\n", hash_value);
	return 0;
}
// 해시테이블의 key들을 차례로 출력 
void hash_show() 
{
	int i = 0;
	int count = 0;
	list_ptr current;

	// TABLE_SIZE 값까지
	for (i = 0; i < TABLE_SIZE; i++) 
	{
		if (hash_table[i] == NULL) // hash_table[i]의 값이 NULL일 때 검사
		{
			continue;
		}
		printf(" hash_table[%d] : <%s> <%s>\n", i, hash_table[i]->item.data, hash_table[i]->item.key); 
		count++;
		current = hash_table[i];
		
		while (current) // current의 값이 NULL이 아니면 
		{
			current = current->link; // link 연결
			if (current == NULL) // NULL이면 break;
				break;
			printf(" hash_table[%d] : <%s> <%s>\n", i, current->item.data, current->item.key); 
			count++;
		}
	}
	printf("%d word found",count);
}
// 해시 함수 (folding + division (TABLE_SIZE로 나눈 나머지))
int hash(char *key) 
{
	return(transform(key) % TABLE_SIZE);
}
// folding (key의 각 character 값을 더함)
int transform(char *key) 
{
	int num = 0, c = 0;
	unsigned int bit = 0x04C11DB7; // CRC32코드
	while (*key)
	{
		bit = (bit << 1) | (bit >> (32 - 1));
		num = (int)(num * bit + *key++); // 비트 시프트로 통해 해시 충돌을 최소로 줄임(단, 여기서 음수가 나올 수 있음)
	}
	if (num < 0)
		num = -num; // 음수의 경우 양수로 전환

	return num;
}
// 영문자인지 아닌지 검사하는 함수 
boolean is_word_alpha(char w)
{
    if (w<97 || w>122) // 특수문자 라인 false 값 반환
	{
		return false;
	}
	else  // 영문자 라인 true 값 반환
	{
		return true;
	}
}

void in_sorting()
{
	int i, next, j;
	address next_w;
	for (i = 1; i < 10; i++)
	{
		if (sorting_list[i].re_n_word == NULL)
		{
			break;
		}
		next = sorting_list[i].re_n_word;
		next_w = sorting_list[i];
		// i ~ 0 중 올바른 자리에 next 삽입
		for (j = i - 1; j >= 0 && next > sorting_list[j].re_n_word; j--)
		{
			sorting_list[j + 1] = sorting_list[j];
		}
		sorting_list[j + 1] = next_w;
	}
	i = 0; j = 0;
	//sorting_list[0]이 비어있지않으면 출력함
	if (sorting_list[i].re_n_word != NULL) 
	{
		//파일명, 단어, 단어갯수 출력
		printf("\n <%s> %s: %d\n", sorting_list[i].hash_table_a[j]->item.data, strlwr(sorting_list[i].hash_table_a[j]->item.key), sorting_list[i].re_n_word);
		//파일에 있는 동일단어 전부 출력
		for (j = 0; j < TABLE_SIZE; j++) {
			if (sorting_list[i].hash_table_a[j] == NULL)
			{
				break;
			}
			print_pre_front(sorting_list[i].hash_table_a[j]);
			sorting_list[i].hash_table_a[j] = NULL;
			sorting_list[i].re_n_word = 0;
		}
	}
	j = 0;
	//sorting_list를 1부터 출력함
	for (i = 1; i < 10; i++)
	{
		j = 0;
		//list가 비어있으면 break
		if (sorting_list[i].hash_table_a[j] == NULL) 
		{
			break;
		}
		//파일명, 단어, 단어갯수 출력
		printf("\n <%s> %s: %d\n", sorting_list[i].hash_table_a[j]->item.data, strlwr(sorting_list[i].hash_table_a[j]->item.key), sorting_list[i].re_n_word);
		//파일명이 같은 동일 단어 전부 출력
		for (j=0; j < TABLE_SIZE; j++) {
			//table이 비었으면 break
			if (sorting_list[i].hash_table_a[j] == NULL) 
			{
				break;
			}
			print_pre_front(sorting_list[i].hash_table_a[j]);
			sorting_list[i].hash_table_a[j] = NULL;
			sorting_list[i].re_n_word = 0;
		}
	}
}
//찾은 단어의 앞뒤 3단어를 출력하는 함수
void print_pre_front(list_ptr word)
{
	list_ptr temp = word;

	// 왼쪽을 1단계 2단계 3단계를 검사 왼쪽 3단어를 뽑아 내기 위한 코드
	if (temp->left_word != NULL)
	{
		if (temp->left_word->left_word != NULL)
		{
			if (temp->left_word->left_word->left_word != NULL)
			{
				printf("...");
				printf("%s ", temp->left_word->left_word->left_word->item.key);
			}
			printf("%s ", temp->left_word->left_word->item.key);
		}
		printf("%s ", temp->left_word->item.key);
	}
	printf("%s ", temp);
	// 오른쪽 1단계 2단계 3단계를 검사 오른쪽 3단어를 뽑아 내기 위한 코드
	if (temp->right_word != NULL)
	{
		printf("%s ", temp->right_word->item.key);
		if (temp->right_word->right_word != NULL)
		{
			printf("%s ", temp->right_word->right_word->item.key);
			if (temp->right_word->right_word->right_word != NULL)
			{
				printf("%s", temp->right_word->right_word->right_word->item.key);
				printf("...");
			}
		}
	}
	printf("\n");
}
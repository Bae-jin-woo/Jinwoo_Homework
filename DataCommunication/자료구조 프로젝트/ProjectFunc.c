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

// ���Ͽ��� �ܾ���� �о� �ؽ����̺� ����
int build_table(char *fname)
{
	int	i = 0;			   // ������ ��
	int c = 0;
	char key[100], data[200];	//�ܾ ���� key�� ���ϸ��� ������ data
	element word;	//�� �������� ��� ����ü
	FILE *ifp;
	//���� ������ ���� ���
	if ((ifp = fopen(fname, "r")) == NULL) 
	{
		printf("No such file ! \n");
		return NULL;
	}

	strcpy(data, fname);
	dcount++;

	last = NULL;

	while (fscanf(ifp, "%s", key) == 1)  // (key)�� �о� �ؽ����̺� ����
	{	  
		strcpy(word.key, key);
		strcpy(word.data, data);
		word.num_word = 1;
		i += hash_insert(word);
	}
	fclose(ifp);

	return(i);
}
// �ؽ����̺� (key, data) �ڷ� ����
int hash_insert(element item) 
{
	int i, j = 0, k = 0;
	int hash_value;
	char w[100], tempW[100], leadW[100];
	list_ptr lead, temp, trail = NULL;

	fcount = 0;
	strcpy(tempW, item.key); // key���� ���ڿ� ����
	strlwr(tempW); // �ҹ��� ��ȯ

	while (tempW[j] != '\0') // temp�� ������ �� ����
	{
		if (is_word_alpha(tempW[j]) == true) // �������̸�
		{
			w[k++] = tempW[j];
		}
		j++;
	}
	w[k] = '\0';
	//�����ȣ���� �빮�ھ��� w�� �ؽ��Լ��� �־� �ؽ����� ����
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
			//txt������ �ٸ��� �ܾ�� ������ ���ϸ�� �ܾ �� ������
			if (strcmp(leadW, w) == 0 && strcmp(lead->item.data, item.data) == 0)
			{
				fcount++;
				ccount++;
				lead->item.num_word += 1;		//���� ���Ͽ� ���� �ܾ ������ 1�� ����
			}
		}
	}

	temp = (list_ptr)malloc(sizeof(list));
	temp->item = item; // item�� ����
	temp->link = NULL; // link �� �ʱ�ȭ
	temp->left_word = NULL; // left �� �ʱ�ȭ
	temp->right_word = NULL; // left �� �ʱ�ȭ
	// list�� ��� �ܾ� ����
	if (trail != NULL) // trail�� NULL�� ������ 
	{
		trail->link = temp; // link�� ����
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
// �ؽ����̺��� Ű���� key�� �ڷḦ �˻�, data�� ��ȯ
int * hash_search(char *key) 
{
	int i, j = 0, k = 0, c = 0, p = 0, a = 0, pp=-1;//���� p�� ���� �ٲ������ �˻��� ����
	int hash_value;
	char w[100], tempW[100], numW[100] = {'\0'};
	list_ptr temp, before=NULL;

	strlwr(key); 
	strcpy(tempW, key); // Ű �� ����
	num_comparison = 0;

	while (tempW[j] != '\0')  // ������ ���� ������ ���� ��
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
			strlwr(tempW); // �ҹ��� ��ȯ
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
					a = 0;	//���ϸ��� �ٲ������ a�� 1�� �ʱ�ȭ
				}
				sorting_list[p].hash_table_a[a] = temp;
				//p�� ���� �ٲ������ �Ʒ� if�� ����
				if (p != pp) 
				{
					//���ϴ� �ѹ��� re_n_word����
					sorting_list[p].re_n_word = temp->item.num_word;
				}
				pp = p;	//p�� �ٲ������ �˻��ϱ����� �� p���� ����
				a++;	//�ܾ ���� index�� �����ϱ� ���� ������Ŵ
				before = temp;	//���� �ܾ�� ���� ���ϸ��� �ٲ������ �˻��ϱ����� �� �ܾ ��� ����
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
				in_sorting();	//�ܾ �� ã������ �ؽ�Ʈ�� ������
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
// �ؽ����̺��� key���� ���ʷ� ��� 
void hash_show() 
{
	int i = 0;
	int count = 0;
	list_ptr current;

	// TABLE_SIZE ������
	for (i = 0; i < TABLE_SIZE; i++) 
	{
		if (hash_table[i] == NULL) // hash_table[i]�� ���� NULL�� �� �˻�
		{
			continue;
		}
		printf(" hash_table[%d] : <%s> <%s>\n", i, hash_table[i]->item.data, hash_table[i]->item.key); 
		count++;
		current = hash_table[i];
		
		while (current) // current�� ���� NULL�� �ƴϸ� 
		{
			current = current->link; // link ����
			if (current == NULL) // NULL�̸� break;
				break;
			printf(" hash_table[%d] : <%s> <%s>\n", i, current->item.data, current->item.key); 
			count++;
		}
	}
	printf("%d word found",count);
}
// �ؽ� �Լ� (folding + division (TABLE_SIZE�� ���� ������))
int hash(char *key) 
{
	return(transform(key) % TABLE_SIZE);
}
// folding (key�� �� character ���� ����)
int transform(char *key) 
{
	int num = 0, c = 0;
	unsigned int bit = 0x04C11DB7; // CRC32�ڵ�
	while (*key)
	{
		bit = (bit << 1) | (bit >> (32 - 1));
		num = (int)(num * bit + *key++); // ��Ʈ ����Ʈ�� ���� �ؽ� �浹�� �ּҷ� ����(��, ���⼭ ������ ���� �� ����)
	}
	if (num < 0)
		num = -num; // ������ ��� ����� ��ȯ

	return num;
}
// ���������� �ƴ��� �˻��ϴ� �Լ� 
boolean is_word_alpha(char w)
{
    if (w<97 || w>122) // Ư������ ���� false �� ��ȯ
	{
		return false;
	}
	else  // ������ ���� true �� ��ȯ
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
		// i ~ 0 �� �ùٸ� �ڸ��� next ����
		for (j = i - 1; j >= 0 && next > sorting_list[j].re_n_word; j--)
		{
			sorting_list[j + 1] = sorting_list[j];
		}
		sorting_list[j + 1] = next_w;
	}
	i = 0; j = 0;
	//sorting_list[0]�� ������������� �����
	if (sorting_list[i].re_n_word != NULL) 
	{
		//���ϸ�, �ܾ�, �ܾ�� ���
		printf("\n <%s> %s: %d\n", sorting_list[i].hash_table_a[j]->item.data, strlwr(sorting_list[i].hash_table_a[j]->item.key), sorting_list[i].re_n_word);
		//���Ͽ� �ִ� ���ϴܾ� ���� ���
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
	//sorting_list�� 1���� �����
	for (i = 1; i < 10; i++)
	{
		j = 0;
		//list�� ��������� break
		if (sorting_list[i].hash_table_a[j] == NULL) 
		{
			break;
		}
		//���ϸ�, �ܾ�, �ܾ�� ���
		printf("\n <%s> %s: %d\n", sorting_list[i].hash_table_a[j]->item.data, strlwr(sorting_list[i].hash_table_a[j]->item.key), sorting_list[i].re_n_word);
		//���ϸ��� ���� ���� �ܾ� ���� ���
		for (j=0; j < TABLE_SIZE; j++) {
			//table�� ������� break
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
//ã�� �ܾ��� �յ� 3�ܾ ����ϴ� �Լ�
void print_pre_front(list_ptr word)
{
	list_ptr temp = word;

	// ������ 1�ܰ� 2�ܰ� 3�ܰ踦 �˻� ���� 3�ܾ �̾� ���� ���� �ڵ�
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
	// ������ 1�ܰ� 2�ܰ� 3�ܰ踦 �˻� ������ 3�ܾ �̾� ���� ���� �ڵ�
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
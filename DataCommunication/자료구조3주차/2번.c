#define ROW 3
#define COL 3
#include <stdio.h>


void matrix_init(int a[ROW][COL]);
void matrix_add(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]);
void matrix_mult(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]);
void matrix_trans(int a[ROW][COL], int b[ROW][COL]);
void matrix_print(int a[ROW][COL]);

void matrix_init(int a[ROW][COL]) {	//��Ʈ������ ���Ҹ� ��� 0���� �ϴ� �Լ�
	int i, j;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			a[i][j] = 0;
}

void matrix_add(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]) {	//��Ʈ���� a��b�� ���� c�� ����
	int i, j;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			c[i][j] = a[i][j] + b[i][j];	//��Ʈ���� ���ϱ�
}
void matrix_mult(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]) {	//��Ʈ���� a��b�� ���� c�� ����
	int i, j, k;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			for (k = 0; k < COL; k++)
					c[i][j] = c[i][j] + (a[i][k] * b[k][j]);	//��Ʈ���� ���ϱ�
}
void matrix_trans(int a[ROW][COL], int b[ROW][COL]) {	//��Ʈ������ ��� ���� �ݴ��
	int i, j;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			b[j][i] = a[i][j];	//�࿭ �ٲٱ�
}
void matrix_print(int a[ROW][COL]) {	//��Ʈ���� ���
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}


int main() {
	int a[ROW][COL] = { {1,0,0},{1,0,0},{1,0,0} };
	int b[ROW][COL] = { {1,1,1},{0,0,0},{0,0,0} };
	int c[ROW][COL] = { {0,0,0}, {0,0,0},{0,0,0} };

	matrix_print(a);
	matrix_print(b);

	matrix_add(a, b, c);
	printf("a + b = \n\n");
	matrix_print(c);

	matrix_init(c);
	matrix_mult(a, b, c);
	printf("a * b = \n\n");
	matrix_print(c);

	matrix_init(c);
	matrix_trans(a, c);
	printf("a transpose = \n\n");
	matrix_print(c);



	return 0;
}
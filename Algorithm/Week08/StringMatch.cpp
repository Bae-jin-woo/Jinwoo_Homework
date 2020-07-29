//2015112128 ������
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#define CLOCKS_PER_SER ((clock_t)1000)
#define TIME_UTC 1
using namespace std;

void BruteForce(char* T, char* P, int n , int m);
vector<int> makeTable(char* pattern);
void KMP(char* T, char* P);
void RabinKarp(char* T, char* P);

int main() {
	//string TextString;
	//string PatternString;
	char* TextString = new char;
	char* PatternString = new char;
	cout << "Text String �Է�>>";
	cin >> TextString;
	cout << "Pattern String �Է�>>";
	cin >> PatternString;
	int tLength = strlen(TextString);
	int pLength = strlen(PatternString);
	time_t start, end;
	double result;
	cout << "-------------Brute Force--------------" << endl;
	start = clock();
	BruteForce(TextString, PatternString, tLength, pLength);
	end = clock();
	result = (double)(end - start);
	printf("���� �ð� : %.2fms\n", result);
	cout << "--------------------------------------" << endl << endl;
	vector<int> table = makeTable(PatternString);
	cout << "---------------- KMP -----------------" << endl;
	start = clock();
	KMP(TextString, PatternString);
	end = clock();
	result = (double)(end - start);
	printf("���� �ð� : %.2fms\n", result);
	cout << "--------------------------------------" << endl << endl;
	
	cout << "------------- Rabin Karp--------------" << endl;
	start = clock();
	RabinKarp(TextString, PatternString);
	end = clock();
	result = (double)(end - start);
	printf("���� �ð� : %.2fms\n", result);
	cout << "--------------------------------------" << endl;
	return 0;
}

void BruteForce(char* T, char* P, int n, int m) {
	//�Է�: T:�ؽ�Ʈ, ũ�Ⱑ n�� ������ �迭
	//		P: ����, ũ�Ⱑ m�� ������ �迭
	//���: �ؽ�Ʈ ���� ������ �����ϴ� ��ġ
	int i, j;
	for (i = 0; i <= n - m; i++) {
		for (j = 0; j < m; j++) {
			if (P[j] != T[i + j]) break;
		}
		if (j == m) cout << "������ �ؽ�Ʈ�� " << i + 1 << "��°���� ��Ÿ��" << endl;
	}
}

vector<int> makeTable(char* pattern) {
	/*�Է�: ���ڿ�
	���: �Է� ���ڿ��� �ִ� ���κ� ���̺�*/
	int patternSize = strlen(pattern);
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {	//��� ���ڸ� �Ѱ��� �˻��ϸ鼭 
		while (j > 0 && (pattern[i] != pattern[j])) {
			j = table[j - 1];	//��ġ���� �ʾ����� 1���� ���� ����Ű�� �ε����� �̵�
		}
		if (pattern[i] == pattern[j]) {	//���� ��ġ�Ѵٸ� ���̺� j+1�� ����
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(char* T, char* P) {
	vector<int> table = makeTable(P);
	int textSize = strlen(T);
	int patternSize = strlen(P);
	int j = 0;
	for (int i = 0; i < textSize; i++) {
		while (j > 0 && T[i] != P[j]) {	//ó�� ���ڿ���Ī�� �̷������ �ʾ����� ���� ��ġ���� 1���� ���� j�� �̵�
			j = table[j - 1];
		}
		if (T[i] == P[j]) {	
			if (j == patternSize - 1) {	//���ڰ� ��ü ��ġ�� ���
				cout << "������ �ؽ�Ʈ�� " << i - patternSize + 2 << "��°���� ��Ÿ��" << endl;
				j = table[j];	//��Ī�� �̷������ ��� ��ġ�� ����ϱ� ���� ����
			}
			else {
				j++;
			}
		}
	}
} 

void RabinKarp(char* T, char* P) {	//���ī�� (�ؽ��Լ�: 
	int textSize = strlen(T);
	int patternSize = strlen(P);
	int textHash = 0, patternHash = 0, power = 1;
	for (int i = 0; i <= textSize - patternSize; i++) {
		if (i == 0) {	//�ʱ�ȭ
			for (int j = 0; j < patternSize; j++) {
				textHash += T[patternSize - 1 - j] * power;
				patternHash += P[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power *= 2;
			}
		}
		else {	//��ȭ��
			textHash = 2 * (textHash - T[i - 1] * power) + T[patternSize - 1 + i];
		}
		if (textHash == patternHash) {	//�κ� ���ڿ��� Ư�� ���ڿ��� �ؽð��� ��ġ�Ѵٸ�
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (T[i + j] != P[j]) {	//������ �������� ��ġ�ϴ��� ��
					finded = false;
					break;
				}
			}
			if (finded) {
				cout << "������ �ؽ�Ʈ�� " << i + 1 << "��°���� ��Ÿ��" << endl;
			}
		}
	}
}
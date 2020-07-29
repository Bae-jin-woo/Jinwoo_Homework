//2015112128 ������
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>

#define CLOCKS_PER_SER ((clock_t)1000)
#define TIME_UTC 1
#define DNA_SIZE 500000
#define TRAN_NUM 5	//X%
#define MISS_MATCH 3	//Y

using namespace std;

void makeReferenceDNA(char[]);
void makeMyDNA(char[], int);
void makeShortRead(char[], int, int);
void RemakeDNA(int, int);
void difCount(char[], char[], int, int);

int main() {
	time_t start, end;
	double result;

	char DNA[4] = { 'A','G','C','T' };
	makeReferenceDNA(DNA);
	makeMyDNA(DNA, 30);
	makeMyDNA(DNA, 60);
	ifstream inFile1("My_DNA_Sequence" + to_string(30) + ".txt");
	ifstream inFile2("My_DNA_Sequence" + to_string(60) + ".txt");
	char* DNA_String1 = new char[DNA_SIZE + 1];
	char* DNA_String2 = new char[DNA_SIZE + 1];
	inFile1.getline(DNA_String1, DNA_SIZE + 1);
	inFile2.getline(DNA_String2, DNA_SIZE + 1);

	makeShortRead(DNA_String1, 30, 20000);
	makeShortRead(DNA_String2, 60, 15000);

	start = clock();
	RemakeDNA(30, 20000);
	end = clock();
	result = (double)(end - start);
	printf("���� �ð� : %.3fms\n\n", result);
	start = clock();
	RemakeDNA(60, 15000);
	end = clock();
	result = (double)(end - start);
	printf("���� �ð� : %.3fms\n\n", result);

	delete[] DNA_String1;
	delete[] DNA_String2;
}

void makeReferenceDNA(char DNA[]) {
	//DNA sequence �����Լ�. ���ڿ��� �ݺ� ������ ���� ���� ���⼭���� �ٸ� ���⼭���� 
	//���� �� �ְ� ����.
	int randomNumber = rand() % 4;
	int preNumber = 0;
	srand(time(NULL));
	ofstream outFile("Reference_DNA_Sequence.txt");
	for (int i = 0; i < DNA_SIZE; i++) {
		while (1) {
			randomNumber = rand() % 4;
			if (randomNumber != preNumber)break;
		}
		outFile << DNA[randomNumber];
		preNumber = randomNumber;
	}
	outFile.close();
}

void makeMyDNA(char DNA[],int sequenceLength) {	
	//Referenct DNA sequence�� x%�ٸ� DNA sequenct�� �����Ѵ�. 
	//My_DNA_Sequence(sequence length).txt ���Ϸ� ����ȴ�. 
	srand(time(NULL));
	int tranNumber = 0;
	ifstream inFile("Reference_DNA_Sequence.txt");
	ofstream outFile("My_DNA_Sequence" + to_string(sequenceLength) + ".txt");
	char* reference_String = new char[DNA_SIZE + 1];
	char* MyDNA_String = new char[DNA_SIZE + 1];
	inFile.getline(reference_String, DNA_SIZE + 1);
	strcpy_s(MyDNA_String, DNA_SIZE + 1, reference_String);
	for (int i = 0; i < DNA_SIZE / TRAN_NUM / 100; i++) {
		int tranNUmber = rand() % DNA_SIZE;	//�ٲ� �ڸ� ����
		int randomNumber = rand() % 4;
		while (reference_String[tranNUmber] == MyDNA_String[tranNUmber]) {
			if (reference_String[tranNUmber] != MyDNA_String[tranNUmber]) break;
			while (1) {
				if (MyDNA_String[tranNUmber] != DNA[randomNumber]) {
					MyDNA_String[tranNUmber] = DNA[randomNumber];
					break;
				}
				else {
					randomNumber = rand() % 4;
				}
			}
		}
	}
	outFile << MyDNA_String;
	outFile.close();
	inFile.close();
	delete[] reference_String;
	delete[] MyDNA_String;
}

void makeShortRead(char string[], int sequenceLength, int sequenceNum) {	
	//�Է¹��� String���� ������ ��ġ�� Short Read�� �����Ͽ� ���Ͽ� �����ϴ� �Լ�
	ofstream outFile("ShortRead"+to_string(sequenceLength)+".txt");
	srand(time(NULL));
	for (int j = 0; j < sequenceNum; j++) {
		vector<char> substring;
		int startPoint = rand() % (DNA_SIZE - sequenceLength);
		for (int i = 0; i < sequenceLength; i++) {
			substring.push_back(string[startPoint + i]);
			outFile << substring[i];
		}
		outFile << endl;
	}
	outFile.close();
}

void RemakeDNA(int sequenceLength, int sequenceNum) {
	//Short Read�� My DNA�� Remake�ϴ� �Լ�.
	//Remake_DNA�� ���� MY_DNA�� ���Ѵ�. 
	ifstream inFile1("ShortRead" + to_string(sequenceLength) + ".txt");
	ifstream inFile2("Reference_DNA_Sequence.txt");
	ifstream inFile3("My_DNA_Sequence" + to_string(sequenceLength) + ".txt");
	ofstream outFile("Remake_My_DNA" + to_string(sequenceLength) + ".txt");
	char* shortRead = new char[sequenceLength + 1];
	char* DNA_String = new char[DNA_SIZE + 1];
	char* reMake_String = new char[DNA_SIZE + 1];
	char* My_DNA = new char[DNA_SIZE + 1];

	inFile2.getline(DNA_String, DNA_SIZE + 1);	//Reference DNA �ҷ���
	inFile3.getline(My_DNA, DNA_SIZE + 1);	//MY DNA �ҷ���
	strcpy_s(reMake_String, DNA_SIZE + 1, DNA_String);
	int disMatchCount = 0;
	for (int i = 0; i < sequenceNum; i++) {	//Short Read�� ������ŭ �ݺ�
		inFile1.getline(shortRead, sequenceLength + 1);
		for (int j = 0; j < sequenceNum - sequenceLength; j++) {	//��ü DNA ���̸�ŭ �ݺ�
			for (int k = 0; k < sequenceLength; k++) {	//Dismatch ���� Ž��
				if (shortRead[k] != DNA_String[j + k]) {
					disMatchCount++;
				}
			}
			if (disMatchCount <= MISS_MATCH) {	//Dismatch�� y���� ���� ��� Short Read�� String�� ����
				for (int k = 0; k < sequenceLength; k++) {
					reMake_String[j + k] = shortRead[k];
				}
			}
			disMatchCount = 0;
		}		
	}
	outFile << reMake_String;
	difCount(My_DNA, reMake_String, sequenceLength, sequenceNum);

	delete[] shortRead;
	delete[] DNA_String;
	delete[] reMake_String;
	delete[] My_DNA;

	inFile1.close();
	inFile2.close();
	inFile3.close();
	outFile.close();
}
void difCount(char DNA_String1[], char DNA_String2[], int sequenceLength, int sequenceNum) {	
	//�ٸ� Ƚ�� ī��Ʈ �Լ�
	cout << "k =  " << sequenceLength << "\t" << "n = " << sequenceNum << "\t" << endl;
	int count = 0;
	for (int i = 0; i < DNA_SIZE; i++) {
		if (DNA_String1[i] != DNA_String2[i]) {
			count++;
		}
	}
	if (count == 0) cout << "��� ��ġ!!" << endl;
	else {
		cout << count << "�� ����ġ!!\t";
		printf("������ : %.2f%%\n", (float(DNA_SIZE) - float(count)) / float(DNA_SIZE) * 100);
	}
}
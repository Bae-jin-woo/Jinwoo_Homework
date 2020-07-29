//2015112128 배진우
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
	printf("실행 시간 : %.3fms\n\n", result);
	start = clock();
	RemakeDNA(60, 15000);
	end = clock();
	result = (double)(end - start);
	printf("실행 시간 : %.3fms\n\n", result);

	delete[] DNA_String1;
	delete[] DNA_String2;
}

void makeReferenceDNA(char DNA[]) {
	//DNA sequence 생성함수. 문자열의 반복 방지를 위해 이전 염기서열과 다른 염기서열을 
	//가질 수 있게 구현.
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
	//Referenct DNA sequence와 x%다른 DNA sequenct를 생성한다. 
	//My_DNA_Sequence(sequence length).txt 파일로 저장된다. 
	srand(time(NULL));
	int tranNumber = 0;
	ifstream inFile("Reference_DNA_Sequence.txt");
	ofstream outFile("My_DNA_Sequence" + to_string(sequenceLength) + ".txt");
	char* reference_String = new char[DNA_SIZE + 1];
	char* MyDNA_String = new char[DNA_SIZE + 1];
	inFile.getline(reference_String, DNA_SIZE + 1);
	strcpy_s(MyDNA_String, DNA_SIZE + 1, reference_String);
	for (int i = 0; i < DNA_SIZE / TRAN_NUM / 100; i++) {
		int tranNUmber = rand() % DNA_SIZE;	//바꿀 자리 선택
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
	//입력받은 String에서 랜덤한 위치의 Short Read를 추출하여 파일에 저장하는 함수
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
	//Short Read로 My DNA를 Remake하는 함수.
	//Remake_DNA와 기존 MY_DNA를 비교한다. 
	ifstream inFile1("ShortRead" + to_string(sequenceLength) + ".txt");
	ifstream inFile2("Reference_DNA_Sequence.txt");
	ifstream inFile3("My_DNA_Sequence" + to_string(sequenceLength) + ".txt");
	ofstream outFile("Remake_My_DNA" + to_string(sequenceLength) + ".txt");
	char* shortRead = new char[sequenceLength + 1];
	char* DNA_String = new char[DNA_SIZE + 1];
	char* reMake_String = new char[DNA_SIZE + 1];
	char* My_DNA = new char[DNA_SIZE + 1];

	inFile2.getline(DNA_String, DNA_SIZE + 1);	//Reference DNA 불러옴
	inFile3.getline(My_DNA, DNA_SIZE + 1);	//MY DNA 불러옴
	strcpy_s(reMake_String, DNA_SIZE + 1, DNA_String);
	int disMatchCount = 0;
	for (int i = 0; i < sequenceNum; i++) {	//Short Read의 갯수만큼 반복
		inFile1.getline(shortRead, sequenceLength + 1);
		for (int j = 0; j < sequenceNum - sequenceLength; j++) {	//전체 DNA 길이만큼 반복
			for (int k = 0; k < sequenceLength; k++) {	//Dismatch 개수 탐색
				if (shortRead[k] != DNA_String[j + k]) {
					disMatchCount++;
				}
			}
			if (disMatchCount <= MISS_MATCH) {	//Dismatch가 y보다 작은 경우 Short Read를 String에 저장
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
	//다른 횟수 카운트 함수
	cout << "k =  " << sequenceLength << "\t" << "n = " << sequenceNum << "\t" << endl;
	int count = 0;
	for (int i = 0; i < DNA_SIZE; i++) {
		if (DNA_String1[i] != DNA_String2[i]) {
			count++;
		}
	}
	if (count == 0) cout << "모두 일치!!" << endl;
	else {
		cout << count << "개 불일치!!\t";
		printf("복구율 : %.2f%%\n", (float(DNA_SIZE) - float(count)) / float(DNA_SIZE) * 100);
	}
}
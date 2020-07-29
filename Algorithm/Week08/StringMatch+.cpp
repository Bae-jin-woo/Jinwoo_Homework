//2015112128 배진우
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>

#define CLOCKS_PER_SER ((clock_t)1000)
#define TIME_UTC 1
#define STRING1_SIZE 10000
#define STRING2_SIZE 100000
#define STRING3_SIZE 100000000
#define PATTERN_SIZE 20
using namespace std;

void BruteForce(char* T, vector<char> P, int n, int m);
vector<int> makeTable(vector<char> pattern);
void KMP(char* T, vector<char> P);
void RabinKarp(char* T, vector<char> P);
void Testing(char* T, vector<char> P, int n, int m);
ofstream outFile("result" + to_string(PATTERN_SIZE) + ".txt");	//결과파일 생성

int main() {
	srand(time(NULL));
	//ofstream outFile1("10000.txt");
	//for (int i = 0; i < STRING1_SIZE; i++) {	//길이 10000의 string 생성
	//	int randomNumber = rand() % 10;
	//	outFile1 << randomNumber;
	//}
	//outFile1.close();
	//ofstream outFile2("100000.txt");
	//for (int i = 0; i < STRING2_SIZE; i++) {	//길이 100000의 string 생성
	//	int randomNumber = rand() % 10;
	//	outFile2 << randomNumber;
	//}
	//outFile2.close();
	//ofstream outFile3("100000000.txt");
	//for (int i = 0; i < STRING3_SIZE; i++) {	//길이 100000000의 string 생성
	//	int randomNumber = rand() % 10;
	//	outFile3 << randomNumber;
	//}
	//outFile3.close();
	char* inputString1 = new char[STRING1_SIZE];
	char* inputString2 = new char[STRING2_SIZE];
	char* inputString3 = new char[STRING3_SIZE];
	vector<char> patternString;

	ifstream inFile1("10000.txt");
	ifstream inFile2("100000.txt");
	ifstream inFile3("100000000.txt");
	inFile1.getline(inputString1, STRING1_SIZE);
	inFile2.getline(inputString2, STRING2_SIZE);
	inFile3.getline(inputString3, STRING3_SIZE);
	cout << "패턴: ";
	outFile << "패턴: ";
	for (int i = 0; i < PATTERN_SIZE; i++) {
		int randomNumber = rand() % 10;
		patternString.push_back(randomNumber + '0');
		cout << patternString[i];
		outFile << patternString[i];
	}
	cout << endl;
	outFile << endl;
	cout << "--------------------------------10000.txt--------------------------------" << endl;
	outFile << "--------------------------------10000.txt--------------------------------" << endl;
	Testing(inputString1, patternString, STRING1_SIZE, PATTERN_SIZE);
	cout << endl;
	outFile << endl;
	cout << "-------------------------------100000.txt--------------------------------" << endl;
	outFile << "-------------------------------100000.txt--------------------------------" << endl;
	Testing(inputString2, patternString, STRING2_SIZE, PATTERN_SIZE);
	cout << endl;
	cout << "------------------------------100000000.txt------------------------------" << endl;
	outFile << endl;
	outFile << "------------------------------100000000.txt------------------------------" << endl;
	
	Testing(inputString3, patternString, STRING3_SIZE, PATTERN_SIZE);
	cout << endl;
	outFile << endl;

	delete[] inputString1;
	delete[] inputString2;
	delete[] inputString3;
}

void BruteForce(char* T, vector<char> P, int n, int m) {
	//입력: T:텍스트, 크기가 n인 문자의 배열
	//		P: 패턴, 크기가 m인 문자의 배열
	//출력: 텍스트 내의 패턴이 존재하는 위치
	int i, j;
	for (i = 0; i <= n - m; i++) {	//모든 인덱스를 비교하여 같다면 출력
		for (j = 0; j < m; j++) {
			if (P[j] != T[i + j]) break;
		}
		if (j == m) {
			cout << "패턴이 텍스트의 " << i + 1 << "번째부터 나타남" << endl;
			outFile << "패턴이 텍스트의 " << i + 1 << "번째부터 나타남" << endl;
		}
	}
}

vector<int> makeTable(vector<char> pattern) {
	/*입력: 문자열
	출력: 입력 문자열의 최대 접두부 테이블*/
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {	//모든 문자를 한개씩 검사하면서 
		while (j > 0 && (pattern[i] != pattern[j])) {
			j = table[j - 1];	//일치하지 않았을때 1을뺀 값이 가리키는 인덱스로 이동
		}
		if (pattern[i] == pattern[j]) {	//값이 일치한다면 테이블에 j+1을 저장
			table[i] = ++j;	
		}
	}
	return table;
}

void KMP(char* T, vector<char> P) {
	vector<int> table = makeTable(P);
	int textSize = strlen(T);
	int patternSize = P.size();
	int j = 0;
	for (int i = 0; i < textSize; i++) {
		while (j > 0 && T[i] != P[j]) {
			j = table[j - 1];
		}
		if (T[i] == P[j]) {
			if (j == patternSize - 1) {
				//cout << "패턴이 텍스트의 " << i - patternSize + 2 << "번째부터 나타남" << endl;
				//outFile << "패턴이 텍스트의 " << i - patternSize + 2 << "번째부터 나타남" << endl;
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

void RabinKarp(char* T, vector<char> P) {	//라빈카프 
	int textSize = strlen(T);
	int patternSize = P.size();
	int textHash = 0, patternHash = 0, power = 1;
	for (int i = 0; i <= textSize - patternSize; i++) {
		if (i == 0) {	//초기화
			for (int j = 0; j < patternSize; j++) {
				textHash += T[patternSize - 1 - j] * power;
				patternHash += P[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power *= 2;
			}
		}
		else {	//점화식
			textHash = 2 * (textHash - T[i - 1] * power) + T[patternSize - 1 + i];
		}
		if (textHash == patternHash) {	//부분 문자열과 특정 문자열의 해시값이 일치한다면
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (T[i + j] != P[j]) {	//실제로 문차열이 일치하는지 비교
					finded = false;
					break;
				}
			}
			if (finded) {
				//cout << "패턴이 텍스트의 " << i + 1 << "번째부터 나타남" << endl;
				//outFile << "패턴이 텍스트의 " << i + 1 << "번째부터 나타남" << endl;
			}
		}
	}
}

void Testing(char* T, vector<char> P, int n, int m) {
	time_t start, end;
	double result;
	start = clock();
	BruteForce(T, P, n, m);
	cout << "-------------Brute Force--------------" << endl;
	outFile << "-------------Brute Force--------------" << endl;
	end = clock();
	result = (double)(end - start);
	printf("실행 시간 : %.3fms\n", result);
	outFile << "실행 시간: " << result << "ms" << endl;
	cout << endl;
	outFile << endl;

	cout << "---------------- KMP -----------------" << endl;
	outFile << "---------------- KMP -----------------" << endl;

	start = clock();
	KMP(T, P);
	end = clock();
	result = (double)(end - start);
	printf("실행 시간 : %.3fms\n", result);
	outFile << "실행 시간: " << result << "ms" << endl;
	cout << endl;
	outFile << endl;

	cout << "------------- Rabin Karp--------------" << endl;
	outFile << "------------- Rabin Karp--------------" << endl;
	start = clock();
	RabinKarp(T, P);
	end = clock();
	result = (double)(end - start);
	printf("실행 시간 : %.3fms\n", result);
	outFile << "실행 시간: " << result << "ms" << endl;
	cout << endl;
	outFile << endl;
}

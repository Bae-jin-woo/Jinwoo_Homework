//2015112128 배진우
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
	cout << "Text String 입력>>";
	cin >> TextString;
	cout << "Pattern String 입력>>";
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
	printf("실행 시간 : %.2fms\n", result);
	cout << "--------------------------------------" << endl << endl;
	vector<int> table = makeTable(PatternString);
	cout << "---------------- KMP -----------------" << endl;
	start = clock();
	KMP(TextString, PatternString);
	end = clock();
	result = (double)(end - start);
	printf("실행 시간 : %.2fms\n", result);
	cout << "--------------------------------------" << endl << endl;
	
	cout << "------------- Rabin Karp--------------" << endl;
	start = clock();
	RabinKarp(TextString, PatternString);
	end = clock();
	result = (double)(end - start);
	printf("실행 시간 : %.2fms\n", result);
	cout << "--------------------------------------" << endl;
	return 0;
}

void BruteForce(char* T, char* P, int n, int m) {
	//입력: T:텍스트, 크기가 n인 문자의 배열
	//		P: 패턴, 크기가 m인 문자의 배열
	//출력: 텍스트 내의 패턴이 존재하는 위치
	int i, j;
	for (i = 0; i <= n - m; i++) {
		for (j = 0; j < m; j++) {
			if (P[j] != T[i + j]) break;
		}
		if (j == m) cout << "패턴이 텍스트의 " << i + 1 << "번째부터 나타남" << endl;
	}
}

vector<int> makeTable(char* pattern) {
	/*입력: 문자열
	출력: 입력 문자열의 최대 접두부 테이블*/
	int patternSize = strlen(pattern);
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

void KMP(char* T, char* P) {
	vector<int> table = makeTable(P);
	int textSize = strlen(T);
	int patternSize = strlen(P);
	int j = 0;
	for (int i = 0; i < textSize; i++) {
		while (j > 0 && T[i] != P[j]) {	//처음 문자열매칭이 이루어지지 않았을때 현재 위치에서 1을뺀 값을 j로 이동
			j = table[j - 1];
		}
		if (T[i] == P[j]) {	
			if (j == patternSize - 1) {	//문자가 전체 일치한 경우
				cout << "패턴이 텍스트의 " << i - patternSize + 2 << "번째부터 나타남" << endl;
				j = table[j];	//매칭이 이루어지는 모든 위치를 출력하기 위해 점프
			}
			else {
				j++;
			}
		}
	}
} 

void RabinKarp(char* T, char* P) {	//라빈카프 (해시함수: 
	int textSize = strlen(T);
	int patternSize = strlen(P);
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
				cout << "패턴이 텍스트의 " << i + 1 << "번째부터 나타남" << endl;
			}
		}
	}
}
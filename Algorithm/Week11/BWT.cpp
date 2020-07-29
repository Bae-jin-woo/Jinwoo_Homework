//2015112128 배진우
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

string** findBWT(string& T);
string* stringSort(string*& s);
string** sort(string** s, int length);
void stringSwap(string& a, string& b);
string recoveryString(string** s, int length);

int main() {
	string s = "BaeJinwoo";
	string** BWT = new string * [2];
	BWT[0] = new string[s.length()];
	BWT[1] = new string[s.length()];
	BWT = findBWT(s);	//BWT에 값이랑 인덱스 들어있음
	string result = recoveryString(BWT, s.length());
	cout << result << endl;
}

string** findBWT(string& T) {
	//Fill the rest를 만들어 정렬 후 BMT를 만드는 과정을 수행한다.
	T += "$";
	int length = T.length();

	string** result;
	result = new string * [2];
	for (int i = 0; i < 2; i++) {
		result[i] = new string[length];
	}

	string* stringList = new string[length + 1];
	int k = 0;
	cout << "== Fill the rest ==" << endl << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {	//인덱스를 순환시켜 Fill the rest를 문자열 배열에 저장
			stringList[i] += T[(j + k) % length];
		}
		stringList[i].append(to_string(i));
		k++;
	}
	for (int i = 0; i < length; i++) {
		cout << stringList[i] << endl;
	}
	cout << endl << "=====  sort  ======" << endl << endl;

	stringList = stringSort(stringList);
	int a = 0;
	for (int i = length - 1; i >= 0; i--) {
		cout << stringList[i] << endl;
		result[0][a] = stringList[i][length - 1];
		result[1][a] = stringList[i].substr(length);
		a++;
	}
	cout << endl;
	delete[] stringList;
	return result;
	delete[] result;
}

string* stringSort(string*& s) {	//문자열을 정렬하는 함수. 버블정렬을 응용하여 문자열 전체를 정렬한다.
	int length = s[0].length();
	for (int i = length - 2; i > 0; i--) {
		for (int j = 0; j < length - 1; j++) {
			if (s[j] < s[j + 1]) {
				stringSwap(s[j], s[j + 1]);
			}
		}
	}
	return s;
}

string recoveryString(string** s, int length) {	//BMT를 입력받아 문자열을 복구하는 함수
	string** BWT = new string * [2];
	string** sortBWT = new string * [2];
	int count = 0;
	for (int i = 0; i < 2; i++) {
		BWT[i] = new string[length];
		sortBWT[i] = new string[length];
	}
	BWT = s;
	sortBWT = sort(BWT, length);
	string result = "";
	string index = "0";
	string now = "";

	cout << "=====  BWT  ======" << endl << endl;
	cout << "BWT" << '\t';
	for (int i = 0; i < length; i++) {
		cout << BWT[0][i];
	}
	cout << endl;
	cout << "SortBWT" << '\t';
	for (int i = 0; i < length; i++) {
		cout << sortBWT[0][i];
	}

	cout << endl;
	cout << endl << "=====  Recover  ======" << endl << endl;
	cout << "index" << '\t' << "now" << endl;
	cout << index << '\t' << now << endl;
	while (1) {	//Fill the rest에서 바로 앞 자리의 문자를 파악할 수 있으므로 이를 반복 추적하여 "$"이 나올 때까지 문자들을 저장한 뒤 뒤집어서 결과를 반환		
		if (now == "$") break;
		for (int i = 0; i < length; i++) {
			if (stoi(index) == stoi(sortBWT[1][i])) {
				now = BWT[0][i];
				if (now == "$") break;
				index = to_string(i);
				result += now;
				break;
			}
		}
		index = BWT[1][stoi(index)];
		cout << index << '\t' << now << endl;

	}
	cout << endl << "=====  result  ======" << endl;
	reverse(result.begin(), result.end());
	return result;
}

string** sort(string** s, int length) {	//문자열과 인덱스로 구성된 2차원 배열을 함께 정렬하는 함수. sortBMT를 만드는데 사용
	string** temp = new string * [2];
	temp[0] = new string[length];
	temp[1] = new string[length];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < length; j++) {
			temp[i][j] = s[i][j];
		}
	}

	string swap;
	string index;

	for (int i = length - 2; i > 0; i--) {
		for (int j = 0; j < length - 1; j++) {
			if (temp[0][j] > temp[0][j + 1]) {
				swap = temp[0][j];
				temp[0][j] = temp[0][j + 1];
				temp[0][j + 1] = swap;

				index = temp[1][j];
				temp[1][j] = temp[1][j + 1];
				temp[1][j + 1] = index;
			}
		}
	}
	return temp;
}

void stringSwap(string& a, string& b) {	//문자열 swap함수. 버블정렬 구현에 사용
	string swap;
	swap = a;
	a = b;
	b = swap;
}



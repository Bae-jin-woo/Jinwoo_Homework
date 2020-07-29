//2015112128 ������
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
	BWT = findBWT(s);	//BWT�� ���̶� �ε��� �������
	string result = recoveryString(BWT, s.length());
	cout << result << endl;
}

string** findBWT(string& T) {
	//Fill the rest�� ����� ���� �� BMT�� ����� ������ �����Ѵ�.
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
		for (int j = 0; j < length; j++) {	//�ε����� ��ȯ���� Fill the rest�� ���ڿ� �迭�� ����
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

string* stringSort(string*& s) {	//���ڿ��� �����ϴ� �Լ�. ���������� �����Ͽ� ���ڿ� ��ü�� �����Ѵ�.
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

string recoveryString(string** s, int length) {	//BMT�� �Է¹޾� ���ڿ��� �����ϴ� �Լ�
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
	while (1) {	//Fill the rest���� �ٷ� �� �ڸ��� ���ڸ� �ľ��� �� �����Ƿ� �̸� �ݺ� �����Ͽ� "$"�� ���� ������ ���ڵ��� ������ �� ����� ����� ��ȯ		
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

string** sort(string** s, int length) {	//���ڿ��� �ε����� ������ 2���� �迭�� �Բ� �����ϴ� �Լ�. sortBMT�� ����µ� ���
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

void stringSwap(string& a, string& b) {	//���ڿ� swap�Լ�. �������� ������ ���
	string swap;
	swap = a;
	a = b;
	b = swap;
}



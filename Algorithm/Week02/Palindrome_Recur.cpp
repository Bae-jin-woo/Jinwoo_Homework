//2015112128 ������
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool arr[100][100]; // i���� j������ ȸ���� ����

bool palindrome(string s, int i, int j) {
	if (i >= j) // i j�� �����ϸ� true. 
		return true; // ��͸� �ٽ� �������� Ż���ϸ� �� ���̶� �Ӹ������ �ƴϸ� false�� �ٲ�� ��ü�� �Ӹ�����̸� true ����

	if (s[i] != s[j]) // i������ j��° ���ڰ� �ٸ��ٸ� ȸ���� �ƴϹǷ� false
		return arr[i][j] = false;

	if (arr[i][j]) // i���� j������ ȸ���̸� true, �ƴϸ� false
		return arr[i][j];

	return palindrome(s, i + 1, j - 1); // ���ٸ� i�� j�� ���� ��ĭ�� �̵����� ��ȯ
}

int main() {
	string filePath = "C://Users//jw969//Desktop//exam_palindrome.txt";
	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		while (getline(openFile, line)) {
			cout << line << endl;
			int length = line.size();
			if (palindrome(line, 0, line.size() - 1)) // �ʱ� left�� 0�̰� right�� ��ü ������-1 �̴�.
				cout << "--Palindrome!!--" << "\n";
			else cout << "--Not Palindrome!!--" << "\n";
		}
		openFile.close();
	}
}


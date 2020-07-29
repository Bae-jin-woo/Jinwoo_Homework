//2015112128 ������
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string filePath = "C://Users//jw969//Desktop//exam_palindrome.txt";
	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		while (getline(openFile, line)) {	//������ �ҷ��� line���� �о�´�
			cout << line << endl;
			int length = line.size();
			for (int i = 0; i < length / 2; i++) {	//���� ���� Ȧ���� ���� ¦���� ��츦 ������ �ʿ�� ������(���� ���� ����)
				if (line[i] != line[length - i - 1]) {	//���� ��Ī�Ǵ� �ε����� ���ڸ� ���Ͽ� �ϳ��� �ٸ� ��� ȸ���� �ƴϰ�
					cout << "--Not Palindrome!!--" << endl;
					break;
				}
				else if ((i == length / 2 - 1) && line[i] == line[length - i - 1]) {	//���ܰ� ���� ��� ȸ��ó��
					cout << "--Palindrome!!--" << endl;
				}
			}
		}
		openFile.close();
	}
}
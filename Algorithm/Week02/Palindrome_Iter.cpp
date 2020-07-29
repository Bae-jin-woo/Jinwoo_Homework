//2015112128 배진우
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string filePath = "C://Users//jw969//Desktop//exam_palindrome.txt";
	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		while (getline(openFile, line)) {	//파일을 불러와 line별로 읽어온다
			cout << line << endl;
			int length = line.size();
			for (int i = 0; i < length / 2; i++) {	//글자 수가 홀수일 경우와 짝수일 경우를 구분할 필요는 없었다(몫이 같기 때문)
				if (line[i] != line[length - i - 1]) {	//각각 대칭되는 인덱스의 문자를 비교하여 하나라도 다를 경우 회문이 아니고
					cout << "--Not Palindrome!!--" << endl;
					break;
				}
				else if ((i == length / 2 - 1) && line[i] == line[length - i - 1]) {	//예외가 없을 경우 회문처리
					cout << "--Palindrome!!--" << endl;
				}
			}
		}
		openFile.close();
	}
}
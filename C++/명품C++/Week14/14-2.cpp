#include <iostream>
using namespace std;

int main() {
	char ch;
	int count = 0;
	while (1) {
		cin.get(ch); // 입력된키를ch에저장하여리턴
		if (cin.eof()) break; // EOF를만나면읽기종료
		if (ch == ' ') count++;
		if (ch == '\n')
			break; // <Enter> 키가입력되면읽기중단
	}
	cout << "빈칸의 수 -->" << count << endl;
}

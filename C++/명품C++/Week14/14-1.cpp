#include <iostream>
using namespace std;

int main() {
	int ch;
	int count = 0;
	while ((ch = cin.get()) != EOF) { // EOF 는-1
		if (ch == 'a')
			count++;
		if (ch == '\n')
			break; // <Enter> 키가입력되면읽기중단
	}
	cout << "a의 갯수 -> " << count << endl;
	
}

#include <iostream>
using namespace std;

int main() {
	char ch;
	char ch1[80];
	do{
		ch = cin.get();
		cin.ignore(80,';');	//;이 나오기 전 입력들은 무시
		cin.get(ch1, 80);
		for (int i = 0; i < cin.gcount(); i++) {
			cout << ch1[i];
		}
		cout << endl;
		cin.ignore();
	} while (ch != EOF);
}

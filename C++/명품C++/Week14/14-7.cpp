#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main() {
	cout << left;
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << "dec";
		cout << setw(10) << "hex";
		cout << setw(10) << "char";
	}
	cout << right << endl;
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << setfill('_');
		cout << "       ";
		cout << setw(10);
		cout << "      ";
		cout << setw(10);
		cout << "      ";
	}
	cout << left << setfill(' ') << endl;
	for (int i = 0; i < 128; i++) {
		cout << setw(10) << dec << i;
		cout << setw(10) << hex << i;
		cout << setw(10);
		if (isprint(i))
			cout << (char)i;
		else
			cout << ".";
		if (i > 0 && i % 4 == 3)	//3마다 개행
			cout << endl;
	}
}

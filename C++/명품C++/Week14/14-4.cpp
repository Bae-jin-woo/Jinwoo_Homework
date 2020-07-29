#include <iostream>
using namespace std;

int main() {
	char before[100];
	char after[100];

	while (1) {
		cin.get(before, 100, ';');
		if (cin.eof()) break;
		for (int i = 0; i < cin.gcount(); i++)
			cout << before[i];
		cin.ignore(1);
		cin.get(after, 100);
		cin.ignore();
		cout << endl;
	}
}

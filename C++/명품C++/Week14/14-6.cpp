#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x;
	cout.setf(ios::left);	//왼쪽 맞춤형식으로 출력
	cout.width(15);
	cout << "Number";
	cout.width(15);
	cout << "Square";
	cout.width(15);
	cout << "Square Root";
	cout << endl;
	for (int i = 0; i < 50; i += 5) {
		x = sqrt(i);
		cout.width(15);
		cout << i;
		cout.fill('_');
		cout.width(15);
		cout << i*i;
		cout.fill('_');
		cout.width(15);
		cout.precision(3);
		cout << x;
		cout.fill('_');
		cout << endl;
	}
}

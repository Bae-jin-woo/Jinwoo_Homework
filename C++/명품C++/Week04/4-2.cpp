#include <iostream>
using namespace std;
double Circle(double r) { return 3.14*r*r; }

int main() {
	double r;
	cout << "반지름 입력>>";
	cin >> r; 
	cout << fixed;
	cout.precision(3);
	cout << "원의 면적은 " << Circle(r) << endl;
}

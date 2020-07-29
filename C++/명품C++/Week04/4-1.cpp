#include <iostream>
using namespace std;
double Mul(double a, double b) { return a * b; }

int main() {
	double num1, num2;
	cout << "두 개의 숫자를 입력>>";
	cin >> num1 >> num2; 
	cout << fixed;
	cout.precision(1);
	cout << "두 수의 곱은 " << Mul(num1, num2) << endl;
}

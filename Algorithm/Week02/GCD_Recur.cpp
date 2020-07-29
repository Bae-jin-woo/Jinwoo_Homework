//2015112128 배진우
#include <iostream>
#include <string>
using namespace std;

int gcd(int num1, int num2);

int main() {
	int num1 = 0, num2 = 0;
	cout << "숫자 2개 입력>>";
	cin >> num1 >> num2;
	cout << gcd(num1, num2) << endl;
}
int gcd(int num1, int num2) {	//num1이 num2로 나누어 떨어지면 num2가 최대공약수이고(num1>num2라 가정)
	if (num2 == 0)			//나누어 떨어지지 않는다면 (num1,num2)자리에 (num2,num1%num2)를 호출하는 과정을 반복한다.
		return num1;
	else {
		return gcd(num2, num1 % num2);
	}
}

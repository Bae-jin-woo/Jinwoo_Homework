//2015112128 ������
#include <iostream>
#include <string>
using namespace std;

int gcd(int num1,int num2);

int main() {
	int num1=0, num2=0;
	cout << "���� 2�� �Է�>>";
	cin >> num1 >> num2;
	cout << gcd(num1, num2) << endl;
}
int gcd(int num1, int num2) {	//�� ���� ���߿��� �������� ���Ͽ� 1���� ���� ������ ������ ���� ������ ��������
	int min = num1 <= num2 ? num1 : num2;	//���� ū ���� ã�� ���Ѵ�.
	int result = 0;
	for (int i = 1; i <= min; i++) {
		if (num1 % i == 0 && num2 % i == 0)
			result = i;
	}
	return result;
}
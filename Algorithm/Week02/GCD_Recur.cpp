//2015112128 ������
#include <iostream>
#include <string>
using namespace std;

int gcd(int num1, int num2);

int main() {
	int num1 = 0, num2 = 0;
	cout << "���� 2�� �Է�>>";
	cin >> num1 >> num2;
	cout << gcd(num1, num2) << endl;
}
int gcd(int num1, int num2) {	//num1�� num2�� ������ �������� num2�� �ִ������̰�(num1>num2�� ����)
	if (num2 == 0)			//������ �������� �ʴ´ٸ� (num1,num2)�ڸ��� (num2,num1%num2)�� ȣ���ϴ� ������ �ݺ��Ѵ�.
		return num1;
	else {
		return gcd(num2, num1 % num2);
	}
}

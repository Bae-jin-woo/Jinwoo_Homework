//2015112128 ������
#include <iostream>
#include <string>
using namespace std;

int gcd(int size, int num[]);

int main() {
	int size;
	int* num;
	cout << "���� ����:";
	cin >> size;
	num = new int[size];
	cout << "���� �Է�:";
	for (int i = 0; i < size; i++) {
		cin >> num[i];
	}
	cout << gcd(size, num);
}
int gcd(int size, int num[]) {	//1������ ����� �˰���� �����ϴ�
	int result = 0;
	int min = num[0];
	for (int i = 0; i < size; i++) {	//�Է¹��� ���� �� ���� ���� ���� ���ϰ�
		if (min > num[i])
			min = num[i];
	}
	for (int i = 1; i <= min; i++) {	//���� ���� ���� �������� ������ ����
		int count = 0;
		for (int j = 0; j < size; j++) {	//�迭�� Ž���ϸ� ���ڰ� ������ ������ ������ ī��Ʈ�ϰ�
			if (num[j] % i == 0) {
				count++;
			}
		}
		if (count == size)	//��� ���ڰ� ������ �������� ������� ��� result�� ����
			result = i;
	}
	return result;
}
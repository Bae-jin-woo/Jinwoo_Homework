//2015112128 ������
#pragma warning (disable: 4996)
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string s;
	vector<double> num;
	stringstream stream1;
	double count = 0;
	double is_num;
	cout << "�迭�� �Է����ּ���: ";
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {	//���ڿ� �������� ���ڿ� ������ �Է¹޾� 
		stream1.str(s);						//������ �������� ���� ����
		while (stream1 >> is_num)
			num.push_back(is_num);
	}
	int size = num.size();
	double* avr = new double[size];
	cout << "Avr ���" << endl;
	for (int i = 0; i < size; i++) {	//count ������ ���ڸ� �����ϸ鼭 avr �迭�� ������ ��� ����
		count += num[i];
		avr[i] = count / (i + 1);
		cout << " Avr[" << i << "]: " << avr[i] << endl;
	}
	delete[] avr;
	return 0;
}

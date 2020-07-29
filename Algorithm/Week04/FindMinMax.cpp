//2015112128 ������
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

long long Make_Random_Number();
long long Minimum(vector<long long>& v, int n);
long long Maximum(vector<long long>& v, int n);
void Find_Min_Max(vector<long long>& v, int n, long long& minimum, long long& maximum);

int main() {
	srand(time(NULL));
	int i;
	vector<long long> v;
	for (i = 0; i < 1000; i++)
		v.push_back(Make_Random_Number());
	cout << "Minimum �Լ��� �̿��� �ּҰ� : " << Minimum(v, v.size()) << endl;	//��� ���
	cout << "Maximum �Լ��� �̿��� �ִ밪 : " << Maximum(v, v.size()) << endl;
	long long max_num = 0;
	long long min_num = 0;
	Find_Min_Max(v, v.size(), min_num, max_num);
	printf("FindMinMax �Լ��� �̿��� �ּҰ��� �ִ밪: %lld, %lld\n", min_num, max_num);
}

long long Make_Random_Number() {	//1~100000���� ���� ���� �Լ�
		double ran = rand() / (double)INT_MAX;	//0~1������ �Ǽ� ���� ���� �� 1~100000���� ���� ����
		ran *= pow(10, 10);
		long long random = (long long)ran;
		random = random % 100000 + 1;
		return random;
}

long long Minimum(vector<long long>& v, int n) {	//�ּҰ� ��� �Լ�
	int i;
	long long temp;
	temp = v[0];
	for (i = 1; i < n; i++) {	//�迭 �ȿ��� �ּҰ��� ã�� ������ temp�� ����
		if (temp > v[i])
			temp = v[i];
	}
	return temp;
}

long long Maximum(vector<long long>& v, int n) {	//�ִ밪 ��� �Լ�
	int i;
	long long temp;
	temp = v[0];
	for (i = 1; i < n; i++) {	//�迭 �ȿ��� �ִ밪�� ã�� ������ temp�� ����
		if (temp < v[i])
			temp = v[i];
	}
	return temp;
}

void Find_Min_Max(vector<long long>& v, int n, long long& minimum, long long& maximum) {
	int i;	//�ּҰ��� �ִ밪�� ���ÿ� ã�� �Լ�
	long long small = 0;
	long long large = 0; 
	minimum = v[0];
	maximum = v[0];
	for (i = 1; i < n - 1; i += 2) {	//�迭 �ε����� 2���� ���ϸ鼭 ���� ���� ū ���� ����
		if (v[i] < v[i + 1]) {			//small, large�� ����
			small = v[i];
			large = v[i + 1];
		}
		else {
			small = v[i + 1];
			large = v[i];
		}
		if (small < minimum) minimum = small;	//������ �� ������ small, large���� maximum, minimum��
		if (large > maximum) maximum = large;	//���Ͽ� �ּҰ��� �ִ밪�� ã�´�
	}
}
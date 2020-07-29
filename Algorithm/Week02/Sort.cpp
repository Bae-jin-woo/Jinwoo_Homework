//2015112128 ������
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

void bubble_sort(int arr[],int n);
void quick_sort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

int main() {
	int N1[10];
	int N2[10];
	int K1[1000];
	int K2[1000];
	int random_number = 0;

	srand((unsigned int)time(NULL));	//1~10000���̿� ������ �����Ͽ� ���α׷� ���� �ø���
	for (int i = 0; i < 10; i++) {	//�迭 N�� K�� �ٸ� ���ڰ� ���� ����
		random_number = rand() % 10000 + 1;
		N1[i] = random_number;
		N2[i] = N1[i];
	}
	for (int i = 0; i < 1000; i++) {
		random_number = rand() % 10000 + 1;
		K1[i] = random_number;
		K2[i] = K1[i];
	}
	clock_t bubble_start, bubble_end, quick_start, quick_end; // �ð� ������ ���� ������
	double bubble_result, quick_result;


	cout << "���� ���� ��: ";
	for (int i = 0; i < 10; i++) {	//���� ���� ��
		cout << K1[i] << " ";
	}
	cout << endl;

	bubble_start = clock();	//���� ���� �� �ӵ� ����
	bubble_sort(K1, 1000);
	bubble_end = clock();
	bubble_result = (double)(bubble_end - bubble_start) / CLOCKS_PER_SEC; // ���� ���Ŀ� �ɸ� �ð�

	cout << "���� ���� ��: ";
	for (int i = 0; i < 10; i++) {	//���� ���� ��
		cout << K1[i] << " ";
	}
	cout<<endl;
	cout << "�� ���� ��: ";
	for (int i = 0; i < 10; i++) {	//���� ���� ��
		cout << K2[i] << " ";
	}
	cout << endl;
	quick_start = clock();
	quick_sort(K2, 0, 999);
	quick_end = clock();
	quick_result = (double)(quick_end - quick_start) / CLOCKS_PER_SEC;	//�� ���Ŀ� �ɸ� �ð�
	cout << "�� ���� ��: ";
	for (int i = 0; i < 10; i++) {	//���� ���� ��
		cout << K2[i] << " ";
	}
	cout << endl;
	cout << "���� ���� �ð�: " << bubble_result << endl;
	cout << "�� ���� �ð�: " << quick_result << endl;
	for (int i = 0; i < 1000; i++) {	//���� ��� �� �� ���
		if (K1[i] != K2[i]) {
			cout << "���� ��� �ٸ�!" << endl;
			return 0;
		}
	}
	cout << "���� ��� ����!" << endl;
	return 0;
}

void bubble_sort(int arr[],int n) {
	int i;
	bool Sorted;
	Sorted = false;
	while (!Sorted) {
		Sorted = true;	//������ �� �Ǿ��� �� break
		for(i=1;i<n;i++)
			if (arr[i - 1] < arr[i]) {	//i-1��° ���� i��° ������ ũ�ٸ� swap�ϴ� ������ �ݺ� 
				swap(arr[i - 1], arr[i]);
				Sorted = false;
			}
	}
}

int partition(int arr[], int left, int right) {	//pivot�� �������� partiotion�� ������ ���� �Լ�
	int first = left;
	int last = right + 1;	//���������� ���� 1 ����
	int pivot = arr[left];
	do {
		do {} while (arr[++first] > pivot); // ���ʿ��� pivot���� ū ���Ҹ� ã�´�
		do {} while (arr[--last] < pivot); // �����ʿ��� pivot���� ���� ���� ã��
		if (first < last) { // first�� last�� �������� ���� ���ʿ��� �ǹ����� ���� ���ҿ�
			swap(arr[first], arr[last]); // �����ʿ��� �ǹ����� ū ���Ҹ� ã���� ���� ��ȯ
		}
	} while (first < last);
	swap(arr[left], arr[last]); // ���������� last�� ���� �ǹ� left ��ġ�� ���� ��ȯ���ش�.
	return last; // �ǹ��� ��ġ ��ȯ
}

void quick_sort(int arr[], int left, int right) {
	vector<int> stack; //����Լ� ���� �� ������ ������ �̿��Ѵ�. left�� right ������ ���� push�Ѵ�.
	stack.push_back(left); 
	stack.push_back(right);

	while (!stack.empty()) { // ������ ������� ���� �� �ݺ�
		right = stack.back(); // FIFO�̹Ƿ� pop�� �ݴ�� �Ѵ�.
		stack.pop_back();
		left = stack.back();
		stack.pop_back();
		int pivot = partition(arr, left, right); // �ǹ��� ��ġ�� ã�´�.

		if (pivot - 1 > left) { // ����Լ��� ����� ��, �ǹ� ���� �κ��� ��ü�ϴ� ����̴�.
			stack.push_back(left); //left�� pivot-1���� ���������� ������ �����ϴ�.
			stack.push_back(pivot - 1); //���ÿ� ���� ���� left, right ������� �ִ´�.
		}
		if (pivot + 1 < right) { // �ǹ� ������ �κ��� �ٷ��.
			stack.push_back(pivot + 1); //pivot+1���� right���� ����
			stack.push_back(right);
		}
	}
}
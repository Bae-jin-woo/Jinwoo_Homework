//2015112128 ������
#define NUM_OF_KEYS 10
#include <iostream>
#include <string>
using namespace std;

int b[NUM_OF_KEYS];

void merge_sort_recursive(int arr[], int left, int right);
void merge_sort_iterative(int arr[]);
void merge(int arr[], int left, int mid, int right);
void arr_show(int arr[]) {
	for (int i = 0; i < NUM_OF_KEYS; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr1[NUM_OF_KEYS] = { 30, 20, 40, 35, 5, 50, 45, 10, 25, 15 };
	int arr2[NUM_OF_KEYS] = { 30, 20, 40, 35, 5, 50, 45, 10, 25, 15 };
	int left = 0, right = NUM_OF_KEYS - 1;
	//cout << "----��ȯ�� �պ����� ȣ�� ��----" << endl;
	//arr_show(arr1);
	//cout << "----��ȯ�� �պ����� ȣ�� ��----" << endl;
	//merge_sort_recursive(arr1, left, right);
	//arr_show(arr1);
	cout << "----���ȯ�� �պ����� ȣ�� ��----" << endl;
	arr_show(arr2);
	cout << "----���ȯ�� �պ����� ȣ�� ��----" << endl;
	merge_sort_iterative(arr2);
	arr_show(arr2);
}
void merge_sort_recursive(int arr[], int left, int right) {
	int mid;
	if (left < right) {	//���Ұ� 2�� �̻� ���� ��
		mid = (left + right) / 2;	//left+�� right�� ���ؼ� mid�� ���ϰ�
		merge_sort_recursive(arr, left, mid);	//left~mid�� mid+1~right �� ���� ȣ���Ͽ� recursive
		merge_sort_recursive(arr, mid + 1, right);
		merge(arr, left, mid, right);	//�� �ε����� ��� 1���� �и��ȴٸ� �̺κ��� ����Ǹ� merge�Ѵ�.
	}
}
void merge_sort_iterative(int arr[]) {
	int left, right, mid;

	for (int i = 1; i < NUM_OF_KEYS; i++) { // ��� ���� �ɰ�
		left = 0;	//���� ����Ʈ
		while (left <= NUM_OF_KEYS) {
			right = left + 2 * i - 1;           
			if (right > NUM_OF_KEYS) { right = NUM_OF_KEYS; }	//����ó��
			mid = left + i - 1;
			if (mid <= NUM_OF_KEYS) { // �߰����� ��ü ������� �۴ٸ� �պ�
				merge(arr, left, mid, right);
			}
			left = right + 1;	//���� ���������� ������ �ٷ� �������� ����
		}
		arr_show(arr);
	}
}
void merge(int arr[], int left, int mid, int right) {
	int i, left_ptr, right_ptr, buf_ptr;
	left_ptr = left; right_ptr = mid + 1; buf_ptr = left;	//left_ptr = left, right_ptr = mid+1���� ����
	while (left_ptr <= mid && right_ptr <= right)	//left_ptr�� right_ptr�� ���� ���� ������ �κп� ���������� �ݺ��Ͽ�
		if (arr[left_ptr] < arr[right_ptr])	//�� �����Ͱ� ����Ű�� ���� ��� ���踦 ���Ͽ�
			b[buf_ptr++] = arr[left_ptr++];	
		else b[buf_ptr++] = arr[right_ptr++];	//���ۿ� �־� �����Ѵ�.
	if (left_ptr > mid)	//���� �κ��� ���ۿ� �� ���ٸ�
		for (i = right_ptr; i <= right; i++)	//���� ������ �κ��� �̹� ������ �Ǿ������Ƿ� ���ۿ� �״�� �߰�
			b[buf_ptr++] = arr[i];
	else
		for (i = left_ptr; i <= mid; i++)	//������ �κ��� ���ۿ� �� ���ٸ� ���� ���ʺκ� ���ۿ� �߰�
			b[buf_ptr++] = arr[i];
	for (i = left; i <= right; i++)	//���ۿ��� �պ��ϸ鼭 ��� �迭�� ���ĵǾ� �����Ƿ� �迭�� ����
		arr[i] = b[i];
}
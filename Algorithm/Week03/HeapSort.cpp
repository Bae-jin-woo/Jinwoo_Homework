//2015112128 ������
#include <iostream>
#include <vector>
#include <algorithm>
#define ARRAY_LENGTH 10
using namespace std;

void HeapSort(vector<int>& A, int n);
void MakeHeap(vector<int>& A, int Root, int LastNode);
void Swap(int *a, int* b);
void arr_show(vector<int> &arr) {
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	HeapSort(arr, ARRAY_LENGTH);
}
void HeapSort(vector<int>& A, int n) {
	int i;
	for (i = n / 2; i >= 0; i--) {
		MakeHeap(A, i, n - 1);	//������ �迭�� ������ ��ȯ
	}
	cout << "�� ���� ��-->";
	arr_show(A);
	for (i = n - 1; i > 0; i--) {
		swap(A[0], A[i]);	//���� �ִ밪�� A[i]�� ��ȯ
		MakeHeap(A, 0, i - 1);	//���� ���ҷ� �� ������
	}
	cout << "���� ��-->";
	arr_show(A);
}

void MakeHeap(vector<int>& A, int Root, int LastNode)
{
	int Parent, LeftSon, RightSon, Son, RootValue;
	// �Է� ��� A[Root+1:LastNode] �� �̹� �� �������� ����
	Parent = Root;
	RootValue = A[Root];
	LeftSon = 2 * Parent + 1;
	RightSon = LeftSon + 1;
	while (LeftSon <= LastNode) {
		if ((RightSon <= LastNode) && (A[LeftSon] < A[RightSon]))
			Son = RightSon;//child �� ū�Ϳ� ��� son�� ����
		else Son = LeftSon;
		if (RootValue < A[Son]) {// ��Ʈ������ son���� ũ��
			 A[Parent] = A[Son];//son�� ���� �ø�
			 Parent = Son;//son �� parent �� ��
			 LeftSon = Parent * 2 + 1;//child �ٽ� ����
			 RightSon = LeftSon + 1;}
		 else break;	
	}
	A[Parent] = RootValue;
}

void Swap(int* a, int* b) {
	int *temp = a;
	a = b;
	b = temp;
}
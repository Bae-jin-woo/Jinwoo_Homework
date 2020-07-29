//2015112128 배진우
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
		MakeHeap(A, i, n - 1);	//정렬한 배열을 힙으로 변환
	}
	cout << "힙 생성 후-->";
	arr_show(A);
	for (i = n - 1; i > 0; i--) {
		swap(A[0], A[i]);	//힙의 최대값을 A[i]와 교환
		MakeHeap(A, 0, i - 1);	//남은 원소로 힙 재정비
	}
	cout << "정렬 후-->";
	arr_show(A);
}

void MakeHeap(vector<int>& A, int Root, int LastNode)
{
	int Parent, LeftSon, RightSon, Son, RootValue;
	// 입력 당시 A[Root+1:LastNode] 는 이미 힙 구조임을 가정
	Parent = Root;
	RootValue = A[Root];
	LeftSon = 2 * Parent + 1;
	RightSon = LeftSon + 1;
	while (LeftSon <= LastNode) {
		if ((RightSon <= LastNode) && (A[LeftSon] < A[RightSon]))
			Son = RightSon;//child 중 큰것올 골라 son에 넣음
		else Son = LeftSon;
		if (RootValue < A[Son]) {// 루트값보다 son값이 크면
			 A[Parent] = A[Son];//son을 위로 올림
			 Parent = Son;//son 이 parent 가 됨
			 LeftSon = Parent * 2 + 1;//child 다시 지정
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
//2015112128 배진우
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
	//cout << "----순환적 합병정렬 호출 전----" << endl;
	//arr_show(arr1);
	//cout << "----순환적 합병정렬 호출 후----" << endl;
	//merge_sort_recursive(arr1, left, right);
	//arr_show(arr1);
	cout << "----비순환적 합병정렬 호출 전----" << endl;
	arr_show(arr2);
	cout << "----비순환적 합병정렬 호출 후----" << endl;
	merge_sort_iterative(arr2);
	arr_show(arr2);
}
void merge_sort_recursive(int arr[], int left, int right) {
	int mid;
	if (left < right) {	//원소가 2개 이상 있을 때
		mid = (left + right) / 2;	//left+와 right를 통해서 mid를 구하고
		merge_sort_recursive(arr, left, mid);	//left~mid와 mid+1~right 를 각각 호출하여 recursive
		merge_sort_recursive(arr, mid + 1, right);
		merge(arr, left, mid, right);	//각 인덱스가 모두 1개로 분리된다면 이부분이 실행되며 merge한다.
	}
}
void merge_sort_iterative(int arr[]) {
	int left, right, mid;

	for (int i = 1; i < NUM_OF_KEYS; i++) { // 모든 값을 쪼갬
		left = 0;	//왼쪽 디폴트
		while (left <= NUM_OF_KEYS) {
			right = left + 2 * i - 1;           
			if (right > NUM_OF_KEYS) { right = NUM_OF_KEYS; }	//예외처리
			mid = left + i - 1;
			if (mid <= NUM_OF_KEYS) { // 중간값이 전체 사이즈보다 작다면 합병
				merge(arr, left, mid, right);
			}
			left = right + 1;	//왼쪽 시작지점을 오른쪽 바로 다음으로 갱신
		}
		arr_show(arr);
	}
}
void merge(int arr[], int left, int mid, int right) {
	int i, left_ptr, right_ptr, buf_ptr;
	left_ptr = left; right_ptr = mid + 1; buf_ptr = left;	//left_ptr = left, right_ptr = mid+1부터 시작
	while (left_ptr <= mid && right_ptr <= right)	//left_ptr와 right_ptr이 각각 왼쪽 오른쪽 부분에 있을때까지 반복하여
		if (arr[left_ptr] < arr[right_ptr])	//두 포인터가 가리키는 수의 대소 관계를 비교하여
			b[buf_ptr++] = arr[left_ptr++];	
		else b[buf_ptr++] = arr[right_ptr++];	//버퍼에 넣어 정렬한다.
	if (left_ptr > mid)	//왼쪽 부분이 버퍼에 다 들어갔다면
		for (i = right_ptr; i <= right; i++)	//남은 오른쪽 부분은 이미 정렬이 되어있으므로 버퍼에 그대로 추가
			b[buf_ptr++] = arr[i];
	else
		for (i = left_ptr; i <= mid; i++)	//오른쪽 부분이 버퍼에 다 들어갔다면 남은 왼쪽부분 버퍼에 추가
			b[buf_ptr++] = arr[i];
	for (i = left; i <= right; i++)	//버퍼에는 합병하면서 모든 배열이 정렬되어 있으므로 배열에 대입
		arr[i] = b[i];
}
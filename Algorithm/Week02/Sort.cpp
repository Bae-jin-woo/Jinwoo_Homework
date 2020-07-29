//2015112128 배진우
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

	srand((unsigned int)time(NULL));	//1~10000사이에 난수를 생성하여 프로그램 실행 시마다
	for (int i = 0; i < 10; i++) {	//배열 N와 K에 다른 숫자가 들어가게 생성
		random_number = rand() % 10000 + 1;
		N1[i] = random_number;
		N2[i] = N1[i];
	}
	for (int i = 0; i < 1000; i++) {
		random_number = rand() % 10000 + 1;
		K1[i] = random_number;
		K2[i] = K1[i];
	}
	clock_t bubble_start, bubble_end, quick_start, quick_end; // 시간 측정을 위한 변수들
	double bubble_result, quick_result;


	cout << "버블 정렬 전: ";
	for (int i = 0; i < 10; i++) {	//버블 정렬 전
		cout << K1[i] << " ";
	}
	cout << endl;

	bubble_start = clock();	//버블 정렬 및 속도 측정
	bubble_sort(K1, 1000);
	bubble_end = clock();
	bubble_result = (double)(bubble_end - bubble_start) / CLOCKS_PER_SEC; // 버블 정렬에 걸린 시간

	cout << "버블 정렬 후: ";
	for (int i = 0; i < 10; i++) {	//버블 정렬 후
		cout << K1[i] << " ";
	}
	cout<<endl;
	cout << "퀵 정렬 전: ";
	for (int i = 0; i < 10; i++) {	//버블 정렬 전
		cout << K2[i] << " ";
	}
	cout << endl;
	quick_start = clock();
	quick_sort(K2, 0, 999);
	quick_end = clock();
	quick_result = (double)(quick_end - quick_start) / CLOCKS_PER_SEC;	//퀵 정렬에 걸린 시간
	cout << "퀵 정렬 후: ";
	for (int i = 0; i < 10; i++) {	//버블 정렬 후
		cout << K2[i] << " ";
	}
	cout << endl;
	cout << "버블 정렬 시간: " << bubble_result << endl;
	cout << "퀵 정렬 시간: " << quick_result << endl;
	for (int i = 0; i < 1000; i++) {	//정렬 결과 비교 및 출력
		if (K1[i] != K2[i]) {
			cout << "정렬 결과 다름!" << endl;
			return 0;
		}
	}
	cout << "정렬 결과 같음!" << endl;
	return 0;
}

void bubble_sort(int arr[],int n) {
	int i;
	bool Sorted;
	Sorted = false;
	while (!Sorted) {
		Sorted = true;	//정렬이 다 되었을 때 break
		for(i=1;i<n;i++)
			if (arr[i - 1] < arr[i]) {	//i-1번째 수가 i번째 수보다 크다면 swap하는 과정을 반복 
				swap(arr[i - 1], arr[i]);
				Sorted = false;
			}
	}
}

int partition(int arr[], int left, int right) {	//pivot을 기준으로 partiotion을 나누는 분할 함수
	int first = left;
	int last = right + 1;	//선위연산을 위한 1 가산
	int pivot = arr[left];
	do {
		do {} while (arr[++first] > pivot); // 왼쪽에서 pivot보다 큰 원소를 찾는다
		do {} while (arr[--last] < pivot); // 오른쪽에서 pivot보다 작은 원소 찾기
		if (first < last) { // first와 last가 엇갈리기 전에 왼쪽에서 피벗보다 작은 원소와
			swap(arr[first], arr[last]); // 오른쪽에서 피벗보다 큰 원소를 찾으면 둘이 교환
		}
	} while (first < last);
	swap(arr[left], arr[last]); // 마지막으로 last의 값과 피벗 left 위치의 값을 교환해준다.
	return last; // 피벗의 위치 반환
}

void quick_sort(int arr[], int left, int right) {
	vector<int> stack; //재귀함수 없는 퀵 정렬은 스택을 이용한다. left와 right 순서로 각각 push한다.
	stack.push_back(left); 
	stack.push_back(right);

	while (!stack.empty()) { // 스택이 비어있지 않은 한 반복
		right = stack.back(); // FIFO이므로 pop은 반대로 한다.
		stack.pop_back();
		left = stack.back();
		stack.pop_back();
		int pivot = partition(arr, left, right); // 피벗의 위치를 찾는다.

		if (pivot - 1 > left) { // 재귀함수를 사용할 때, 피벗 왼쪽 부분을 대체하는 방법이다.
			stack.push_back(left); //left가 pivot-1보다 작을때까지 분할이 가능하다.
			stack.push_back(pivot - 1); //스택에 넣을 때는 left, right 순서대로 넣는다.
		}
		if (pivot + 1 < right) { // 피벗 오른쪽 부분을 다룬다.
			stack.push_back(pivot + 1); //pivot+1부터 right까지 분할
			stack.push_back(right);
		}
	}
}
//2015112128 배진우
#include <iostream>
#include <string>
using namespace std;

int gcd(int size, int num[]);

int main() {
	int size;
	int* num;
	cout << "숫자 갯수:";
	cin >> size;
	num = new int[size];
	cout << "숫자 입력:";
	for (int i = 0; i < size; i++) {
		cin >> num[i];
	}
	cout << gcd(size, num);
}
int gcd(int size, int num[]) {	//1번에서 사용한 알고리즘과 동일하다
	int result = 0;
	int min = num[0];
	for (int i = 0; i < size; i++) {	//입력받은 숫자 중 가장 작은 수를 구하고
		if (min > num[i])
			min = num[i];
	}
	for (int i = 1; i <= min; i++) {	//가장 작은 수를 기준으로 루프를 돈다
		int count = 0;
		for (int j = 0; j < size; j++) {	//배열을 탐색하며 숫자가 나누어 떨어질 때마다 카운트하고
			if (num[j] % i == 0) {
				count++;
			}
		}
		if (count == size)	//모든 숫자가 나누어 떨어지는 공약수일 경우 result에 저장
			result = i;
	}
	return result;
}
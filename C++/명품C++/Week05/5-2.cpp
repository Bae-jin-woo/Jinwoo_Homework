#include <iostream>
using namespace std;
int main() {
	double sum = 0;
	int *array = new int[5];	//배열 동적할당
	cout << "정수 5개 입력>>";
	cin >> array[0] >> array[1] >> array[2] >> array[3] >> array[4];
	for (int i=0; i<5; i++)
		sum += array[i];
	cout << "평균: " << sum/5 << endl;
	delete [] array;
}

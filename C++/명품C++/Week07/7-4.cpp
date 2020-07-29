#include <iostream>
using namespace std;
class MyVector {
	int *mem;
	int size;
public:
	MyVector(int n, int val);
	~MyVector() { delete[] mem; }
	void show();
};
//size만큼의 배열을 동적 생성해서 val값으로 초기화
MyVector::MyVector(int n=100, int val=0) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++)	mem[i] = val;
	
}
void MyVector::show() {
	for (int i = 0; i < size; i++)
		cout << mem[i] << " ";
	cout << endl;
}
int main() {
	MyVector v1;
	MyVector v2(10, 5);
	v1.show();
	v2.show();
}

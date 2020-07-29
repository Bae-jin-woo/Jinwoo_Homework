#include <iostream>
using namespace std;

class SortedArray {
	int size;	//현재 배열의 크기
	int *p;	//정수 배열에 대한 포인터
	void sort();	//정수 배열을 오름차순으로 정렬
public:
	SortedArray();
	SortedArray(SortedArray& src);
	SortedArray(int p[], int size);
	~SortedArray();
	SortedArray operator +(SortedArray& op2);
	SortedArray operator =(const SortedArray& op2);
	void show();
};
SortedArray::SortedArray() {	//p=NULL로 size = 0으로 초기화
	this->p = NULL;
	this->size = 0;
}
SortedArray::SortedArray(SortedArray& src) {	//복사 생성자
	this->size = src.size;
	p = new int[this->size];
	for (int i = 0; i < this->size; i++)
		p[i] = src.p[i];
}
SortedArray::SortedArray(int p[], int size) {	//생성자. 정수 배열과 크기를 전달받음
	this->size = size;
	this->p = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->p[i] = p[i];
}
SortedArray::~SortedArray() {	//소멸자
	delete[] p;
}
SortedArray SortedArray::operator +(SortedArray& op2) {	//temp 배열을 동적할당하여 두 배열을 합친 값을 저장
	SortedArray temp;
	temp.size = this->size + op2.size;
	temp.p = new int[temp.size];
	for (int i = 0; i < this->size; i++)
		temp.p[i] = p[i];
	for (int i = this->size; i < temp.size; i++)
		temp.p[i] = op2.p[i - this->size];
	return temp;
}
SortedArray SortedArray::operator =(const SortedArray& op2) {	//현재 배열에 op2 배열 복사
	size = op2.size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = op2.p[i];
	return *this;
}
void SortedArray::show() {	//배열의 원소 출력
	sort();
	for (int i = 0; i < size; i++)
		cout << p[i] << " ";
	cout << endl;
}
void SortedArray::sort() {
	for (int i = 0; i < size-1; i++) {
		if (p[i] > p[i + 1]) {
			int temp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = temp;
			i = 0;
		}
	}
}
int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;
	c = a + b;
	a.show();
	b.show();
	c.show();	
}

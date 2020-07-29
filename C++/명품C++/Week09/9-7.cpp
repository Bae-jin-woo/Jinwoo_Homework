#include <iostream>
#include <string>
using namespace std;

class Matrix {
	int a, b, c, d;
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		this->a = a; this->b = b; this->c = c; this->d = d;
	}
	void show() { cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl; }
	friend int operator >>(Matrix m, int array[4]);
	friend Matrix& operator <<(Matrix& m, int array[4]);
};
int operator >>(Matrix m, int array[4]) {
	array[0] = m.a;
	array[1] = m.b;
	array[2] = m.c;
	array[3] = m.d;
	return array[4];
}
Matrix& operator <<(Matrix& m, int array[4]) {
	m.a = array[0];
	m.b = array[1];
	m.c = array[2];
	m.d = array[3];
	return m;
}
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;	//a의 원소를 x에 복사
	b << y;	//y의 원소를 b에 설정
	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}

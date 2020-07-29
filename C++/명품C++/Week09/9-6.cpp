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
	friend Matrix operator+(Matrix m, Matrix n);
	friend Matrix& operator+=(Matrix m, Matrix n);
};
Matrix operator+(Matrix m, Matrix n) {
	Matrix temp;
	temp.a = n.a + m.a;
	temp.b = n.b + m.b;
	temp.c = n.c + m.c;
	temp.d = n.d + m.d;
	return temp;
}
Matrix& operator+=(Matrix m, Matrix n) {
	Matrix temp;
	temp.a = n.a + m.a;
	temp.b = n.b + m.b;
	temp.c = n.c + m.c;
	temp.d = n.d + m.d;
	return temp;
}
int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
}

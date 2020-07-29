#include <iostream>
using namespace std;
template<class T>	//일반화한 concat함수
T* concat(T a[], int sizea, T b[], int sizeb) {
	T *c = new int[sizea + sizeb];
	for (int i = 0; i < sizea; i++)
		c[i] = a[i];
	for (int i = sizea; i < sizea + sizeb; i++)
		c[i] = b[i - sizea];
	return c;
}

int main() {	//예시
	int x[] = { 1,2,3,4,5 };
	int y[] = { 6,7,8,9,10 };
	int *z = concat(x, 5, y, 5);
	for (int i = 0; i < 10; i++)
		cout << z[i] << " ";
}

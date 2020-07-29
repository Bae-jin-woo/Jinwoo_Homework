#include <iostream>
using namespace std;

template<class T> T biggest(T x[], int n) {
	T result = x[0];
	for (int i = 0; i < n; i++)
		if (result < x[i])
			result = x[i];
	return result;
}
int main() {
	int x[] = { 1,10,100,5,4 };
	cout << biggest(x, 5) << endl;
}

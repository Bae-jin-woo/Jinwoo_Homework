#include <iostream>
using namespace std;

template<class T>
T *remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	bool find;	//같은 인덱스를 발견하면 false
	T *result = new int[sizeSrc];
	for (int i = 0; i < sizeSrc; i++) {
		find = true;
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) {
				find = false; break;
			}
		}
		if (find == true) result[retSize++] = src[i];
	}
	return result;
}

int main(){
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[] = { 1,2,3 };
	int size = 0;
	int *c = remove(a, 10, b, 3, size);
	for (int i = 0; i < size; i++)
		cout << c[i] << " ";
	cout << endl;
}

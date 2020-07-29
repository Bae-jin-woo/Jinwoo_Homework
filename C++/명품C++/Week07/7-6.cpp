#include <iostream>
using namespace std;

class ArrayUtility2{
public:
	static int* concat(int s1[], int s2[], int size);	//s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	static int* remove(int s1[], int s2[], int size, int& retSize); //s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴.
		//리턴하는 배열의 크기는 retSize에 전달. retSize가 0인 경우 NULL 리턴
};
int* ArrayUtility2::concat(int s1[], int s2[], int size) {	//s1과 s2를 새로운 배열을 동적 생성하고 포인터 리턴
	int *s3 = new int[size];
	for (int i = 0; i < size; i++) {
		if (i < 5) s3[i] = s1[i];
		else  s3[i] = s2[i-5];
	}
	return s3;
}
int* ArrayUtility2::remove(int s1[], int s2[], int size,int& retSize) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j])	//s1과 s2배열에 같은 원소가 있다면
				s1[i] = NULL;	//s1원소를 비운다
		}
	}
	for (int i = 0; i < size; i++) {	//비어있지 않은 s1배열만큼 크기 설정
		if (s1[i] != NULL)
			retSize++;
	}
	int n = 0;
	int *s4 = new int[retSize];	//설정한 크기만큼 배열 동적할당
	for (int i = 0; i < size; i++) {
		if (s1[i] != NULL)
			s4[n++] = s1[i];
	}
	return s4;
}

int main() {
	int x[5];
	int y[5];
	int size;
	int retSize = 0;
	cout << "정수 5개를 입력하라. 배열 x에 삽입한다>>";
	cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
	cout << "정수 5개를 입력하라. 배열 y에 삽입한다>>";
	cin >> y[0] >> y[1] >> y[2] >> y[3] >> y[4];
	size = sizeof(x) / 4 + sizeof(y) / 4;
	int *s3 = ArrayUtility2::concat(x, y, size);
	cout << "합친 정수 배열을 출력한다 "<<endl;
	for (int i = 0; i < size; i++)
		cout << s3[i] << " ";
	size = sizeof(x) / 4;
	int *s4 = ArrayUtility2::remove(x, y, size, retSize);
	cout << endl;
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는" << retSize << endl;
	for (int i = 0; i < retSize; i++)
		cout << s4[i] << " ";
	cout << endl;
	delete[] s3, s4;
}

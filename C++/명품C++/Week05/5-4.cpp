#include <iostream>
using namespace std;

class Sample {
	int *p;
	int size;
public:
	Sample(int n){	//생성자
		size = n; p = new int[n];	//n개 정수 배열의 동적생성
	}
	void read();	//동적 할당받은 정수 배열 p에 사용자로부터 정수를 입력받음
	void write();	//정수 배열을 화면에 출력
	int big();	//정수 배열에서 가장 큰 수 리턴
	~Sample();	//소멸자
};
void Sample::read() {	//배열 원소 입력
	for (int i = 0; i < size; i++) { cin >> p[i]; }
}
void Sample::write() {	//배열 원소 출력
	for (int i = 0; i < size; i++) { cout << p[i] << " "; }
}
int Sample::big() {	//가장 큰 배열 원소를 반환
	int Max = p[0];
	for (int i = 0; i < size; i++) {
		if (p[i] > Max)
			Max = p[i];
	}
	return Max;
}
Sample::~Sample() {}
int main() {
	Sample s(10);	//10개 정수 배열의 동적생성
	s.read();
	s.write();
	cout << endl;
	cout << "가장 큰 수는 " << s.big() << endl;	//가장 큰 수 출력
}

#include <iostream>
using namespace std;
bool bigger(int a, int b, int &big) {
	if (a == b) {	//a,b가 같으면 true 반환
		big = a; return true;
	}
	else if (a > b) {	//a,b가 다르면 false 반환 big에 큰 수 저장
		big = a; return false;
	}
	else big = b; return false;
}
int main() {
	int a, b, big;
	cout << "두 개의 정수 입력 : ";
	cin >> a >> b;
	bigger(a, b, big);
	cout << "두 정수중 큰 값 : " << big << endl;
}

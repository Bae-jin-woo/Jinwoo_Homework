#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success) {	//문자열 a에서 c를 찾아, 문자 c가 있는 공간에 대한 참조를 리턴
	int size = sizeof(a);	//문자열의 크기
	for (int i = 0; i < size; i++) {
		if (a[i] == c) {	//문자 c를 찾았다면
			success = true;
			return a[i];
		}
		else success = false;
	}
}
int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);	//참조에 의한 호출
	if (b == false) {
		cout << "M을 발견할 수 없다" << endl;
		return 0;
	}
	loc = 'm';	// 'M' 위치에 'm' 기록
	cout << s << endl;	//"mike"가 출력됨
}

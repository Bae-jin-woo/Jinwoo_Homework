#include <iostream>
#include <string>
using namespace std;

class Trace {
public:
	static string tag[100];
	static string debug[100];
	static int count;
	static void put(string tag,string debug);
	static void print(string tag =" ");
};

string Trace::tag[100];	//static 멤버 변수 초기화
string Trace::debug[100];
int Trace::count = 0;

void Trace::put(string t, string d) {
	tag[count] = t;
	debug[count] = d;
	++count;
}
void Trace::print(string t) {
	if (t == " ") {	//태그가 디폴트인 경우
		cout << "----- 모든 태그의 Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < count; i++)
			cout << tag[i] << ":" << debug[i] << endl;
	}
	else {		
		cout << "----- " << t << "태그의 Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < count; i++) {
			if (tag[i] == "f()")
				cout << tag[i] << ":" << debug[i] << endl;
		}
	}
}
void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력받았음");	//디버깅 정보 저장
	c = a + b;
	Trace::put("f()", "합 계산");	//디버깅 정보 저장
	cout << "합은 " << c << endl;
}


int main() {
	Trace::put("main()", "프로그램 시작합니다");	//디버깅 정보저장
	f();
	Trace::put("main()", "종료");	//put()의 첫 번째 매개 변수는 태그이고
									//두 번쨰 매개변수는 디버깅 정보이다.
	Trace::print("f()");	//"f()" 태그를 가진 디버깅 정보를 모두 출력한다
	Trace::print();
}

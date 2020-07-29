#include <iostream>
#include <string>
using namespace std;
void combine(string &text, string &text2, string &text3) {	//참조에 의한 호출
	text3 = text + " " + text2;	//문자열 더하기
}
int main() {
	string text("I love you"), text2("very much");
	string text3;	//비어있는 문자열
	combine(text, text2, text3);	//text1과 " ", 그리고 text2를 덧붙여 text3 만들기
	cout << text3 << endl;	//I love you very much출력
}

#include <iostream>
#include <string>
using namespace std;
class Buffer {
	string text;
public:
	Buffer(string next) { this->text = next; }
	void add(string next) { text += next; }	//text에 next문자열 덧붙이기
	void print() { cout << text << endl; }
};
Buffer& append(Buffer& buf,string str) {	//Buffer 객체에 문자열 str을 추가하는 함수
	buf.add(str);	//add함수를 호출하여 문자열추가
	return buf;
}
int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");	//buf 문자열에 "Guys" 덧붙임
	temp.print();	//"HelloGuys" 출력
	buf.print();	//"HelloGuys" 출력
}

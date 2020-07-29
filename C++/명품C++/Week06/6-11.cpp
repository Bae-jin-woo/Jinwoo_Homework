#include <iostream>
#include <string>
using namespace std;
class Book {
	string title;	//제목 문자열
	int price;	//가격
public:
	Book(string title, int price);
	~Book() {}
	Book(Book& b);
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};
Book::Book(string title, int price) {	//생성자
	this->title = title;
	this->price = price;
}
Book::Book(Book& b) {	//복사생성자
	this->title = title;
	this->price = b.price;
}
void Book::set(string title,int price){	//set
	this->title = title;
	this->price = price;
}
int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;	//복사 생성자 호출
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}

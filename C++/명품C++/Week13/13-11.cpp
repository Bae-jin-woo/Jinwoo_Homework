#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
	int year;
	string name;
	string author;
public:
	Book(int y, string n, string a) { this->year = y; this->name = n; this->author = a; }
	int getYear() { return year; }
	string getName() { return name; }
	string getAuthor() { return author; }
};

int main() {
	int year;
	string name;
	string author;
	vector<Book> v;
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 종료합니다." << endl;
	while (1) {
		cout << "년도 >>";
		cin >> year; cin.ignore();
			if (year == -1)	break;
			cout << "책이름 >>";
		getline(cin, name);
		cout << "저자 >>";
		getline(cin, author);
		Book b(year, name, author);
		v.push_back(b);
	}
	cout << "총 입고된 책은 " << v.size() << "권입니다." << endl;
	cout << "검색하고자 하는 저자 이름을 입력하세요 >>";
	cin >> author;
	for (int i = 0; i < v.size(); i++) {
		if (author == v[i].getAuthor()){
			cout << v[i].getYear() << "년도, " << v[i].getName() << ", " << v[i].getAuthor() << endl;
			break;
		}
	}
	cout << "검색하고자 하는 년도을 입력하세요 >>";
	cin >> year;
	for (int i = 0; i < v.size(); i++) {
		if (year == v[i].getYear()) {
			cout << v[i].getYear() << "년도, " << v[i].getName() << ", " << v[i].getAuthor() << endl;
			break;
		}
	}
}

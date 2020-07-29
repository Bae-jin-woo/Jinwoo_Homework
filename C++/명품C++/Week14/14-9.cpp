#include <iostream>
#include <string>
using namespace std;

class Phone {
	string name;
	string telnum;
	string address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	string getName() { return name; }
	string getTelnum() { return telnum; }
	string getAddress() { return address; }
	void setName(string n) { this->name = n; }
	void setTelnum(string t) { this->telnum = t; }
	void setAddress(string a) { this->address = a; }
	friend istream& operator >>(istream& ins, Phone& p);
	friend ostream& operator <<(ostream& stream, Phone& p);

};

istream& operator>>(istream& ins, Phone& p) {
	string n, t, a;
	cout << "이름:";
	getline(cin, n);
	p.setName(n);
	cout << "전화번호:";
	getline(cin, t);
	p.setTelnum(t);
	cout << "주소:";
	getline(cin, a);
	p.setAddress(a);
	return ins;
}

ostream& operator<<(ostream& stream, Phone& p) {
	cout << "(" << p.getName() << "," << p.getTelnum() << "," << p.getAddress() << ")" << endl;
	return stream;
}

int main() {
	Phone girl, boy;
	cin >> girl >> boy;	//전화 번호를 키보드로부터 읽는다.
	cout << girl << boy << endl;	//전화번호를 출력한다.
}

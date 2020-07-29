//Account.h 함수 선언부
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;
class Account {	//클래스 선언
	int num;
	int money;
	string name;
public:
	Account(string s, int n, int m);
	string getOwner();
	int inquiry();
	void deposit(int n);
	int withdraw(int n);
};
#endif

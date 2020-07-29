#include <iostream>
#include <string>
using namespace std;
#include "Account.h"
Account::Account(string s, int n, int m) {
	name = s;
	num = n;
	money = m;
}
string Account::getOwner() {
	return name;
}
int Account::inquiry() {
	return money;
}
void Account::deposit(int n) {
	money += n;
}
int Account::withdraw(int n) {
	money -= n;
	return money;
}

//Date.cpp 함수 구현부
#include <iostream>
#include <string>
using namespace std;
#include "Date.h"

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
Date::Date(const char *s) {	// '/'를 기준으로 숫자를 각각 변수에 저장
	year = atoi(strtok(strdup(s), "/"));
	month = atoi(strtok(NULL, "/"));
	day = atoi(strtok(NULL, "/"));
}
int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}
void Date::show() {
	cout << year << "년" << month << "월" << day << "일" << endl;
}

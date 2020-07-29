//main.cpp
#include <iostream>
using namespace std;
#include "Date.h"

int main() {
	Date birth(2014, 3, 20);	//2014년 3월 20일
	Date independencyDay("1945/8/15");	//1945년 8월 15일
	independencyDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}

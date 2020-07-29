#include <iostream>
using namespace std;
#include "Ram.h"
int main() {
	Ram ram;
	ram.write(100, 20);	//100번지에 20저장
	ram.write(101, 30);	//101번지에 30저장
	char res = ram.read(100) + ram.read(101);	//20+30=50
	ram.write(102, res);//102번지에 50저장
	cout << "102번지의 값 = " << (int)ram.read(102) << endl;//102번지값 출력
}

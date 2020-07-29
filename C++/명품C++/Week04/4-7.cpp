#include <stdio.h>
struct cracker {	//구조체
	int price;
	int kal;
};
int main() {
	struct cracker snack;
	printf("크래커의 가격과 열량을 입력하세요>");
	scanf("%d %d", &snack.price, &snack.kal);
	printf("크래커의 가격 : %d\n", snack.price);
	printf("크래커의 열량 : %d\n", snack.kal);
	return 0;
}	#include <iostream>
using namespace std;
struct cracker {	//구조체
	int price;
	int kal;
};
int main() {
	struct cracker snack;
	cout << "크래커의 가격과 열량을 입력하세요>";
	cin >> snack.price >> snack.kal;
	cout << "크래커의 가격 : " << snack.price << endl;
	cout << "크래커의 열량 : " << snack.kal << endl;
}

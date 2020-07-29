	#include <iostream>
#include <string>
using namespace std;
class Color {
	int red, green, blue;
public:
	Color(int red = 0, int green = 0, int blue = 0) {
		this->red = red, this->green = green, this->blue = blue;
	}
	void show() { cout << red << " " << green << " " << blue << endl; }
	friend Color operator+(Color op1, Color op2);
	friend bool operator ==(Color op1, Color op2);
};
Color operator+(Color op1, Color op2) {
	Color temp;
	temp.red = op1.red + op2.red;
	temp.green = op1.green + op2.green;
	temp.blue = op1.blue + op2.blue;
	return temp;
}
bool operator ==(Color op1, Color op2) {
	if (op1.red == op2.red && op1.green == op2.green && op1.blue == op2.blue)
		return true;
	else return false;
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음" << endl;
	else cout << "보라색 아님" << endl;
}

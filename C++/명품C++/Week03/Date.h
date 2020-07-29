//Date.h 선언부
class Date {
	int year, month, day;
	string str;
public:
	Date(int y, int m, int d);
	Date(const char *s);
	int getYear();
	int getMonth();
	int getDay();
	void show();
};

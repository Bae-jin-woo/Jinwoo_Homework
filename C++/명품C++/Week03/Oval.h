//클래스 선언부
#ifndef OVAL_H
#define OVAL_H
class Oval {
	int width, height;
public:
	Oval();
	Oval(int w, int h);
	~Oval();
	int getWidth();
	int getHeight();
	void Set(int w, int h);
	void show();
};
#endif

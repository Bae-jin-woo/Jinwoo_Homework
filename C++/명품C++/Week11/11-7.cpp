#include <iostream>
#include <string>
using namespace std;

class BaseMemory {
	char *mem;
	int size, index;
protected:
	BaseMemory(int size) { this->size = size; mem = new char[size]; index = 0; }
public:
	char read(int i) { return mem[i]; }
	void burn(char *mem, int size) {
		if (this->size < index) return;
		for (int i = index; i < index + size; i++) this->mem[i] = mem[i - index];
		index += size;
	}
	void write(int i, char c) { mem[i] = c; }
};

class ROM :public BaseMemory {
public:
	ROM(int cap, char *mem, int size) :BaseMemory(cap) { burn(mem, size); }
};

class RAM :public BaseMemory {
public:
	RAM(int cap) :BaseMemory(cap) {};
};


int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);	//10KB의 ROM 메모리. 배열 x로 초기화됨
	RAM mainMemory(1024 * 1024);	//1MB의 RAM 메모리

	//0번지에서 4번지까지 biosROM에서 읽어 mainMemory에 복사
	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}


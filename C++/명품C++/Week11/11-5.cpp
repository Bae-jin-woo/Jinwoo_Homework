#include <iostream>
#include <string>
using namespace std;

class BaseArray {
private:
	int capacity;	//배열의 크기
	int *mem;	//정수 배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[]mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
	int front = -1;
	int rear = -1;
public:
	MyQueue(int n) : BaseArray(n) {	}
	void enqueue(int n) {	//큐 삽입
		put(++rear, n);
	}
	int dequeue() {	//큐 삭제
		if (rear == front) {
			return 0;
		}
		else return get(++front);
	}
	int length() {	//큐 길이
		return (rear - front);
	}
	int capacity() {	//큐 용량
		return getCapacity();
	}
};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);	//삽입
	}
	cout << "큐의 용량" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>>";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';	//큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}

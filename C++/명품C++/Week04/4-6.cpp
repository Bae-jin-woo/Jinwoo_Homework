#include <iostream>
#include <string>
using namespace std;
int main() {
	int row, col;
	cout << "행의 개수를 입력하세요>";
	cin >> row;
	cout << "열의 개수를 입력하세요>";
	cin >> col;
	int **matrix1 = new int *[row];	//2차원 배열 세로 동적할당
	int **matrix2 = new int *[row];
	int **matrix3 = new int *[row];
	for (int i = 0; i < row; i++) {	//2차원 배열 가로 동적할당
		matrix1[i] = new int[col];
		matrix2[i] = new int[col];
		matrix3[i] = new int[col];
	}
	cout << "행렬1을 입력하세요 : ";
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> matrix1[i][j];	//행렬1값 입력
	cout << "행렬2을 입력하세요 : ";
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++)
			cin >> matrix2[i][j];	//행렬2값 입력
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
			cout << matrix3[i][j] << " ";
		}
		cout << endl;
	}
 for (int i = 0; i < col; i++) {	//메모리 해제
	 delete[] matrix1[i];
	 delete[] matrix2[i];
	 delete[] matrix3[i];
 } 
 delete[] matrix1;
 delete[] matrix2;
 delete[] matrix3;
}

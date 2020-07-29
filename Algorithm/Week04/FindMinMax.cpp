//2015112128 배진우
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

long long Make_Random_Number();
long long Minimum(vector<long long>& v, int n);
long long Maximum(vector<long long>& v, int n);
void Find_Min_Max(vector<long long>& v, int n, long long& minimum, long long& maximum);

int main() {
	srand(time(NULL));
	int i;
	vector<long long> v;
	for (i = 0; i < 1000; i++)
		v.push_back(Make_Random_Number());
	cout << "Minimum 함수를 이용한 최소값 : " << Minimum(v, v.size()) << endl;	//결과 출력
	cout << "Maximum 함수를 이용한 최대값 : " << Maximum(v, v.size()) << endl;
	long long max_num = 0;
	long long min_num = 0;
	Find_Min_Max(v, v.size(), min_num, max_num);
	printf("FindMinMax 함수를 이용한 최소값과 최대값: %lld, %lld\n", min_num, max_num);
}

long long Make_Random_Number() {	//1~100000사이 난수 생성 함수
		double ran = rand() / (double)INT_MAX;	//0~1사이의 실수 난수 생성 후 1~100000으로 범위 변경
		ran *= pow(10, 10);
		long long random = (long long)ran;
		random = random % 100000 + 1;
		return random;
}

long long Minimum(vector<long long>& v, int n) {	//최소값 출력 함수
	int i;
	long long temp;
	temp = v[0];
	for (i = 1; i < n; i++) {	//배열 안에서 최소값을 찾을 떄마다 temp에 저장
		if (temp > v[i])
			temp = v[i];
	}
	return temp;
}

long long Maximum(vector<long long>& v, int n) {	//최대값 출력 함수
	int i;
	long long temp;
	temp = v[0];
	for (i = 1; i < n; i++) {	//배열 안에서 최대값을 찾을 떄마다 temp에 저장
		if (temp < v[i])
			temp = v[i];
	}
	return temp;
}

void Find_Min_Max(vector<long long>& v, int n, long long& minimum, long long& maximum) {
	int i;	//최소값과 최대값을 동시에 찾는 함수
	long long small = 0;
	long long large = 0; 
	minimum = v[0];
	maximum = v[0];
	for (i = 1; i < n - 1; i += 2) {	//배열 인덱스를 2개씩 비교하면서 작은 값과 큰 값을 각각
		if (v[i] < v[i + 1]) {			//small, large에 저장
			small = v[i];
			large = v[i + 1];
		}
		else {
			small = v[i + 1];
			large = v[i];
		}
		if (small < minimum) minimum = small;	//루프를 돌 때마다 small, large값을 maximum, minimum와
		if (large > maximum) maximum = large;	//비교하여 최소값과 최대값을 찾는다
	}
}
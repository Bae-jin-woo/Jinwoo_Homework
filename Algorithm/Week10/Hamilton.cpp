//2015112128 배진우
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void makeGraph(vector<string> s, int n);
void Hamiltonian(vector<string> s, int* graph[], int here, string& result, vector<int>& visited, int size);

int main() {
	vector<string> spectrum1 = { "AGT", "AAA", "ACT", "AAC", "CTT" ,"GTA", "TTT", "TAA" };
	vector<string> spectrum2 = { "ATG", "AGG", "TGC", "TCC", "GTC", "GGT", "GCA", "CAG" };
	vector<string> spectrum3 = { "ATG", "TGG", "TGC", "GTG", "GGC", "GCA", "GCG", "CGT" };
	vector<string> spectrum4 = { "ATGC", "TGCG", "GCGG", "CGGC", "GGCT", "GCTG", "CTGT", "TGTA", "GTAT", "TATG", "ATGG", "TGGT", "GGTG" };
	vector<string> myspectrum = { "ATC", "TCG", "CGA", "AGT", "GAG", "GTT" };
	//makeGraph(spectrum1, 3);
	//cout << endl;
	//makeGraph(spectrum2, 3);
	//cout << endl;
	//makeGraph(spectrum3, 3);
	//cout << endl;
	//makeGraph(spectrum4, 4);
	makeGraph(myspectrum, 3);
}

void makeGraph(vector<string> s, int n) {
	//그래프를 만드는 함수 (입력: 스펙트럼, 각 인덱스의 길이)
	int size = s.size();
	int seqLength = s[0].size();
	int** graph;	//이차원 배열 동적할당
	graph = new int* [size];
	for (int i = 0; i < size; i++)
		graph[i] = new int[size];
	for (int i = 0; i < size; i++) {	//2차원 배열로 그래프를 구현
		for (int j = 0; j < size; j++) {
			if (s[i].substr(1, n - 1) == s[j].substr(0, n - 1)) {	//문자열 시퀀스가 이어지면 1
				graph[i][j] = 1;	// 012 
			}
			else if (i == j) {	//자기 자신은 0
				graph[i][j] = 0;
			}
			else graph[i][j] = 0;	//나머지 0
		}
	}
	string result = s[0].substr(0, seqLength - 1);
	vector<int> visited(size);
	cout << "방문 순서: ";
	Hamiltonian(s, graph, 0, result, visited, size);
	cout << endl << "result >> ";
	cout << result << endl;

	for (int i = 0; i < size; i++) 
		delete[] graph[i];
	delete[] graph;
}

void Hamiltonian(vector<string> s, int* graph[], int here, string& result, vector<int>& visited, int size) {
	int seqLength = s[0].size();
	int *possible = 0;
	int finish = s[0].size() + s.size() - 1;	//생성될 복구 문자열의 길이 변수. 문자열이 완성되었는지 여부 파악
	//지금 here이 이미 방문된 정점이라면 다시 회귀
	if (visited[here] == 1) return;
	printf("%d ", here);
	cout << s[here] << " ";
	result += s[here].substr(seqLength - 1, seqLength);
	//cout << result << endl;
	visited[here] = 1;  //지금 here 정점은 방문처리
	for (int next = 0; next < size; next++) {
		//그래프가 이어져있으면서, 아직 다음 정점이 방문되지 않았으면 방문
		//cout << "here = " << here << ", next = " << next << endl;
		if (graph[here][next] == 1 && (visited[next] != 1)) {
			Hamiltonian(s, graph, next, result, visited, size);		
		}
		if (next == size - 1 && result.length() < finish) {	//문자열이 복구되지 않았고 일치하는 문자열이 없을때
			cout << endl << "길 없음!" << here << endl;
			visited[here] = 0;	//방문했던 노드를 미방문 처리하고 재탐색을 진행할 수 있게 변수 정리
			result = result.substr(0, result.length() - 1);	
			next = here;
			here = here - 1;
		}
	}
}

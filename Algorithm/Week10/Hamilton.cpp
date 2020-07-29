//2015112128 ������
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
	//�׷����� ����� �Լ� (�Է�: ����Ʈ��, �� �ε����� ����)
	int size = s.size();
	int seqLength = s[0].size();
	int** graph;	//������ �迭 �����Ҵ�
	graph = new int* [size];
	for (int i = 0; i < size; i++)
		graph[i] = new int[size];
	for (int i = 0; i < size; i++) {	//2���� �迭�� �׷����� ����
		for (int j = 0; j < size; j++) {
			if (s[i].substr(1, n - 1) == s[j].substr(0, n - 1)) {	//���ڿ� �������� �̾����� 1
				graph[i][j] = 1;	// 012 
			}
			else if (i == j) {	//�ڱ� �ڽ��� 0
				graph[i][j] = 0;
			}
			else graph[i][j] = 0;	//������ 0
		}
	}
	string result = s[0].substr(0, seqLength - 1);
	vector<int> visited(size);
	cout << "�湮 ����: ";
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
	int finish = s[0].size() + s.size() - 1;	//������ ���� ���ڿ��� ���� ����. ���ڿ��� �ϼ��Ǿ����� ���� �ľ�
	//���� here�� �̹� �湮�� �����̶�� �ٽ� ȸ��
	if (visited[here] == 1) return;
	printf("%d ", here);
	cout << s[here] << " ";
	result += s[here].substr(seqLength - 1, seqLength);
	//cout << result << endl;
	visited[here] = 1;  //���� here ������ �湮ó��
	for (int next = 0; next < size; next++) {
		//�׷����� �̾��������鼭, ���� ���� ������ �湮���� �ʾ����� �湮
		//cout << "here = " << here << ", next = " << next << endl;
		if (graph[here][next] == 1 && (visited[next] != 1)) {
			Hamiltonian(s, graph, next, result, visited, size);		
		}
		if (next == size - 1 && result.length() < finish) {	//���ڿ��� �������� �ʾҰ� ��ġ�ϴ� ���ڿ��� ������
			cout << endl << "�� ����!" << here << endl;
			visited[here] = 0;	//�湮�ߴ� ��带 �̹湮 ó���ϰ� ��Ž���� ������ �� �ְ� ���� ����
			result = result.substr(0, result.length() - 1);	
			next = here;
			here = here - 1;
		}
	}
}

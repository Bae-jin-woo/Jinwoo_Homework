#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <fstream>
#include <random>
#include <set>

#define MAXNUM 10000000
#define TABLE_SIZE 1000001
using namespace std;
char DNA[4] = { 'T', 'A', 'G', 'C' }; // 해시 값이 이 순서대로 생김
int x = 5;  //x%
int y = 3;

int GetRand(int min, int max) {
    random_device rn;
    mt19937_64 rnd(rn());
    uniform_int_distribution<int> range(min, max);

    return range(rnd);
}
void MakeSequence(string& rseq) {
    string fName = "rseq.txt";
    ofstream wFile(fName.data());

    // 랜덤 시퀀스 생성
    for (int i = 0; i < MAXNUM; i++) {
        int random = GetRand(0, 3);
        rseq += DNA[random];
    }
    // 파일에 쓰기
    if (wFile.is_open()) {
        wFile << rseq;
        wFile.close();
    }
}

string MakeMySequence(string rseq, int k) {
    set<int> dup_check_set;
    string fName = "mseq.txt";
    ofstream wFile(fName.data());
    string myseq = rseq;
    // 달라야 하는 base 갯수
    int should_diff = MAXNUM * x / 100;
    int rsize = rseq.size();

    for (int i = 0; i < should_diff; i++) {
        // 랜덤으로 바꿀 부분의 위치를 뽑는다.
        int pos = GetRand(0, rsize - 1);
        // set을 이용해서 이번에 뽑힌 위치를 바꾼 적 있는지 확인한다
        // 만약에 없다면 set에 추가하고, 그렇지 않다면 
        // 뽑은 적 없는 위치가 나올 때 까지 반복한다.
        while (dup_check_set.find(pos) != dup_check_set.end()) {
            pos = GetRand(0, rsize - 1);
        }

        dup_check_set.insert(pos);
        // 해당하는 위치의 base를 새로운 base로 바꾼다.
        char theChar = myseq[pos];
        int newChar = GetRand(0, 3);
        while (DNA[newChar] == theChar) // 기존과 다른 문자 나올 때까지 반복
            newChar = GetRand(0, 3);
        myseq[pos] = DNA[newChar];
    }
    // 파일에 쓰기
    if (wFile.is_open()) {
        wFile << myseq;
        wFile.close();
    }
    return myseq;
}

void MakeShortRead(string seq, int k, int n) {

    int random;
    int maxIndex = seq.length() - k; // 첫 인덱스가 될 수 있는 최대 수
    string shortseq = "";
    string fName = "shortread_1000.txt";
    ofstream wFile(fName.data());

    if (wFile.is_open()) {
        for (int i = 0; i < n; i++) {
            //random = GetRand(0, maxIndex); // 랜덤한 인덱스
            random = rand() % (maxIndex + 1);
            shortseq = "";
            for (int j = random; j < random + k; j++) // 해당 인덱스부터 k개의 문자열을 잘라서 파일에 저장
                shortseq += seq[j];
            wFile << shortseq << endl;
        }
        wFile.close();
    }
}
void Trivial(string& seq, string read) {
    int count = y; // 다른 문자 허용 개수
    int seqSize = seq.size();
    int readSize = read.size();
    for (int i = 0; i <= seqSize - readSize; i++) {
        int j = 0;
        count = y;
        for (; j < readSize; j++) {
            if (seq[i + j] != read[j]) { // seq의 특정 위치 문자가 read의 특정 위치 문자와 같지 않다면
                count--; // 다르면 count 감소
                if (count < 0) // 허용된 개수를 초과하면 반복 탈출
                    break;
            }
        }
        if (count >= 0) { // 틀린 개수가 0 이하이면 위치를 찾은 것.
            for (int k = i; k < i + readSize; k++)
                seq[k] = read[k - i]; // read로 덭붙이기
            break;
        }
    }
}

struct node {   //position이 들어갈 벡터
    vector<int> nodes;
};

node table[TABLE_SIZE]; //해시 테이블


int calculateHash(string str, int len) {    //해시 key값을 계산하는 함수
    long long hashValue = 0;
    int cnt = len - 1;
    for (int j = 0; j < len; j++)
        hashValue += (((str[j] - '0' - 15) % 5 - 1) * pow(4, cnt--));
    hashValue %= TABLE_SIZE;
    return hashValue;
}

void MakeTable(string seq, int rsize) { // seqHash의 선처리 //seq, 30
    int slicesize = rsize / (y + 1);
    int ssize = seq.size(); //20000

    for (int i = 0; i < ssize - slicesize; i++) {   //shortread
        int slice = 0;
        int cnt = slicesize - 1;
        string subString = seq.substr(i, slicesize);
        slice = calculateHash(subString, slicesize);    //해시 key값을 계산
        table[slice].nodes.push_back(i);
    }
    //for (int i = 0; i < TABLE_SIZE; i++) {  //print table
    //    cout << i << "==>>(" << table[i].nodes.size() << ")";
    //    for (int j = 0; j < table[i].nodes.size(); j++) {
    //        cout << table[i].nodes[j] << " ";
    //    }
    //    cout << endl;
    //}
}

void Indexing(string& seq, string read) { // read = shortread 한줄

    int* hashStorage = new int[y + 1];
    bool* match = new bool[y + 1];
    int matchCount = 0;
    string remakeString = seq;
    string shortRead = read;

    int hashNumber = 0;
    int subLength = shortRead.length() / (y + 1);   //10

    for (int i = 0; i < y + 1; i++) {   //shortRead를 missmatch+1등분 한 substring의 해시 key값을 구한다.
                                        // key에 해당되는 정보가 있는지 여부와 DNA인덱스들을 테이블에서 추출하여 각각 저장한다.       
        string sequence = shortRead.substr(i * subLength, subLength);
        hashNumber = calculateHash(sequence, subLength);
        hashStorage[i] = hashNumber;
        if (table[hashNumber].nodes.size() > 0) {
            match[i] = true;
            matchCount++;
        }
        else {
            match[i] = false;
        }
        hashNumber = 0;
    }

    int minMismatch = shortRead.length();
    int subIndex = 0;

    for (int k = 0; k < y + 1; k++) {   //테이블에 저장된 인덱스를 각각 탐색
        string str;
        if (match[k]) { //k번째 해시 함수에 노드가 들어있을 때 값
            int mismatchCount = 0;
            int size = table[hashStorage[k]].nodes.size();
            for (int j = 0; j < size; j++) {
                int startIndex = table[hashStorage[k]].nodes[j];
                if (table[hashStorage[k]].nodes[j] - ((subLength * k)) < 0) continue;
                else {
                    str = seq.substr(table[hashStorage[k]].nodes[j] - ((subLength * k)), shortRead.length());
                }
                if (str.length() != shortRead.length()) continue;

                for (int i = 0; i < shortRead.length(); i++) {  //mismatch 카운트
                    if (str[i] != shortRead[i]) mismatchCount++;
                }

                if (minMismatch > mismatchCount) {  //미스매치가 적은 경우가 있을경우 시작 인덱스를 저장
                    subIndex = table[hashStorage[k]].nodes[j] - ((subLength * k));
                    minMismatch = mismatchCount;
                }
                mismatchCount = 0;
            }
        }
    }
    if (matchCount != 0)    //노드가 있는 해시함수가 하나도 없는 경우는 바꾸지 않음
        seq.replace(subIndex, shortRead.length(), shortRead, 0, shortRead.length());   //가장 miss match가 낮은 인덱스를 찾아 쇼트리드 대입

    delete[] hashStorage;
    delete[] match;
}

int main() {
    srand((unsigned int)time(0));
    string rseq = "";
    string mseq = "";
    int k = 0, n = 0;   //k = length of shortread, n = number of shortread
    string referenceFileName = "test_ref_1000.txt";
    string MydnaFileName = "Mydna_1000.txt";
    string remakeFileName = "repair_dna_1000.txt";
    ifstream rFile(referenceFileName.data());   //reference data
    ifstream rFile2(MydnaFileName.data());
    ofstream wFile;
    wFile.open(remakeFileName);

    getline(rFile, rseq);
    getline(rFile2, mseq);

    cout << "Input length of shortRead :";
    cin >> k;
    cout << "Input number of shortRead :";
    cin >> n;
    cout << endl;

    cout << "Making ShortRead File..." << endl;
    MakeShortRead(mseq, k, n);
    cout << "Done" << endl << endl;

    string reference = "";
    string SeqFname = "shortread_1000.txt";
    ifstream seqFile(SeqFname.data());
    if (seqFile.is_open()) {
        getline(seqFile, reference);
    }
    seqFile.close();
    string remakeseq = rseq;

    // Trivial 복원 과정
    cout << "Calculate Difference between Rsequence and Msequence..." << endl;
    string fseq = reference; // rseq로부터 복원해야 하는 fseq
    string shortreadFname = "shortread.txt";
    ifstream oFile(shortreadFname.data());

    int coun = 0;
    for (int i = 0; i < rseq.length(); i++) {
        if (rseq[i] != mseq[i]) coun++;
    }
    cout << "정답: " << coun << endl;
    clock_t start = clock(); // 시간 측정 시작

    if (oFile.is_open()) {
        string tmp;
        while (getline(oFile, tmp)) {
            Trivial(fseq, tmp);
        }
        oFile.close();
    }

    clock_t end = clock(); // 시간 측정 종료
    cout << "Done" << endl << endl;
    //Trivial 결과 출력
    cout << "<Trivial 알고리즘 결과>" << endl;
    int count = 0;
    for (int i = 0; i < fseq.size(); i++)
        if (mseq[i] != fseq[i])
            count++;
    cout << "Difference Count : ";
    cout << count << endl;
    cout << "Accuracy : ";
    cout.precision(4);
    cout << ((double)(rseq.length() - count) / rseq.length()) * 100 << "%" << endl;
    cout << "Executing Time : ";
    cout << (double)(end - start) / CLOCKS_PER_SEC << "second";
    cout << endl;

    ifstream o2File(shortreadFname.data());
    clock_t startr = clock(); // 시간 측정 시작

    MakeTable(remakeseq, k); // 선처리용 

    if (o2File.is_open()) { //전체 호출
        string tmp;
        while (getline(o2File, tmp)) {
            Indexing(remakeseq, tmp);
        }
        o2File.close();
    }
    clock_t endr = clock(); // 시간 측정 종료

    wFile << remakeseq; //파일 쓰기

    cout << endl << "Done" << endl;

    cout << endl << "<My 알고리즘 결과>" << endl;
    int countr = 0;


    for (int i = 0; i < rseq.size(); i++)
        if (mseq[i] != remakeseq[i])
            countr++;
    cout << "Difference Count : ";
    cout << countr << endl;
    cout << "Accuracy : ";
    cout.precision(4);
    cout << ((double)(rseq.length() - countr) / rseq.length()) * 100 << "%" << endl;
    cout << "Executing Time : ";
    cout << (double)(endr - startr) / CLOCKS_PER_SEC << "second";


    rFile.close();  //reference DNA
    rFile2.close(); //my DNA
    wFile.close();  //repair DNA
    return 0;
}
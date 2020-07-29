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
char DNA[4] = { 'T', 'A', 'G', 'C' }; // �ؽ� ���� �� ������� ����
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

    // ���� ������ ����
    for (int i = 0; i < MAXNUM; i++) {
        int random = GetRand(0, 3);
        rseq += DNA[random];
    }
    // ���Ͽ� ����
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
    // �޶�� �ϴ� base ����
    int should_diff = MAXNUM * x / 100;
    int rsize = rseq.size();

    for (int i = 0; i < should_diff; i++) {
        // �������� �ٲ� �κ��� ��ġ�� �̴´�.
        int pos = GetRand(0, rsize - 1);
        // set�� �̿��ؼ� �̹��� ���� ��ġ�� �ٲ� �� �ִ��� Ȯ���Ѵ�
        // ���࿡ ���ٸ� set�� �߰��ϰ�, �׷��� �ʴٸ� 
        // ���� �� ���� ��ġ�� ���� �� ���� �ݺ��Ѵ�.
        while (dup_check_set.find(pos) != dup_check_set.end()) {
            pos = GetRand(0, rsize - 1);
        }

        dup_check_set.insert(pos);
        // �ش��ϴ� ��ġ�� base�� ���ο� base�� �ٲ۴�.
        char theChar = myseq[pos];
        int newChar = GetRand(0, 3);
        while (DNA[newChar] == theChar) // ������ �ٸ� ���� ���� ������ �ݺ�
            newChar = GetRand(0, 3);
        myseq[pos] = DNA[newChar];
    }
    // ���Ͽ� ����
    if (wFile.is_open()) {
        wFile << myseq;
        wFile.close();
    }
    return myseq;
}

void MakeShortRead(string seq, int k, int n) {

    int random;
    int maxIndex = seq.length() - k; // ù �ε����� �� �� �ִ� �ִ� ��
    string shortseq = "";
    string fName = "shortread_1000.txt";
    ofstream wFile(fName.data());

    if (wFile.is_open()) {
        for (int i = 0; i < n; i++) {
            //random = GetRand(0, maxIndex); // ������ �ε���
            random = rand() % (maxIndex + 1);
            shortseq = "";
            for (int j = random; j < random + k; j++) // �ش� �ε������� k���� ���ڿ��� �߶� ���Ͽ� ����
                shortseq += seq[j];
            wFile << shortseq << endl;
        }
        wFile.close();
    }
}
void Trivial(string& seq, string read) {
    int count = y; // �ٸ� ���� ��� ����
    int seqSize = seq.size();
    int readSize = read.size();
    for (int i = 0; i <= seqSize - readSize; i++) {
        int j = 0;
        count = y;
        for (; j < readSize; j++) {
            if (seq[i + j] != read[j]) { // seq�� Ư�� ��ġ ���ڰ� read�� Ư�� ��ġ ���ڿ� ���� �ʴٸ�
                count--; // �ٸ��� count ����
                if (count < 0) // ���� ������ �ʰ��ϸ� �ݺ� Ż��
                    break;
            }
        }
        if (count >= 0) { // Ʋ�� ������ 0 �����̸� ��ġ�� ã�� ��.
            for (int k = i; k < i + readSize; k++)
                seq[k] = read[k - i]; // read�� �E���̱�
            break;
        }
    }
}

struct node {   //position�� �� ����
    vector<int> nodes;
};

node table[TABLE_SIZE]; //�ؽ� ���̺�


int calculateHash(string str, int len) {    //�ؽ� key���� ����ϴ� �Լ�
    long long hashValue = 0;
    int cnt = len - 1;
    for (int j = 0; j < len; j++)
        hashValue += (((str[j] - '0' - 15) % 5 - 1) * pow(4, cnt--));
    hashValue %= TABLE_SIZE;
    return hashValue;
}

void MakeTable(string seq, int rsize) { // seqHash�� ��ó�� //seq, 30
    int slicesize = rsize / (y + 1);
    int ssize = seq.size(); //20000

    for (int i = 0; i < ssize - slicesize; i++) {   //shortread
        int slice = 0;
        int cnt = slicesize - 1;
        string subString = seq.substr(i, slicesize);
        slice = calculateHash(subString, slicesize);    //�ؽ� key���� ���
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

void Indexing(string& seq, string read) { // read = shortread ����

    int* hashStorage = new int[y + 1];
    bool* match = new bool[y + 1];
    int matchCount = 0;
    string remakeString = seq;
    string shortRead = read;

    int hashNumber = 0;
    int subLength = shortRead.length() / (y + 1);   //10

    for (int i = 0; i < y + 1; i++) {   //shortRead�� missmatch+1��� �� substring�� �ؽ� key���� ���Ѵ�.
                                        // key�� �ش�Ǵ� ������ �ִ��� ���ο� DNA�ε������� ���̺��� �����Ͽ� ���� �����Ѵ�.       
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

    for (int k = 0; k < y + 1; k++) {   //���̺� ����� �ε����� ���� Ž��
        string str;
        if (match[k]) { //k��° �ؽ� �Լ��� ��尡 ������� �� ��
            int mismatchCount = 0;
            int size = table[hashStorage[k]].nodes.size();
            for (int j = 0; j < size; j++) {
                int startIndex = table[hashStorage[k]].nodes[j];
                if (table[hashStorage[k]].nodes[j] - ((subLength * k)) < 0) continue;
                else {
                    str = seq.substr(table[hashStorage[k]].nodes[j] - ((subLength * k)), shortRead.length());
                }
                if (str.length() != shortRead.length()) continue;

                for (int i = 0; i < shortRead.length(); i++) {  //mismatch ī��Ʈ
                    if (str[i] != shortRead[i]) mismatchCount++;
                }

                if (minMismatch > mismatchCount) {  //�̽���ġ�� ���� ��찡 ������� ���� �ε����� ����
                    subIndex = table[hashStorage[k]].nodes[j] - ((subLength * k));
                    minMismatch = mismatchCount;
                }
                mismatchCount = 0;
            }
        }
    }
    if (matchCount != 0)    //��尡 �ִ� �ؽ��Լ��� �ϳ��� ���� ���� �ٲ��� ����
        seq.replace(subIndex, shortRead.length(), shortRead, 0, shortRead.length());   //���� miss match�� ���� �ε����� ã�� ��Ʈ���� ����

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

    // Trivial ���� ����
    cout << "Calculate Difference between Rsequence and Msequence..." << endl;
    string fseq = reference; // rseq�κ��� �����ؾ� �ϴ� fseq
    string shortreadFname = "shortread.txt";
    ifstream oFile(shortreadFname.data());

    int coun = 0;
    for (int i = 0; i < rseq.length(); i++) {
        if (rseq[i] != mseq[i]) coun++;
    }
    cout << "����: " << coun << endl;
    clock_t start = clock(); // �ð� ���� ����

    if (oFile.is_open()) {
        string tmp;
        while (getline(oFile, tmp)) {
            Trivial(fseq, tmp);
        }
        oFile.close();
    }

    clock_t end = clock(); // �ð� ���� ����
    cout << "Done" << endl << endl;
    //Trivial ��� ���
    cout << "<Trivial �˰��� ���>" << endl;
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
    clock_t startr = clock(); // �ð� ���� ����

    MakeTable(remakeseq, k); // ��ó���� 

    if (o2File.is_open()) { //��ü ȣ��
        string tmp;
        while (getline(o2File, tmp)) {
            Indexing(remakeseq, tmp);
        }
        o2File.close();
    }
    clock_t endr = clock(); // �ð� ���� ����

    wFile << remakeseq; //���� ����

    cout << endl << "Done" << endl;

    cout << endl << "<My �˰��� ���>" << endl;
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
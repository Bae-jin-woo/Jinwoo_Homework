class Integer {
	int num;
public:
	Integer(int n);
	Integer(string s);
	int get();
	void set(int n);
	int isEven();
};
inline Integer::Integer(int n) {
	num = n;
}
inline Integer::Integer(string s){
	num = stoi(s);	//문자열을 정수로 변환
}
inline int Integer::get() {
	return num;
}
inline void Integer::set(int n){
	num = n;
}
inline int Integer::isEven(){
	if (num % 2 == 0) return 1;
	else return 0;
}

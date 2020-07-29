public class Source1 {
	public static void main(String[] args) {
		Student s1 = new Student("홍길동",1,1234,100,60,76);
		System.out.println("이름 : "+s1.getName());
		System.out.println("국어점수 : "+s1.getKor());
		System.out.println("영어점수 : "+s1.getEng());
		System.out.println("수학점수 : "+s1.getMath());
		System.out.println("총점 : "+s1.getTotal());
		System.out.printf("평균 : %.1f",s1.getAverage());	//소숫점 둘째 자리 반올림
	}
}
class Student{
	String name;	//학생이름
	int Ban;	//반
	int No;	//번호
	int Kor;	//국어점수
	int Eng;	//영어점수
	int Math;	//수학점수
	public String getName() {return name;}	//필드의 getter/setter 함수
	public void setName(String name) {this.name = name;}
	public int getBan() {return Ban;}
	public void setBan(int ban) {Ban = ban;}
	public int getNo() {return No;}
	public void setNo(int no) {No = no;}
	public int getKor() {return Kor;}
	public void setKor(int kor) {Kor = kor;}
	public int getEng() {return Eng;}
	public void setEng(int eng) {Eng = eng;}
	public int getMath() {return Math;}
	public void setMath(int math) {	Math = math;}
	int getTotal() {return Kor+Eng+Math;}
	float getAverage() {return (float)getTotal()/3;}
	Student(String name, int ban, int no){}	//학생의 이름, 반, 번호를 초기화
	Student(String name, int ban, int no, int kor, int eng, int math){
		this.name = name;
		this.Ban = ban;
		this.No=no;
		this.Kor=kor;
		this.Eng=eng;
		this.Math=math;
	}
}

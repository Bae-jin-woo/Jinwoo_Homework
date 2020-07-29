public class Source1 {

	public static void main(String[] args) {
		Student s1 = new Student("홍길동",1,2);
		s1.setScore(75, 88, 54);
		Student s2 = new Student("김영희",1,20,90,100,94);
		Student s3 = new Student("김철수",2,12,12,54,30);
		s1.printInfo();
		s2.printInfo();
		s3.printInfo();
	}

}
class Student{
	private String name;	//학생이름
	@SuppressWarnings("unused")
	private int ban;	//반	
	@SuppressWarnings("unused")
	private int no;		//번호
	private int kor;	//국어점수
	private int eng;	//영어점수
	private int math;	//수학점수
	private static int cntCurrentStudent=0;	//현재까지 생성된 학생 수, 0으로 초기화됨
	int getTotal() {return kor+eng+math;}	//점수 총점
	float getAverage() {return (float)getTotal()/3;}	//평균 반환
	void setScore(int kor,int eng,int math) {//점수를 저장한다.
		this.kor=kor; this.eng=eng;this.math=math;
	}
	void printInfo() {	//학생의 정보를 출력하는 함수
		System.out.println(this.name+" 학생의 정보는 다음과 같습니다.");
		System.out.println("국어 : "+this.kor+" ,영어 : "+this.eng+" ,수학 : "+this.math);
		System.out.println("총점 : "+this.getTotal()+" ,평균 : "+String.format("%.1f", this.getAverage()));
	}
	char Grade() {	//학점 반환
		if(getAverage()>=91)	return 'A';
		else if(getAverage()>=81)	return 'B';
		else if(getAverage()>=71)	return 'C';
		else if(getAverage()>=61)	return 'D';
		else return 'F';
	}
	Student(String name,int ban,int no){	//이름,반,번호를 초기화, 초기화되지 않은 필드 0으로 초기화, 현재 학생 수 증가
		this.name = name;
		this.ban=ban;
		this.no=no;
		this.kor=0;this.eng=0;this.math=0;
		cntCurrentStudent++;
		System.out.println(this.name+" 학생이 생성되었습니다.");
		System.out.println("현재까지 처리중인 학생 수는 "+cntCurrentStudent+"입니다.");
	}
	Student(String name,int ban, int no, int kor, int eng,int math){		
		this(name,ban,no);	//자기자신을 나타내는 키워드를 이용한 값 저장
		setScore(kor,eng,math);	//메소드를 사용한 점수 저장
	}
	
}

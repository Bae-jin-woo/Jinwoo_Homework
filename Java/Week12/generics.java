import java.util.*;

class Student implements Comparable<Student>{
	String name;
	int ban;
	int no;
	int kor,eng,math;
	
	Student(String name, int ban, int no, int kor, int eng, int math){	//생성자
		this.name = name; this.ban = ban; this.no = no;
		this.kor = kor; this.eng = eng; this.math = math;
	}
	
	int getTotal() {	//총점
		return kor+eng+math;
	}
	
	float getAverage() {	//평균
		return (int)((getTotal() / 3f)*10+0.5)/10f;
	}
	
	public String toString() {
		return name+","+ban+","+no+","+kor+","+eng+","+math
				+","+getTotal() +","+getAverage();
	}
	
	public int compareTo(Student s) {
		if(s instanceof Student) {
			Student tmp = s;
			return name.compareTo(tmp.name);
		}
		else { return -1;}
	}
	
}

public class Source1{
	
	public static void main(String []args) {
		
		List<String> nameList = new ArrayList<>();
		
		nameList.add("Heo");
		nameList.add("Choi");
		nameList.add("Lee");
		
		System.out.println("- 정렬 전 "+nameList);
		
		Collections.sort(nameList);
		
		System.out.println("- 정렬 후 "+ nameList);
	}
}

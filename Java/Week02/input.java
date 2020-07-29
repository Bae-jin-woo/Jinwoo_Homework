import java.util.Scanner;

public class Source2 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("화씨온도를 입력하세요: ");	//화씨 입력
		int fahrenheit=sc.nextInt();
		System.out.println("Fahrenheit: "+ fahrenheit);
		double Celcius = (double)(fahrenheit-32)*5/9;	
		System.out.printf("Celcius: %.2f", Celcius);	//출력
	}
}


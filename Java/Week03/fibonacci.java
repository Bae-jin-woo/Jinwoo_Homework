import java.util.*;

public class Source2 {
	public static void main(String[] args) {
		
		long a = 0, b = 1, c;
		int i;
		Scanner scanner = new Scanner(System.in);
		System.out.print("몇번째 항까지 출력할까요?>");
		i = scanner.nextInt();	//항 입력
		if(i == 1) {	//첫번쨰 항
			System.out.printf("%d ", a);
		}
		else if(i == 2) {	//두번째 항
			System.out.printf("%d %d",a,b);
		}
		else {
			System.out.printf("%d %d ",a,b);
			for(int n = 3; n <= i; n++) {
				c = a + b;	//새로운 항 생성
				a = b;
				b = c;
				System.out.printf("%d ", c);	//n번째 항
			}
		}		
	}
}

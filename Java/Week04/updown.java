
import java.util.*;
public class Source3 {

	public static void main(String[] args) {
		int num=0;
		int random=(int)(Math.random()*100);
		int count=0;
		while(num!=random) {
		System.out.print("1과 100사이의 값을 입력하세요 : ");
		Scanner scanner = new Scanner(System.in);
		num=scanner.nextInt();
		if(num<random) {
			System.out.println("더 큰 수를 입력하시오.");
			count++;
		}
			else if(num>random) {
			System.out.println("더 작은 수를 입력하시오.");
			count++;
			}
		}
		count++;
		System.out.println("시도 횟수는 "+count+"번 입니다.");
	}
}

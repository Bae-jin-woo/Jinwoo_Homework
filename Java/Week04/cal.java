import java.util.*;
public class Source4 {

	public static void main(String[] args) {
		String str;
		int num1,num2,result = 0;
		char op;
		System.out.print("숫자와 연산자를 입력하세요 : ");
		Scanner scanner = new Scanner(System.in);	//입력
		str = scanner.nextLine();
		num1=(int)str.charAt(0)-48;	//아스키코드값을 빼주면서 형 변환
		op=str.charAt(1);
		num2=(int)str.charAt(2)-48;	//아스키코드값을 빼주면서 형 변환
		switch(op) {	//결과값 계산
		case '+':	result = num1+num2;	break;
		case '-':	result = num1-num2; break;
		case '*':	result = num1*num2; break;
		case '/':	result = num1/num2; break;	
		}
		System.out.println("연산의 결과는 "+num1+" "+op+" "+num2+" = "+result);
	}
}

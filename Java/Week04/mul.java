import java.io.*;

public class Source1 {

	public static void main(String[] args) throws NumberFormatException, IOException{
		int result=0;
		int num;
		int mid_result=1;
		System.out.print("숫자를 입력하시오 : ");
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		num=Integer.parseInt(input.readLine());	//문자열 입력
		for(int i=1;i<=num;i++) {
			mid_result*=i;	//각 항 계산
			result += mid_result;	//결과값
		}
		System.out.println(result);
	}
}

public class Source3 {

	public static void main(String[] args) {
		
		String myString = "abcdef";	
		String myString2 = "ABCDEF";	
		String myString3 = "abc,def";
		int length = myString.length();	//문자열 크기 반환 메소드
		System.out.println("abcdef 문자열의 길이 : " + length);
		boolean b1 = myString.contentEquals(myString2);	//문자열 비교 메소드
		if(b1) {
			System.out.println("abcdef와 ABCDEF 문자열 비교(대소문자 구분O) : 같은 문자열");
		}
		else {
			System.out.println("abcdef와 ABCDEF 문자열 비교(대소문자 구분O) : 다른 문자열");
		}
		boolean b2 = myString.equalsIgnoreCase(myString2);	//대소문자를 구분하지 않는 문자열 비교 메소드
		if (b2) {
			System.out.println("abcdef와 ABCDEF 문자열 비교 (대소문자 구분X) : 같은 문자열");
		}
		else {
			System.out.println("abcdef와 ABCDEF 문자열 비교 (대소문자 구분X) : 다른 문자열");
		}
		String[] arr = myString3.split(",",2);	//분리자로 문자열을 분리하는 메소드
		System.out.print("분리된 문자열 : ");
		for(int i=0;i<=1;i++) {			
			System.out.printf("%s ", arr[i]);
		}
		System.out.println();
		boolean b3 = myString.startsWith("adf");	//주어진 문자열로 시작하는지 검색하는 메소드
		if(b3) {
			System.out.println("abcdef가 adf로 시작하는가? : 참");
		}
		else {
			System.out.println("abcdef가 adf로 시작하는가? : 거짓");
		}
	}
}

// 컴퓨터공학과 2015112128 배진우 문제1번

public class Source1 {
	public static void main(String[] args)	{
		
		int [][]Original = {{1,2,3},{4,5,6}};	//배열 선언
		int a,b;
		a=Original.length;
		b=Original[0].length;	//행과 열 선언
		
		int [][]Transpose = new int[b][a];
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				Transpose[j][i] = Original[i][j];	//행열변환
			}
		}
		
		System.out.println("Original:");
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				System.out.printf(Original[i][j] + " ");
			}
			System.out.print("\n");
		}
		System.out.println("Transpose:");
		for(int j=0;j<b;j++)
		{
			for(int i=0;i<a;i++)
			{
				System.out.printf(Transpose[j][i]+" ");
			}
			System.out.printf("\n");	//출력
		}
	}
}

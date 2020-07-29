
import java.util.*;

public class Source2 {
	
	@SuppressWarnings({ "resource", "unused" })
	public static void main(String[] args) {
		int row,col;
		Scanner scan = new Scanner(System.in);	//행렬 인덱스를 입력받기 위한 스캐너
		Matrix m1 = new Matrix();
		System.out.printf("행 입력>>");
		row = scan.nextInt();
		m1.setRow(row);
		System.out.printf("열 입력>>");
		col = scan.nextInt();
		m1.setCol(col);
		m1.array = new int[m1.getRow()][m1.getCol()];	//입력받은 값으로 행렬 만들기
		System.out.printf("행렬 인덱스 입력>>");
		for(int i = 0;i < m1.getRow();i++)
			for(int j = 0;j < m1.getCol();j++)
				m1.array[i][j] = scan.nextInt();
		
		Matrix m2 = new Matrix();
		System.out.printf("행 입력>>");
		row = scan.nextInt();
		m2.setRow(row);
		System.out.printf("열 입력>>");
		col = scan.nextInt();
		m2.setCol(col);
		m2.array = new int[m2.getRow()][m2.getCol()];	//입력받은 값으로 행렬 만들기
		System.out.printf("행렬 인덱스 입력>>");
		for(int i=0;i<m2.getRow();i++)
			for(int j=0;j<m2.getCol();j++)
				m2.array[i][j] = scan.nextInt();
		
		System.out.println("첫번째 행렬");
		for(int i=0;i<m1.getRow();i++) {
			for(int j=0;j<m1.getCol();j++) {
				System.out.printf(" %d ",m1.array[i][j]);
			}
			System.out.println("");
		}
				
		System.out.println("두번째 행렬");
		for(int i=0;i<m2.getRow();i++) {
			for(int j=0;j<m2.getCol();j++) {
				System.out.printf(" %d ",m2.array[i][j]);
			}
			System.out.println("");
		}
		Matrix m3=  new Matrix();
		
		m3.Multiply(m1, m2, m3);
		System.out.println("두 행렬의 곱");
		for(int i=0;i<m3.getRow();i++) {
			for(int j=0;j<m3.getCol();j++) {
				System.out.printf(" %d ",m3.array[i][j]);
			}
			System.out.println("");
		}
		
		System.out.println("첫번째 행렬의 상수배 행렬");
		m1.Multiply(m1, 3);
		for(int i=0;i<m1.getRow();i++) {
			for(int j=0;j<m1.getCol();j++) {
				System.out.printf(" %d ",m1.array[i][j]);
			}
			System.out.println("");
		}
		Matrix.getArrayNumber();
	}
	static class Matrix{
		private int row;	//행
		private int col;	//열
		public int [][]array;
		void setRow(int row) {this.row=row; }
		void setCol(int col) {this.col=col;}
		int getRow() {return this.row;}
		int getCol() {return this.col;}
		static public int Array_number=0;	//현재까지 생성된 행렬의 개수
		Matrix(){
			this.row=0;
			this.col=0;
			array = new int[row][col];
			Matrix.Array_number++;
			System.out.println(Matrix.Array_number+"번째 행렬 생성");
		}
		public void Multiply(Matrix m,int n) {
			for(int i=0;i<m.getRow();i++)
				for(int j=0;j<m.getCol();j++)
					m.array[i][j] *= n;
		}
		void Multiply(Matrix A,Matrix B,Matrix C) {	//행렬 간의 곱셈을 구함
			C.setRow(A.getRow());	//행렬곱의 결과는 첫번째 행렬의 행과 두번쨰 행렬의 열과 같다.
			C.setCol(B.getCol());
			C.array = new int[A.getRow()][B.getCol()];	//입력받은 값으로 행렬 만들기
			if(A.getCol() == B.getRow()) {	//행렬 곱셈이 가능한경우
				for(int i=0;i<C.getRow();i++)
					for(int j=0;j<C.getCol();j++)
						for(int k=0;k<A.getCol();k++)
							C.array[i][j] += A.array[i][k]*B.array[k][j];
			}
			else {	//행렬 곱셈이 불가능한경우
				System.out.println("곱셈을 실행할 수 없습니다.");
				}	
			}
		static void getArrayNumber() {System.out.println("총 행렬의 개수 : "+Matrix.Array_number);}
	}
}


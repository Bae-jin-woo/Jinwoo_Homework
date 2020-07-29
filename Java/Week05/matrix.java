import java.util.*;
public class Source3 {

	@SuppressWarnings({ "resource", "unused" })	//예외처리
	public static void main(String[] args) {
	int row,col;
	Matrix m1=new Matrix();
	Matrix m2 =new Matrix();
	Scanner scan = new Scanner(System.in);	//행렬 인덱스를 입력받기 위한 스캐너
	System.out.println("*******1번쨰 행렬을 만듭니다.*******");
	System.out.print("행을 입력하세요>>");
	row=scan.nextInt();
	m1.setRow(row);	//행 입력
	System.out.print("열을 입력하세요>>");	
	col=scan.nextInt();
	m1.setCol(col);	//열 입력
	m1.array = new int[m1.getRow()][m1.getCol()];	//입력받은 값으로 행렬 만들기
	System.out.print(row+" * "+col+" 행렬이 만들어졌습니다. 인덱스를 입력하세요.>>");
	Matrix.Array_number++;	//행렬 카운트
		for(int i=0;i<m1.getRow();i++) {
			for(int j=0;j<m1.getCol();j++) {
				m1.array[i][j] = scan.nextInt();	//행렬 인덱스 입력
			}
		}
	System.out.println("*******2번쨰 행렬을 만듭니다.*******");
	System.out.print("행을 입력하세요>>");
	row=scan.nextInt();
	m2.setRow(row);	//행 입력
	System.out.print("열을 입력하세요>>");	
	col=scan.nextInt();
	m2.setCol(col);	//열 입력
	m2.array = new int[m2.getRow()][m2.getCol()];	//입력받은 값으로 행렬 만들기
	System.out.print(row+" * "+col+" 행렬이 만들어졌습니다. 인덱스를 입력하세요.>>");
	Matrix.Array_number++;	//행렬 카운트
		for(int i=0;i<m1.getRow();i++) {
			for(int j=0;j<m1.getCol();j++) {
				m2.array[i][j] = scan.nextInt();
			}
		}	
	System.out.println("첫번째 행렬의 전치행렬을 출력합니다");
	Matrix m3 = new Matrix();
	m3 = Matrix.Transpose(m1);	//전치행렬 생성
	Matrix.Array_number++;	//행렬 카운트
	for(int i=0;i<m3.getRow();i++) {
		for(int j=0;j<m3.getCol();j++) {
			System.out.print(m3.array[i][j]+" ");
		}
		System.out.println("");
	}
	System.out.println("두 행렬의 합을 출력합니다");
	Matrix m4 = Matrix.Summaion(m1, m2);
	Matrix.Array_number++;
	for(int i=0;i<m4.getRow();i++) {	//두 행렬의 합 출력
		for(int j=0;j<m4.getCol();j++) {
			System.out.print(m4.array[i][j]+" ");
		}
		System.out.println("");
		}
	System.out.println("총 만들어진 행렬 수 : "+Matrix.Array_number);	//행렬 수 출력
	}	
}

class Matrix{
	int Row;	//행
	int Col;	//열
	int [][] array;	//배열 요소
	static int Array_number=0;	//현재까지 생성된 행렬의 총 개수
	int getRow() {return Row;}	//행의 값을 가져옴
	void setRow(int row) {Row = row;}	//행의 값을 저장함
	int getCol() {return Col;}	//열의 값을 가져옴
	void setCol(int col) {Col=col;}	//열의 값을 저장함
	Matrix(){	//클래스 생성자
		Row=0; Col=0;
		array = new int[Row][Col];	//행과열이 0인 기본 행렬
	}
	static Matrix Transpose(Matrix A) {	//A행렬의 전치 행렬을 구하는 메소드
		Matrix B = new Matrix();	//빈 행렬 생성
		B.setRow(A.getCol());	//
		B.setCol(A.getRow());
		B.array = new int[B.getRow()][B.getCol()];
		for(int i=0;i<A.getRow();i++) {	//전치 행렬 생성
			for(int j=0;j<A.getCol();j++) {
				B.array[j][i]=A.array[i][j];
			}
		}
		return B;	//전치행렬 반환
	}
	static Matrix Summaion(Matrix A, Matrix B) {	//행렬의 합을 구하는 메소드
		Matrix C = new Matrix();
		C.setRow(A.getRow());
		C.setCol(A.getCol());
		C.array = new int[C.getRow()][C.getCol()];	//매개변수가 되는 행렬과 같은 크기의 행렬 생성
	if(A.getRow()==B.getRow()&&A.getCol()==B.getCol()) {	//행렬 2개의 행과열이 같다면	
		for(int i=0;i<A.getRow();i++) {	//행렬 더하기 수행
				for(int j=0;j<A.getCol();j++) {	
					C.array[i][j]=A.array[i][j]+B.array[i][j];	//행렬 더하기
				}
			}
			return C;	//더한 행렬 반환
		}
	else	{System.out.println("계산할 수 없는 행렬입니다.");}
	return C;
	}	
}

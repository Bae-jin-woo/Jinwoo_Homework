import java.util.Scanner;
import java.util.*;

class UserDefinedException extends Exception {
   UserDefinedException(String s) {
      super(s);
   }
}

public class Source3 {
   public static void NException(int n) throws UserDefinedException{
      if(n<=0)
         throw new UserDefinedException("ex05:NegativeException: 행렬의 행과 열은 0과 음수가 될 수 없습니다.");
   }
   public static void InputException(double d) throws UserDefinedException{
      int n = (int)d;
      double d1 = d;
      if(n!=d1)
         throw new UserDefinedException("java.util.InputMismatchException: 행렬 내부의 값은 정수 형태만 가능합니다.");
   }
   
   public static void main(String[] args) {
      int row, col;
      Matrix m1 = new Matrix();
      Scanner sc = new Scanner(System.in);
      while(true) {
      try {
      System.out.println("행렬의 행을 입력하세요.");
      m1.Row = sc.nextInt();
      NException(m1.Row);
      break;
      } catch(Exception e) {
         System.out.println(e.getMessage());
      }
      }
      while(true) {
      try {
      System.out.println("행렬의 열을 입력하세요.");
      m1.Col = sc.nextInt();
      NException(m1.Col);
      break;
      } catch(Exception e) {
         System.out.println(e.getMessage());
      }
      }
      System.out.println("현재까지 생성된 행렬의 총 개수는 "+Matrix.Array_number+"개 입니다.");
      
      System.out.println("행렬내부의 값을 입력하세요.");
      m1.setMatrix();
      
      
      for(int i=1;i<=m1.Row;i++)
         for(int j=1;j<=m1.Col;j++) {
            double f=1;
            int n;
            while(true) {
            System.out.print(i+"행"+j+"열의 값을 입력하세요.");
            try {
               f = sc.nextDouble(); 
               InputException(f);
               break;
            }catch(Exception e) {
               System.out.println(e.getMessage());
            	}
            }
            n = (int) f;
            m1.array[i-1][j-1] = n;
         }
       
      
      for(int i=1;i<=m1.Row;i++) {
         for(int j=1;j<=m1.Col;j++) {
            System.out.print(m1.array[i-1][j-1]+" ");
         }
         System.out.println();
      }
   }
}   

class Matrix{
   int Row;   //행
   int Col;   //열
   int [][] array;   //배열 요소
   static int Array_number=0;   //현재까지 생성된 행렬의 총 개수
   int getRow() {return Row;}   //행의 값을 가져옴
   void setRow(int row) {Row = row;}   //행의 값을 저장함
   int getCol() {return Col;}   //열의 값을 가져옴
   void setMatrix() {array = new int[Row][Col];}
   void setCol(int col) {Col=col;}   //열의 값을 저장함
   Matrix(){   //클래스 생성자
      Row=0; Col=0;
      array = new int[Row][Col];   //행과열이 0인 기본 행렬
      Array_number++;
   }
}

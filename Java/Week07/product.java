public class Source1 {

   public static void main(String[] args) {
      Buyer b = new Buyer();
      b.buy(new Tv());
      b.buy(new Computer());
      b.buy(new Tv());
      b.buy(new Computer());
      b.summary();
   }
}

class Product{
   int price;
   Product(int price){
      this.price = price;
   }
}
class Tv extends Product{   
   Tv() {
      super(100);
   }
   public String toString() {
      return "Tv";
   }
}
class Computer extends Product{   
   Computer(){
      super(200);
   }
   public String toString() {
      return "Computer";
   }
}
class Buyer extends Product{
   Buyer(){
      super(0);
   }
   int money = 500;   //가지고 있는 돈
   Product []cart = new Product[3];      //구입한 제품을 저장하기 위한 배열
   int i=0;   //cart에 사용될 인덱스
   void buy(Product t) {
      if(money < t.price) {
         System.out.println("잔액이 부족하여 "+t.toString()+"을 살 수가 없습니다.");
         return;
      }
      else {
         add(t);
         money-=t.price;
      }
   }
   void add(Product t) {
      cart[i++] = t;
      if(i>2) {   //장바구니가 꽉 찼다면 크기를 늘리고 저장
         Product []copy = new Product[i+1];	
         System.arraycopy(cart, 0, copy, 0, i);
         cart = new Product[i+1];
         System.arraycopy(copy, 0, cart, 0, i);
         cart[i++] = t;
      }
   }
   public void summary() {
      //구입한 물건의 목록과 사용금액, 남은금액을 출력
      System.out.print("구입한 물건 : ");
      for(int j=0;j<cart.length-1;j++)
         System.out.print(cart[j].toString() + ", ");
      System.out.println("");
      System.out.println("사용한 금액 : "+ (500 - money));
      System.out.println("남은 금액 : " + money);
      
   }
}

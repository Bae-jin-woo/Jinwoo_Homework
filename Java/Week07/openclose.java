public class Source2 {

   public static void main(String[] args) {
      Door d= new Door();
      d.open();
      d.close();
      Bottle b= new Bottle();
      b.open();
      b.close();
   }

}


interface OpenCloseIf{
   void open();
   void close();
}

class Door implements OpenCloseIf{
   public void open() {
      System.out.println("Door open");
   }
   public void close() {
      System.out.println("Door close");
   }
}
class Bottle implements OpenCloseIf{
   public void open() {
      System.out.println("Bottle open");
   }
   public void close() {
      System.out.println("Bottle close");
   }
}

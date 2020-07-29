import java.util.ArrayList;

class Fruit{
	public String toString(){
		return "Fruit";
	}
}

class Apple extends Fruit{
	public String toString(){
		return "Apple";
	}
}

class Grape extends Fruit{
	public String toString(){
		return "Grape";
	}
}

class Juice{
	String name;
	Juice(String name){this.name = name+"Juice";}
	public String toString() {return name;}
}

class Juicer{
	
	static<T extends Fruit> Juice makeJuice(FruitBox<T> box) {
		String tmp="";
		for(Fruit f:box.getList())
			tmp+=f+" ";
		return new Juice(tmp);}
	
}

class Box<T>{
	ArrayList <T> list = new ArrayList<T>();
	public void  add(T e) {
		list.add(e);
	}
	public void  get(int i) {
		list.get(i);
	}	
	public ArrayList<T> getList() {
		return list;
	}
	public int  size() {
		return list.size();
	}
	public String toStinrg() {return list.toString(); }
}

class FruitBox<T extends Fruit> extends Box<T>{}
	

public class Source2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FruitBox<Fruit> fruitBox = new FruitBox<Fruit>();
		FruitBox<Apple> appleBox = new FruitBox<Apple>();
		
		
		fruitBox.add(new Apple());
		fruitBox.add(new Grape());
		appleBox.add(new Apple());
		appleBox.add(new Apple());
		
		System.out.println(Juicer.makeJuice(fruitBox));
		System.out.println(Juicer.makeJuice(appleBox));
		
		
	}

}


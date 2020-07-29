import java.util.*;

class Table{
	String[] dishNames = {"donut","donut","burger"}; //음식이름
	final int MAX_FOOD = 6; //테이블에 세팅될 최대 음식 수
	private ArrayList<String> dishes = new ArrayList<String>();	//테이블에 세팅될 음식접시
	
	synchronized boolean add(String dish) {
		
		boolean b = false;
		int size = dishes.size();
		
		if(size < MAX_FOOD) {	//테이블에 세팅 할 수 있는 최대 음식 수보다 적게 세팅이 되어있다면
			dishes.add(dish);	//dish을 추가한다.
			System.out.print("Dishes : [");
			for(int i=0;i<dishes.size();i++)
				System.out.print(dishes.get(i)+", ");
			System.out.println("]");	
		}
		int resize = dishes.size();
		notifyAll();
		if(size!=resize) {
			b= true;
		}
		return b;
	}	//add
	
	synchronized boolean remove(String dishNames) throws InterruptedException{
		boolean b = false;
		
		while(true) {
			try {	//0.5초마다 음식이 추가되었는지 확인하며 기다린다.
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
			
		while(true) {
		for(int i=0;i<dishes.size();i++) {
			if(dishes.get(i)==dishNames) {	//원하는 음식과 일치하는 음식이 있다면
				break;
				}
			}
		b=false; break;	//원하는 음식과 일치하는 음식이 없음
		}
		int size=dishes.size();
		
		dishes.remove(dishNames);
		
	int resize=dishes.size();

	if(size!=resize) {b=true; break;}
	else {
		System.out.println(Thread.currentThread().getName()+" is waiting");
		try {
		wait();
	} catch (Exception e) {
		// TODO: handle exception
	}
	notifyAll();
		continue;
	}
		}
	return b;
	}
	
}	//table

class Customer implements Runnable{
	private Table table;
	private String food;	//고객이 주문한 음식. 음식 주문은 한 사람당 한 개만 한다.
	
	Customer(Table table, String food){
		this.table = table;
		this.food = food;
	}
	
	@Override
	public void run() {
		while(true) {
		try {	//0.1초를 기다린다.
			Thread.sleep(100);	
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
	boolean b=false;
	
	try {
		b = table.remove(food);
	} catch (InterruptedException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	if(b) 	//음식이 제거되었다면 메세지 출력
		System.out.println(Thread.currentThread().getName()+" ate a "+food);		
		}
	}	//run	
}	//Customer

class Cook implements Runnable{	//table의 dishNames에서 랜덤하게 한 음식을 add한다. 이 행동을 0.1초쉬고 반복
	private Table table;
	
	Cook(Table table){
		this.table = table;
	}
	@Override
	public synchronized void run() {
		while(true) {
			
		int i= (int)(Math.random()*3);
		
		boolean b= table.add(table.dishNames[i]);	//dishNames에서 랜덤하게 한 음식을 add 한다.

		try {	//그리고 이 행동을 0.1초 쉬고 다시 반복한다.
			Thread.sleep(100);
					
		} catch (InterruptedException e) {	
			// TODO Auto-generated catch block
			e.printStackTrace();
			}
		}
	}	
}	//cook

public class Source3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Table table = new Table();
		new Thread(new Cook(table),"Cooker").start();
		new Thread(new Customer(table,"donut"),"client1").start();
		new Thread(new Customer(table,"burger"),"client2").start();
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO: handle exception
			System.exit(0);
		}
	}
}


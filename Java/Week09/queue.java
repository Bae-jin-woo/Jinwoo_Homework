interface Collection {
	void add(Object obj);	//큐에서 obj 데이터 추가
	
	void delete();	//큐에서 데이터 삭제
	
	void find(Object obj);	//큐에서 obj 데이터가 있는지 찾기
	
	int CurrentCount();	//큐에서 현재 몇 개의 데이터가 있는 지 찾기
}
class Link{	//생성자가 
	Object data;
	Link next;
	
	Link (Object d, Link n){
		data = d;	//실제 데이터 값 설정
		next = n;	//연결 고리 설정
	}
}

class queue implements Collection{
	private Link head = null;
	@SuppressWarnings("unused")
	private Link tail = null;
	private Link ptr = null;
	private int count = 0;	//큐에 저장된 데이터의 개수를 저장할 변수
	
	
	public void add(Object obj) {
		if(head==null) {
			head =new Link(obj,null);
			tail=ptr=head;
		}
		else {
			ptr.next = new Link(obj,null);
			ptr=ptr.next;
			ptr.data=obj;
			tail=ptr;
		}
		System.out.println(obj+" is added");
	}
	
	public void delete() {
		System.out.println(head.data +" is deleted");
		head=head.next;
	}

	public void find(Object obj) {
		ptr=head;
		count=0;
		while(true) {
		if(ptr.data == obj) {
			System.out.println(obj+" is "+count+"th queue's data");
			break;
		}
		ptr=ptr.next;
		count++;
		if(ptr.next==null) {
			System.out.println("there is no "+obj+" in the queue");
			break;
			}
		}	
	}

	public int CurrentCount() {
		ptr=head;
		count=0;
		if(ptr==null) {
			System.out.println("Queue is empty");
			return 0;
		}
		else 
			count++;
		while(true) {
			if(ptr.next==null)
				break;
			else {
				count++;
				ptr=ptr.next;
			}
		}
		System.out.println(count+" Object are found");
		return 0;
	}
	
}

public class Source1 {

	@SuppressWarnings("unused")
	public static void main(String[] args) {
		System.out.println("Queue Simulator Start.");
		
		queue q = new queue();
		
		Integer a = 1;
		
		q.add(new Integer(1));
		q.add(a);
		q.add(new Integer(5));
		
		q.CurrentCount();
		q.find(new Integer(5));
		q.find(a);
		
		q.delete();
		q.delete();
		q.delete();
		
		q.CurrentCount();
		
		System.out.println("Queue Simulator end.");

	}

}


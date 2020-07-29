public class Source3 {

	public static void main(String[] args) {
		MyTv t = new MyTv();
		t.channel=100;
		t.volume=0;
		System.out.println("CH : "+t.channel+", VOL : "+t.volume);
		
		t.channelDown();
		t.volume=0;
		System.out.println("CH : "+t.channel+", VOL : "+t.volume);
		
		t.channel=100;
		t.volume=100;
		t.channelUp();
		t.volumeUp();
		System.out.println("CH : "+t.channel+", VOL : "+t.volume);
	}

}

class MyTv{
	boolean isPowerOn;	//전원의 켜짐 여부
	int channel;	//채널
	int volume;		//볼륨
	int MAX_VOLUME=100;	//최대볼륨 초기화 100
	int MIN_VOLUME=0;	//최소볼륨 초기화 0
	int MAX_CHANNEL=100;	//최대채널 초기화 100
	int MIN_CHANNEL=0;	//최소채널 초기화 0
	void turnOnOff() {if(isPowerOn) isPowerOn=false; else isPowerOn= true;}	//켜져있다면(true)끄고, 꺼져있따면(false) 킴.
	void volumeUp() {	//현재 볼륨이 최대 볼륨보다 작을 때만 값을 1 증가시킴
		if(volume<MAX_VOLUME) volume++;
	}	
	void volumeDown() {	//현재 볼륨이 최소 채널보다 클 때만 값을 1 감소시킴	
		if(volume>MIN_VOLUME) volume--;
	}
	void channelUp() {	//현재 채널이 최대 최대보다 작을 때만 값을 1 증가시킴
		if(channel<MAX_CHANNEL) channel++;
	}	
	void channelDown() {	//현재 채널이 최소 채널보다 클 때만 값을 1 감소시킴
		if(channel>MIN_CHANNEL) channel--;
	}
}

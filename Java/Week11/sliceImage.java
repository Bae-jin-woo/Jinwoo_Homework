import javax.swing.*;
import java.awt.*;
import java.io.*;
import javax.imageio.*;

@SuppressWarnings("serial")
class UserDefinedComponent extends JComponent{
	@SuppressWarnings("unused")
	public void paintComponent(Graphics g) {
		
		try {
			int a,b;
			int sx1 = 0,sy1 = 0,sx2 = 0,sy2 = 0, dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
			Image img = ImageIO.read(new File("fish.jpg"));
			
			int []arr = new int[16];
			int []arr2 = new int[16];
			for(int i=0;i<16;i++) {	//sx에 사용할 arr배열과  dx에 사용할 arr2배열
				arr[i] = i;
				arr2[i] = i;
			}
			
			for(int i=0;i<100;i++) {	//arr2 배열 섞기
				int n = (int)(Math.random()*16);
				int temp = arr2[0];
				arr2[0] = arr2[n];
				arr2[n] = temp;
			}
			for(int i=0;i<16;i++) {	//arr배열 인덱스로 sx, sy 좌표를 나누고 arr2 배열 인덱스로 dx, dy 좌표를 나누어 이미지를 생성 
				a=arr[i];
				b=arr2[i];
				if(a==0) {sx1 = 0; sy1 = 0; sx2 = 240; sy2 = 180;}
				else if(a==1) {	sx1 = 240; sy1 = 0; sx2 = 480; sy2 = 180;}
				else if(a==2) {	sx1 = 480; sy1 = 0; sx2 = 720; sy2 = 180;}
				else if(a==3) {	sx1 = 720; sy1 = 0; sx2 = 960; sy2 = 180;}
				else if(a==4) {	sx1 = 0; sy1 = 180; sx2 = 240; sy2 = 360;}
				else if(a==5) {	sx1 = 240; sy1 = 180; sx2 = 480; sy2 = 360;}
				else if(a==6) {	sx1 = 480; sy1 = 180; sx2 = 720; sy2 = 360;}
				else if(a==7) {	sx1 = 720; sy1 = 180; sx2 = 960; sy2 = 360;}
				else if(a==8) {	sx1 = 0; sy1 = 360; sx2 = 240; sy2 = 540;}
				else if(a==9) {	sx1 = 240; sy1 = 360; sx2 = 480; sy2 = 540;}
				else if(a==10) {sx1 = 480; sy1 = 360; sx2 = 720; sy2 = 540;}
				else if(a==11) {sx1 = 720; sy1 = 360; sx2 = 960; sy2 = 540;}
				else if(a==12) {sx1 = 0; sy1 = 540; sx2 = 240; sy2 = 720;}
				else if(a==13) {sx1 = 240; sy1 = 540; sx2 = 480; sy2 = 720;}
				else if(a==14) {sx1 = 480; sy1 = 540; sx2 = 720; sy2 = 720;}
				else if(a==15) {sx1 = 720; sy1 = 540; sx2 = 960; sy2 = 720;}
				
				if(b==0) {dx1 = 0; dy1 = 0; dx2 = 240; dy2 = 180;}
				else if(b==1) {	dx1 = 240; dy1 = 0; dx2 = 480; dy2 = 180;}
				else if(b==2) {	dx1 = 480; dy1 = 0; dx2 = 720; dy2 = 180;}
				else if(b==3) {	dx1 = 720; dy1 = 0; dx2 = 960; dy2 = 180;}
				else if(b==4) {	dx1 = 0; dy1 = 180; dx2 = 240; dy2 = 360;}
				else if(b==5) {	dx1 = 240; dy1 = 180; dx2 = 480; dy2 = 360;}
				else if(b==6) {	dx1 = 480; dy1 = 180; dx2 = 720; dy2 = 360;}
				else if(b==7) {	dx1 = 720; dy1 = 180; dx2 = 960; dy2 = 360;}
				else if(b==8) {	dx1 = 0; dy1 = 360; dx2 = 240; dy2 = 540;}
				else if(b==9) {	dx1 = 240; dy1 = 360; dx2 = 480; dy2 = 540;}
				else if(b==10) {dx1 = 480; dy1 = 360; dx2 = 720; dy2 = 540;}
				else if(b==11) {dx1 = 720; dy1 = 360; dx2 = 960; dy2 = 540;}
				else if(b==12) {dx1 = 0; dy1 = 540; dx2 = 240; dy2 = 720;}
				else if(b==13) {dx1 = 240; dy1 = 540; dx2 = 480; dy2 = 720;}
				else if(b==14) {dx1 = 480; dy1 = 540; dx2 = 720; dy2 = 720;}
				else if(b==15) {dx1 = 720; dy1 = 540; dx2 = 960; dy2 = 720;}
				g.drawImage(img, dx1, dy1, dx2, dy2, sx1, sy1, sx2, sy2, null);
			
				}
			
			} catch (IOException e) {}	
	}
}
public class Source2 {

	public static void main(String[] args) {
		JFrame frame = new JFrame();
		
		final int FRAME_WIDTH = 960;
		final int FRAME_HEIGHT = 720;
		
		frame.setSize(FRAME_WIDTH,FRAME_HEIGHT);
		frame.setTitle("2015112128 배진우");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		UserDefinedComponent component = new UserDefinedComponent();
		frame.add(component);
		frame.setVisible(true);

	}
}


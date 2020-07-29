import java.awt.Color;
import java.awt.Graphics;
import javax.swing.*;

public class Source1 {

	public static void main(String[] args) {
		JFrame frame = new JFrame();	
		frame.setSize(620,290);
		frame.setTitle("2015112128 배진우");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		BouncingBall ball = new BouncingBall();
		frame.add(ball);
	}

}
@SuppressWarnings({ "unused", "serial" })
class BouncingBall extends JPanel{
	
	private static final int FRAME_WIDTH = 600;	//전체 폭
	private static final int FRAME_HEIGHT = 240;	//전체 높이
	private static final int BALL_SIZE = 20;	//공의 반지름
	private static final int SPEED = 5; //공 속도
	
	private float ballX = BALL_SIZE + 120;	//공의 초기 x 위치
	private float ballY = BALL_SIZE + 80;	//공의 초기 Y 위치
	private float xstep=SPEED;	//x의 이동방향
	private float ystep=SPEED;	//y의 이동방향
	public BouncingBall() {
		//패널 크기 지정
		
		class MyThread extends Thread{
			public void run() {	//수행하여야 하는 작업을 적어줌
				while(true) {
					ballX += xstep;	
					ballY += ystep;
					//1. 공이 왼쪽 프레임을 벗어나려하면
					// x의 값을 BALL_SIZE_ 바꾸고 x축 이동방향(xStep)을 반대로 한다.
					if(ballX==0) {
						ballX = BALL_SIZE;
						xstep *= -1;
					}
					//2. 공이 오른쪽 프레임을 벗어나려하면
					//x의 값을 FRAME_WIDTH - BALL_SIZE로 바꾸고 x축 이동방향(xStep)을 반대로 한다.
					if(ballX+BALL_SIZE==600) {
						ballX = FRAME_WIDTH - BALL_SIZE;
						xstep *= -1;
					}
					//3. 공이 위쪽 프레임을 벗어나려하면
					//y의 값을 BALL_SIZE로 바꾸고 y축 이동방향(yStep)을 반대로 한다.
					if(ballY == 0) {
						ballY = BALL_SIZE;
						ystep *= -1;
					}
					//4. 공이 아래쪽 프레임을 벗어나려하면
					//y의 값을 FRAME_HEIGHT - BALL_SIZE로 바꾸고 y축 이동방향(yStep)을 반대로 한다.
					if(ballY+BALL_SIZE == 240) {
						ballY = FRAME_HEIGHT - BALL_SIZE;
						ystep *= -1;
					}
					//그린다
					repaint();
					try {
						Thread.sleep(50);	//공의 속도 조절
					} catch(InterruptedException ex) {
					}
					}
				}
			}
		Thread t = new MyThread();	//스레드 객체 생성
		t.start();//스레드 시작
	}

public void paintComponent(Graphics g) {
	//프레임 크기만큼의 노란색 직사각형과 ballsize 크기를 갖고 있는 빨간색 원을 그리시오.
	g.setColor(Color.YELLOW);
	g.fillRect(0, 0, FRAME_WIDTH, FRAME_HEIGHT);
	g.setColor(Color.RED);
	g.fillOval((int)ballX,(int)ballY, BALL_SIZE, BALL_SIZE);
	
	
	}
}

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.color.*;


public class Source1 extends JPanel implements Runnable, ActionListener{
	JFrame f;
	JButton b;
	Thread thr = null;
	public String str = "Hello World!!";
	
	public void paintComponent(Graphics g) {	//글자의 색을 랜덤으로 출력하는 메소드
		g.setFont(new Font("Dialog",Font.BOLD,30));
		super.paintComponent(g);
		for(int i=0; i<str.length();i++) {
			int rVal, gVal, bVal;
			rVal = (int)(Math.random() * 256);
			gVal = (int)(Math.random() * 256);
			bVal = (int)(Math.random() * 256);
			g.setColor(new Color(rVal,gVal,bVal));
			g.drawString(str.substring(i,i+1),25+i * 40, 100);
		}
		
	}
	public Source1() {	//메인 메소드에서  객체를 만들때 호출되므로 생성자에서 미리button을 만든다.
		
		this.b = new JButton();
		JButton b = this.b;
		b.addActionListener(this);
		b.setText("Press to start the animation");
		
		add(b);
	}
	
	public void run() {	
		while(thr!= null) {
			try {
				repaint();
				Thread.sleep(1000);
			} catch(InterruptedException e) {
			}
		}
	}
	public void actionPerformed(ActionEvent e) {
		if(thr == null) {
			thr = new Thread(this);
			thr.start();
			b.setText("Press to stop the animation.");
		} else {
			thr = null;
			b.setText("Press to start the animation");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame f = new JFrame();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(600, 300);
		f.setTitle("2015112128 배진우");
		f.add(new Source1());	//Source1의 생성자에서 만들어낸 JFrame을 모두 더한다.
		f.setVisible(true);
	}
}

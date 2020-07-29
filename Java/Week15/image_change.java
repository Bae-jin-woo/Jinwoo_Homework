import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.ImageIO;

public class Source2 extends JPanel implements ActionListener{
	JFrame f;
	JButton b;
	Image[] images = new Image[6];
	int curImageIndex = 0;
	
	String imageName = "C:\\Users\\jw969\\Desktop\\image\\icon";
	public void paintComponent(Graphics g) {	//이미지 그리기
		curImageIndex++;	//다음 이미지 지정
		curImageIndex %= images.length;
		super.paintComponent(g);
		g.drawImage(images[curImageIndex], 0, 0,null);
	}
	
	public Source2() {	//메인 메소드에서  객체를 만들때 호출되므로 생성자에서 미리button을 만든다.
		this.b = new JButton();
		JButton b = this.b;
		b.addActionListener(this);
		b.setText("Press to start the animation");
		this.add(b);
		 for (int i = 0; i < 6; i++) {
		      try {
		         images[i] = ImageIO.read(new File(imageName +(i+1)+ ".jpg"));
		      } catch (IOException e) {
		         // TODO Auto-generated catch block
		         e.printStackTrace();
		      	}   
		      }
		}

	public void actionPerformed(ActionEvent e) {
		curImageIndex++;	//다음 이미지 지정
		curImageIndex %= images.length;
		repaint();
		JButton b = (JButton)e.getSource();
		if(t.isRunning()) {
			t.stop();
			b.setText("Press to start the animation");
		} else {
			t.start();
			b.setText("Press to stop the animation");
		}		
	}
	Timer t=new Timer(200, new ActionListener() {
	      public void actionPerformed(ActionEvent e) {
	    	  repaint();
	      }
	   });
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame f = new JFrame();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(600,300);
		f.setTitle("2015112128 배진우");
		f.add(new Source2());
		
		f.setVisible(true);
	}
}

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JApplet;

public class MoveMessage extends JApplet implements Runnable {
	String str;
	int time;
	private Thread thread;

	public void init() {
		setBackground(Color.PINK);
		str = getParameter("message");
		String timeArg = getParameter("time");
		time = Integer.parseInt(timeArg);
		;
		thread = new Thread(this);
	}

	public void start() {
		thread.start();
	}

	public void run() {
		int x = 0;
		Graphics g = getGraphics();
		while (true) {
			try {
				Thread.sleep(time);
			} catch (Exception e) {
				e.printStackTrace();
			}
			g.clearRect(0, 0, getWidth(), getHeight());
			g.drawString(str, x, 30);
			x += 2;
			if (x >= getWidth())
				x = 0;
		}

	}
}
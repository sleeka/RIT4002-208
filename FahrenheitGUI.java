import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class FahrenheitGUI {
	
	private int WIDTH = 295;
	private int HEIGHT = 150;
	
	private JFrame frame;
	private JPanel panel;
	private JLabel inputLabel, outputLabel, resultLabel;
	private JTextField fahrenheit;
	private JRadioButton toCelsius, toFahrenheit;
	
    public FahrenheitGUI() {
 		frame = new JFrame ("Temperature Conversion");
 		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
 		
 		inputLabel = new JLabel ("Enter Fahrenheit temperature:");
 		outputLabel = new JLabel ("Temperature in Celsius: ");
 		resultLabel = new JLabel ("----");
 		
 		toCelsius = new JRadioButton ("Convert to Celsius", true);
 		toCelsius.setBackground (Color.yellow);
 		toFahrenheit = new JRadioButton ("Convert to Fahrenheit", true);
 		toFahrenheit.setBackground (Color.yellow); 		
 		
 		ButtonGroup group = new ButtonGroup();
 		group.add(toCelsius);
 		group.add(toFahrenheit);
 		toCelsius.addActionListener (new TempListener());
 		toFahrenheit.addActionListener (new TempListener());
 		
 		fahrenheit = new JTextField (5);
 		fahrenheit.addActionListener (new TempListener());
 		
 		panel = new JPanel();
 		panel.setPreferredSize(new Dimension(WIDTH, HEIGHT));
 		panel.setBackground (Color.yellow);
 		panel.add (inputLabel);
 		panel.add (fahrenheit);
 		panel.add (outputLabel);
 		panel.add (resultLabel);
 		panel.add (toCelsius);
 		panel.add (toFahrenheit);
 		
 		frame.getContentPane().add (panel);
    }
    
	public void display(){
		frame.pack();
		frame.show();
	}

	private class TempListener implements ActionListener{
		public void actionPerformed (ActionEvent event){
			int fahrenheitTemp, celsiusTemp;
			Object source = event.getSource();
			String text = fahrenheit.getText();		
			fahrenheitTemp = Integer.parseInt (text);
			if (source == toCelsius){
				inputLabel.setText("Enter Fahrenheit temperature:");
				outputLabel.setText("Temperature in Celsius: ");
				celsiusTemp = (fahrenheitTemp-32)*5/9;		
			}
			else{
				inputLabel.setText("Temperature in Celsius: ");
				outputLabel.setText("Enter Fahrenheit temperature:");
				celsiusTemp = ((9/5)*fahrenheitTemp)+32;
			}
			resultLabel.setText (Integer.toString (celsiusTemp));
		}
	}
}

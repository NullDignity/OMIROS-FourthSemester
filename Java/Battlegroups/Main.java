import java.io.IOException;
// import javax.swing.JOptionPane;

public class Main {
    public static void main(String[] args) {

        Fleet myFleet;

        myFleet = new Fleet("Enterprise");
        myFleet.printFleetDetails();

        System.out.println("Press ENTER to continue...");

        /*
        === JAVA SWING GUI ===
        String name = JOptionPane.showInputDialog("What is your name?");

        String message =
            String.format("Welcome %s, to Java Programming!", name);

        JOptionPane.showMessageDialog(null, message);
        */

        try {
            int key = System.in.read();
        } catch (IOException e) {
            System.out.println("Error");
        }

    }
}
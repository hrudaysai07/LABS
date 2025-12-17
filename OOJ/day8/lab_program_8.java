class BMS extends Thread {
    public void run() {
        try {
          while (true) {
            System.out.println("BMS College of Engineering");
            Thread.sleep(1000);
          }
        }
        catch (InterruptedException e) {
          System.out.println(e);
        }
    }
}
class CSE extends Thread {
    public void run() {
        try {
          while (true) {
            System.out.println("CSE");
            Thread.sleep(2000);
          }
        }
        catch (InterruptedException e) {
          System.out.println(e);
        }
    }
}
public class lab_program_8 {
    public static void main(String[] args) {
        BMS t1 = new BMS();
        CSE t2 = new CSE();
        
        t1.start();
        t2.start();
    }
}

class WrongAgeException extends Exception {
    public WrongAgeException(String message) {
        super(message);
    }
}
class Father{
  public int fatherage;
  public Father(int fatherage) throws WrongAgeException {
    if(fatherage < 0){
      throw new WrongAgeException("Age cannot be negative");
    }
    this.fatherage = fatherage;
  }
}
class Son extends Father {
  public int sonage;
  public Son(int fatherage, int sonage) throws WrongAgeException {
    super(fatherage);
    if(sonage < 0){
      throw new WrongAgeException("Age cannot be negative");
    }
    if(sonage >= fatherage){
      throw new WrongAgeException("Son's age must be less than Father's age");
    }
    this.sonage = sonage;
  }
  public void displayAges() {
    System.out.println("Father's Age: " + fatherage);
    System.out.println("Son's Age: " + sonage);
  }
}
public class lab_program_7 {
  public static void main(String[] args) {
    try {
      Son s1 = new Son(65, 75);
      s1.displayAges(); 
    } 
    catch (WrongAgeException e) {
      System.out.println("Error: " + e.getMessage());
    }
    try {
      Son s2 = new Son(-56, 25);
      s2.displayAges();
    } catch (WrongAgeException e) {
      System.out.println("Error: " + e.getMessage());
    }
    try {
      Son s3 = new Son(43, 18);
      s3.displayAges();
      
    } catch (WrongAgeException e) {
      System.out.println("Error: " + e.getMessage());
    }
    try {
      Son s4 = new Son(50, -5);
      s4.displayAges();
    } catch (WrongAgeException e) {
      System.out.println("Error: " + e.getMessage());
    }
  }
}

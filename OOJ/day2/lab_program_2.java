import java.util.Scanner;
public class lab_program_2 {
  String USN;
  String name;
  int credits[] = new int[10];
  int marks[] = new int[10];

  public void accept(int n){
    Scanner input = new Scanner(System.in);
    System.out.print("Enter USN: ");
    USN = input.nextLine();
    System.out.print("Enter Name: ");
    name = input.nextLine();
    for(int i = 0; i < n; i++){
      System.out.print("Enter credits for subject " + (i+1) + ": ");
      credits[i] = input.nextInt();
      System.out.print("Enter marks for subject " + (i+1) + ": ");
      marks[i] = input.nextInt();
    }
  }
  public void display(int n){
    System.out.println("USN: " + USN);
    System.out.println("Name: " + name);
    System.out.println("Subject\tCredits\tMarks");
    for(int i = 0; i < n; i++){
      System.out.println((i+1) + "\t" + credits[i] + "\t" + marks[i]);
    }
  }
  public void SGPA(int n){
    int total=0;
    int creditsum=0;
    float sgpa=0;
    for(int i=0;i<n;i++){
      total = total + (credits[i] * marks[i]);
      creditsum = creditsum + credits[i];
      sgpa = (float)total / (creditsum*10);
    }
    System.out.printf("SGPA: %.2f%n", sgpa);
  }
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter number of subjects: ");
    int n = input.nextInt();
    lab_program_2 student = new lab_program_2();
    student.accept(n);
    student.display(n);
    student.SGPA(n);
    input.close();
  }
}

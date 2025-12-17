import CIE.*;
import SEE.*;
import java.util.Scanner;

public class lab_program_6 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();

        External[] students = new External[n];
        Internals[] internals = new Internals[n];

        for (int i = 0; i < n; i++) {

            System.out.println("\nEnter details of student " + (i + 1));

            System.out.print("USN: ");
            String USN = sc.next();

            System.out.print("Name: ");
            String name = sc.next();

            System.out.print("Semester: ");
            int sem = sc.nextInt();

            int inMarks[] = new int[5];
            System.out.println("Enter internal marks:");
            for (int j = 0; j < 5; j++) {
                inMarks[j] = sc.nextInt();
            }

            int exMarks[] = new int[5];
            System.out.println("Enter external marks:");
            for (int j = 0; j < 5; j++) {
                exMarks[j] = sc.nextInt();
            }

            internals[i] = new Internals(inMarks);
            students[i] = new External(USN, name, sem, exMarks);
        }
        System.out.println("\nStudent Details with Total Marks:");
        for (int i = 0; i < n; i++) {
            System.out.println("\nStudent " + (i + 1) + ":");
            students[i].display();
            int totalMarks = 0;
            for (int j = 0; j < 5; j++) {
                totalMarks = internals[i].internalMarks[j] + (students[i].externalMarks[j]/2);
                System.out.println("subject" + (j + 1) + " Total Marks: " + totalMarks);
            }
            sc.nextLine();            
        }
        sc.close();
    }
}

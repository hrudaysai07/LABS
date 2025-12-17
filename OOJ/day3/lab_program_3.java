import java.util.Scanner;
public class lab_program_3 {
  private String name;
  private String author;
  private double price;
  private int pages;
  public lab_program_3() {
    this.name="";
    this.author="";
    this.price=0.0;
    this.pages=0;
  }
  public void setname(){
    this.name=name;
  }
  public void setauthor(){
    this.author=author;
  }
  public void setprice(){
    this.price=price;
  }
  public void setpages(){
    this.pages=pages;
  }
  public String getname(){
    return name;
  }
  public String getauthor(){
    return author;
  }
  public double getprice(){
    return price;
  }
  public int getpages(){
    return pages;
  }
  public String ToString(){
    return "Book Name: " + name + "\nAuthor: " + author + "\nPrice: " + price + "\nPages: " + pages;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter number of books: ");
    int n = sc.nextInt();
    lab_program_3[] b = new lab_program_3[n];
    for(int i=0;i<n;i++){
      b[i] = new lab_program_3();
      sc.nextLine();
      System.out.print("Enter name of book " + (i+1) + ": ");
      b[i].name = sc.nextLine();
      System.out.print("Enter author of book " + (i+1) + ": ");
      b[i].author = sc.nextLine();
      System.out.print("Enter price of book " + (i+1) + ": ");
      b[i].price = sc.nextDouble();
      System.out.print("Enter number of pages of book " + (i+1) + ": ");
      b[i].pages = sc.nextInt();
    }
    System.out.println("\nBook Details:");
    for(int i=0;i<n;i++){
      System.out.println("\nBook " + (i+1) + " Details:");
      System.out.println(b[i].ToString());
    }
    sc.close();
  }
}

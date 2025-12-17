import java.util.Scanner;
class Account{
  String cust_name;
  int acc_no;
  String acc_type;
  double balance;
  Account(String cust_name, int acc_no, String acc_type, double balance){
    this.cust_name = cust_name;
    this.acc_no = acc_no;
    this.acc_type = acc_type;
    this.balance = balance;
  }
  void deposit(double amount){
    if(amount > 0){
      balance += amount;
      System.out.printf("Deposited amount:" + amount + "\nNew Balance: " + balance);
    } else {
      System.out.println("Invalid deposit amount.");
    }
  }
  void dis_balance(){
    System.out.println("Account number: " + acc_no);
    System.out.println("Type:" + acc_type);
    System.out.println("Balance: " + balance);
  }
}
class Sav_acct extends Account{
  double interest_rate=0.05;
  Sav_acct(String cust_name, int acc_no ){ 
    super(cust_name, acc_no, "Savings account", 0.0);
    
  }
  void compute_interest(){
    double interest = balance * interest_rate;
    balance += interest;
    System.out.printf("Interest added: " + interest + "\nNew Balance: " + balance);
  }
  void withdraw(double amount){
    if(amount > 0 && amount <= balance){
      balance -= amount;
      System.out.printf("Withdrawn amount: " + amount + "\nNew Balance: " + balance);
    } else {
      System.out.println("Invalid withdraw amount or insufficient balance.");
    }
  }
}
class Curr_acct extends Account{
  double min_balance=1000.0;
  double penalty=100.0;
  Curr_acct(String cust_name, int acc_no ){ 
    super(cust_name, acc_no, "Current account", 0.0);
  }
  void withdraw(double amount){
    if(amount > 0 && amount <= balance){
      balance -= amount;
      System.out.printf("Withdrawn amount: " + amount + "\nNew Balance: " + balance);
      
    } else {
      System.out.println("Invalid withdraw amount or insufficient balance.");
    }
  }
  void check_min_balance(){
    if(balance < min_balance){
      balance -= penalty;
      System.out.printf("Penalty imposed: " + penalty + "\nNew Balance: " + balance);
    } else {
      System.out.println("Minimum balance maintained. No penalty imposed.");
    }
  }
}
public class lab_program_5 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter customer name: ");
    String cust_name = sc.nextLine();
    System.out.print("Enter account number: ");
    int acc_no = sc.nextInt();
    System.out.print("Enter account type : ");
    int acc_type = sc.nextInt();
    System.out.println("Balance:");
    double balance=sc.nextDouble();
    System.out.println("Choose type of account operation \n 1. Savings Account \n 2. Current Account");
    int choice = sc.nextInt();
    if(choice == 1){
      Sav_acct sav = new Sav_acct(cust_name, acc_no);
      sav.deposit(5000);
      sav.compute_interest();
      sav.withdraw(2000);
      sav.dis_balance();
  }
    else if(choice == 2){
      Curr_acct curr = new Curr_acct(cust_name, acc_no);
      curr.deposit(3000);
      curr.withdraw(2500);
      curr.check_min_balance();
      curr.dis_balance();
    } else {
      System.out.println("Invalid choice.");
    }
    sc.close();
  }
}

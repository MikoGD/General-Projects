package bank;

import java.util.Scanner;

public class Atm extends BankSystem{
	Scanner input = new Scanner(System.in);
	
	public void addBalance(User curUser) {
		int balance;
		
		System.out.println("Enter the amount you are depositing");
		balance = input.nextInt();
		balance += curUser.getBalance();
		curUser.setBalance(balance);
	}//END addBalance()
	
	public void minusBalance(User curUser) {
		int balance;
		
		System.out.println("Enter the amount you are withdrawing");
		balance = input.nextInt();
		balance -= curUser.getBalance();
		curUser.setBalance(balance);
	}//END addBalance()
}//END CLASS Atm

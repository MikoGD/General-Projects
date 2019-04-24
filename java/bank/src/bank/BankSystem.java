package bank;

import java.util.Scanner;

public class BankSystem {
	static String bankName = "Lion Bank";
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		Database database0 = new Database();
		Atm lionAtm = new Atm();
		
		displayMenu();
		
	}//END main()
	
	private static void displayMenu() {
		System.out.println("Welcome to Lion Bank");
		System.out.println("Option 1: Open ATM");
		System.out.println("Option 2: Log in");
		System.out.println("Option 3: Register new account");
	}//END displayMenu()
	
	private static String getUserInput() {
		String userInput = input.nextLine();
		
	}//END getUserInput()
	
	protected void makeNewAccount(Database database0) {
		String firstName;
		String surname;
		String username;
		String pin;
		float balance;
		
		System.out.println("Enter your first name: ");
		firstName = input.nextLine();
		System.out.println("Enter your second name: ");
		surname = input.nextLine();
		System.out.println("Enter your PIN: ");
		pin = input.nextLine();
		System.out.println("Enter your balance: ");
		balance = input.nextFloat();
		username = firstName + surname;
		
		database0.setNewUsername(username);
		database0.setNewPin(pin);
		database0.setNewBalance((int) (balance * 100));
	}//END makeNewAccount()
}//END CLASS BankSystem

class Database {
	private String[] usernames = new String[100];
	private String[] pins = new String[100];
	private int[] balances = new int[100];
	
	private int usernameTracker = 0;
	private int pinTracker = 0;
	private int balanceTracker = 0;
	
	static int databaseTracker = 0;
	
	public String[] getUsernames() {
		return usernames;
	}//END getuserNames()
	
	public void setNewUsername(String username) {
		this.usernames[this.usernameTracker] = username;
		this.usernameTracker++;
	}//END setUsernames()
	
	public String[] getPins() {
		return pins;
	}//END getPins()
	
	public void setNewPin(String pin) {
		this.pins[this.pinTracker] = pin;
		this.pinTracker++;
	}//END setPins()
	
	public int[] getBalances() {
		return balances;
	}//END getBalances()
	
	public void setNewBalance(int balance) {
		this.balances[this.balanceTracker] = balance;
		this.balanceTracker++;
	}//END setBalances
}//END CLASS Database

package bank;

public class User {
	short pinSize = 4;
	
	private String firstName;
  private String secondName;
  private char[] userPin = new char[pinSize];
  private int balance;
  private int[] tryAttempts = {0, 0};
  
	public String getFirstName() {
		return firstName;
	}//END getFirstName()
	
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}//END setFirstName()
	
	public String getSecondName() {
		return secondName;
	}//END getSecondName()
	
	public void setSecondName(String secondName) {
		this.secondName = secondName;
	}//END setSecondName
	
	public char[] getUserPin() {
		return userPin;
	}//END getUserPin()
	
	public void setUserPin(char[] userPin) {
		this.userPin = userPin;
	}//END setUserPin()
	
	public int getBalance() {
		return balance;
	}//END getBalance()
	
	public void setBalance(int balance) {
		this.balance = balance;
	}//END setBalance()
	
	public int[] getTryAttempts() {
		return tryAttempts;
	}//END getTryAttempts()
	
	public void setTryAttempts(int[] tryAttempts) {
		this.tryAttempts = tryAttempts;
	}//END setTryAttempts();
}//END CLASS User

class User extends Atm{
  private String firstName;
  private String secondName;
  private char[] userPin = new char[pinSize];
  private float balance;
  private int[] tryAttempts = {0, 0};

  public User (String firstName, String secondName, char[] userPin, float balance) {
    this.firstName = firstName;
    this.secondName = secondName;
    this.userPin = userPin;
    this.balance = balance;
  }//END CONSTRUCTOR

  public static void displayUserMenu() {
    System.out.println("Option 1: Deposit cash/cheque");
    Sytsem.out.println("Option 2: Withdraw cash");
    System.out.println("Option 3: Transaction history");
    System.out.println("Option 4: To change PIN");
    System.out.println("Option 5: To check amount of times code entered correctly");
  }//END displayUserMenu()

  public static void changePin() {
    String userInput, newPin, newPinConfirm;

    System.out.println("Enter your PIN: ");
    userInput = input.nextLine();
    char[] userInputArray = userInput.toCharArray();

    if(comparePins(userInputArray)) {
      System.out.println("Enter new PIN: ");
      newPin = input.nextLine();
      System.out.println("Confirm your new PIN: ");
      newPinConfirm = input.nextLine();

      if(this.comparePins(this.userPin, userInput)) {
        System.out.println("New PIN confirmed");
        System.out.println("Your PIN has been changed");

        System.arraycopy(newPinConfirm, 0, this.userPin, 0, pinSize);
    } else {
        System.out.println("The PINs you entered did not match\nYour PIN was not changed");
    }
    } else {
      System.out.println("Wrong PIN entered");
    }//END IF
  }//END changePin()

  public static void addToBalance() {
    float balanceToAdd;

    System.out.println("Enter the amount you want to add to your balance: ");
    balanceToAdd = input.nextFloat();

    this.balance += balanceToAdd();
  }//END addToBalance()

  public static void minusFromBalance() {
    float balanceToMinus;

    System.out.println("Enter the amount you want to take away from your balance: ");
    balanceToMinus = input.nextFloat();

    this.balance -= balanceToAdd();
  }//END addToBalance()

  public void getFirstName() {
    return firstName;
  }//END getFirstName()

  public void getSecondName() {
    return secondName;
  }//END getSecondName;

  public void setFirstname(String newFirstName) {
    firstName = newFirstName;
  }//END setFirstName();

  public void setSecondName(String newSecondName) {
    secondName = newSecondName;
  }//END setSecondName()

  public void setUserPin(char[] newUserPin) {
    System.arraycopy(newUserPin, 0, userPin, 0, pinSize);
  }//END setUserPin

  public void setBalance (float newBalance) {
    balance = newBalance;
  }//END setBalance();
}//END CLASS User

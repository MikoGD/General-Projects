import java.util.Scanner;
import java.util.Arrays;

public class Atm {
  short pinSize = 4;
  private char[] defaultPin = {'1', '2', '3', '4'};

  Scanner input = new Scanner(System.in);

  public Atm() {

  }//END DEFAULT CONTRSUCTOR

  public void main(String[] args) {
    Atm atm = new Atm();

    do {
      atm.displayMenu();
    } while (atm.runOptionFromMenu());
  }//END main()

  private void displayMenu() {
    System.out.println("welcome To The Bank");
    System.out.println("Option 1: Log in");
    System.out.println("Option 2: Register new account");
    System.out.println("Option 3: To exit\n");
    System.out.println("Option: ");
  }//END displayMenu()

  private String getUserInput() {
    short i;
    String userInput;

    userInput = input.nextLine();

    for(char literal: userInput.toCharArray()) {
      if(Character.isDigit(literal)) {
        continue;
      } else {
        System.out.println("ERROR: Invalid input");
        return userInput;
      }//END IF
    }//END FOR

    return userInput;
  }//END getUserInput()

  private boolean runOptionFromMenu() {
    char[] userInput = getUserInput().toCharArray();

    if(userInput.length > 1) {
      System.out.println("Only input from the menu can be entered\n");
      return true;
    }//END IF

    switch(userInput[0]) {
      case '1':
        System.out.println("Entered 1\n")
        break;
      //END CASE

      case '2':
        System.out.println("Entered 2\n")
        break;
      //END CASE

      case '3':
        System.out.println("Exiting program...");
        System.out.println("Goodbye\n");
        return false;
      //END CASE

      default:
        System.out.print("ERROR: invalid input\nOnly input from the menu can be entered\n");
        return true;
      //END DEFAULT
    }//END SWITCH

    return true;
  }//END runOptionFromMenu

  public static boolean comparePins(char[] pin1, char[] pin2) {
    if(Arrays.equals(pin1, pin2)) {
      return true;
    } else {
      return false;
    }//END IF
  }//END comparePins()

  public char[] getDefaultPin() {
    return defaultPin;
  }
}//END CLASS Atm

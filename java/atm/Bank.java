public class Bank {

  private Bank() {

  }//END DEFAULT CONSTRUCTOR

  public static void main() {
    Database database0 = new Database();
    Atm curAtm = new Atm();
  }//END main()
}//END CLASS Bank

class Database {
  private char[] usernames = new char[100];
  private char[] pins = new char[100];
  private int[] balances = new balances[100];
  static int databaseTracker = 0;

  public Database() {
    databaseTracker++;
  }//END CONSTRUCTOR

  private char[] getUsernames() {
    return usernames;
  }//END getUsernames()

  private char[] getPins() {
    return  pins;
  }//END getPins()

  private char[] getBalances() {
    return balances;
  }//END getBalances()

  private char[] setUsernames(int index, String newUsername) {
    usernames[index] = newUsername;
  }//END setUsernames()

  private char[] setPins(int index, String newPin) {
    pins[index] = newPin;
  }//END setPins()

  private char[] setBalances(int index, float newBalance) {
    balances[index] = newBalance
  }//END setBalances()
}//END CLASS DATABASE

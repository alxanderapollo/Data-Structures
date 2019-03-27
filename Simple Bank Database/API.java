/*
 * This is the interface file 
 * Written By Alexander Apollo Salazar
 * Data Structures 313 
 * 2/19
 */
public interface API {
	
//------------->These are all the methods for the checking account<--------------- 
	//takes a checking account number for verification, and the amount to deposited into the account
	//returns a string to determine whether or not the transaction was successful
	public String deposit(String CheckingAccNum, double amount);
	
	//takes a checking account number for verification, and the amount to be withdrawn from the account
	//returns a string to determine whether or not the transaction was successful
	public String withdraw(String CheckingAccNum, double amount);
	
//-------------->Credit card  Account methods<------------------------	
	
	//takes a Credit account number for verification, and the amount to be used from the Credit Card account
	//returns a string to determine whether or not the transaction was successful
	public String useCredit(String creditAccNum, double amount);
	
	//takes a Credit account number for verification, Checking account number and the amount to be paid back into the Credit Card account
	//returns a String that determines whether or not the transaction was a success
	 public String payCreditCard(String creditAccNum,  String accNum, double amount);
}

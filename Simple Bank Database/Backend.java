/*
 * Written by Alex Salazar
 * 2/18/2019
 * DATA structures 313 
 * Professor Jinqiu Liu
 * Project one
 */

import java.util.Random;
import java.util.Collection;
import java.util.HashMap;
public class Backend  {
	
	
	//Array list of objects representing all the members
	private ArrayList<BankAccount> AccList;
	
	//hash map to store arraylist
	private HashMap<String, Integer>hashMap;
	
	int size = 0;
	//will log each transaction
	private String recordLog = "";
	
	
	public Backend() {
		AccList = new ArrayList<BankAccount>();
		hashMap = new HashMap<String, Integer >();
	}
	
	public void read(String[] array) {
		
		//read input from file, receives an array
		//each switch case calls a method either Add account, pay credit card, 
		//deposit funds, withdraw funds, use credit card or Delete an account
		switch(array[0]) { 
		case "ADD":
			addPerson(array[1], array[2], array[3], array[4],array[5]);
			break;
			
		case "DEP":
			 deposit(array[1], array[2]);
				break;
				
		case "WID":
				withdraw(array[1], array[2]);
			break;
		
		case "PAY":
			payCreditCard(array[1], array[2]);
		break;	
		
		case "USE":
			useCreditCard(array[1], array[2]);
			break;	
		case "DEL":
			removeAccount(array[1]);
			break;
		}
	}// end read file
		
	//Add
	// all the parameters for creating an object w/ or without a Credit account are passed to create the object
	public  void addPerson(String firstName, String lastName, String SSN, String balance, String creditBalance) {
		//1. Create the object w/ all the user info
		//parse string values into double.
			double temp, temp1;
			temp = Double.parseDouble(balance);
			temp1 = Double.parseDouble(creditBalance);
		BankAccount accMember = new BankAccount (firstName, lastName, SSN, temp, temp1 );
		//2 check if the member is already inside the map
		if(hashMap.containsKey(accMember.getSSN())) {
			
			//---------------------------------------------->log it already exists------------------------->
			recordLog += "Checking Account Already exists: "+ accMember.getFirstName()+ " "+accMember.getLastName()+" Continuing to the next one."+ "\n";
			
			return;
		//3 if it doesn't add it to the database
		}else
			 //put it in the hash map using a the unique mapping of the Users SSN #
			 hashMap.put( accMember.getSSN(), AccList.addAccount(accMember));
			size++;
			
			//log Value -------------------------------------------------------------------------------------------------->
			recordLog+= "Successfully Created account with name: "+ accMember.getFirstName()+ " "+ accMember.getLastName()+
					" Checking Account number: "+accMember.getCheckingAccNum() +" \n";
	}//end add person
	
	
//<--------------------------------------------------------------------Modification Methods ---------------------------------------------> 
	public void deposit(String SSN, String transaction) {
		
		//user index  allows us to access class bank account methods from the hashMap into the arrayList into the bankAccount class
		//1. pass social security number to identify the user and use it as index inside both the hash Map and array list
		Integer userIndex = hashMap.get(SSN);
		
		/*2. Use temp vars to access each individual members information for modification 
		    -->Checking account will equal the member unique checking account # which is attached to a specific SSN #
		  	-->Tran or transaction will represent the value to be inserted into the account. 
	     */
		String checkingAccount = AccList.getAccount(userIndex).getCheckingAccNum();
		//transactions converted to a double 
		double tran = Double.parseDouble(transaction);
		
		
		//----> Call BankAccount's  deposit method which takes the checking account and transaction parsed value
		AccList.getAccount(userIndex).deposit(checkingAccount, tran);
		
		//--------------------------------------------------------->Log the changed value<--------------------------------------------------
		recordLog+= AccList.getAccount(userIndex).getFirstName() +": Successfully Deposited $:"+transaction+ " into Checking Account #: "+AccList.getAccount(userIndex).getCheckingAccNum()+
		" Remaining balance: "+AccList.getAccount(userIndex).getcheckingBal() +" \n";			
	}// end deposit
	
	public void withdraw(String SSN, String transaction) {
		//1. find user in the hash Map 
		Integer userIndex = hashMap.get(SSN);
		//2. get users checking  account from the arraylist 
		String checkingAccount = AccList.getAccount(userIndex).getCheckingAccNum();
		//3. parse the value which represents the amount to be withdrawn into a double
		double tran = Double.parseDouble(transaction);
		//4.--------------> Call BankAccount's  withdraw method which takes the checking account and transaction parsed value
		AccList.getAccount(userIndex).withdraw(checkingAccount, tran);
		//.5 -------------------------------------->log the successful transaction
		recordLog+= AccList.getAccount(userIndex).getFirstName() +": Successfully Withdrawn $"+transaction+ " from Checking  account #: "+AccList.getAccount(userIndex).getCheckingAccNum()+
				" Remaining balance: "+AccList.getAccount(userIndex).getcheckingBal() +" \n";
		
		
	}// end withdraw
	
	public void payCreditCard(String SSN, String transaction){	
		//1. find user in the index
		Integer userIndex = hashMap.get(SSN);
		//2. get users checking, and Credit account # 
		String checkingAccount = AccList.getAccount(userIndex).getCheckingAccNum();
		String creditAccount = AccList.getAccount(userIndex).getCreditAccNum();
	    //3. parse the value which represents the amount to be withdrawn into a double
		double tran = Double.parseDouble(transaction);
		//4.--------------> Call BankAccount's  withdraw method which takes the checking account and transaction parsed value
		AccList.getAccount(userIndex).payCreditCard(creditAccount,checkingAccount,tran );
		//.5 -------------------------------------->log the successful transaction
		recordLog+= AccList.getAccount(userIndex).getFirstName() +": Successfully Made a payment of$: "+transaction+ " To Credit Account #: "+AccList.getAccount(userIndex).getCreditAccNum()+
				" Remaining Credit balance: "+AccList.getAccount(userIndex).getCreditBal()+  "  Remaining Checking  balance: "+AccList.getAccount(userIndex).getcheckingBal() +" \n";
	}// end payCreditCard
	
	
	//write this method in the members class
	public void useCreditCard(String SSN, String transaction) {
		//1. find user in the index
		Integer userIndex = hashMap.get(SSN);
		//2. get users Credit Card number
		String creditAccount = AccList.getAccount(userIndex).getCreditAccNum();
		//3. parse the value which represents the amount to be used as Credit into a double
		double tran = Double.parseDouble(transaction);
		//4.--------------> Call BankAccount's  useCredit method which takes the checking account and transaction parsed value
		AccList.getAccount(userIndex).useCredit(creditAccount, tran);
		//.5 -------------------------------------->log the successful transaction
		recordLog+= AccList.getAccount(userIndex).getFirstName() +": Successfully Used Credit amount of: "+transaction+ " Remaining Credit: "+ 
		(AccList.getAccount(userIndex).getCreditLimit() -AccList.getAccount(userIndex).getCreditBal())+ " Credit Balance: "+AccList.getAccount(userIndex).getCreditBal() +" \n";
		
	}//end useCredit Card
	
	 public void removeAccount(String SSN) {
		 //1.find user in the index 
		 Integer userIndex = hashMap.get(SSN);
		//2. removve user from hash and arra
		 hashMap.remove(userIndex,AccList.removeElementAt(userIndex));
		 //3. log that the user has been removed <-----------------------------------------------
		 recordLog += "Successfully Deleted Account number: "+ AccList.getAccount(userIndex).getCheckingAccNum()+ " Name: "+ AccList.getAccount(userIndex).getFirstName() +
				 ", "+AccList.getAccount(userIndex).getLastName()+" Has been removed.\n" ;
	 }// remove account
	 //print all stored information
	 public String printAllAccounts() {
		 return AccList.toString();
	 }
	 //returns all the logged information
	 public String returnLoggedInfo() {
		 return recordLog;
	 }
	 
	
}//end class

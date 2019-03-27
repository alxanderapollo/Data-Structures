/*
 * Written by Alex Salazar
 * 2/18/2019
 * DATA structures 313 
 * Professor Jinqiu Liu
 * Project one
 * 
 *  WARNINIG CREDIT ACCOUNT NUMBER AND CHECKING ACOUNT NUMBER IS GENERATED WHEN A NEW ACCOUNT IS MADE, THEREFORE A USER CANNOT
 * CREATE AN ACCOUNT NUMBER
 * 
 */

import java.util.Random;

public class BankAccount extends Members implements API {
	
	//Credit and checking account #
	  private String creditAcc, checkingAcc;
			
	//Checking and credit balance, which is the running total on the amount used from the credit set. 
	  //(creditSet - creditSpent) = creditBalance
	  private  double balance, creditBalance, creditLimit; 
	  
	  
	  public BankAccount() {
		// null the objects in the super class
		super(null,null,null);
		// credit and account balance
		this.balance = 0.00;
		this.creditBalance = 0.00;
				
		//account numbers
		this.creditAcc = null;
		this.checkingAcc = null;	
		}
			
	 //checking Balance 
	  public BankAccount(String firstName, String lastName, String SSN, double bal) {
		super(firstName, lastName, SSN);
		this.balance = bal;
		this.checkingAcc = createcheckingAccountNum();//randomly generated number
	   }
	  //create credit account balance 
	  public BankAccount(String firstName, String lastName, String SSN, double bal, double credLimit) {
		super(firstName, lastName, SSN);
		this.balance = bal;
		this.creditBalance = 0.00;
		this.creditLimit = credLimit;
		//randomly generated number makes it unique to each account
		this.checkingAcc = createcheckingAccountNum();
		this.creditAcc = createCreditAccountNum();
	
	  }
			
	//set methods
	  public void setCheckingBalance(double bal) {
	    this.balance = bal;
	 }
	  public void setCreditBalance(double calBalance) {
	    this.creditBalance = calBalance;
	 } 
	 public void setCreditLimit(double credLim) {
		 this.creditLimit = credLim;
	 }
			
	 //get methods
	 public String getCreditAccNum() {
	   return this.creditAcc;
	 }
	 public String getCheckingAccNum() {
	   return this.checkingAcc;
	 }
	 public double getcheckingBal() {
		   return this.balance;
	 }
	 //credit balance, limit and spent
	 public double getCreditBal() {
	   return this.creditBalance;
	 }
	 public double getCreditLimit() {
		 return this.creditLimit;
	 }
			
	 //these methods will generate account and credit numbers randomly
	 private String createcheckingAccountNum() {
	 //temp varaible to hold the random account number that will be generated
	   String temp = "";
	   Random rand = new Random();
						
	   for(int i = 0;i <6; i++) {
	   int randomInt = rand.nextInt(10);
	   temp+= Integer.toString(randomInt);
	   }// end for
	   return temp;
	  }//end createAccountNum
	 
	 private String createCreditAccountNum() {
	 //temp varaible to hold the random generated credit account number that will be generated
	   String temp = "";
	   Random rand = new Random();
						
		for(int i = 0;i <6; i++) {
		int randomInt = rand.nextInt(10);
		temp+= Integer.toString(randomInt);
		}// end for
		return temp;	
	 }// end createCreditAccountNum
	 
	 //toString
	 public String toString() {
		 
		 String temp = "";
		 temp +=  super.toString();
		 temp += " \nChecking Account Number: "+this.checkingAcc+ 
					" \nCredit Account Number: "+this.creditAcc+ " \nChecking Account Balance: "+String.valueOf(this.balance)+
					"\nCredit Account Balance: "+String.valueOf(this.creditBalance)+" \n"+"Credit Limit : "+String.valueOf(this.creditLimit)+ "\n";
	    return temp; 
	 }
	 
	 
	 
	//--------------------->API(INTERFACE) METHODS<-----------------------
	public String deposit(String accnum, double amount) {
				
	 //if the amount is a negative value  throw illegal argument except 
	      if(amount<0) 
				throw new IllegalArgumentException("no negative values, only pos");
	      //authenticate account
		  if(!accnum.equals(this.checkingAcc))
			   throw new IllegalArgumentException("Incorrect Account number");
			
		  //temp varaibles
			 double temp = 0;
		  // temp 2 will hold balance value
			 double temp2 =this.balance;
		  //add everything to a result varaible
			 double result = 0;
			 temp = amount; //the amount being sent
			 result = temp+temp2;
				
		  //update check balance
			 this.balance = result;
			return "Succesfully added: "+ amount+ " for a total account blance of: "+result;	
	   }// end deposit 
			
    public String withdraw(String accnum, double amount) {
		//create interface to enter checking account number manually GUI
		 if(!accnum.equals(this.checkingAcc))
			throw new IllegalArgumentException("Incorrect Account number"); 
			//Authenticate Account number	
			if(this.balance<=0 && this.balance< amount ) 
			throw new IllegalArgumentException("insuficent funds");
				
				double temp = 0;
				//temp 2 will hold balance value
				double temp2 =this.balance;
				//subtract everything to a result varaible
				double result = 0;
				temp = amount; //the amount being sent
				result = temp2-temp;
						
				//update check balance
				this.balance = result;
				return "Succesfully added: "+ amount+ " for a total account blance of: "+result;
			}
	public String payCreditCard(String creditAcc, String accountNum, double amount) {
		
		//1.Authenticate Account
		 if(!accountNum.equals(this.checkingAcc) && !creditAcc.equals(this.creditAcc) ) throw new IllegalArgumentException("Incorrect Account number");
		 //2. verify that the payment is not <= 0 
		 if(amount <= 0) throw new IllegalArgumentException("No negative Values");  
		 //3. check that the user has insufficient funds in the account 
		  if( this.getcheckingBal() < amount)  throw new IllegalArgumentException("insufficient funds ");
		  //4. Perform Transaction
		  //take money from checking account
		  this.balance = this.balance- amount;
		  //use the amount to pay off Credit Balance
		  this.creditBalance = this.creditBalance - amount; 
		 
			return "Succesffuly paid" + amount+ " Reamining Balance: "+ this.creditBalance;
				
	}//end pay credit card
	
	//use Credit Card 
	public String useCredit(String creditAccNum, double amountUsed) {
		//1.Authenticate Account
		 if(!creditAcc.equals(this.creditAcc) ) throw new IllegalArgumentException("Incorrect Account number"); 
		 //2.check that user is using credit within limits
		 //prompt user of insufficient funds, adjust value or deposit more money. 
		   if(amountUsed > this.getCreditLimit()) throw new IllegalArgumentException("You're are using way more than you have as a limit, try a smaller value, your limit is "+ this.creditLimit);
		 //3.no negative values only greater than zero values
		   if(amountUsed <= 0) throw new IllegalArgumentException("No negative Values");
		 //4. Credit balance cannot exceed limit 
		    if(this.creditBalance == this.creditLimit) throw new IllegalArgumentException("you've maxed your card "+ this.creditBalance);
		    
		   this.creditBalance += amountUsed;
		   
		return "Amount used in this transaction is :"+ amountUsed+ " Credit Balance: "+ this.creditBalance+ "Credit Left: "+ (this.creditBalance - this.creditLimit); 
	}
			
					
			
			
			
			

}

/*
 * Written by Alex Salazar
   2/18/2019
   DATA structures 313 
   Professor Jinqiu Liu
    Project one
 *
 * 
*/
public class Members {
	
		//clients first and last name, social security #
		private String firstName, lastName, SSN;
		
		
		//default constructor
		public Members() {
			//personal info
			this.firstName = null;
			this.lastName = null;
			this.SSN = null;
		}
		public Members(String first, String last,String ssn) {
			//personal info
			this.firstName =first;
			this.lastName = last;
			this.SSN = ssn;
		}
		//set methods
		public void setFirstName(String Name) {
			this.firstName = Name; 
		}
		public void setLastName(String surName) {
			this.lastName = surName;
		}
		public void setSSN(String ssn) {
			this.SSN = ssn;
		}
		
		//get methods
		public String getFirstName() {
			 return this.firstName;
		}
		public String getLastName() {
			return this.lastName;
		}
		public String getSSN() {
			return this.SSN;
		}
		
		
		//Returns all the account information
		public String toString() {
			
			return "\nFirst Name: " +this.firstName+
			" \nLast Name: "+this.lastName+" \nSocial Security number: "+this.SSN;
			
		}
		
		
		
	}//end class
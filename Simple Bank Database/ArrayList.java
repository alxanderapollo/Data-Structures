/*
 * Written by Alex Salazar
 * 2/18/2019
 * DATA structures 313 
 * Professor Jinqiu Liu
 * Project one
 */
public class ArrayList <S>{
	
	
	//The max size of the array
	final private int defaultMaxSize = 15;
	//size
	private int size;
	//Account members 
	private  S  []data;
	
	//default constructor
	public ArrayList() {
		//cast as an object
		data = (S[]) new Object[defaultMaxSize]; 
		this.size = 0;
	}
	//construct with a desired array list with specified size
	public ArrayList(int size) {
		data = (S[]) new Object[size];
				this.size = 0;
	} 
	//check if the array is empty
	public boolean isEmpty() {
		return size == 0;
	}
	//check size of the array
	public int getSize() {
		return this.size;
	}
	
	//increase size to make the array list dynamic
	private void increaseSize() {
		//increase by length and multiply by two
		//create a new array with the existing array capacity
		//add ten more
		S[] newArray = (S[]) new Object [data.length + defaultMaxSize*2];
		//copy all the elements from the old array into the bigger
		//container
		for(int i = 0; i< size; i++) {
			newArray[i] = data[i];
		}
		//make the old array point to the old one.
		data = newArray;
	}
	
	//creates new accounts and adds them 
	public int addAccount(S member) {
		//create member object with client info 
		//if the size  of the array is less than
		// the array length, add the obj to the end of the array
		if(size < data.length) {
			data[size++] = member; //add to the following postion (end of the array)
		}else {
			// otherwise call increaseSize method to increase the  size of the array
			//and place the item at the end of the array 
			increaseSize();
			data[size++] = member;
		}
		return size-1; //returns postion of the added item. 	
	}
	
	// returns an account at a specfic address
	//with a toString method displaying all the contents of the OBJECT
	//change this method
	public int contains(Object o) {
		for( int i = 0; i < size; i++ ) {
			if( data[i].equals(o) )
				return i;
		}
		return -1;
	}
	
	
	public S getAccount(int i) {
		//if the index sent i
		try {
			return data[i];
		}catch(ArrayIndexOutOfBoundsException e) {
			return null;
		}
		
	}
	//check if there is anything in the array
	
	//replace an element at a specified location
	//index is passed by the user representing such positions
	//Object is element to be placed within the array
	public S replaceElementAt(int index, S Object) {
		//check that index is bounded from zero to one  number less than size
		//replace at index, and return the object removed
		//null if no object was replaced. 
		if(index >= 0 && index < size) { 
			S temp = data[index];
			data[index] = Object;
			return temp;
			}
			else
				return null; //if failed to replace object return null
		}//end of set method
	
	// remove at a specific postion
	public S removeElementAt(int index) {
		if( index >= 0 && index < size ) {
			S temp = data[index];
			for(int i = index; i < size-1; i++ ) 
				data[i] = data[i+1]; 
			size--;// decrement size when element is removed
			return temp;
		}
		return null;	
	}// end of RemoveElement At
	
	//prints all the stored objects
	public String toString() {
		String temp = "";// hold all the objects  
		for( int i = 0; i < size; i++) {
			temp += data[i];
		}
		return temp;//return all the objects as a string 
	}
	
	
}// end of array list method
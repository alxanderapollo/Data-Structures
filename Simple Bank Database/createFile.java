/* 
Written by Alex Salazar
 * 2/18/2019
 * DATA structures 313 
 * Professor Jinqiu Liu
 * Project one
 */

import java.io.IOException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
public class createFile {
	
	PrintWriter out;
	String fileName;// file to be sent 
	  public createFile(String fileName) {
	    try {
	      out = new PrintWriter(new FileWriter(fileName)); //wrap file writer with the print writer
	      this.fileName = fileName;
	    } catch (IOException e) {
	      System.out.println("Failed to open file " + fileName);
	    }    
	  }
	  //recvies a string and then prints to a file 
	  public void writeLine(String o) {
	    try {
	      out.println(o);
	    } catch (NullPointerException np) {
	      System.out.println("Must first initiate the file writer");
	    }
	  }
	  //close file method
	  public void close() {
	    try {
	      out.flush(); //In case something got stuck in the buffer
	      out.close(); //Properlly close the file and release control
	    } catch (NullPointerException np) {
	      System.out.println("Must first initiate the file writer");
	    }
	  }

}

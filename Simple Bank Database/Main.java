import java.io.*;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
public class Main {

	public static void main(String [] alex) {
        // The name of the file to open.
        String fileName1 = "input.txt";
        //resulting accounts
        String fileName2 = "results.txt";
        // log file
        String fileName3 = "log.txt";

        // This will reference one line at a time
        String line = null;
        
        //call backEnd class
        Backend one = new Backend();
        //String to hold all of the content read from input file
        String temp = ""; 

        try {
        		// FileReader reads text files in the default encoding.
	            FileReader fileReader = 
	                new FileReader(fileName1);
	
	            //  wrap FileReader in BufferedReader.
	            BufferedReader bufferedReader = 
	                new BufferedReader(fileReader);
	
	            while((line = bufferedReader.readLine()) != null) {
	                //System.out.println(line);
	            	temp+= line+ "\n";  	
            }   

            // close files.
            bufferedReader.close();         
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                "Unable to open file '" + 
                fileName1 + "'");                
        }
        catch(IOException ex) {
            System.out.println(
                "Error reading file '" 
                + fileName1 + "'");                  
        }
   
        //this array will hold 6 words at a time
        String [] temp1 = new String [6];
        //tokenizer to break long string into individual words
        StringTokenizer st = new StringTokenizer(temp);
        //count for the array
        int i = 0;
        
        //while loop to break string into individual words
        while (st.hasMoreTokens()) {
            //each letter will temporarily  hold one of the six words in the input.
            String a = st.nextToken();
			String b = st.nextToken();
			String c = st.nextToken();
			String d = st.nextToken();
			String e = st.nextToken();
			String f = st.nextToken();
			
			//each position  will hold one word from the input
			 temp1[i] = a; i++;
			 temp1[i] = b; i++;
			 temp1[i] = c; i++;
			 temp1[i] = d; i++;
			 temp1[i] = e; i++;
			 temp1[i] = f; i++;
			 //Passes the parameters to either make an account, make payment deposit, etc.
			 one.read(temp1);
			 ///reset counter to start at zero and restart process
			 i = 0;  
      }//end while
       
        //check if objects are being made
       //System.out.println(one.printAllAccounts());
        
        //create results file 
        createFile resultsOutPut = new createFile(fileName2);
        resultsOutPut.writeLine(one.printAllAccounts());
        resultsOutPut.close();
        
        //create LOG FILE 
        createFile logOutPut = new createFile(fileName3);
        logOutPut.writeLine(one.returnLoggedInfo());
        logOutPut.close(); 
   }//end main
}// end class 

/*
 * this is the main file of the binary tree and binary search tree
 *
 * 11/7
 * author Alexander Apollo Salazar
 * Notes: The purpose of this program is to read in file of text,
 * and output The lexicon in a report along with summary analysis of its contents
 */
#include "BSTreeImp.cpp"
#include "BtreeImp.cpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int totalNodes = 0; //count for all the nodes
int totalCharacterLength = 0; // will hold all the characters found in every word.
int totalWords = 0; // will keep count of the number of words.
int totalSentences = 0;// will count the number of sentences.
int avgWordlength = 0;  //Average word Length.
int avgSentenceLength = 0; // Average Sentence Length.
int wordsMoreThanThree = 0; //summing words that are more than three letters.
int uniqueWords = 0;// unique node count

//necessary decelerations for print Index
bool flag = false;
char i;

//stream objects
ifstream inputFile;// file to be opened & analyzed.
ofstream outputFile("Results.txt");// file to contain report.

//functions
void Statistics();
void collectData(std::string&, int&); //collects the count of words, and sums up the overall text
void wordsTooOften(string&,int&); //function to be passed to another function
void printIndex(std::string& info, int& count); // function to print index

int main(){
		//test class
		Statistics();
	return 0;
}
void Statistics(){

	string fileName;// name entered by user.
	string word; // will hold the string
	BStree<string> Tree; // Search tree to hold the first set of sentences.


	//prompt user to enter name of file
	cout<<"Please enter the name of the file followed by .txt\n"<<endl;
	cin>>fileName;

	// open file
	inputFile.open(fileName);

	// reading file
	if(inputFile.fail()){
		cout <<"File name must be incorrect or Not placed in folder";
		return;
	}
	else {
		while(inputFile>>word){
			// count the number of sentences
			for(char& c:word) {
			  if(c == '.'||c=='?'||c=='!')
				  totalSentences++;
			}
			// words longer than 3 letters add to unique words
				if(word.length()>3){
			    wordsMoreThanThree++;
				}
				//Before insertion, delete any commas, exclamation points...etc
				word.erase(remove(word.begin(), word.end(), ','), word.end());
				word.erase(remove(word.begin(), word.end(), '.'), word.end());
				word.erase(remove(word.begin(), word.end(), '!'), word.end());
				word.erase(remove(word.begin(), word.end(), '?'), word.end());
				word.erase(remove(word.begin(), word.end(), ';'), word.end());
				transform(word.begin(), word.end(), word.begin(), ::tolower);

				totalWords++; // every time there's a word add to total sum
				totalCharacterLength+=word.length();

				//insert
				Tree.insert(word);
		}
	}
	inputFile.close();
	inputFile.clear();

	//get total nodes & total length.
	Tree.InOrder(collectData);



	// note results.txt file is not saving to BinarySearch Tree folder, found using search bar.

	//average  = all the words divided by # of sentences
	avgSentenceLength  = (totalNodes/totalSentences);
	avgWordlength = (totalCharacterLength/totalWords);
	outputFile<<"FILE NAME: "<<fileName;



	outputFile<<" \n"<<"Total number of words: "<<totalWords<<endl;
	outputFile<<"Total # of unique words: "<<uniqueWords<<endl;
	outputFile<<"Total # of unique words with more than 3 letters: "<<wordsMoreThanThree<<endl;
	outputFile <<"Total number of sentences: "<<totalSentences<<endl;
	outputFile <<"Average sentence length: "<<avgSentenceLength<<endl;
	outputFile<<"Average word length: "<<avgWordlength<<endl;

    //Style warnings

    if(avgSentenceLength>10){
    	outputFile<<"\n"<<"AVERAGE SENTENCE LENGTH TOO LONG: "<<avgSentenceLength<<endl;
    }
    if(avgWordlength>5){
    	outputFile<<"AVERAGE WORD LENGTH TOO LONG : "<<avgWordlength<<endl;
    }

    //printing words used more than 5 percent
    Tree.InOrder(wordsTooOften);

    //printing index of words
    Tree.InOrder(printIndex);


	return;
 }
void wordsTooOften(string& word,int& count){

	if (wordsMoreThanThree != 0 && wordsMoreThanThree != 1) {
			int percent = (count / wordsMoreThanThree) * 100;

			if (percent > 5) {
				outputFile << word << "\n";
			}
		}


	}
void collectData(string& word, int& count){
	totalNodes += count; //counts all the nodes up
	totalCharacterLength += word.length(); //adds up the length
	uniqueWords++;//unique words
}
void printIndex(string& word, int& count) {
		if (!flag && i != word[0]) {
			char c = toupper(word[0]);
			outputFile << "\n\n" << c << "\n";
			outputFile<< "---------------\n";
			flag = true;
			i = word[0];
		}
		else if (i != word[0]) {
			char c = toupper(word[0]);
			i = word[0];
			outputFile << "\n\n" << c << "\n";
			outputFile << "---------------\n";
			flag = false;
		}
			outputFile << word << "\n";
}








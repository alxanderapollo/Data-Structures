/*
	Notes:
		Project 1 CSC 430 Written by : Alexander Apollo Salazar
		09/16

		The purpose of this program is to place under scrutiny  the behavior  of each
		algorithm: Selection Sort, Insertion Sort, Bubble Sort, Heap Sort, Merge Sort, Quick Sort.
		Each algorithm will count the # of comparisons & swaps made. This will aid in my conclusion
		to which algorithm is more "efficient".

		TXT Files attached: Inverse 100, Inverse 1000, Almost 100, Almost 1000, Random 100, Random 1000


*/
#include <iostream>
#include <fstream>
using namespace std;

//global variables
 int Swaps = 0; //swap counter
 int Comparisons_Count = 0; //comparison counter

//Sorting algorithms
 void SelectionSort(int [], int);
 void InsertionSort(int [], int);
 void BubbleSort(int [], int);

 //heap sort
 void HeapSort(int [], int);
 void Heapify(int[], int, int);
 //void Build_MaxHeap(int[],int);

//merge sort
 void MergeSort(int [], int, int );
 void Merge(int [], int, int, int);

//quick sort methods
 void QuickSort(int [], int length);
 void recQuickSort(int [],int, int);
 int Partition(int [], int, int);

//methods to pass txt info into array and call display
 void Inverse();
 void Inverse2();
 void almost();
 void almost2();
 void Random();
 void Random2();

//Swap function
 void Swap_quick(int [], int, int);

//display methods for selection sort
 void SelectionSortDisplay(int); //Displays Inverse results
 void SelectionSortDisplay2(int); //Displays almost results
 void SelectionSortDisplay3(int);//Displays Random results

//display for Insertion sort
 void InsertionSortDisplay(int); //Displays Inverse result
 void InsertionSortDisplay2(int); //Displays almost results
 void InsertionSortDisplay3(int);//Displays Random results

//display for Heap Sort
 void HeapSortDisplay(int);//Displays Inverse results
 void HeapSortDisplay2(int);//Displays almost results
 void HeapSortDisplay3(int);//Displays Random results

//display Merge sort
 void MergeSortDisplay(int);//Displays Inverse results
 void MergeSortDisplay2(int);//Displays almost results
 void MergeSortDisplay3(int);//Displays Random results

//display Quick sort
 void QuickSortDisplay(int);//Displays Inverse results
 void QuickSortDisplay2(int);//Displays almost results
 void QuickSortDisplay3(int);//Displays Random results

//display Bubble Sort
 void BubbleSortDisplay(int);//Displays Inverse results
 void BubbleSortDisplay2(int);//Displays almost results
 void BubbleSortDisplay3(int);//Displays Random results

 int main (){
	 Inverse();
     Inverse2();
	 almost();
	 almost2();
	 Random();
	 Random2();
	 return 0;
}
//these methods read the files, call on the sorting alogrithms & calls to displays contents

 void Inverse(){

	    ifstream fin; // output object
        int length = 100; // length of the array

	    int Inverse1[length],
	    Inverse2[length],
	    Inverse3[length],
	    Inverse4[length],
	    Inverse5[length],
	    Inverse6[length];

		fin.open("Inverse100.txt");

		int i = 0;
		while( i < length){
			fin >> Inverse1[i];
			i++;
		}
		fin.close();

		for(int j =0; j<length; j++){

		Inverse2[j] = Inverse1[j];
		Inverse3[j] = Inverse2[j];
		Inverse4[j] = Inverse3[j];
		Inverse5[j] = Inverse4[j];
		Inverse6[j] = Inverse1[j];
		}

		//Inverse 100
		SelectionSort(Inverse1,length);
	    SelectionSortDisplay(length);

	    InsertionSort(Inverse2,length);
	    InsertionSortDisplay(length);

	    BubbleSort(Inverse3,length);
	    BubbleSortDisplay(length);

	    int n = sizeof(Inverse4)/sizeof(Inverse4[0]);
	    HeapSort(Inverse4, n);
	    HeapSortDisplay(length);

	    MergeSort(Inverse5, 0, length);
	    MergeSortDisplay(length);

	    QuickSort(Inverse6,length);
	   	QuickSortDisplay(length);
}
 void Inverse2(){
	    ifstream fin; // output object
        int length = 1000;

		int Inverse1[length],
		Inverse2[length],
		Inverse3[length],
		Inverse4[length],
		Inverse5[length],
		Inverse6[length];

		fin.open("Inverse1000.txt");
		int i = 0;
		while( i < length){
		fin >> Inverse1[i];
		i++;
		}
		fin.close(); // close file

		for(int j =0; j<length; j++){

		Inverse2[j] = Inverse1[j];
		Inverse3[j] = Inverse2[j];
		Inverse4[j] = Inverse3[j];
		Inverse5[j] = Inverse4[j];
		Inverse6[j] = Inverse1[j];
		}
     	//Inverse 1000
		SelectionSort(Inverse1,length);
		SelectionSortDisplay(length);

		InsertionSort(Inverse2,length);
		InsertionSortDisplay(length);

		BubbleSort(Inverse3,length);
	    BubbleSortDisplay(length);

	    int n = sizeof(Inverse4)/sizeof(Inverse4[0]);
	    HeapSort(Inverse4, n);
	    HeapSortDisplay(length);

		MergeSort(Inverse5, 0, length);
		MergeSortDisplay(length);

		QuickSort(Inverse6,length);
		QuickSortDisplay(length);
}
 void almost(){
	    ifstream fin;
	    int length = 85; // number of integers in txt file
	    int length_output = 100; // for output purposes

		int Almost1[length],
		Almost2[length],
		Almost3[length],
		Almost4[length],
		Almost5[length],
		Almost6[length];

	    fin.open("almost100.txt");
	    int i = 0;
	 	while( i < length){
	 	fin >> Almost1[i];
	 	i++;
	 	}
	    fin.close(); // close file

		for(int j =0; j<length; j++){
		Almost2[j] = Almost1[j];
		Almost3[j] = Almost2[j];
	    Almost4[j] = Almost3[j];
		Almost5[j] = Almost4[j];
		Almost6[j] = Almost1[j];
		}
        //almost 100
	    SelectionSort(Almost1,length);
     	SelectionSortDisplay2(length_output);

	    InsertionSort(Almost2,length);
	    InsertionSortDisplay2(length_output);

	    BubbleSort(Almost3, length);
	    BubbleSortDisplay2(length_output);

	    int n = sizeof(Almost4)/sizeof(Almost4[0]);
	    HeapSort(Almost4, n);
	    HeapSortDisplay2(length_output);

	    MergeSort(Almost5, 0, length);
	    MergeSortDisplay2(length_output);

	    QuickSort(Almost1,length);
	    QuickSortDisplay2(length_output);
 }
 void almost2(){
	   ifstream fin;
	   int length = 782; // actual number integers in the array
	   int length_output = 1000;

	   int Almost1[length],
	   Almost2[length],
	   Almost3[length],
	   Almost4[length],
	   Almost5[length],
	   Almost6[length];

	   fin.open("almost1000.txt");
	   int i = 0;
	   while( i < length){
	   fin >> Almost1[i];
	   i++;
	   }
	   fin.close();

	   for(int j =0; j<length; j++){
	   Almost2[j] = Almost1[j];
	   Almost3[j] = Almost2[j];
	   Almost4[j] = Almost3[j];
	   Almost5[j] = Almost4[j];
	   Almost6[j] = Almost1[j];
	   }
	   //almost 1000
	   SelectionSort(Almost1,length);
	   SelectionSortDisplay2(length_output);

	   InsertionSort(Almost2,length);
	   InsertionSortDisplay2(length_output);

	   BubbleSort(Almost3, length);
	   BubbleSortDisplay2(length_output);

	   int n = sizeof(Almost4)/sizeof(Almost4[0]);
	   HeapSort(Almost4, n);
	   HeapSortDisplay2(length_output);

	   MergeSort(Almost5, 0, length);
	   MergeSortDisplay2(length_output);

	   QuickSort(Almost6,length);
	   QuickSortDisplay2(length_output);
 }
 void Random(){

	 ifstream fin;
	 int length = 100;

	 int Random1[length],
	 Random2[length],
	 Random3[length],
	 Random4[length],
	 Random5[length],
	 Random6[length];

	 fin.open("Random100.txt");
	 int i = 0;
	 while( i < length){
	 fin >> Random1[i];
	 i++;
	 }
	 fin.close();

	 for(int j =0; j<length; j++){

	 Random2[j] = Random1[j];
	 Random3[j] = Random2[j];
	 Random4[j] = Random3[j];
	 Random5[j] = Random4[j];
	 Random6[j] = Random1[j];
	 }
	 //Random 100
	 SelectionSort(Random1,length);
	 SelectionSortDisplay3(length);

	 InsertionSort(Random2,length);
	 InsertionSortDisplay3(length);

	 BubbleSort(Random3,length);
	 BubbleSortDisplay3(length);

	 int n = sizeof(Random4)/sizeof(Random4[0]);
	 HeapSort(Random4, n);
	 HeapSortDisplay3(length);

	 MergeSort(Random5, 0, length);
	 MergeSortDisplay3(length);

	 QuickSort(Random6,length);
	 QuickSortDisplay3(length);
 }
 void Random2(){
	 ifstream fin;
	 int length = 1000;

	 int Random1[length],
	 Random2[length],
	 Random3[length],
	 Random4[length],
	 Random5[length],
	 Random6[length];

	 fin.open("Random1000.txt");
	 int i = 0;
	 while( i < length){
	 fin >> Random1[i];
	 i++;
	 }
	 fin.close();

	 for(int j =0; j<length; j++){

	 Random2[j] = Random1[j];
	 Random3[j] = Random2[j];
	 Random4[j] = Random3[j];
	 Random5[j] = Random4[j];
	 Random6[j] = Random1[j];
	 }
	 //Random 1000
	 SelectionSort(Random1,length);
	 SelectionSortDisplay3(length);

	 InsertionSort(Random2,length);
	 InsertionSortDisplay3(length);

	 BubbleSort(Random3,length);
	 BubbleSortDisplay3(length);

	 int n = sizeof(Random4)/sizeof(Random4[0]);
	 HeapSort(Random4, n);
	 HeapSortDisplay3(length);

	 MergeSort(Random5, 0, length);
	 MergeSortDisplay3(length);

	 QuickSort(Random6,length);
	 QuickSortDisplay3(length);
 }

//Sorting algorithms
 void SelectionSort(int A[], int length){
	 int smallest;
	 for(int i = 0; i < length - 1; i++){

	 smallest = i;
	 for(int j = i + 1; j < length; j++){
		if(A[j] < A[smallest]){
		  Comparisons_Count++;
		  smallest = j;
		    if(smallest != 0){
		    Swap_quick(A,smallest,i );
			}
		  }
			else
			Comparisons_Count++;
	     }
	  }
  }
 void InsertionSort(int A[], int length)
{
	int j;
	bool flag;
	for (int i = 0; i < length; i++){
		j = i;
		flag = false;
			if(A[j] < A[j-1]){
			flag = true;

			while (j > 0 && A[j] < A[j-1] && flag!= false){
				Comparisons_Count++;
				Swap_quick(A,j,j-1 );
				  j--;
			 }
			}
			else
			   Comparisons_Count++;
			}

		 }
 void BubbleSort(int A[], int length){
	bool swapped = true;
	int j = 0;

	while(swapped){
	swapped = false;
	j++;
	for(int i = 0; i < length-j; i++){
       if(A[i] > A[i+1]){
	   Comparisons_Count++;
	   Swap_quick(A,i,i + 1 );
	   swapped = true;
	}
	   else
		Comparisons_Count++;

		}
	}
}

//heap sort
 void Heapify(int A[], int n, int i)
 {
     int largest = i;  // Initialize largest as root
     int l = 2*i + 1;  // left = 2*i + 1
     int r = 2*i + 2;  // right = 2*i + 2

     // If left child is larger than root
     if (l < n && A[l] > A[largest]){
         largest = l;
      Comparisons_Count++;
     }
     else
    	 Comparisons_Count++;

     // If right child is larger than largest so far
     if (r < n && A[r] > A[largest]){
         largest = r;
         Comparisons_Count++;
     }
     else
    	 Comparisons_Count++;

     // If largest is not root
     if (largest != i)
     {
     	Swap_quick(A, i,largest);

         // Recursively heapify the affected sub-tree
         Heapify(A, n, largest);
     }
 }
 void HeapSort(int arr[], int n)
 {
     // Build heap (rearrange array)
     for (int i = n / 2 - 1; i >= 0; i--)
         Heapify(arr, n, i);

     // One by one extract an element from heap
     for (int i=n-1; i>=0; i--)
     {
         // Move current root to end
     	Swap_quick(arr,0, i);

         // call max heapify on the reduced heap
         Heapify(arr, i, 0);
     }
 }

//merge sort
 void MergeSort(int A[], int lowerBound, int upperBound){
	 int mid;

	    if (upperBound > lowerBound){
	        mid = ( lowerBound + upperBound) / 2;
	        MergeSort(A, lowerBound, mid);
	        MergeSort(A, mid + 1, upperBound);
	        Merge(A, lowerBound, upperBound, mid);
	    }

}
 void Merge(int A[], int lowerBound, int upperBound, int mid){
	    int* leftArray = NULL;
	    int* rightArray = NULL;
	    int i, j, k;
	    int n1 = mid - lowerBound + 1;
	    int n2 = upperBound - mid;
	    leftArray = new int[n1];
	    rightArray = new int[n2];
	    for (i = 0; i < n1; i++)
	    leftArray[i] = A[lowerBound + i];
	    for (j = 0; j < n2; j++)
	    rightArray[j] = A[mid + 1 + j];

	    i = 0;
	    j = 0;
	    k = lowerBound;

	    while (i < n1 && j < n2)
	    {
	        if (leftArray[i] <= rightArray[j])
	        {

	            A[k] = leftArray[i];
	            i++;
	        }
	        else
	        {
	            A[k] = rightArray[j];
	            j++;
	        }


	        k++;
	        Comparisons_Count++;
	        Swaps++;
	    }

	    while (i < n1)
	    {
	        A[k] = leftArray[i];
	        i++;
	        k++;
	        Comparisons_Count++;
	    }

	    while (j < n2)
	    {
	        A[k] = rightArray[j];
	        j++;
	        k++;
	        Comparisons_Count++;
	    }

	    delete [] leftArray;
	    delete [] rightArray;
	}

 //quick sort
 void QuickSort(int A[], int length){
 recQuickSort(A, 0, length - 1);
}
 int Partition(int A[], int first, int last){
	int pivot;
	int index, smallIndex;

	Swap_quick(A,first, (first + last) / 2);

	pivot = A[first];
	smallIndex = first;

	for(index = first + 1; index <= last; index++)
	if(A[index] < pivot){

		Comparisons_Count++;
		smallIndex++;

		Swap_quick(A, smallIndex, index);
		}
		else
		{
	     Comparisons_Count++;
		}
		Swap_quick(A, first, smallIndex);

	return smallIndex;
}
 void recQuickSort(int A[], int first, int last){
	int pivotLocation;

	if(first < last){
		pivotLocation = Partition(A, first, last);
		recQuickSort(A, first, pivotLocation - 1 );
		recQuickSort(A, pivotLocation + 1, last);
	}
}

//Swap function
 void Swap_quick(int A[], int first, int second){
	 int temp;
	 temp = A[first];
	 A[first] = A[second];
	 A[second] = temp;
	 Swaps++;
}

//Selection Sort Display
 void SelectionSortDisplay(int length){
  cout <<"Selection Sort number of comparisons of Inverse " << length << ": " << Comparisons_Count<<endl;
  cout <<"Selection Sort number of Swaps of Inverse " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void SelectionSortDisplay2(int length){
	cout <<"Selection Sort number of comparisons of Almost " << length << ": " << Comparisons_Count<<endl;
	cout <<"Selection Sort number of Swaps of Almost " << length << ": " << Swaps<<endl;
	cout<<"\n";
	Comparisons_Count = 0;
	Swaps = 0;
 }
 void SelectionSortDisplay3(int length){
	 cout <<"Selection Sort number of comparisons of Random " << length << ": " << Comparisons_Count<<endl;
	 cout <<"Selection Sort number of Swaps of Random " << length << ": " << Swaps<<endl;
	 cout<<"\n";
	 Comparisons_Count = 0;
	 Swaps = 0;
 }
//Insertion Sort Display
 void InsertionSortDisplay(int length){
  cout <<"Insertion Sort number of comparisons of Inverse " << length << ": " << Comparisons_Count<<endl;
  cout <<"Insertion Sort number of Swaps of Inverse " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void InsertionSortDisplay2(int length){
  cout <<"Insertion Sort number of comparisons of Almost " << length << ": " << Comparisons_Count<<endl;
  cout <<"Insertion Sort number of Swaps of Almost " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void InsertionSortDisplay3(int length){
  cout <<"Insertion Sort number of comparisons of Random " << length << ": " << Comparisons_Count<<endl;
  cout <<"Insertion Sort number of Swaps of Random " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
//Heap Sort Display
 void HeapSortDisplay(int length){
  cout <<"Heap Sort number of comparisons of Inverse " << length << ": " << Comparisons_Count<<endl;
  cout <<"Heap Sort number of Swaps of Inverse " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void HeapSortDisplay2(int length){
  cout <<"Heap Sort number of comparisons of Almost " << length << ": " << Comparisons_Count<<endl;
  cout <<"Heap Sort number of Swaps of Almost " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void HeapSortDisplay3(int length){
  cout <<"Heap Sort number of comparisons of Random " << length << ": " << Comparisons_Count<<endl;
  cout <<"Heap Sort number of Swaps of Random " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
//Merge Sort Display
 void MergeSortDisplay(int length){
  cout <<"Merge Sort number of comparisons of Inverse " << length << ": " << Comparisons_Count<<endl;
  cout <<"Merge Sort number of Swaps of Inverse " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void MergeSortDisplay2(int length){
  cout <<"Merge Sort number of comparisons of Almost " << length << ": " << Comparisons_Count<<endl;
  cout <<"Merge Sort number of Swaps of Almost " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void MergeSortDisplay3(int length){
  cout <<"Merge Sort number of comparisons of Random " << length << ": " << Comparisons_Count<<endl;
  cout <<"Merge Sort number of Swaps of Random " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
//Quick Sort Display
 void QuickSortDisplay(int length){
  cout <<"Quick Sort number of comparisons of Inverse " << length << ": " << Comparisons_Count<<endl;
  cout <<"Quick Sort number of Swaps of Inverse " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
  cout <<"\n\n";
 }
 void QuickSortDisplay2(int length){
  cout <<"Quick Sort number of comparisons of Almost " << length << ": " << Comparisons_Count<<endl;
  cout <<"Quick Sort number of Swaps of Almost " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
  cout <<"\n\n";
 }
 void QuickSortDisplay3(int length){
  cout <<"Quick Sort number of comparisons of Random " << length << ": " << Comparisons_Count<<endl;
  cout <<"Quick Sort number of Swaps of Random " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
  cout <<"\n\n";
 }
//Bubble Sort Display
 void BubbleSortDisplay(int length){
  cout <<"Bubble Sort number of comparisons of Inverse " << length << ": " << Comparisons_Count<<endl;
  cout <<"Bubble Sort number of Swaps of Inverse " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void BubbleSortDisplay2(int length){
  cout <<"Bubble Sort number of comparisons of Almost " << length << ": " << Comparisons_Count<<endl;
  cout <<"Bubble Sort number of Swaps of Almost  " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }
 void BubbleSortDisplay3(int length){
  cout <<"Bubble Sort number of comparisons of Random " << length << ": " << Comparisons_Count<<endl;
  cout <<"Bubble Sort number of comparisons of Random " << length << ": " << Swaps<<endl;
  cout<<"\n";
  Comparisons_Count = 0;
  Swaps = 0;
 }

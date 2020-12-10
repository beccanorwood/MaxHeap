//Rebecca Norwood
//Email: norwo009@cougars.csusm.edu
//Student ID: 200430599	

//Program is to create a max heap which is set up with an array and the largest value is the "root node" 

#include <iostream>
#include <array>
#include <sstream>
#include <string>

using namespace std; 

class MaxHeap{
private:
	int *A; //Declare pointer to point to array, to be able to dynamically change the size 
	int SIZE; 
	
public:
	MaxHeap(int user_Size);  
	void heapify(int A[], int len, int i);
	void heapsort(int A[], int len); 
	void swap(int &x, int &y); 
	void siftup(int i); 
	void siftdown(int i); 
	void insert(int k); 
	int parent(int i); 
	int left(int i); 
	int right(int i); 
	int removeAt(int i); 
	int extractMax(); 
	void Display(int A[], int len); 
	int size(); 

}; 

//==================================================================================================

MaxHeap::MaxHeap(int user_Size) //Constructor for user size 
{
	 A = new int[user_Size]; 
}

//==================================================================================================

void MaxHeap::heapify(int A[], int len, int i)
{
	//Create max heap
	
	int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2;
  

    if (left < len && A[left] > A[largest]) 
        largest = left; 
  

    if (right < len && A[right] > A[largest]) 
        largest = right; 
  

    if (largest != i) 
    { 
        swap(A[i], A[largest]); 
  
       
        heapify(A, len, largest); 
    } 
	
}

//==================================================================================================

void MaxHeap::heapsort(int A[], int len)
{
	//Method that will sort the array into ascending order 
	//Cannot use second array

    for (int i = len / 2 - 1; i >= 0; i--){
        heapify(A, len, i); 
	}
 
    for (int i=len-1; i>0; i--) 
    { 
        swap(A[0], A[i]); 
        heapify(A, i, 0); 
    } 

}

//==================================================================================================

void MaxHeap::swap(int &x, int &y)
{
	int temp = x; 
	x = y; 
	y = temp; 
	 
}

//==================================================================================================

void MaxHeap::siftup(int i)
{
	if(i && A[parent(i)] < A[i]){
		swap(A[i], A[parent(i)]); 
		siftup(parent(i)); 
	}
}

//==================================================================================================

void MaxHeap::siftdown(int i)
{
	int l = left(i); 
	int r = right(i); 
	
	
	int max = i; 
	
	if(l < size() && A[l] > A[i]){
		max = l; 
	}
	if(r < size() && A[r] > A[max]){
		max = r; 
	}
	if(max != i){
		swap(A[i], A[max]);
		siftdown(max); 
	}
}

//==================================================================================================

void MaxHeap::insert(int k)
{
	int i = k; 
	A[i] = k; 
	
	siftup(i); 
	SIZE++; 
}

//==================================================================================================

int MaxHeap::parent(int i)
{
	return (i-1)/2; 
}

//==================================================================================================

int MaxHeap::left(int i)
{
	return (2*i+1); 
}

//==================================================================================================

int MaxHeap::right(int i)
{
	return (2*i+2); 
}

//==================================================================================================

int MaxHeap::removeAt(int i)
{
	if(SIZE == 1) {
		return A[--SIZE]; 
	}
	
	int index = A[i]; 
	A[i] = A[--SIZE]; 
	if(A[i] > index){
		siftdown(i); 
	}
	else{
		siftup(i); 
	}
	
	return index; 
}

//==================================================================================================

int MaxHeap::extractMax()
{
	//For maxheap, max will be last index since it has been sorted 
	if(SIZE == 1){
		return A[--SIZE]; 
	}
	
	int index = A[0]; 
	A[0] = A[--SIZE]; 
	siftdown(0); 
	return index; 
	
}

//==================================================================================================

void MaxHeap::Display(int A[], int len)
{
	for(int i = 0; i < len; i++){
		cout << A[i] << " "; 
	}
	
	cout << "\n"; 
}

//==================================================================================================

int MaxHeap::size()
{
	return SIZE; 
}

//================================================================================

int main()
{

 	int i=0, j=0; 
 	int user_Array[20]; //Declare array with initial size of 20
 
  	//Get user input for initial array 
  	cout << "Enter list of integers seperated by a space" << endl; 
  
	  char temp; 
	  do { 
	      scanf("%d%c", &user_Array[i], &temp); 
	      i++; 
	  } while(temp != '\n'); 
	  
	  
	int initial_size = i; //new array size 
	  
	//Debug to check output is correct 
	cout << "\nHere is your list of integers" << endl; 
	    
	  for(j=0; j<i; j++) { 
	    printf("%d ", user_Array[j]); 
	  }
	  
	  
	  //Send to heapmax array with user size
	  MaxHeap h(initial_size); 
	  
	  
	  cout << "\n\nYou array has been sorted in ascending order: " << endl; 
	  h.heapsort(user_Array, initial_size); 
	  h.Display(user_Array, initial_size); 
	  
}

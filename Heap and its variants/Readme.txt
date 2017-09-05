									ReadMe File

This has:

•	2 header files 
•	3 CPP files 


					##########################  	Header Files    ##########################

1) priorityQueue.h ---->>>>

This header files contains declaration of all functions that are to be implemented for achieving all the requirement stated for priority queue.
Definition of all these functions are implemented in “implement_PriorityQueue.cpp”
Main functions are - 
- insert
- all-minimum
- decrease key function
- extract all minimum function
All other are helper function

2) smoothSort.h ---->>>>

Leonardo numbers are declared as constants as they will never change and we have to use them again and again.
swap, unique_Random_Numbers, evaluate used as helper function
- main functions used are - insertion_In_Heap, dequeue_From_Heap, sort_In_Heap, heap_Structure_Rebalancing, max_Heapify 
to achieve smooth sort using leonardo heap


		##########################  	End of Header Files   ##########################




##########################  	CPP Files	  ##########################


1)			<<<<---- implement_PriorityQueue.cpp  ---->>>>
Includes definition of all functions that are declared in the  priorityQueue.h header file.

Description of all the constructors and the Functions are below:
-  void priorityQueue::all_Minimum(int min)
this function will iterate through the heap (vector of vector used as a data structure for making a heap) and used recursion, traversing left side and then right.

- void priorityQueue::min_Heapify(int i)
this function will help in min heapifying the whole heap

	Block A
	- This helps achieving the min heap property i.e. the parent should be smaller than its children.
	- a smallest variable is used which compares value with with its left and right child
	- used recursion for achieving this.


- void priorityQueue::extract_All_Min()
	- This will first extract the topmost element which is the minimum.
	- now first element will be replaced with the last 
	- as the min heap property distorted 
	- using min heap function to achieve min heap property back.

- void priorityQueue:: decrease_HeapKey(vector<int> vec_child, int position)
	- this will help changing(decreasing) the key value keeping the data value same
	- after changing key it will compare its value with its parent and iterate the new key to its new correct position.

- void priorityQueue:: minHeap_insert_In_PriorityQueue(vector<int> vec_child)
	- This will insert the element in the heap
	- call the decrease key function that helps it attaching the min heap property.

- void priorityQueue::displayQueue_withVec(vector<vector<int> > displayVector)
	- used when a vector is passed as an argument to display it.

- void priorityQueue::displayQueue()
	- used when main queue needs to be displayed 


2)			<<<<---- implement_smoothSort.cpp  ---->>>>
Includes definition of all functions that are declared in the  smoothSort.h header file.
- void leonardo_Heap_Structure::heap_Structure_Rebalancing(heap_Iterator rootElement, size_t size_of_Heap)
function used to rebalance the heap when a new element is introduced 

- void leonardo_Heap_Structure::max_Heapify(heap_Iterator startPoint, heap_Iterator endPoint, leonardo_Heap_Structure input_Heap)
helps attaining the max heapify property

- void leonardo_Heap_Structure::insertion_In_Heap(heap_Iterator startPoint, heap_Iterator endPoint, heap_Iterator end_ofHeap , leonardo_Heap_Structure& inputHeap)
	 
	 - We have to add the popped element from the array as the root of the two 2 consecutive number.
	 - if the right most is not of size 1, the new element will be a new heap of size 1
	 - else the new element will become new heap of size 1.

- void leonardo_Heap_Structure::dequeue_From_Heap(heap_Iterator startPoint, heap_Iterator endPoint, leonardo_Heap_Structure& input_Heap)
	- 1st step is that we are removing the top node of the right heap
	- then we have to search for its children, if they are present
		- start from the left heap
		- then right heap
	- else we do not need to do anything.

3)	<<<<---- main.cpp ---->>>>

This file has the main function. So, the execution will start from this file. 
	•	It will create objects of priorityQueue and smoothSort.
	•	This file has 10 test cases that will check the required functionality of PriorityQueue and smoothSort.

	<<<<——END of main.cpp ---->>>>	


		##########################  	END of CPP Files	  ##########################




REFERENCES USED-
I have used these 2 websites for a better understanding of smooth sort.
1) http://www.keithschwarz.com/smoothsort/
2) http://www.slideshare.net/habib_786/smooth-sort
3) CLRS book for basics of priority Queue.















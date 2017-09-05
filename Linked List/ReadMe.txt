									ReadMe File

This has:

•	4 header files 
•	3 CPP files 


					##########################  	Header Files	  ##########################

1) SinglyNode.h ---->>>>

This header file defines a class “SingleNode”, which will create a new Node for Singly Linked List. It has data member, which will store the data of the node. Also, there is a next pointer which will point to the next node. A constructor of this class is defined which will declare the data as 0 and next would be NULL.


2) DoublyNode.h ---->>>>

This header file defines a class “DoublyNode”, which will create a new Node for Doubly Linked List. It has data member, which will store the data of the node. There is a next pointer which will point to the next node. Also, there is a prev pointer which will point to the previous node. A constructor of this class is defined which will declare the data as 0 and, the next and prev would be NULL.


3) SinglyList.h ---->>>>

This header file defines a class SingleList, containing the declaration of the functions required to attain the required functionalities.


4) DoublyList.h ---->>>>

This header file defines a class DoublyList, containing the declaration of the functions required to attain the required functionalities.


				       ##########################  	End of Header Files	  ##########################




##########################  	CPP Files	  ##########################


1)			<<<<---- ImplementSingly.cpp  ---->>>>

This CPP file have the definition of all the functions that are declared in the SinglyList header file and will implement all the functionalities by using Singly Linked List.


Description of all the constructors and the Functions are below:


SingleNode::SingleNode()---->>>>
This is the Constructor of the SingleNode Class and will initialize its data value by 0 and its next pointer is pointing to the NULL.


SingleList::SingleList()---->>>>
Defines a Constructor of the SingleList Class. When a new object of SingleList class is created, its constructor will be called and will define its head pointer to be NULL.


void SingleList::Append_to_list(int new_data) ---->>>>
This function Creates a new temporary node and assign a data value to its value part. It also checks if the list is empty and if it is, then the head will be pointed to this new node. And if the List is non-empty, these statements will append the newly created node to the end of the List.


void SingleList::display_List(int disp_shufle) ---->>>>
This function displays the whole linked list. In case of an empty list, it will check and display the message that the list is empty.



int SingleList::list_size(SingleNode* Node) ---->>>>
This is function to calculate the size of the linked list and returns the size.


void SingleList::sort()---->>>>
This is function which is implementing the solution of the Team of Four Problem.
 
	Block A – is the main block which will determine that till when the sorting operation works. 
		•	It has a Current pointer which will iterate will with every iteration of the bubble sort.
		•	The function will work till the current pointer reaches the last element.

	Block A1—is the sub-part of the block A. 
		•	Before this, size of the remaining linked list is calculated.
		•	Based on that, the Block A will iterate and perform Bubble Sort on the linked list. 
		•	If the size is greater than 4 then the cal_size variable will be equal to 4 and if it is less than 4, then the cal_size will be equal to 			the size calculated. 
		•	The loop is iterated for cal_size – 1 as for 4 elements there would be only 3 comparisons.


	Block A2—is the sub-part of Block A1. 
		•	This loop is actually performing the Bubble sort on the size passed by Block A1.
		•	Defines pointers which will check the data and will swap the nodes by manipulating the pointer such that after the first iteration the 			largest will be at the end.
		•	In the next iteration, the same work will be performed but this time the comparisons will be one less than the previous.
		•	A previous pointer is also defined which helps the swapping, as it facilitates the pointer manipulation.



 
void SingleList::Reverse()---->>>>
This is function which is implementing the solution of the Reversing the Linked List Problem.
	•	In this, a pointer Current is defined which will iterate till the end of the loop and make the head point at it.
	•	Then another temporary variable will iterate till its next is the current pointer and it will be marked as the next element of the current.
	•	Now the current will be at its new position and again the temporary pointer will be iterated.
	•	After performing the above operation, the last element will be pointed at NULL.





void SingleList::shuffle()---->>>>
This is function which is implementing the solution of the Shuffling the Linked List Problem.
	Block B
		•	Calculating the size of the linked list by using the list_size function.
		•	If the size if even, then it will assign same value to both the variables.
		•	For odd case, the bigger size is assigned to the 1st part of the list

	Block C-
		•	This defines 4 pointers. Two for the first part of the list and the other two will point at other part of the list which after the mid-point.
		•	Current1-> next will be nextList1, i.e. the first element of the first part of the list will point to the first element of the other part 					of the list.
		•	And Likewise, the first element of the 2nd list will point to current2. 
		•	Every pointer will be incremented and this is how the whole shuffling will take place.
		•	current1->next = nextList1  this will point to NULL in case of an odd list size. For the even list, it will point to the last element of 					the 2nd part of the list whose next is NULL.


void SingleList::delete_List()---->>>>
This will delete the Linked List.


 			<<<<---- END of ImplementSingly.cpp  ---->>>>



2)			<<<<---- ImplementDoubly.cpp ---->>>>

This CPP file have the definition of all the functions that are declared in the DoublyList header file and will implement all the functionalities by using Doubly Linked List. 

Description of all the constructors and the Functions are below:


DoublyNode::DoublyNode()---->>>>
This is the Constructor of the DoublyNode Class and will initialize its data value by 0 and its next and prev pointer is pointing to the NULL.


DoublyList::DoublyList()---->>>>
Defines a Constructor of the DoublyList Class. When a new object of DoublyList class is created, its constructor will be called and will define its head pointer to be NULL.

void DoublyList::Append_to_list(int new_data) ---->>>>
	•	This function Creates a new temporary node and assign a data value to its value part. 
	•	It also checks if the list is empty and if it is, then the head will be pointed to this new node. 
	•	If the List is non-empty, these statements will append the newly created node to the end of the List.
	•	Next of the new node would be NULL and the prev would be the last element of the old list.



void DoublyList::display_List(int disp_shufle) ---->>>>
This function displays the whole linked list. In case of an empty list, it will check and display the message that the list is empty.



int DoublyList::list_size(DoublyNode* Node) ---->>>>
This is function to calculate the size of the linked list and returns the size.


void DoublyList::sort()---->>>>
This is function which is implementing the solution of the Team of Four Problem.
 
	Block A – is the main block which will determine that till when the sorting operation works. 
		•	It has a Current pointer which will iterate will with every iteration of the bubble sort.
		•	The function will work till the current pointer reaches the last element.

	Block A1 — is the sub-part of the block A. 
		•	Before this, size of the remaining linked list is calculated.
		•	Based on that, the Block A will iterate and perform Bubble Sort on the linked list. 
		•	If the size is greater than 4 then the cal_size variable will be equal to 4 and if it is less than 4, then the cal_size will be equal to 			the size calculated. 
		•	The loop is iterated for cal_size – 1 as for 4 elements there would be only 3 comparisons.

	Block A2 — is the sub-part of Block A1. 
		•	This loop is actually performing the Bubble sort on the size passed by Block A1.
		•	Defines pointers which will check the data and will swap the nodes by manipulating the pointer such that after the first iteration the 			largest will be at the end.
		•	In the next iteration, the same work will be performed but this time the comparisons will be one less than the previous.


 
void DoublyList::Reverse()---->>>>
This is function which is implementing the solution of the Reversing the Linked List Problem.
	•	In this, a pointer Current is defined which will iterate till the end of the loop and make the head point at it.
	•	Then another temporary variable will iterate till its next is the current pointer and it will be marked as the next element of the current.
	•	For the first case, the prev of current will be pointed to the NULL.
	•	Now the current will be at its new position and again the temporary pointer will be iterated.
	•	After performing the above operation, the last element will be pointed at NULL.





void DoublyList::shuffle()---->>>>
This is function which is implementing the solution of the Shuffling the Linked List Problem.

	Block B
		•	Calculating the size of the linked list by using the list_size function.
		•	If the size if even, then it will assign same value to both the variables.
		•	For odd case, the bigger size is assigned to the 1st part of the list

	Block C-
		•	This defines 4 pointers. Two for the first part of the list and the other two will point at other part of the list which after the mid-point.
		•	Current1-> next will be nextList1, i.e. the first element of the first part of the list will point to the first element of the other part 					of the list.
		•	The prev of nextList1 will be pointed to current1.
		•	And Likewise, the first element of the 2nd list will point to current2. 
		•	Every pointer will be incremented and this is how the whole shuffling will take place.
		•	current1->next = nextList1  this will point to NULL in case of an odd list size. For the even list, it will point to the last element of 					the 2nd part of the list whose next is NULL.
		•	It will now check if the nextList1 is not NULL, the prev of nextList1 will be current1.


void DoublyList::delete_List()---->>>>
This will delete the Linked List.


 			<<<<---- END of ImplementDoubly.cpp  ---->>>>





3)	<<<<---- main.cpp ---->>>>

This file has the main function. So, the execution will start from this file. 
	•	It will create objects of SingleList and DoublyList.
	•	This file has 12 test cases that will check the required functionality of Singly and Doubly Linked List.
	•	For sequence 1, for loop is used which generated a sequence from 1 to 100.
	•	For sequence 2, rand() % 1000 is used inside the for loop which will generate 100 numbers from 1 to 1000.
	•	Srand(time(NULL)) is used to generate different set of random numbers every time the new list is generated.
	•	Header files “time.h” and “cstdlib” are included to use the functionality of rand and srand.

	<<<<——END of main.cpp ---->>>>	


		##########################  	END of CPP Files	  ##########################


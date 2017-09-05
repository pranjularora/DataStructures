#ifndef DOUBLY_LIST
#define DOUBLY_LIST
#include "DoublyNode.h"

// The above 2 statements are a guard to check weather this header file has already been included or not..
class DoublyList
{

public:
	DoublyNode *head;	// Creates a new pointer of the SingleNode Class, which will be the head of the Linked List Created..
	int i, counter, size;

	// Constructor of this class
	DoublyList();

	// Declares a Function to append to the list
	void Append_to_list(int new_data);

	// Declares a Function to display the list
	void display_List(int disp_shufle);
	
	// Declares a Function to Display REVERSE LINK LIST --> just for checking the previous links. Not included as a part of functionality..
	void display_Reverse_List();


	// calculate size of linked list
	int list_size(DoublyNode* Node);

	// Declares a Function to REVERSE A LINK LIST
	void Reverse();
	
	// Declares a Function to SORT LINKED LIST
	void sort();

	// SHUFFLE A Doubly-LINKED LIST
	void shuffle();

	// Declares a Function to DELETE the LINKED LIST
	void delete_List();


};

#endif // !DOUBLY_LIST

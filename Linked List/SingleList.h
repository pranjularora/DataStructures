#ifndef LIST_H    
#define LIST_H 

// The above 2 statements are a guard to check weather this header file has already been included or not..

#include "SingleNode.h"


class SingleList
{
public:
	SingleNode *head; 		// Creates a new pointer of the SingleNode Class, which will be the head of the Linked List Created.. 
	int i, counter, size;

	// Constructor of this class 
	SingleList();

	// Declares a Function to append to the list
	void Append_to_list(int new_data);

	// Declares a Function to display the list
	void display_List(int disp_shuffle);

	// calculate size of linked list
	int list_size(SingleNode* Node);

	// Declares a Function to sort the list
	void sort();

	// Declares a Function to REVERSE A LINK LIST
	void Reverse();

	// Declares a Function to SHUFFLE A LINKED LIST
	void shuffle();

	// Declares a Function to DELETE the LINKED LIST
	void delete_List();



};


#endif // !LIST_H

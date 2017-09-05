			//		<<<<<---- This CPP File is for performing several Operations on a Singly Linked List ---->>>>>

#include "SingleList.h"
#include <iostream>
using namespace std;


// Defines a Constructor of the SingleNode Class and will initialize its data value by 0 and its next pointing to the NULL..
SingleNode::SingleNode()
{
	data = 0;
	next = NULL;
}

// Defines a Constructor of the SingleList Class..
SingleList::SingleList()
{
	head = NULL;   	// whenever a new object of SingleList class is created, its constructor will be called defining its head pointer to be NULL..
}


// ******** Definess a Funtion to append to the list  ********

void SingleList::Append_to_list(int new_data)
{
	SingleNode* temp = new SingleNode();
	temp->data = new_data;   		// Creates a new temporary node and assign the data value..
	if (head == NULL)			// check if the list is empty, and if it is then the head will be pointed to this new node..
		head = temp;
	else
	{

	// if the List is non-empty, these statements will append the above newly created node to the end of the List..

		SingleNode* temp1;
		temp1 = head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}


//  ******** Definess a Funtion to display the list  ********

void SingleList::display_List(int disp_shufle)
{
	SingleNode* temp;
	temp = head;
	int i = 1;
	if (head == NULL)  //  Check if the List is empty...
	{
		cout << "The List is Empty \n";
	}
	else
	{

	// For a non-Empty List, it will iterate through all the nodes and will display it
		while (temp != NULL)
		{
			if (disp_shufle == 1 && ( i == 1 || i == 51 ))   // These are added for a better display to the Shuffle Function
			{
				if (i == 1)
					cout << "\n\n<<<<=====    ** first half **    =====>>>> \n\n";
				if (i==51)
					cout << "\n\n<<<<=====    ** second half **    =====>>>> \n\n";

			}
			cout << temp->data;

		// These are added for a better display to the Linked List..
	
			if (temp->next != NULL)
				cout << " --> ";

			if (i % 4 == 0)
				cout << endl;
			

			temp = temp->next;
			i++;
		}
	}
	cout << endl << endl;
}


//  ******** Declare a function to calculate the size of linked list  ********
int SingleList::list_size(SingleNode* Node)
{
	size = 0;
	while (Node != NULL)
	{
		Node = Node->next;
		size++;
	}
	return size;
}



// ******** Defines a Funtion to sort the list ********

void SingleList::sort()    // ***** Using Bubble Sort to sort the List *****
{

    if (head != NULL)
    {
        
        // ***** Declaring Local Variables ***** //
        
        counter	= 0;
        SingleNode* temp = head;    	// a Temp pointer, pointing to the head when initialized..
        SingleNode* prev = head;	// a Prev pointer, which will help sorting funtion by being a temporary variable for swapping..
        SingleNode* prev1 = NULL;	// a pointer that will help the Prev pointer by assigning the correct value to it after a single iteration of bubble sort is finished ..
        SingleNode* current = head;	// This is the variable defining the actual position of the variable and ends soting operation when it reaches NULL..
        SingleNode* temp1 = temp->next; // a pointer helping the sorting by staying ahead of the temp variable..
        SingleNode* stamp;		// a pointer that will be at the first postion in the team of four..
        
        // ***** End of Declaring Local Variables ***** //
        
        ///********************************* Block A ***********************************///
        
        while (((current->next) != NULL))
        {
            i = 0;
            stamp = current;
            
            int cal_size = list_size(current); // Calculating size of the remaining list to be sorted ..
            
            if (cal_size >= 4)		   // calculating the size of the team on which the sorting needs to be performed (can be 4 or less than 4)
                cal_size = 4;
            
            ///*********************** Block A1 *************************///
            
            while (i < cal_size - 1 && (stamp->next != NULL)) // Iterating the below statements depending on the size of List calculated
            {
                int j = cal_size - 1;
                j = j - i;
                
                temp = stamp;
                temp1 = temp->next;
                if (counter % 4 != 0 && counter > 4)
                    prev = prev1;
                else if (counter < 4)
                    prev = head;
                
                int flag = 0;
                
                ///***************** Block A2 *******************///
                while (j > 0 && temp->next != NULL && temp1 != NULL) // Performing the bubble sort on the size determined above i.e. putting the biggest element at the end
                {
                    
                    if (temp->data > temp1->data) // Comparing two elements and checking if the sorting needs to be performed..
                    {
                        
                        SingleNode* swap = temp1;
                        int check = -1;
                        if (current == temp)
                            check = 0;
                        if (current == temp1)
                            check = 1;
                        
                        // Two sorting options..
                        
                        if (flag == 0 && counter < 4) // Swap operation for the first team, i.e. for the list having the head element
                        {
                            
                            temp->next = temp1->next;
                            temp1->next = temp;
                            temp1 = temp;
                            temp = swap;
                            
                            head = temp;
                            stamp = temp;
                            prev = stamp;
                            
                        }
                        else 				// Swap operation for all other teams
                        {
                            temp->next = temp1->next;
                            temp1->next = temp;
                            prev->next = temp1;
                            
                            temp1 = temp;
                            temp = swap;
                            if (flag == 0)
                                stamp = temp;
                            
                            prev = prev->next;
                            
                        }
                        if (check == 1)
                            current = temp1;
                        if (check == 0)
                            current = temp;
                        
                        
                    }
                    else // if swapping needs not to be done and, prev and head are not equal then increment the previous..
                    {
                        if (prev != head)
                        {
                            prev = prev->next;
                        }
                        
                    }
                    //incrementing and decrementing for the next iteration..
                    j--;
                    flag++;
                    temp = temp->next;
                    temp1 = temp1->next;
                    if (prev == head && prev->next != temp)
                        prev = prev -> next;
                    
                }
                ///***************** END of Block A2 *******************///			
                i++;
                counter++;
                
                if (i != cal_size)
                    current = current->next;
            }
            
            ///*********************** END of Block A1 *************************///
            counter++;
            
            prev = current;
            prev1 = prev;
            
            if (current->next != NULL)
                current = current->next;
        }
        ///********************************* END of Block A ***********************************///
    }
    else
    {
        cout << " \n########## This is an Empty List ########## \n";
    }
    
}


// ******** Defining a Function to REVERSE the LINK LIST ********

void SingleList::Reverse()
{
    if (head != NULL)
    {
        SingleNode* current;
        SingleNode* previous;
        SingleNode* newHead;
        int count = 0;
        current = head;
        previous = head;
        
        // Iterating the current variable to the end of the List, and pointing the head to the current..
        while (current->next != NULL)
        {
            current = current->next;
            count++;
        }
        newHead = current;
        
        // Iterating a prev pointer one position before the present current pointer and making the prev the current next..
        for (int i = 0; i < count; i++)
        {
            while (previous->next != current)
            {
                previous = previous->next;
            }
            current->next = previous;
            current = previous;
            previous = head;
        }
        // Making the last element pointing at the NULL..
        previous->next = NULL;
        head = newHead;
        
        
    
        cout << "\n\n=================================================================================\n\n";
    }
    else
    {
        cout << " \n########## This is an Empty List ########## \n";
    }
}


// ******** Defining a Function to SHUFFLE A LINKED LIST ********

void SingleList::shuffle()
{
    if (head != NULL)
    {
        ///********************************* Block B ***********************************///
        
        // Calculating the size of the list and finding the mid point of the list
        int iterator = 0;
        int size = list_size(head);
        int size_first, size_second;
        if (size % 2 == 0)
        {
            size_first = size / 2;
            size_second = size_first;
            iterator = size_second;
        }
        else
        {
            size_second = size / 2;
            size_first = size_second + 1;
            iterator = size_first;
        }
        ///********************************* END of Block B ***********************************///
        
        
        ///********************************* Block C ***********************************///
        SingleNode* current1;
        SingleNode* current2;
        SingleNode* nextList1;
        SingleNode* nextList2;
        
        current1 = head;
        current2 = current1->next;
        nextList1 = head;
        
        for (int i = 0; i < iterator; i++)
        {
            nextList1 = nextList1->next;
        }
        nextList2 = nextList1->next;
        
        // Making the current1->next as nextList1 and, nextList1->next as current2 and incrementing them and repeating the steps..
        
        for (int i = 0; i < size_first - 1; i++)
        {
            current1->next = nextList1;
            nextList1->next = current2;
            current1 = current2;
            
            nextList1 = nextList2;
            if (nextList2 != NULL)
                nextList2 = nextList2->next;
            
            if (i < (size_first - 2))
                current2 = current2->next;
        }
        current1->next = nextList1;
        ///********************************* END of Block c ***********************************///
    }
    else
    {
        cout << " \n########## This is an Empty List ########## \n";
    }
}

// ******** Defining a Function to delete the current LINKED LIST ******** 
void SingleList::delete_List()
{
	SingleNode* current = head;
	while (current != NULL)
	{
		head = head->next;
		delete current;
		current = head;
	}
	head = NULL;
}

                        //              <<<<<---- This CPP File is for performing serveral Operations on a Singly Linked List ---->>>>>

#include "DoublyList.h"
#include <iostream>
using namespace std;

// Defines a Constructor of the DoubleNode Class and will intiaze its data value by 0 and its null pointing to the NULL..
DoublyNode::DoublyNode()
{
	data = 0;
	next = NULL;
	prev = NULL;
}

// Defines a Constructor of the SingleList Class..

DoublyList::DoublyList()
{
	head = NULL;	// whenever a new object of SingleList class is created, its constructor will be called defing its head pointer to be NULL..
}



// ******** Definess a Funtion to append to the list  ********

void DoublyList:: Append_to_list(int new_data)
{
	DoublyNode *temp = new DoublyNode();
	temp->data = new_data;		// Creates a new temporary node and assign its data value..

	if (head == NULL)		// check if the list is empty, and if it is then the head will be pointed to this new node..
	{
		head = temp;		
	}
	else
	{

	// if the List is non-empty, these statements will append the above newly created node to the end of the List..

		DoublyNode *temp1;
		temp1 = head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->prev = temp1;

	}

}

//  ******** Definess a Funtion to display the list  ********

void DoublyList:: display_List(int disp_shufle)
{
	DoublyNode* temp;
	temp = head;
	int i = 1;
	if (head == NULL)	//  Check if the List is empty..
	{
		cout << "The List is Empty \n";
	}
	else
	{
		
	// For a non-Empty List, it will iterate through all the nodes and will display it	
		while (temp != NULL)
		{
			if (disp_shufle == 1 && (i == 1 || i == 51))		// These are added for a better display to the Shuffle Function
			{
				if (i == 1)
					cout << "\n\n<<<<=====    ** first half **    =====>>>> \n\n";
				if (i == 51)
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


// This function Displays the List in the Reverse Order. This is just for the checking the previous links not as a part of the functionality..

void DoublyList:: display_Reverse_List()
{
	DoublyNode* temp;
	temp = head;
	if (head == NULL)
	{
		cout << "The List is Empty \n";
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		while (temp != NULL)
		{
			cout << temp->data;
			if (temp->prev != NULL)
				cout << " --> ";

			temp = temp->prev;
		}
	}
	cout << endl << endl;
}


// calculate size of linked list

int DoublyList::list_size(DoublyNode* Node)
{
	size = 0;
	while (Node != NULL)
	{
		Node = Node->next;
		size++;
	}
	return size;
}




// ******** Defining a Function to REVERSE the LINK LIST ********

void DoublyList:: Reverse()
{
    if(head != NULL)
    {
        DoublyNode *newHead;
        DoublyNode *current;
        DoublyNode *temp;
        current = head;
        int count = 0;
        
        // Iterating the current variable to the end of the List, and pointing the head to the current..
        while (current->next != NULL)
        {
            current = current->next;
            count++;
        }
        newHead = current;
        
        for (int i = 0; i <= count; i++)
        {
            
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = current->next;
            
        }
        head = newHead;
    }
    else
    {
        cout << " \n########## This is an Empty List ########## \n";
    }
}

// ******** Defines a Function to sort the list ********

void DoublyList:: sort()	// ***** Using Bubble Sort to sort the List *****
{
    if(head != NULL)
    {
        // ***** Declaring Local Variables ***** //
        
        counter = 0;
        DoublyNode* temp = head;	// a Temp pointer, pointing to the head when initialized..
        DoublyNode* current = head;
        DoublyNode* temp1 = temp->next;
        DoublyNode* stamp;
        
        // ***** End of Declaring Local Variables ***** //
        
        ///********************************* Block A ***********************************///
        
        while (((current->next) != NULL))
        {
            i = 0;
            stamp = current;
            int cal_size = list_size(current);
            
            if (cal_size >= 4)
                cal_size = 4;
            
            ///*********************** Block A1 *************************///
            
            while (i < cal_size - 1 && (stamp->next->next != NULL))
            {
                temp = stamp;
                
                temp1 = temp->next;
                
                int j = cal_size - 1;
                j = j - i;
                int flag = 0;
                
                ///***************** Block A2 *******************///
                
                while (j > 0 && temp->next != NULL && temp1 != NULL)
                {
                    
                    if (temp->data > temp1->data)
                    {
                        DoublyNode* swap = temp1->next;
                        int check = -1;
                        if (current == temp)
                            check = 0;
                        if (current == temp1)
                            check = 1;
                        
                        if (flag == 0 && counter < 4)
                        {
                            temp1->next = temp;
                            temp1->prev = temp->prev;
                            temp->next = swap;
                            temp->prev = temp1;
                            swap->prev = temp;
                            
                            DoublyNode *swap1;
                            swap1 = temp1;
                            temp1 = temp;
                            temp = swap1;
                            
                            
                            head = temp;
                            stamp = temp;
                        }
                        else
                        {
                            temp1->next = temp;
                            temp1->prev = temp->prev;
                            temp->prev->next = temp1;
                            temp->next = swap;
                            temp->prev = temp1;
                            if (swap != NULL)
                                swap->prev = temp;
                            
                            DoublyNode *swap1;
                            swap1 = temp1;
                            temp1 = temp;
                            temp = swap1;
                            
                            if (flag == 0)
                                stamp = temp;
                        }
                        if (check == 1)
                            current = temp1;
                        if (check == 0)
                            current = temp;
                        
                    }
                    
                    
                    j--;
                    flag++;
                    temp = temp->next;
                    temp1 = temp1->next;
                }
                
                ///***************** END of Block A2 *******************///
                i++;
                counter++;
                if (i != cal_size)
                    current = current->next;
            }
            ///*********************** END of Block A1 *************************///
            if (current->next != NULL)
                current = current->next;
            counter++;
        }
        
        ///********************************* END of Block A ***********************************///
    }
    else
    {
        cout << " \n########## This is an Empty List ########## \n";
    }
}




// ******** Defining a Function to SHUFFLE A LINKED LIST ********

// Same Logic as in Implement_Singly Linked List..
void DoublyList:: shuffle()
{
    if(head!=NULL)
    {
        
        ///********************************* Block B ***********************************///
        
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
        DoublyNode* current1;
        DoublyNode* current2;
        DoublyNode* nextList1;
        DoublyNode* nextList2;
        
        current1 = head;
        current2 = current1->next;
        nextList1 = head;
        
        for (int i = 0; i < iterator; i++)
        {
            nextList1 = nextList1->next;
        }
        nextList2 = nextList1->next;
        
        for (int i = 0; i < size_first - 1; i++)
        {
            current1->next = nextList1;
            nextList1->prev = current1;
            
            nextList1->next = current2;
            current2->prev = nextList1;
            
            current1 = current2;
            
            nextList1 = nextList2;
            if (nextList2 != NULL)
                nextList2 = nextList2->next;
            
            if (i < (size_first - 2))
                current2 = current2->next;
        }
        current1->next = nextList1;
        if (nextList1 != NULL)
            nextList1->prev = current1;
        
        ///********************************* END of Block c ***********************************///
    }
    else
    {
        cout << " \n########## This is an Empty List ########## \n";
    }
	
}

// ******** Defining a Function to delete the current LINKED LIST ********
void DoublyList::delete_List()
{
	DoublyNode* current = head;
	while (current != NULL)
	{
		head = head->next;
		delete current;
		current = head;
	}
	head = NULL;
}


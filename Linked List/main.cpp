// main.cpp : Defines the entry point for the console application.
//

#include "SingleList.h"
#include "DoublyList.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
	SingleList singleList;
	DoublyList doubleList;
    srand(time(NULL));
	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 1] --> (Singly linked list -- Team of Four -- Sequence-1) ---->>>>> \n\n";
    
    
	for (int i = 1; i <= 100; i++)
	{
		singleList.Append_to_list(i);
	}
	
	cout << "<<<<=====    The List Before Sorting is:   =====>>>> \n\n";
	singleList.display_List(0);

	// Question 1
	singleList.sort();
	cout << "<<<<=====    The Sorted List is:   =====>>>> \n\n";
	singleList.display_List(0);
	cout << "\n\n============================================================================================================================================================\n\n";
	
	singleList.delete_List();
	//////////////////////////////////////////////////////////////////////////////////////////

	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 2] --> (Doubly linked list -- Team of Four -- Sequence-1) ---->>>>> \n\n";


	cout << "<<<<=====    The List Before Sorting is:   =====>>>> \n\n";

	for (int i = 1; i <= 100; i++)
	{
		doubleList.Append_to_list(i);
	}
	doubleList.display_List(0);

	doubleList.sort();

	cout << "<<<<=====    The Sorted List is:   =====>>>> \n\n";
	doubleList.display_List(0);

	doubleList.delete_List();

	cout << "\n\n============================================================================================================================================================\n\n";
	///////////////////////////////////////////////////////////////////////////////////////////  

	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 3] --> (Singly linked list -- Team of Four -- Sequence-2) ---->>>>> \n\n";
	SingleList singleList1;
	
	for (int i = 0; i < 100 ; i++)
	{
		int num = rand() % 1000 + 1;
		singleList1.Append_to_list(num);
	}

	cout << "<<<<=====    The List Before Sorting is:   =====>>>> \n\n";
	singleList1.display_List(0);

	// Question 1
	singleList1.sort();
	cout << "<<<<=====    The Sorted List is:   =====>>>> \n\n";
	singleList1.display_List(0);
	cout << "\n\n============================================================================================================================================================\n\n";

	singleList1.delete_List();

	///////////////////////////////////////////////////////////////////////////////////////////
	
	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 4] --> (Doubly linked list -- Team of Four -- Sequence-2) ---->>>>> \n\n";
	DoublyList doubleList1;
	for (int i = 1; i <= 100; i++)
	{
		int num = rand() % 1000 + 1;
		doubleList1.Append_to_list(num);
	}

	cout << "<<<<=====    The List Before Sorting is:   =====>>>> \n\n";
	doubleList1.display_List(0);

	doubleList1.sort();
	cout << "<<<<=====    The Sorted List is:   =====>>>> \n\n";
	doubleList1.display_List(0);
	cout << "\n\n============================================================================================================================================================\n\n";

	doubleList1.delete_List();
	///////////////////////////////////////////////////////////////////////////////////////////

	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 5] --> (Singly linked list -- Reverse -- Sequence-1) ---->>>>> \n\n";

	for (int i = 1; i <= 100; i++)
	{
		singleList.Append_to_list(i);
	}

	cout << "\n\n<<<<=====    The List Before Reversing is:   =====>>>> \n\n";
	singleList.display_List(0);

	singleList.Reverse();

	cout << "<<<<=====    The Reversed List is:   =====>>>> \n\n";
	singleList.display_List(0);
	cout << "\n\n============================================================================================================================================================\n\n";
	singleList.delete_List();
	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 6] --> (Doubly linked list -- Reverse -- Sequence-1) ---->>>>> \n\n";
	for (int i = 1; i <= 100; i++)
	{
		doubleList.Append_to_list(i);
	}

	cout << "\n\n<<<<=====    The List Before Reversing is:   =====>>>> \n\n";
	doubleList.display_List(0);

	
	doubleList.Reverse();
	cout << "<<<<=====    The Reversed List is:   =====>>>> \n\n";
	doubleList.display_List(0);

	cout << "\n\n=================================================================================\n\n";
	doubleList.delete_List();

	///////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 7] --> (Singly linked list -- Reverse -- Sequence-2) ---->>>>> \n\n";

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 1000 + 1;
		singleList.Append_to_list(num);
	}

	cout << "\n\n<<<<=====    The List Before Reversing is:   =====>>>> \n\n";
	singleList.display_List(0);

	singleList.Reverse();

	cout << "<<<<=====    The Reversed List is:   =====>>>> \n\n";
	singleList.display_List(0);
	cout << "\n\n============================================================================================================================================================\n\n";
	singleList.delete_List();

	///////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 8] --> (Doubly linked list -- Reverse -- Sequence-2) ---->>>>> \n\n";
	
	for (int i = 1; i <= 100; i++)
	{
		int num = rand() % 1000 + 1;
		doubleList.Append_to_list(num);
	}

	cout << "\n\n<<<<=====    The List Before Reversing is:   =====>>>> \n\n";
	doubleList.display_List(0);


	doubleList.Reverse();
	cout << "<<<<=====    The Reversed List is:   =====>>>> \n\n";
	doubleList.display_List(0);

	cout << "\n\n============================================================================================================================================================\n\n";
	doubleList.delete_List();
	
	///////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 9] --> (Singly linked list -- Shuffle -- Sequence-1) ---->>>>> \n\n";
	
	for (int i = 1; i <= 100; i++)
	{
		singleList.Append_to_list(i);
	}
	
	cout << "\n\n<<<<=====    The List Before Shuffling is:   =====>>>> \n\n";
	singleList.display_List(1);

	// Question 3
	singleList.shuffle();

	cout << "<<<<=====    The Shuffled List is:   =====>>> \n\n";
	singleList.display_List(0);
	cout << "\n\n============================================================================================================================================================\n\n";
	singleList.delete_List();


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 10] --> (Doubly linked list -- Shuffle -- Sequence-1) ---->>>>> \n\n";

	
	cout << "\n\n<<<<=====    The List before Shuffling is:   =====>>>>  \n\n";

	for (int i = 1; i <= 100; i++)
	{
		doubleList.Append_to_list(i);
	}

	doubleList.display_List(1);

	doubleList.shuffle();

	cout << "<<<<=====    The Shuffled List is:   =====>>>> \n\n";
	doubleList.display_List(0);

	doubleList.delete_List();
	cout << "\n\n============================================================================================================================================================\n\n";
    


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 11] --> (Singly linked list -- Shuffle -- Sequence-2) ---->>>>> \n\n";

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 1000 + 1;
		singleList.Append_to_list(num);
	}

	cout << "\n\n<<<<=====    The List Before Shuffling is:   =====>>>> \n\n";
	singleList.display_List(1);

	// Question 3
	singleList.shuffle();

	cout << "<<<<=====    The Shuffled List is:   =====>>>> \n\n";
	singleList.display_List(0);
	cout << "\n\n============================================================================================================================================================\n\n";
	singleList.delete_List();


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	cout << "\t\t\t\t\t <<<<<---- [Test Case No. 12] --> (Doubly linked list -- Shuffle -- Sequence-2) ---->>>>> \n\n";


	cout << "\n\n<<<<=====    Shuffling the List:   =====>>>>  \n\n";

	for (int i = 1; i <= 100; i++)
	{
		int num = rand() % 1000 + 1;
		doubleList.Append_to_list(num);
	}

	doubleList.display_List(1);

	doubleList.shuffle();

	cout << "<<<<=====    The Shuffled List is:   =====>>>> \n\n";
	doubleList.display_List(0);
	doubleList.delete_List();
	cout << "\n\n============================================================================================================================================================\n\n";



	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	return 0;

}


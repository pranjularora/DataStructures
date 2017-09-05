									ReadMe File

This has:

•	4 header files 
•	3 CPP files 


					##########################  	Header Files    ##########################

1) BSTNode.h ---->>>>

Defines node pointer and data values, basically defining data structure of a doubly linked list

2) KDNode.h ---->>>>

Defines node pointer and data values, basically defining data structure of a doubly linked list

3) BSTList.h ---->>>>

This header files contains declaration of all functions that are to be implemented for achieving all the requirement stated for BST Tree.
Definition of all these functions are implemented in “BST_Implement.cpp”

 insert(BSTNode*, int, int); ———>>>>    insert in BST function
 CreateNode(int, int); ———>>>>          create new node function
 search (BSTNode*, int); ———>>>>    search in BST function
 FindMinInRightSubTree(BSTNode*); ———>>>>   find minimum in right subtree function
    
 Delete(BSTNode*, int, int); ———>>>> delete function
    
 displayInOrder(BSTNode*);  ———>>>> display the BST using in order traversal
    
 unique_Random_Numbers(int, int, int);  ———>>>> creates unique random numbers
 BSTHeight(BSTNode*); ———>>>> calculates height of the node
    
    
 displayBstTable(std::vector<std::vector<double>>); ———>>>> display function as per requirement
 displayCase7(std::vector<std::vector<int>>);
    
    
 DotNull(std::string, int, FILE*);———>>>> generates null node
    
 PrintDotFile(BSTNode*, FILE*);   ———>>>> generates dot node
 show_BST(BSTNode*, std::string);  ———>>>> creates whole dot repesentation


4) KDList.h ---->>>>

This header files contains declaration of all functions that are to be implemented for achieving all the requirement stated for KD Tree.
Definition of all these functions are implemented in “KD_Implement.cpp”



insert_KD(KDNode*, std::vector<int>);  // insert in KD
CreateNode(std::vector<int>);   // create new node
displayInOrder(KDNode*);  // diplays inorder of KD
    
KDHeight(KDNode*);        // calculates height
unique_Random_Numbers(int, int, int);  // generates random numbers
    
displayKDTable(std::vector<std::vector<double>>);  // display function as per requirement
smallest_in_KD(KDNode*, int, int); // smallest function
    
Delete_KD(KDNode*, int);
unique_Random_array(int, int, int);
    
DotNull(std::string, int, FILE*);   // generates null node
PrintDotFile(KDNode*, FILE*);  // generates dot node
show_KD(KDNode*, std::string); // creates whole dot repesentation
    
    
search_KD(KDNode*, std::vector<int>, int); // search node in tree
Depth(KDNode* q);  // calculates depth



				       ##########################  	End of Header Files   ##########################




##########################  	CPP Files	  ##########################


1)			<<<<---- BST_Implement.cpp  ---->>>>
Includes definition of all functions that are declared in the  BSTList.h header file.

— BSTNode* BSTList::CreateNode(int key, int value)
function used to create new node.


— BSTNode* BSTList::insert(BSTNode* rootElement, int key, int value)
function used to insert new node.


— BSTNode* BSTList::search(BSTNode* rootElement, int key)
function used to search in BST


— BSTNode* BSTList::FindMinInRightSubTree(BSTNode* rootElement)
function used to find minimum in the right subtree as required by the delete function


— BSTNode* BSTList::Delete(BSTNode * rootElement, int key, int value)
function used to delete a node in BST

— void BSTList::displayInOrder(BSTNode* rootElement)
traverse from root node using in-order

— vector<int> BSTList::unique_Random_Numbers(int min, int max, int size)
creates a vector of unique random numbers

— int BSTList::BSTHeight(BSTNode* rootElement)
calculate height of the BST node

— void BSTList::displayBstTable(vector<vector<double>> BSTvector)
Display fucntion as a per Test Case Requirement

— void BSTList::displayCase7(std::vector<std::vector<int>> BSTvector)
Display fucntion as a per Test Case Requirement

— void BSTList::PrintDotFile(BSTNode* root, FILE* file_Stream)

— void BSTList::show_BST(BSTNode* root, string file)

— void BSTList::DotNull(string values, int count, FILE* file_Stream)
creates a dot file



2)			<<<<---- KD_Implement.cpp  ---->>>>
Includes definition of all functions that are declared in the  smoothSort.h header file.


— KDNode* insert_KD(KDNode*, std::vector<int>);  
 function used to insert in KD, creates new node by assigning values of x_axis, y_axis and data value extracted from the argument vector

— KDNode* CreateNode(std::vector<int>);   
function used to create new node

— void displayInOrder(KDNode*);  
function used to diplays inorder of KD by using left—root—right traversing
    
— int KDHeight(KDNode*);        
function used to calculate height 

— std::vector<std::vector<int>> unique_Random_Numbers(int, int, int);  
function used to generates random numbers

    
— void displayKDTable(std::vector<std::vector<double>>);  
function used to display function as per requirement


— KDNode* smallest_in_KD(KDNode*, int, int); 
function used to smallest function
    
— KDNode* Delete_KD(KDNode*, int);
function used to 

— std::vector<int> unique_Random_array(int, int, int);
function used to generate unique numbers

— void DotNull(std::string, int, FILE*);   
function used to generates null node which has a shape of a point

— void PrintDotFile(KDNode*, FILE*);  
function used to generates dot node 

— void show_KD(KDNode*, std::string); 
creates a dot file
    
  
— bool search_KD(KDNode*, std::vector<int>, int);
function used to search in KD

— int Depth(KDNode* q);
function used to find depth










3)	<<<<---- main.cpp ---->>>>

This file has the main function. So, the execution will start from this file. 
	•	It will create objects of KDList and BSTList.
	•	This file has 8 test cases that will check the required functionality of BST - Tree and KD-Tree.

	<<<<——END of main.cpp ---->>>>	


		##########################  	END of CPP Files	  ##########################




REFERENCES USED-
I have used these 2 websites for a better understanding of smooth sort.
1) http://www.keithschwarz.com/smoothsort/
2) http://www.slideshare.net/habib_786/smooth-sort
3) CLRS book for basics of priority Queue.















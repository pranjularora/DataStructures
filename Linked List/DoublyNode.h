#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

// This header file will create a new node for Doubly Linked List..
class DoublyNode
{
public:
	int data;		// declares a data member of the Double Node which will store the data of the Node..
	DoublyNode *next;	// declares a next pointer of the New node created..
	DoublyNode *prev;	// declares a prev pointer of the New node created..

	DoublyNode();		// declares the constructor of this class..

};

#endif // !DOUBLYNODE_H

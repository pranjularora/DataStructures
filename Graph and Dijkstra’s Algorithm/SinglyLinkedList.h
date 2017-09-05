//
//  SinglyLinkedList.h
//  Graph
//
//  Created by Pranjul Arora on 12/8/16.
//  Copyright © 2016 graphs. All rights reserved.
//

#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h
#include <string>
// class for Node
class Node {
public:
	Node();
	Node(std::string);
 	Node(std::string, int);

	std::string data;
	int wt;  // weight
	int d_cal;
	bool status;
	Node *next; // next
	Node *prev_ns;


};


class SinglyLinkedList
{
public:
	void print();
	
	Node* root; // head
	int length;

	SinglyLinkedList()
	{
		root = NULL;
		length = 0;
	}

};





#endif /* SinglyLinkedList_h */

//
//  List_Implementation.cpp
//  Graph
//
//  Created by Pranjul Arora on 12/8/16.
//  Copyright © 2016 graphs. All rights reserved.
//

#include <stdio.h>
#include "SinglyLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

Node::Node()
{
	data = "";
	wt = 0;
	status = false;

	next = NULL;
	prev_ns = NULL;
	d_cal = 999;

}

Node::Node(string value)
{
	data = value;
	wt = 0;
	status = false;
	next = NULL;
	prev_ns = NULL;
	d_cal = 999;   ////////////////##########

}

Node::Node(string value, int wt_val)
{
	data = value;
	wt = 0;
	status = false;
	wt = wt_val;

	next = NULL;
	prev_ns = NULL;
	d_cal = 999;   ////////////////##########
}

void SinglyLinkedList::print()
{
	if (root != NULL)
	{
		Node *temp;
		temp = root;

		int counter = 0;

		while (temp->next != NULL)
		{
			if (counter == 10)
			{
				counter = 0;
			}
			cout << temp->data << "->";
			counter++;
			temp = temp->next;
		}
		cout << temp->data;
		cout << endl;

	}
}


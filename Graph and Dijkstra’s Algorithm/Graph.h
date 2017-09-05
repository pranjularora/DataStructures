//
//  Graph.h
//  Graph
//
//  Created by Pranjul Arora on 12/8/16.
//  Copyright © 2016 graphs. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include "SinglyLinkedList.h"
#include <vector>
#include <tr1/unordered_map>
using namespace std;
// header file declaring all the required functions to complete assignment.

class Graph
{
public:
	bool undir_graph;
	int Vertex_Count;
	int edged_Count;
	vector<Node*> Adjacency_List;
	vector<string> vertex_List;

	Graph();
	Graph(string);
	vector<int> unique_Random_array(int, int, int);
	void adding_new_Edge(string, string, int);

	void adding_new_Vertex(string);

	bool find_Vertex(string);

	Node* Vertext_in_list(string);

	void deleteVertex(string);

	void deleteEdge(string, string);

	bool checkEdge(Node*, Node*);

	

	/////////////////////////////////// Dijkastra




	void dijkstra_shortest_Path(string);

	Node* minimum_Distance();

	void updateValues(Node*, Node*);

	int calculate_wt(Node*, Node*);

	void Path_tables(int, string);

	void Print_Distance(int, string);

	std::tr1::unordered_map<string, string> Path_locator(string, string);

	void Update_Vertices(string, int, Node*);

	void initialize_List();

};




#endif /* Graph_h */

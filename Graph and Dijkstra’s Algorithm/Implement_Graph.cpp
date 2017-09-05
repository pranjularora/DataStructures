//
//  Implement_Graph.cpp
//  Graph
//
//  Created by Pranjul Arora on 12/8/16.
//  Copyright © 2016 graphs. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Graph.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;


// no argument constructor
Graph::Graph()
{
	undir_graph = true;
	Vertex_Count = 0;
}

// the constructor will help in generating graph
Graph::Graph(string inputFile)
{
	// string line;
	int iteration = 0;
	ifstream fileName(inputFile.c_str());
	if (fileName.is_open())
	{

		while (fileName.good())
		{
			string readLine;
			getline(fileName, readLine);

			stringstream single_line(readLine);
			for (size_t i = 0; i < readLine.size(); i++)
			{
				string val;
				getline(single_line, val, ',');
				const char* c = val.c_str();
				int local_wt = atoi(c);
				if (iteration == 0)
				{
					if (val != "" && i != 0)
					{
						vertex_List.push_back(val);
					}
				}
				else
					if (local_wt > 0 && i > 0)
					{
						adding_new_Edge(vertex_List.at(iteration - 1), vertex_List.at(i - 1), local_wt);
					//	cout << endl << vertex_List.at(iteration - 1) << "----" << vertex_List.at(i - 1);
					}
			}
			iteration++;
		}
	}

	else
	{
		cout << "\n\nError in opening file\n";
	}

}

// a new vertex will be added and will be inserted into adjacency list as well
void Graph::adding_new_Vertex(string ver)
{
	if (!find_Vertex(ver))
	{
		Node* vertex = new Node(ver);
		Adjacency_List.push_back(vertex);
		Vertex_Count++;
	}

}
// add edges between the two vertex
void Graph::adding_new_Edge(string vertex1, string vertex2, int wt)
{
	bool new_edge = true;
	adding_new_Vertex(vertex1);
	adding_new_Vertex(vertex2);

	Node* check = Vertext_in_list(vertex1);
	while (check->next != NULL)
	{
		if (check->next->data == vertex2)
		{
			new_edge = false;
			break;
		}
		else
			check = check->next;
	}
	if (new_edge)
	{
		check->next = new Node(vertex2, wt);
		edged_Count++;
	}
	new_edge = true;
	if (undir_graph)
	{
		Node* temp = Vertext_in_list(vertex2);
		while (temp->next != NULL)
		{
			if (temp->next->data == vertex1)
			{
				new_edge = false;
				break;
			}
			else
				temp = temp->next;
		}
		if (new_edge)
		{
			temp->next = new Node(vertex1, wt);
			edged_Count++;
		}
	}
}

// check if vertex exists
bool Graph::find_Vertex(string vertex)
{
	for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
		if ((*iterate)->data == vertex)
			return true;
	return false;

}

// a reference will be returned
Node* Graph::Vertext_in_list(string VertexVal)
{
	for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
		if ((*iterate)->data == VertexVal)
			return *iterate;
	return NULL;
}

// delete vertex and all its edges
void Graph::deleteVertex(string vertexVal)
{
	if (find_Vertex(vertexVal))
	{
		Node* removeV = Vertext_in_list(vertexVal);
		for (vector<Node*>::iterator temp = Adjacency_List.begin(); temp != Adjacency_List.end(); temp++)
		{
			if ((checkEdge(removeV, (*temp))) || (checkEdge((*temp), removeV)))
			{
				deleteEdge(removeV->data, (*temp)->data);

			}
		}
		for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
		{
			if ((*iterate)->data == vertexVal)
			{
				Adjacency_List.erase(iterate);
				break;
			}
		}
		for (vector<string>::iterator i = vertex_List.begin(); i != vertex_List.end(); i++)
		{
			if (*i == vertexVal)
			{
				vertex_List.erase(i);
				break;
			}
		}
	}
	//Adjacency_List.erase(remove(Adjacency_List.begin(), Adjacency_List.end(), vertexVal), Adjacency_List.end());
}


// check if edge exists
bool Graph::checkEdge(Node* E1, Node* E2)
{
	Node* getV = Vertext_in_list(E1->data);
	if (getV != NULL)
	{
		Node* temp = getV->next;
		while (temp != NULL)
		{
			if (temp->data == E2->data)
			{
				return true;
			}
			temp = temp->next;
		}
	}
	return false;

}

// delete edges between the the vertex
void Graph::deleteEdge(string vertex1, string vertex2)
{
	if (Vertext_in_list(vertex1) != NULL && Vertext_in_list(vertex2) != NULL)
	{
		Node* ver1 = Vertext_in_list(vertex1);
		Node* current = NULL;
		Node* prev = ver1;
		current = ver1->next;
		while (current != NULL)
		{
			if (current->data == vertex2)
			{
				if (current->next == NULL)
				{
					prev->next = NULL;
					edged_Count--;
				}
				else
				{
					prev->next = current->next;
					edged_Count--;
					break;
				}
			}
			prev = current;
			current = current->next;
		}



	}
	//if (undir_graph) // if undir_graph the vertex2 to vertex1 will be deleted
//	{
		Node* ver2 = Vertext_in_list(vertex2);
		Node* current = NULL;
		Node* prev = ver2;
		current = ver2->next;
		while (current != NULL)
		{
			if (current->data == vertex1)
			{
				if (current->next == NULL)
				{
					prev->next = NULL;
					edged_Count--;
				}
				else
				{
					prev->next = current->next;
					edged_Count--;
					break;
				}
			}
			prev = current;
			current = current->next;
		}

	//}
}


vector<int> Graph::unique_Random_array(int min, int max, int size)
{
	vector<int> uniqueKeys;
	for (int i = 0; i < size; i++)
	{
		int flag = 1;
		while (flag == 1)
		{
			int random_number = rand() % (max - min + 1) + min;
			if (uniqueKeys.size() == 0)
			{
				uniqueKeys.push_back(random_number);
				flag = 0;
				break;
			}
			for (size_t j = 0; j < uniqueKeys.size(); j++)
			{
				if (random_number == uniqueKeys[j]) // checking if element already exists
				{
					flag = 1;
					break;
				}
				else
					flag = 0;
			}
			if (flag == 0) // this states if not exists then add it
				uniqueKeys.push_back(random_number);
		}
	}
	return uniqueKeys;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

//find the minimum of distances of all vertices
Node* Graph::minimum_Distance()
{
	int d_min = 999;
	Node* temp = NULL;
	for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
	{
		if ((*iterate)->d_cal < d_min && (*iterate)->status == false)
		{
			d_min = (*iterate)->d_cal;
			temp = Vertext_in_list((*iterate)->data);
		}

	}
	return temp;
}




// use dijkstra to calculate shortest path
void Graph::dijkstra_shortest_Path(string vertex)
{
	initialize_List();
	string getV = vertex;
	Node* dis = Vertext_in_list(getV);
	dis->d_cal = 0;
	for (int i = 0; i < Vertex_Count; i++)
	{
		Node* dis = Vertext_in_list(vertex);
		dis->status = true;
		Node* temp = dis->next;
		while (temp != NULL)
		{
			if (!Vertext_in_list(temp->data)->status)
				updateValues(dis, temp);
			temp = temp->next;
		}
		dis = minimum_Distance();
		if (dis != NULL)
			vertex = dis->data;
		else
			break;
	}
}

//updating values of d_Cal
void Graph::updateValues(Node* first, Node* second)
{
	int wt = calculate_wt(first, second);
	if (second->d_cal > (first->d_cal + wt))
	{
		Update_Vertices(second->data, (first->d_cal + wt), first);
	}
}

// update all vertices
void Graph::Update_Vertices(string vertexVal, int new_dCal, Node* prev_new)
{
	for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
	{
		if ((*iterate)->data == vertexVal)
		{
			(*iterate)->d_cal = new_dCal;
			(*iterate)->prev_ns = prev_new;
		}
		Node* temp = (*iterate)->next;
		while (temp != NULL)
		{
			if (temp->data == vertexVal)
			{
				temp->d_cal = new_dCal;
				temp->prev_ns = prev_new;
			}
			temp = temp->next;
		}
	}
}



//calculate and return weights
int Graph::calculate_wt(Node* first, Node* second)
{
	Node* iterate = Vertext_in_list(first->data);
	Node* temp = iterate->next;
	while (temp != NULL)
	{
		if (temp->data == second->data)
		{
			return temp->wt;
		}
		temp = temp->next;
	}
	return 999;
}


// initializer
void Graph::initialize_List()
{
	for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
	{
		(*iterate)->d_cal = 999;
		(*iterate)->prev_ns = NULL;
		(*iterate)->status = false;

		Node* temp = (*iterate)->next;
		while (temp != NULL)
		{
			temp->d_cal = 999;
			temp->status = false;
			temp->prev_ns = NULL;
			temp = temp->next;
		}
	}
}

// Path from each vertex
void Graph::Path_tables(int count, string vertex)
{
	cout << "\n------------------------------------------------------------------------";
	cout << "\n   Vertex Name \t The Path from source vertex " << vertex << " to this vertex in G3" << "\n";
	cout << "------------------------------------------------------------------------";
	int incr = 1;
	for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
	{
		if (incr <= count)
		{
			if ((*iterate)->data != vertex)
			{
				vector<std::string> calcPath;
				int weight = 0;
				calcPath.push_back((*iterate)->data);

				if ((*iterate)->prev_ns != NULL)
				{
					calcPath.push_back(((*iterate)->prev_ns)->data);
					weight += calculate_wt((*iterate)->prev_ns, (*iterate));
					Node* temp = (*iterate)->prev_ns;
					while (temp->data != vertex)
					{
						calcPath.push_back((temp->prev_ns)->data);
						weight += calculate_wt(temp->prev_ns, temp);
						temp = temp->prev_ns;
					}
				}
				if (calcPath.size() > 1)
				{
					cout << endl << "\t";
					cout << (*iterate)->data; 
					cout << " \t\t";
					incr++;
				}
				while (calcPath.size() > 0)
				{
					cout << calcPath.back() << " ";
					calcPath.erase(calcPath.end() - 1);
				}
			}
			else
			{
				cout << "\n\t" << (*iterate)->data << " \t\t";
				cout << "nil";
			}
		}
	}
	cout << endl;
}

// distance from every vertex
void Graph::Print_Distance(int count, string vertex)
{
	std::cout << "\n   Vertex Name \t Distance from source vertex " << vertex << "\n";
	for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
	{
		if ((*iterate)->data != vertex)
		{
			vector<std::string> calcPath;
			int weight = 0;

			calcPath.push_back((*iterate)->data);

			if ((*iterate)->prev_ns != NULL)
			{
				calcPath.push_back(((*iterate)->prev_ns)->data);
				weight += calculate_wt((*iterate)->prev_ns, (*iterate));
				Node* temp = (*iterate)->prev_ns;
				while (temp->data != vertex)
				{

					calcPath.push_back((temp->prev_ns)->data);
					weight += calculate_wt(temp->prev_ns, temp);
					temp = temp->prev_ns;
				}
			}
			if (weight > 0)
			{
				cout << "\n\t" << (*iterate)->data << "\t";
				cout << "\t\t" << weight;
			}
			while (calcPath.size() > 0)
			{
				calcPath.erase(calcPath.end() - 1);
			}
		}
	}
	cout << endl;
}

// it will return the path from source to destination
std::tr1::unordered_map<string, string> Graph::Path_locator(string destination, string source)
{
	std::tr1::unordered_map<string, string> all_edg;
	
	int incr = 0;
	string check_Dest;
	for (vector<Node*>::iterator iterate = Adjacency_List.begin(); iterate != Adjacency_List.end(); iterate++)
	{
		check_Dest = vertex_List.at(incr);

		if (check_Dest == destination)
		{
			if ((*iterate)->data != source)
			{
				vector<std::string> calcP;
				calcP.push_back((*iterate)->data);
				if ((*iterate)->prev_ns != NULL)
				{
					calcP.push_back(((*iterate)->prev_ns)->data);
					Node* temp = (*iterate)->prev_ns;
					while (temp->data != source)
					{
						calcP.push_back((temp->prev_ns)->data);
						temp = temp->prev_ns;
					}
				}
				while (calcP.size() > 0)
				{
					string edg1 = calcP.back();
					calcP.erase(calcP.end() - 1);
					if (calcP.size() > 0)
					{
						string edg2 = calcP.back();
						all_edg.insert({ edg1, edg2 });
					}
				}
			}
		}
		incr++;
	}
	return all_edg;
}

//
//  main.cpp
//  Graph
//
//  Created by Pranjul Arora on 12/8/16.
//  Copyright © 2016 graphs. All rights reserved.
//

#include <iostream>
#include <sstream>

#include "Graph.h"
#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "stdio.h"
#include <iomanip>
#include <string>
#include <time.h>


using namespace std;
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

void disp_dot_graph(Graph* graph, FILE* stream, int flag)
{
	if (graph->undir_graph)
		fprintf(stream, "strict graph {\n");
	else
		fprintf(stream, "digraph BST {\n");
	fprintf(stream, "    node [fontname=\"Arial\"];\n");
	vector<Node*> temp = graph->Adjacency_List;
	if (temp.size() == 0)
		fprintf(stream, "\n");
	else
	{
		for (vector<Node*>::iterator iterator = temp.begin(); iterator != temp.end(); iterator++)
		{

			Node* temp = (*iterator)->next;
			if (temp != NULL)
			{
				while (temp != NULL)
				{
					ostringstream conv_str;
					conv_str << (*iterator)->data;
					std::string sc = conv_str.str();
					conv_str.str("");
					conv_str << temp->data;
					std::string tData = conv_str.str();
					
					if (graph->undir_graph)
					{

						fprintf(stream, "    %s -- %s;\n", sc.c_str(), tData.c_str());
					}
					else
					{
						int weight = graph->calculate_wt((*iterator),temp);
						conv_str.str("");
						conv_str << weight;
						std::string lb = conv_str.str();
						if (flag == 1)
						{
							fprintf(stream, "    %s -> %s[label=%s];\n", sc.c_str(), tData.c_str(), lb.c_str());
						}
						else
						{
							fprintf(stream, "    %s -> %s;\n", sc.c_str(), tData.c_str());
						}
					}
					temp = temp->next;
				}
			}
			else
			{
				ostringstream conv_str;
				conv_str << (*iterator)->data;
				string sc = conv_str.str();
				fprintf(stream, "    %s;\n", sc.c_str());
			}
		}
	}
	fprintf(stream, "}\n");
}

void disp_dot_color_graph(Graph* graph, FILE* stream, std::tr1::unordered_map<string,string> edges, string put_color)
{
	if (graph->undir_graph)
		fprintf(stream, "strict graph {\n");
	else
		fprintf(stream, "digraph BST {\n");
	fprintf(stream, "    node [fontname=\"Arial\"];\n");
	std::vector<Node*> temp = graph->Adjacency_List;
	if (temp.size() == 0)
		fprintf(stream, "\n");
	else
	{
		for (std::vector<Node*>::iterator it = temp.begin(); it != temp.end(); it++)
		{

			Node* temp = (*it)->next;
			if (temp != NULL)
			{
				while (temp != NULL)
				{
					
					string x1 = (*it)->data;
					string x2 = temp->data;
					std::tr1::unordered_map<string, string>::iterator iter;
					bool color = false;
					iter = edges.find(x1);
					ostringstream conv_str;
					int weight = graph->calculate_wt((*it),temp);
					conv_str.str("");
					conv_str << weight;
					std::string lb = conv_str.str();

					if (iter != edges.end())
					{
						if (iter->second == x2)
							color = true;
					}
					if (graph->undir_graph)
					{
						if (color)
							fprintf(stream, "    \"%s\" -- \"%s\"[color=\"%s\",label=%s];\n", (*it)->data.c_str(), temp->data.c_str(), put_color.c_str(), lb.c_str());
						else
							fprintf(stream, "    \"%s\" -- \"%s\"[label=%s];\n", (*it)->data.c_str(), temp->data.c_str(), lb.c_str());
					}
					else
					{
						if (color)
							fprintf(stream, "    \"%s\" -> \"%s\"[color=\"%s\",label=%s];\n", (*it)->data.c_str(), temp->data.c_str(), put_color.c_str(), lb.c_str());
						else
							fprintf(stream, "    \"%s\" -> \"%s\"[label=%s];\n", (*it)->data.c_str(), temp->data.c_str(), lb.c_str());
					}
					temp = temp->next;
				}
			}
			else
				fprintf(stream, "    \"%s\";\n", (*it)->data.c_str());
		}
	}
	fprintf(stream, "}\n");
}

int main() {
	
	srand(time(NULL));
	// Test case1
	cout << "\n\n/============================== TEST CASE 1 ==============================/\n\n";

	Graph g1("../../fig1.csv");
	g1.undir_graph = true;
	cout << "\n \t Undirected ------- Unweighted \n";
	cout << "at 0";
	string f1 = "t1.dot";
	FILE *t1 = fopen (f1.c_str(), "w+");
	
	disp_dot_graph(&g1, t1, 0);
	cout << "\n\n Dot file t1.dot created";

	cout << "\n\n/============================== TEST CASE 2 ==============================/\n\n";

	Graph g2("../../fig2.csv");
	g2.undir_graph = false;
	cout << "\n \t directed ------- Unweighted\n";

	string f2 = "t2.dot";
	FILE *t2 = fopen (f2.c_str(), "w+");
	disp_dot_graph(&g2, t2, 0);
	cout << "\n\nDot file t2.dot created";

	cout << "\n\n/============================== TEST CASE 3 ==============================/\n\n";

	Graph g3("../../fig3-w.csv");
	g3.undir_graph = false;
	cout << "\n \t directed ------- weightedr\n";

	string f3 = "t3.dot";
	FILE *t3 = fopen (f3.c_str(), "w+");

	disp_dot_graph(&g3, t3, 1);
	cout << "\n\n Dot file t3.dot created";

	cout << "\n\n/============================== TEST CASE 4 ==============================/\n\n";
	cout << "\n Adding vertex \"Z\" and Edges \n";
	g1.adding_new_Vertex("z");
	g1.adding_new_Edge("z", "w", 1);
	g1.adding_new_Edge("z", "x", 1);
	g1.adding_new_Edge("z", "y", 1);
	g1.undir_graph = true;

	string f4a = "t4a.dot";
	FILE *t4a = fopen (f4a.c_str(), "w+");

	
	disp_dot_graph(&g1, t4a, 0);
	cout << "\n\n Dot File t4a.dot created";
	cout << "\n Deleting vertex \"S\" and Edges \n";
	g1.deleteVertex("s");

	cout << "\n Deleting vertex \"X\" and Edges \n";
	g1.deleteVertex("x");

	cout << "\n Deleting edges between \"S\" and \"U and T\" \n";
	g1.deleteEdge("u", "t");
	g1.undir_graph = true;
	string f4b = "t4b.dot";
	FILE *t4b = fopen (f4b.c_str(), "w+");

	disp_dot_graph(&g1, t4b, 0);
	cout << "\n\n Dot File t4b.dot created";

	cout << "\n\n/============================== TEST CASE 5 ==============================/\n\n";

	Graph g5;
	g5.undir_graph = true;

	cout << "\n Adding vertex \"6....10\" and Edges \n";
	for (int i = 6; i <= 10; i++)
	{
		g5.adding_new_Vertex(patch::to_string(i));
	}
	g5.adding_new_Edge("6", "7", 1);
	g5.adding_new_Edge("7", "8", 1);
	g5.adding_new_Edge("8", "9", 1);
	g5.adding_new_Edge("9", "10", 1);
	g5.adding_new_Edge("10", "6", 1);

	cout << "\n Adding vertex \"1....5\" and Edges \n";
	for (int i = 1; i <= 5; i++)
	{
		g5.adding_new_Vertex(patch::to_string(i));
	}

	g5.adding_new_Edge("1", "6", 1);
	g5.adding_new_Edge("2", "7", 1);
	g5.adding_new_Edge("3", "8", 1);
	g5.adding_new_Edge("4", "9", 1);
	g5.adding_new_Edge("5", "10", 1);

	string f5a = "t5a.dot";
	FILE *t5a = fopen (f5a.c_str(), "w+");

	
	disp_dot_graph(&g5, t5a, 0);
	cout << "\n\n Dot File t5a.dot created";
	cout << "\n Deleting vertex \"8 and then 6\" \n";
	g5.deleteVertex("8");
	g5.deleteVertex("6");

	string f5b = "t5b.dot";
	FILE *t5b = fopen (f5b.c_str(), "w+");
	
	
	disp_dot_graph(&g5, t5b, 0);
	cout << "\n\n Dot File t5b.dot created";



	cout << "\n\n/============================== TEST CASE 6 ==============================\n\n";
	Graph g6;
	g6.undir_graph = false;

	vector<int> randomNumber_Vec = g6.unique_Random_array(0, 4, 5);
	vector<int> insertVec;
	vector<int> insertVec1;
	int j = 2;
	for (int i = 0; i < 5; i++)
	{
		insertVec.push_back(j);
		j = j + 2;
	}

	for (size_t i = 0; i < insertVec.size(); i++)
	{
		cout << "\nInserting random value: " << insertVec.at(randomNumber_Vec.at(i));
		g6.adding_new_Vertex(patch::to_string(insertVec.at(randomNumber_Vec.at(i))));
	}

	g6.adding_new_Edge("2", "4", 1);
	g6.adding_new_Edge("2", "6", 1);
	g6.adding_new_Edge("4", "6", 1);
	g6.adding_new_Edge("4", "8", 1);
	g6.adding_new_Edge("6", "8", 1);
	g6.adding_new_Edge("6", "10", 1);
	g6.adding_new_Edge("8", "10", 1);
	g6.adding_new_Edge("8", "2", 1);


	j = 1;
	for (int i = 0; i < 5; i++)
	{
		insertVec1.push_back(j);
		j = j + 2;
	}

	for (size_t i = 0; i < insertVec1.size(); i++)
	{
		cout << "\nInserting random value: " << insertVec1.at(randomNumber_Vec.at(i));
		g6.adding_new_Vertex(patch::to_string(insertVec1.at(randomNumber_Vec.at(i))));
	}

	// insert edges
	cout << "\nInserting edges\n";
	for (int i = 1; i <= 10; i = i + 2)
	{
		g6.adding_new_Edge(patch::to_string(i), patch::to_string(i + 1), 1);
		cout << endl << i << " " << i + 1 << endl;

	}

	string f6a = "t6a.dot";
	FILE *t6a = fopen (f6a.c_str(), "w+");

	
	disp_dot_graph(&g6, t6a, 0);
	cout << "\n\n Dot File t6a.dot created";

	int random_number = rand() % (0 - 4 + 1) + 0;
	cout << "\nDeleting: " << insertVec.at(randomNumber_Vec.at(random_number));
	g6.deleteVertex(patch::to_string(insertVec.at(randomNumber_Vec.at(random_number))));


	int random_number1 = random_number;
	while (random_number != random_number1)
	{	
	    random_number1 = rand() % (0 - 4 + 1) + 0;
	}
	cout << "\nDeleting: " << insertVec1.at(randomNumber_Vec.at(random_number1));
	g6.deleteVertex(patch::to_string(insertVec1.at(randomNumber_Vec.at(random_number1))));

	string f6b = "t6b.dot";
	FILE *t6b = fopen (f6b.c_str(), "w+");

	
	disp_dot_graph(&g6, t6b, 0);
	cout << "\n\n t6b.dot created";


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////


	cout << "\n\n/============================== TEST CASE 7 ==============================/\n\n";

	g3.dijkstra_shortest_Path("s");
	g3.Print_Distance(g3.Vertex_Count, "s");

	g3.dijkstra_shortest_Path("t");
	g3.Print_Distance(g3.Vertex_Count, "t");



	g3.dijkstra_shortest_Path("y");
	g3.Print_Distance(g3.Vertex_Count, "y");



	g3.dijkstra_shortest_Path("x");
	g3.Print_Distance(g3.Vertex_Count, "x");

	g3.dijkstra_shortest_Path("z");
	g3.Print_Distance(g3.Vertex_Count, "z");

	cout << "\n\n/============================== TEST CASE 8 ==============================/\n\n";
	Graph g4("../../fig3-w.csv");
	g4.undir_graph = true;

	g4.dijkstra_shortest_Path("s");
	g4.Print_Distance(g4.Vertex_Count, "s");


	g4.dijkstra_shortest_Path("t");
	g4.Print_Distance(g4.Vertex_Count, "t");

	g4.dijkstra_shortest_Path("y");
	g4.Print_Distance(g4.Vertex_Count, "y");

	g4.dijkstra_shortest_Path("x");
	g4.Print_Distance(g4.Vertex_Count, "x");

	g4.dijkstra_shortest_Path("z");
	g4.Print_Distance(g4.Vertex_Count, "z");




	cout << "\n\n/============================== TEST CASE 9 ==============================/\n\n";

	g3.dijkstra_shortest_Path("s");
	g3.Path_tables(g3.Vertex_Count, "s");


	g3.dijkstra_shortest_Path("z");
	g3.Path_tables(g3.Vertex_Count, "z");

	cout << "\n\n/============================== TEST CASE 10 ==============================/\n\n";

	g4.dijkstra_shortest_Path("s");
	g4.Path_tables(g4.Vertex_Count, "s");


	g4.dijkstra_shortest_Path("z");
	g4.Path_tables(g4.Vertex_Count, "z");

	cout << "\n\n/============================== TEST CASE 11 ==============================/\n\n";

	vector<std::tr1::unordered_map<string, string> > vec_Paths;
	vector<int> cost;
	for (size_t i = 0; i < g3.vertex_List.size(); i++)
	{
		string src = g3.vertex_List.at(i);
		for (size_t i = 0; i < g3.vertex_List.size(); i++)
		{
			g3.dijkstra_shortest_Path(src);
			std::tr1::unordered_map<string, string> getEdg = g3.Path_locator(g3.vertex_List.at(i), src);
			if (getEdg.size() != 0)
			{
				vec_Paths.push_back(getEdg);
				int wt = 0;
				for (std::tr1::unordered_map<string, string>::iterator it = getEdg.begin(); it != getEdg.end(); it++)
				{
					wt = wt + g3.calculate_wt(g3.Vertext_in_list(it->first), g3.Vertext_in_list(it->second));
				}
				cost.push_back(wt);
			}
		}
	}
	int findMaxi = cost.at(0);
	int maximum = 0;
	for (size_t i = 0; i < cost.size(); i++)
	{
		if (findMaxi < cost.at(i))
		{
			maximum = i;
			findMaxi = cost.at(i);
		}

	}

	std::tr1::unordered_map<string, string> path = vec_Paths.at(maximum);
	int count = 0;
	cout << "\nGraph G3 Path: ";
	for (std::tr1::unordered_map<string, string>::iterator iterator = path.begin(); iterator != path.end(); iterator++)
	{
		if (count == 0)
			cout << iterator->first << "->" << iterator->second;
		else
			cout << "->" << iterator->second;
		count++;
	}

	cout << "\n\n dot file t11.dot created!!";
	string f11 = "t11.dot";
	FILE *t11 = fopen (f11.c_str(), "w+");
	

	disp_dot_color_graph(&g3, t11, path, "red");




	cout << "\n\n/============================== TEST CASE 12 ==============================/\n\n";
	vector<std::tr1::unordered_map<string, string> > vec_Paths1;
	vector<int> pathCosts2;
	for (size_t i = 0; i < g4.vertex_List.size(); i++)
	{
		string source = g4.vertex_List.at(i);
		for (size_t i = 0; i < g4.vertex_List.size(); i++)
		{
			g4.dijkstra_shortest_Path(source);
			std::tr1::unordered_map<string, string> edge2 = g4.Path_locator(g4.vertex_List.at(i), source);
			if (edge2.size() != 0)
			{
				vec_Paths1.push_back(edge2);
				int weight = 0;
				for (std::tr1::unordered_map<string, string>::iterator it = edge2.begin(); it != edge2.end(); it++)
				{
					weight = weight + g4.calculate_wt(g4.Vertext_in_list(it->first), g4.Vertext_in_list(it->second));
				}
				pathCosts2.push_back(weight);
			}
		}
	}
	int findMaxi1 = pathCosts2.at(0);
	int maximum1 = 0;
	for (size_t i = 0; i < pathCosts2.size(); i++)
	{
		if (findMaxi1 < pathCosts2.at(i))
		{
			maximum1 = i;
			findMaxi1 = pathCosts2.at(i);
		}

	}

	std::tr1::unordered_map<string,string> pc2 = vec_Paths1.at(maximum1);
	int counter = 0;
	cout << "\nGraph G4 Path:\n ";
	for (std::tr1::unordered_map<string, string>::iterator iterator = pc2.begin(); iterator != pc2.end(); iterator++)
	{
		if (counter == 0)
			cout << iterator->first << "->" << iterator->second;
		else
			cout << "->" << iterator->second;
		counter++;
	}

	cout << "\n\n Dot file t12.dot created";

	string f12 = "t12.dot";
	FILE *t12 = fopen (f12.c_str(), "w+");

	disp_dot_color_graph(&g4, t12, pc2, "blue");
	cout << endl;

	return 0;
}

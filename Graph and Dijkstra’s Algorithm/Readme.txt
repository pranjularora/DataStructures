Note: For a better view open this file in Notepad++.
									
									ReadMe File

This has:

•	2 header files 
•	3 CPP files 


					##########################  	Header Files    ##########################

1) SinglyLinkedList.h
Defines 2 classes --> Node and SinglyLinkedList
Node-> defines structure of the class
SinglyLinkedList-> constructor defining root i.e, head

2) Graph.h
List of all the functions declared are- 

Funcitonality will be explained below:
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

	/////////////////////////////////// USED for -Dijkastra

	void dijkstra_shortest_Path(string);

	Node* minimum_Distance();

	void updateValues(Node*, Node*);

	int calculate_wt(Node*, Node*);

	void Path_tables(int, string);

	void Print_Distance(int, string);

	unordered_map<string, string> Path_locator(string, string);

	void Update_Vertices(string, int, Node*);

	void initialize_List();



				       ##########################  	End of Header Files   ##########################




##########################  	CPP Files	  ##########################

1) ListImplementation.cpp --> defines all function declared in SinglyLinkedList.h
Node::Node() --> No arguments constructor

Node::Node(string value) --> this will take value for data field

Node::Node(string value, int wt_val) --> this will take values for data and weight field

void SinglyLinkedList::print() --> print function

2) Implement_Graph.cpp --> defines all functions declared in Graph.h


--> Graph::Graph() --> constructor

--> Graph::Graph(string inputFile) --> the constructor takes an inputFile and will help in generating graph


--> void Graph::adding_new_Edge(string vertex1, string vertex2, int wt) --> // add edges between the two vertex

--> bool Graph::find_Vertex(string vertex) --> // check if vertex exists and return true or false



--> Node* Graph::Vertext_in_list(string VertexVal) -> // a reference to the vertex will be returned


--> void Graph::deleteVertex(string vertexVal) // delete vertex and all its edges
	--> it uses these functions to delete
		- find_Vertex
		- checkEdge
		- vertex_in_list
	

--> bool Graph::checkEdge(Node* E1, Node* E2) -> check if edge exists between these 2 vertices
	it uses - vertex_in_list function
		
--> void Graph::deleteEdge(string vertex1, string vertex2) --> delete edges between the the vertex
	- uses functions
		vertex_in_list
		and if the graph is undirected then edge between vertex2 and vertex1 will also be deleted
	

--> vector<int> Graph::unique_Random_array(int min, int max, int size) --> generates a vector of random numbers

Now functions for dijkstra
////////////////////////////////////////////////////////////////////////////////////////////


--> Node* Graph::minimum_Distance() --> find the minimum of distances of all vertices

--> void Graph::dijkstra_shortest_Path(string vertex) --> use dijkstra to calculate shortest path
	-- uses 
		initialize_List();
		Vertext_in_list(getV);
		minimum_Distance();
	

--> void Graph::updateValues(Node* first, Node* second) --> updating values of d_Cal
	uses--Update_Vertices(second->data, (first->d_cal + wt), first);
	
--> void Graph::Update_Vertices(string vertexVal, int new_dCal, Node* prev_new)-- update all vertices

--> int Graph::calculate_wt(Node* first, Node* second) --> calculate and return weights
	uses-- vertex_in_list


--> void Graph::initialize_List() --> intializer

--> void Graph::Path_tables(int count, string vertex) --> creates a table that will show from every source to each destination--> 

--> Void Graph::Print_Distance(int count, string vertex) --> distance from every vertex


--> std::unordered_map<string, string> Graph::Path_locator(string destination, string source)
	it will return the path from source to destination, all the edges will be returned


3)	<<<<---- main.cpp ---->>>>

This file has the main function. So, the execution will start from this file. 
	•	It will create objects of Graph.h and SinglyLinkedList.h.
	•	This file has 12 test cases that will check the required functionality of Adjacency_List and dijkstra.

	<<<<——END of main.cpp ---->>>>	


		##########################  	END of CPP Files	  ##########################




REFERENCES USED-

1) CLRS book for basics of priority Queue.















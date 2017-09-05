

=====================
LinkedList Directory-
=====================

-- Singly and Doubly Linkedlist have been implemented to solve the following problems-

1) Team of "N" problem- 
It will rearrange the list so that, for each block in the list of size N, the node will be sorted 
in ascending order, according to the data stored in these nodes. 

For example, in the singly linked list case(N = 4), 

if the list is: 
    Head ->[ 2 ]->[ 3 ]->[ 1 ]->[ 6 ]->[ 8 ]-[ 5 ]->[ 7 ]->[ 13 ]->[ 0 ]->nil
    
then, the resulting list, after performing the operation, is:
     Head ->[ 1 ]->[ 2 ]->[ 3 ]->[ 6 ]->[ 5 ]->[ 7 ]->[ 8 ]->[ 13 ]->[ 0 ]->nil

2) Reverse- It will rearrange the list so that the nodes will be in reverse order. 

For example, in the singly linked list case, if the list is:
     Head ->[ 2 ]->[ 3 ]->[ 1 ]->[ 6 ]->[ 8 ]-[ 5 ]->[ 7 ]->[ 13 ]->[ 0 ]->nil
     
then the resulting list, after performing the operation, is:
     Head ->[ 0 ]->[ 13 ]->[ 7 ]->[ 5 ]->[ 8 ]-[ 6 ]->[ 1 ]->[ 3 ]->[ 2 ]->nil
     
     
3) Shuffle- it will shuffle the first half of the list with the second half of the list so that the nodes will be listed 
from each half alternatively. 

For example, in the singly linked list case, if the list is:
     Head ->[ 2 ]->[ 3 ]->[ 1 ]->[ 6 ]->[ 8 ]->[ 5 ]->[ 7 ]->[ 13 ]->[ 0 ]->nil
     
then the resulting list, after the operation, is:
     Head ->[ 2 ]->[ 5 ]->[ 3 ]->[ 7 ]->[ 1 ]->[ 13 ]->[ 6 ]->[ 0 ]->[ 8 ]->nil 
     
     
===============================
Heap and its variants Directory-
===============================
It has implementations of the following-
1. A priority queue based on Min-Heap
2. Leonardo Heap, a variant of the Max-Heap

I. A Min-Heap Based Priority Queue
Priority queue has been implemented using Min-Heap Data Structure and is verified by-

1. Insert: insert a data item, say d, to P Q
2. All-Minimum: Return all the data items in P Q with the minimum key (highest priority)
3. Decrease-key: decrease the value of an data item’s key to a new value
4. Extract-all-min: Remove and return all the data items with the smallest key value

II. Leonardo Heap for Smooth Sorting


===============================
Binary Search Tree and k-d tree-
===============================

a). Binary Search Trees: 
  operations performed: insert, delete and search. No balancing actions will be implemented.
b). kd Trees: a generalization of binary search trees for higher dimensional data. kd trees is implemented when k = 2. 
operations performed: insert, delete and search.

==============================
Graph and Dijkstra’s Algorithm-
==============================
Graphs have been implemented to solve single source shortest path problem where all the edges have non negative weights.









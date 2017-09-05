//
//  priorityQueue.h
//  assignment 2
//
//  Created by Pranjul Arora on 10/24/16.
//  Copyright © 2016 assignment 2. All rights reserved.
//

// header file for declaring priority queue functions

#ifndef priorityQueue_h
#define priorityQueue_h
#include <vector>

// not included std as it will utilize more memory

class priorityQueue
{
public:

    // description of all these function are in implement_PriorityQueue.cpp
    // where the defination of these functions are given
    std::vector <std::vector<int> > vecQueue;
    void minHeap_insert_In_PriorityQueue(std::vector<int>);
    void decrease_HeapKey(std::vector<int>, int);
    void min_Heapify(int);
    std::vector <std::vector<int> > minVector;
    void all_Minimum(int);
    
    void displayQueue();
    void displayQueue_withVec(std::vector <std::vector<int> >);
    
    
    std::vector <std::vector<int> > extract_all_min_vector;
    void extract_All_Min();
     
};



#endif /* priorityQueue_h */

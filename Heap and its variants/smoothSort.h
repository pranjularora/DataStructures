//
//  smoothSort.h
//  assignment 2
//
//  Created by Pranjul Arora on 10/27/16.
//  Copyright © 2016 assignment 2. All rights reserved.
//

#ifndef smoothSort_h
#define smoothSort_h

#include <iterator>
#include <bitset>
#include <vector>

// an iterator of type vector is used as a type
typedef std::vector<int>::iterator heap_Iterator;

const size_t leonardo_numbers = 46;

// using these numbers so that we do not need to calculate them
// easy for access and comparing sizes of heap.

const size_t array_Of_leonardo_numbers[leonardo_numbers] =
{
    1, 1, 3, 5, 9, 15, 25, 41, 67, 109, 177, 287, 465, 753,1219, 1973, 3193, 5167, 8361, 13529, 21891, 35421, 57313, 92735, 150049, 242785, 392835, 635621, 1028457, 1664079, 2692537, 4356617, 7049155, 11405773, 18454929, 29860703, 48315633, 78176337, 126491971u, 204668309u, 331160281u, 535828591u, 866988873u, 1402817465u,2269806339u, 3672623805u
};


class leonardo_Heap_Structure
{
    // description of all these function are in implement_smothSort.cpp
    // where the defination of these functions are given
    public:
    int number_of_Comparisons;
    leonardo_Heap_Structure();
   
    void swap(int &,int &, std::vector<int> &);
    std::vector<int> unique_Random_Numbers(int, int, int);
    
    bool evaluate(int&, int&);
    std::bitset<leonardo_numbers> bit_Vector_Of_Leo_Nums;
    size_t smallest_Leo_heap_size;
    
    heap_Iterator bigger_Child(heap_Iterator, size_t);
    heap_Iterator operate_on_Right_Child(heap_Iterator);
    heap_Iterator operate_on_Left_Child(heap_Iterator, size_t);
    
    void insertion_In_Heap(heap_Iterator, heap_Iterator, heap_Iterator, leonardo_Heap_Structure& );
    void dequeue_From_Heap(heap_Iterator, heap_Iterator, leonardo_Heap_Structure&);
    void sort_In_Heap(heap_Iterator, heap_Iterator);
    
    void heap_Structure_Rebalancing(heap_Iterator, size_t);
    void max_Heapify(heap_Iterator, heap_Iterator, leonardo_Heap_Structure);
    int smooth_Sort(std::vector<int>::iterator, std::vector<int>::iterator);

};




#endif /* smoothSort_h */

//
//  implement_smoothSort.cpp
//  assignment 2
//
//  Created by Pranjul Arora on 10/27/16.
//  Copyright © 2016 assignment 2. All rights reserved.
//

#include <stdio.h>
#include "smoothSort.h"
#include <cstdlib>

// IMPLEMETATION OF FUNCTIONS DEFINED IN SMOOTH SORT HEADER FILE


using namespace std;

// defining the constructor which will initiate the value of number of comparisons
leonardo_Heap_Structure:: leonardo_Heap_Structure()
{
    number_of_Comparisons = 0;
}

// Swap function used and takes parameter as reference
void leonardo_Heap_Structure::swap(int &a, int &b, std::vector<int> &A)
{
    int swap = A[a];
    A[a] = A[b];
    A[b] = swap;
}

// function to generate unique number

vector<int> leonardo_Heap_Structure::unique_Random_Numbers(int min, int max, int size)
{
    vector<int> random_Array;
    for (int i=0; i< size; i++)
    {
        int flag = 1;
        
        while (flag == 1)
        {
            int random_number = rand() % (max - min + 1) + min;
            if (random_Array.size() == 0)
            {
                random_Array.push_back(random_number);
                flag = 0;
                break;
            }
            
            for (int j =0; j < random_Array.size() ; j++)
            {
                if (random_number == random_Array[j]) // checking if element already exists
                {
                    flag = 1;
                    break;
                }
                else
                    flag = 0;

            }
            if (flag == 0) // this states if not exists then add it
                random_Array.push_back(random_number);
            
            
        }
    }
    return random_Array;
    
}




// returns true false based on the value evaluated
bool leonardo_Heap_Structure::evaluate(int& firstPointer, int& secondPointer)
{
    if (firstPointer > secondPointer)
        return false;
    else
        return true;
}


// this function will operate on the right child, this will be the second child
heap_Iterator leonardo_Heap_Structure::operate_on_Right_Child(heap_Iterator rootElement)
{
    rootElement = rootElement - 1;
    return rootElement;
}

// this function will operate on the left child, this will be the first child
heap_Iterator leonardo_Heap_Structure::operate_on_Left_Child(heap_Iterator rootElement, size_t size_of_Heap)
{
    
    heap_Iterator right = operate_on_Right_Child(rootElement);
    heap_Iterator diff = right - array_Of_leonardo_numbers[size_of_Heap - 2];
    return diff;
}

// it will return the larger child iterator
heap_Iterator leonardo_Heap_Structure::bigger_Child(heap_Iterator rootElement, size_t size_of_Heap)
{
    heap_Iterator firstElement = operate_on_Left_Child(rootElement, size_of_Heap);
    heap_Iterator secondElement = operate_on_Right_Child(rootElement);
    
    // incrementing number of comparisons
    number_of_Comparisons++;
    
    bool comparisonResult = leonardo_Heap_Structure::evaluate(*firstElement, *secondElement);
    
    if ( comparisonResult == true)
        return secondElement;
    else
        return firstElement;
    
}


// rebalancing the heap after it doesnot satistfy max heap property
void leonardo_Heap_Structure::heap_Structure_Rebalancing(heap_Iterator rootElement, size_t size_of_Heap)
{
    while (size_of_Heap > 1)
    {
        heap_Iterator firstElement = operate_on_Left_Child(rootElement, size_of_Heap);
        heap_Iterator secondElement = operate_on_Right_Child(rootElement);
        heap_Iterator biggerChild;
        size_t size_of_Child;
        number_of_Comparisons++;
        if (leonardo_Heap_Structure::evaluate(*firstElement, *secondElement)) // call the evaluate function
        {
            biggerChild = secondElement;
            size_of_Child = size_of_Heap - 2;
            number_of_Comparisons++;
        }
        else
        {
            biggerChild = firstElement;
            size_of_Child = size_of_Heap - 1;
            number_of_Comparisons++;
        }
        
        if(evaluate(*rootElement, *biggerChild) != true)
        {
            return;
        }
        
        iter_swap(rootElement, biggerChild); // calling the swap function
        rootElement = biggerChild; // new root element
        size_of_Heap = size_of_Child; // new size of heap
    }
}

// attaing the max heapify property
void leonardo_Heap_Structure::max_Heapify(heap_Iterator startPoint, heap_Iterator endPoint, leonardo_Heap_Structure input_Heap)
{
    heap_Iterator iterator = endPoint - 1;
    size_t visited_Heap_Size;
    
    while (true)
    {
        visited_Heap_Size = input_Heap.smallest_Leo_heap_size;
        if(size_t(distance(startPoint, iterator)) == array_Of_leonardo_numbers[visited_Heap_Size] - 1)
        {
            break;
        }
        heap_Iterator compare_With = iterator;
        if (input_Heap.smallest_Leo_heap_size > 1)
        {
            heap_Iterator biggerChild = bigger_Child(iterator, input_Heap.smallest_Leo_heap_size);
            number_of_Comparisons += 1;
            if (evaluate(*compare_With, *biggerChild))
            {
                compare_With = biggerChild;
            }
        }
        
        heap_Iterator previousHeap = iterator - array_Of_leonardo_numbers[visited_Heap_Size];
        number_of_Comparisons += 1;
        
        if (!evaluate(*compare_With, *previousHeap)) {
            break;
        }
        
        iter_swap(iterator, previousHeap);
        iterator = previousHeap;
        do
        {
            input_Heap.bit_Vector_Of_Leo_Nums >>= 1;
            ++input_Heap.smallest_Leo_heap_size;
        } while (!input_Heap.bit_Vector_Of_Leo_Nums[0]);
    }
    heap_Structure_Rebalancing(iterator, visited_Heap_Size);
}


// this is the function to insert in heap
void leonardo_Heap_Structure::insertion_In_Heap(heap_Iterator startPoint, heap_Iterator endPoint, heap_Iterator end_ofHeap , leonardo_Heap_Structure& inputHeap)
{
    if (!inputHeap.bit_Vector_Of_Leo_Nums[0])
    {
        inputHeap.bit_Vector_Of_Leo_Nums[0] = true;
        inputHeap.smallest_Leo_heap_size = 1;
    }
    else if (inputHeap.bit_Vector_Of_Leo_Nums[1] && inputHeap.bit_Vector_Of_Leo_Nums[0])
    {
        inputHeap.bit_Vector_Of_Leo_Nums >>=2;
        inputHeap.bit_Vector_Of_Leo_Nums[0] = true;
        inputHeap.smallest_Leo_heap_size += 2;
    }
    else if (inputHeap.smallest_Leo_heap_size == 1)
    {
        inputHeap.bit_Vector_Of_Leo_Nums <<=1;
        inputHeap.smallest_Leo_heap_size = 0;
        inputHeap.bit_Vector_Of_Leo_Nums[0] = true;
    }
    else
    {
        inputHeap.bit_Vector_Of_Leo_Nums <<= inputHeap.smallest_Leo_heap_size - 1;
        inputHeap.bit_Vector_Of_Leo_Nums[0] = true;
        inputHeap.smallest_Leo_heap_size = 1;
    }
    
    bool lastHeap = false;
    
    switch (inputHeap.smallest_Leo_heap_size) {
        case 0:
            if (endPoint + 1 == end_ofHeap)
                lastHeap = true;
            break;
        case 1:
            if (endPoint + 1 == end_ofHeap || (endPoint + 2 == end_ofHeap && !inputHeap.bit_Vector_Of_Leo_Nums[1]) )
                lastHeap = true;
            break;
            
        default:
            if (size_t(distance(endPoint + 1, end_ofHeap)) < array_Of_leonardo_numbers[inputHeap.smallest_Leo_heap_size - 1] + 1)
                lastHeap = true;
            break;
    }
    if(lastHeap == false)
        heap_Structure_Rebalancing(endPoint, inputHeap.smallest_Leo_heap_size);
    
    else
        max_Heapify(startPoint, endPoint + 1, inputHeap);
    
}
 // this function will dequeu from heap
void leonardo_Heap_Structure::dequeue_From_Heap(heap_Iterator startPoint, heap_Iterator endPoint, leonardo_Heap_Structure& input_Heap)
{
    if (input_Heap.smallest_Leo_heap_size <= 1) {
        do
        {
            input_Heap.bit_Vector_Of_Leo_Nums >>= 1;
            ++input_Heap.smallest_Leo_heap_size;
        }while (input_Heap.bit_Vector_Of_Leo_Nums.any() && !input_Heap.bit_Vector_Of_Leo_Nums[0]);
        return;
    }
    
    const size_t order_of_Heap = input_Heap.smallest_Leo_heap_size;
    input_Heap.bit_Vector_Of_Leo_Nums[0] = false;
    input_Heap.bit_Vector_Of_Leo_Nums <<= 2;
    input_Heap.bit_Vector_Of_Leo_Nums[1] = true;
    input_Heap.bit_Vector_Of_Leo_Nums[0] = true;
    input_Heap.smallest_Leo_heap_size -= 2;
    
    heap_Iterator leftHeap = operate_on_Left_Child(endPoint -1 , order_of_Heap);
    heap_Iterator rightHeap = operate_on_Right_Child(endPoint -1);
    leonardo_Heap_Structure last = input_Heap;
    ++last.smallest_Leo_heap_size;
    last.bit_Vector_Of_Leo_Nums >>= 1;
    max_Heapify(startPoint, leftHeap + 1, last);
    max_Heapify(startPoint, rightHeap + 1, input_Heap);
    
}

// this is the sorting function which will sort the heap

void leonardo_Heap_Structure::sort_In_Heap(heap_Iterator startPoint, heap_Iterator endPoint)
{
    if ( startPoint == endPoint || startPoint + 1 == endPoint)
        return;
    
    leonardo_Heap_Structure input_Heap;
    input_Heap.smallest_Leo_heap_size = 0;
    
    for (heap_Iterator iterator = startPoint; iterator != endPoint; ++iterator)
    {
        insertion_In_Heap(startPoint, iterator, endPoint, input_Heap);
    }
    
    for (heap_Iterator iterator = endPoint; iterator != startPoint; --iterator)
        dequeue_From_Heap(startPoint, iterator, input_Heap);
    
}

// function called from the main function.
// call the main sort funciton
int leonardo_Heap_Structure::smooth_Sort(vector<int>::iterator startPoint, vector<int>::iterator endPoint)
{
    leonardo_Heap_Structure leonardoHeap;
    leonardoHeap.sort_In_Heap(startPoint, endPoint);
    return leonardoHeap.number_of_Comparisons;
}



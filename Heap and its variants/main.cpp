//
//  main.cpp
//  assignment 2
//
//  Created by Pranjul Arora on 10/24/16.
//  Copyright © 2016 assignment 2. All rights reserved.
//

#include <iostream>
#include "priorityQueue.h"
#include "smoothSort.h"
#include <vector>
#include <cstdlib>
#include <limits.h>
#include <time.h>

using namespace std;


int main(int argc, const char * argv[])
{
    
    srand(time(NULL));
    
    cout << "============================================ Test Case 1 ============================================\n";
    
    // creating an object of the class priorityQueue
    priorityQueue q1;
    
    // defining a vector which will be used through out priority queue implementation.
    vector<int> vec_c (2);
    
    cout << "\n============================================ Test Case 1->1\n";
    cout << "\nInsert the following data items to PQ in the given order: [100 1] [99 2] ... [1 100] \n";
    
    // Inserting the following data items to PQ in the given order: [100 1] [99 2] ... [1 100]
    for( int i=100, j=1; j<=100; i--,j++)
    {
        vec_c [0] = i;
        vec_c [1] = j;
        q1.minHeap_insert_In_PriorityQueue(vec_c); // this is insert function
        
    }
    
    
    cout << "\n\n============================================ Test Case 1->2\n";
    cout << "\nApply Extra-all-min operation to PQ and print the results to the screen  \n";
    
    
    
    q1.extract_All_Min(); // calling extract all minimum function
    cout << "\nResult:\n";
    q1.displayQueue_withVec(q1.extract_all_min_vector);  // displaying the result.
    q1.extract_all_min_vector.clear();  // emptying the vector, to use for other cases.
    
    cout << endl;
    
    cout << "\n============================================ Test Case 1->3\n\n";
    cout << "Insert the data [1 0] to PQ  \n";
    
    vec_c[0] = 1;
    vec_c[1] = 0;
    q1.minHeap_insert_In_PriorityQueue(vec_c);
    
    
    
    cout << "\n============================================ Test Case 1->4\n";
    cout << "Apply Extra-all-min operation to PQ and print the results to the screen  \n\n";
    
    q1.extract_All_Min();
    cout << "\nResult:\n";
    q1.displayQueue_withVec(q1.extract_all_min_vector);
    q1.extract_all_min_vector.clear();
    
    
    
    cout << "\n\n============================================ Test Case 1 END ============================================\n";
    
    
    
    cout << "\n\n============================================ Test Case 2 ============================================\n";
    // creating a new object of priority queue.
    
    priorityQueue q2;
    
    
    
    
    cout << "\n============================================ Test Case 2->1\n";
    cout << "Insert the following data items to P Q in the given order: [1000 1] [999 2] ... [1 1000] \n\n";
    
    // Inserting theses data items to PQ in the given order: [1000 1] [999 2] ... [1 1000]
    
    for( int i=1000, j=1; j<=1000; i--,j++)
    {
        vec_c [0] = i;
        vec_c [1] = j;
        
        q2.minHeap_insert_In_PriorityQueue(vec_c);
        
    }
    cout << endl;
    
    
    
    
    cout << "============================================ Test Case 2->2\n";
    cout << "Apply All-Minimum operation to PQ and print the results to the screen \n";
    q2.all_Minimum(1);
    
    cout << "\nResult:\n";
    q2.displayQueue_withVec(q2.minVector);
    q2.minVector.clear();
    
    cout << "\n\n============================================ Test Case 2->3\n";
    cout << "Insert the following data items to P Q in the given order: [1 1] [1 2] ... [1 30] \n";
    
    //
    
    for( int i=1; i<=30; i++)
    {
        vec_c [0] = 1;
        vec_c [1] = i;
        q2.minHeap_insert_In_PriorityQueue(vec_c);
        
    }
    
    // Applying Extract-all-min operation to PQ and printing the results to the screen
    
    cout << "\n============================================ Test Case 2->4\n";
    cout << "Apply Extra-all-min operation to PQ and print the results to the screen\n";
    
    q2.extract_All_Min();
    cout << "\nResult:\n";
    q2.displayQueue_withVec(q2.extract_all_min_vector);
    q2.minVector.clear();
    
    // Applying All-Minimum operation to PQ and printing the results to the screen
    
    cout << "\n\n============================================ Test Case 2->5\n";
    cout << "Apply All-Minimum operation to PQ and print the results to the screen \n";
    q2.all_Minimum(1);
    cout << "\nResult:\n";
    q2.displayQueue_withVec(q2.minVector);
    q2.minVector.clear();
    
    cout << "\n============================================ Test Case 2 END ============================================\n\n\n";
    
    
    cout << "============================================ Test Case 3 ============================================\n";
    
    
    priorityQueue q3;
    
    cout << "\n============================================ Test Case 3->1\n";
    cout << "\nInsert 500 randomly generated data items to PQ. For each of these data item [i j], 10 ≤ i, j ≤ 1000\n";
    
    
    for (int i =0; i < 500; i++)
    {
        vec_c[0] = rand() % (1000 - 10 + 1)  + 10; // generating random numbers [10,1000]
        vec_c[1] = rand() % (1000 - 10 + 1)  + 10; // i.e. it will include 10 and 1000.
        q3.minHeap_insert_In_PriorityQueue(vec_c); // inserting the random numbers
    }
    
    
    
    
    
    cout << "\n============================================ Test Case 3->2\n";
    cout << "Apply Extra-all-min operation to PQ 5 times, and print the results to the screen each time right after the Extra-all-min operation is completed\n\n";
    
    // Extract-all-min operation to PQ 5 times
    for (int i =0; i < 5; i++)
    {
        q3.extract_All_Min();
        cout << "\n\nResult:\n";
        q3.displayQueue_withVec(q3.extract_all_min_vector);
        q3.extract_all_min_vector.clear();
        
    }
    
    
    
    cout << "\n============================================ Test Case 3->3\n";
    cout << "Randomly select a data item from the P Q. Decrease the key value to 5\n";
    
    
    
    int random_Index = rand() % q3.vecQueue.size();
    // displaying the randomly selected value
    cout << "random val Selected: \n";
    cout << "[" << q3.vecQueue.at(random_Index).at(0) << ", " << q3.vecQueue.at(random_Index).at(1) << "]" << "\n";
    vec_c[0] = 5;
    vec_c[1] = q3.vecQueue.at(random_Index).at(1);
    
    // only displaying the new vector which will be changed after decrease key operation
    cout << "\nchange it to: " << "[" << vec_c[0] << ", " << vec_c[1] << "]" << "\n\n";
    q3.decrease_HeapKey(vec_c, random_Index);
    
    
    
    
    cout << "\n============================================ Test Case 3->4 \n";
    cout << "Apply the All-Minimum operation to PQ and print the results to the screen\n";
    q3.minVector.clear(); // clearing for future use
    
    q3.all_Minimum(1);
    cout << "\n\nResult:\n";
    q3.displayQueue_withVec(q3.minVector);
    
    
    
    cout << "\n============================================ Test Case 3 END ============================================\n\n\n";
    
    
    cout << "============================================ Test Case 4 ============================================\n";
    
    
    priorityQueue q4;
    
    cout << "\n============================================ Test Case 4->1\n";
    cout << "\nInsert 500 randomly generated data items to PQ. For each of these data item [i j], 10 ≤ i, j ≤ 1000.\n";
    
    
    for (int i =0; i < 500; i++)
    {
        vec_c[0] = rand() % (1000 - 10 + 1)  + 10;  // generating random numbers [10,1000]
        vec_c[1] = rand() % (1000 - 10 + 1)  + 10;  // i.e. it will include 10 and 1000.
        q4.minHeap_insert_In_PriorityQueue(vec_c); // insert operation
    }
    
    cout << "\n============================================ Test Case 4->1 END\n";
    
    cout << "\n============================================ Test Case 4->2 \n";
    cout << "\nPerform 10 Decrease-key operations to PQ. When a Decrease-key operation is performed, the data item should be chosen randomly from the current PQ and the key value should be decreased to a randomly selected value that lies between 0 to 9.\n";
    
    for (int i = 0; i< 10; i++)
    {
        // 10 decrease key operation
        
        int random_Index = rand() % q4.vecQueue.size();
        cout << "random val: ";
        cout << "[" << q4.vecQueue.at(random_Index).at(0) << ", " << q4.vecQueue.at(random_Index).at(1) << "]" << "\n";
        vec_c[0] = rand() % 9 + 1; // generating random between 0 & 9.
        vec_c[1] = q4.vecQueue.at(random_Index).at(1);
        cout << "change it to: " << "[" << vec_c[0] << ", " << vec_c[1] << "]" << "\n\n";
        q4.decrease_HeapKey(vec_c, random_Index);
        
        
        
    }
    
    
    
    
    
    cout << "\n============================================ Test Case 4->3 \n";
    
    cout << "\nPerform 10 Extra-min operations to PQ and print the results to the screen each time such an operation is performed.\n";
    
    q4.extract_all_min_vector.clear();
    for (int i =0; i < 10; i++)
    {
        // 10 extract minimum operation
        q4.extract_All_Min();
        cout << "\n\nResult:\n";
        q4.displayQueue_withVec(q4.extract_all_min_vector);
        q4.extract_all_min_vector.clear();
        
    }
    
    
    
    cout << "\n============================================ Test Case 4 END ============================================\n\n\n";
    
    
    
    cout << "============================================ Test Case 5 ============================================\n\n\n";
    cout << "\n============================================ Test Case 5->1 \n";
    
    cout << "\nPerform 100 randomly generated operations to PQ. The random generated operations should include all four operations stated. In addition, when a Decrease key operation is chosen, the data item should be chosen randomly from the current PQ and the key value should be decreased that is less than all the existing key value.\n";
    
    
    priorityQueue q5;
    // 100 randomly generated operation
    
    for (int i = 0; i < 100; i++)
    {
        int randomFunc = rand() % 4;
        // Insert function will be called if random value is 0
        if (randomFunc == 0)
        {
            vec_c[0] = rand()%(1000 - 10 + 1)  + 10;
            vec_c[1] = rand()%(1000 - 10 + 1)  + 10;
            q5.minHeap_insert_In_PriorityQueue(vec_c);
            
        }
        
        // all minimum function will be called if random value is 1
        else if (randomFunc == 1 && q5.vecQueue.size() > 0)
        {
            q5.minVector.clear();
            q5.all_Minimum(1);
        }
        
        // decrease key operation will be called if the randomfunc value is 2
        else if (randomFunc == 2  && q5.vecQueue.size() > 0)
        {
            int random_Index = rand() % q5.vecQueue.size();
            vec_c[0] = rand() % (q5.vecQueue.at(random_Index).at(0)) + 1;
            vec_c[1] = q5.vecQueue.at(random_Index).at(1);
            
            q5.decrease_HeapKey(vec_c, random_Index);
        }
        
        // extract all minimum operation will be called if the randomfunc value is 3
        else if (randomFunc == 3  && q5.vecQueue.size() > 0)
        {
            q5.extract_all_min_vector.clear();
            q5.extract_All_Min();
            
            q5.extract_all_min_vector.clear();
            
        }
        else {}
        
        // displaying after 20 operations
        if (i%20 == 0)
        {
            cout << "\n\nAfter 20 operation: \n";
            q5.displayQueue();
            cout << endl;
        }
    }
    
    
    
    
    
    
    
    
    cout << "============================================ Test Case 5 END ============================================\n\n\n";
    
    //////////////////// END  OF PRIORITY QUEUE ////////////////////////
    
    
    //////////////////// STARTING WITH SMOOTH SORT ////////////////////////
    
    
    cout << "============================================ Test Case 6 ============================================\n\n\n";
    cout << "\n============================================ Test Case 6->1 \n";
    cout << "\nInserting Elements into Vector A.\n";
    
    vector<int> A; // Insertion will be in vector A.
    vector<int> rand_numbers; // this is the vector used for receiving random numbers
    
    leonardo_Heap_Structure leoHeap; // object of class leonardo_Heap_Structure defined in smoothSort.h
    
    
    for (int i = 1000; i > 0; i--)
    {
        A.push_back(i); // inserting in vector A using pushback
    }
    
    
    
    cout << "\n============================================ Test Case 6->2 \n";
    cout << "\nNow, Applying Smooth Sort to Vector A.\n";
    
    int number_of_Comparisons=0; // varibale for calculation number of comparisons
    number_of_Comparisons = leoHeap.smooth_Sort(A.begin(), A.end()); //calling smooth sort function.
    
    
    
    cout << "\n============================================ Test Case 6->3 \n";
    cout << "\nPrint the following data to the screen:\n";
    
    // displaying number of comparisons
    cout << "\nThe total number of comparisons among elements in A performed = \"" << number_of_Comparisons << "\""<< endl;
    
    cout << "\n============================================ Test Case 6->4 \n";
    cout << "\nA shortened listing of element of A :\n";
    
    // shortened listing of elements i.e. after every 20 element
    cout << "[";
    for (int i = 0; i < 1000; i++)
    {
        if (i % 20 == 0)
        {
            cout << A[i] << ", ";
        }
    }
    cout << "]" << endl;
    
    A.clear();
    // reseting the number_of_Comparisons for next test case
    number_of_Comparisons=0;
    
    cout << "\n============================================ Test Case 6->4 END\n";
    
    cout << "\n\n============================================ Test Case 6 END ============================================\n\n\n";
    
    
    cout << "============================================ Test Case 7 ============================================\n\n\n";
    cout << "\n============================================ Test Case 7->1 \n";
    
    cout << "\nInitially generated a almost sorted list by first setting A to be:\n";
    
    for (int i = 1; i <= 2000; i++)
    {
        A.push_back(i);
    }
    
    cout << "\n============================================ Test Case 7->2 \n";
    
    cout << "\nRandomly select 20 distinct numbers that lies between 1 to 2000, say i1, . . . , i20. Swap A[i1] and A[i2], A[i3] and A[i4], , ..., A[i19] and A[i20] (Here, I assume the array index starts with 1).\n";
    
    
    
    rand_numbers.clear();
    // calling unique_Random_Numbers function, which will return an array of unique numbers
    // between 1 and 2000 and 20 parameter is for size of the array
    rand_numbers = leoHeap.unique_Random_Numbers(1, 2000, 20);
    
    // using that size to iterate on the vector
    for (int i = 0; i < rand_numbers.size(); i=i+2)
    {
        leoHeap.swap(rand_numbers[i], rand_numbers[i+1], A);
    }
    
    cout << "\n============================================ Test Case 7->3 \n";
    
    cout << "\nApplying Smooth Sort to A.\n";
    
    number_of_Comparisons = leoHeap.smooth_Sort(A.begin(), A.end());
    
    
    cout << "\n============================================ Test Case 7->4 \n";
    cout << "\nPrint the following data to the screen:\n";
    
    cout << "\nThe total number of comparisons among elements in A performed = \"" << number_of_Comparisons << "\""<< endl;
    
    
    
    
    cout << "\n============================================ Test Case 7->5 \n";
    cout << "\nA shortened listing of element of A :\n";
    cout << "[";
    for (int i = 0; i < 2000; i++)
    {
        if (i % 20 == 0)
        {
            cout << A[i] << ", ";
        }
    }
    cout << "]" << endl;
    
    A.clear();
    // reseting the number_of_Comparisons for next test case
    number_of_Comparisons=0;
    
    
    cout << "\n\n============================================ Test Case 7 END ============================================\n\n\n";
    
    
    
    
    cout << "\n\n============================================ Test Case 8 ============================================\n\n\n";
    
    cout << "\n============================================ Test Case 8->1 \n";
    cout << "\nInitially generated a almost sorted list by first setting A to be:\n";
    
    // inserting
    for (int i = 1; i <= 2000; i++)
    {
        A.push_back(i);
    }
    
    
    
    
    cout << "\n============================================ Test Case 8->2 \n";
    cout << "\nRandomly select 60 distinct numbers that lies between 1 to 1000, say i1, . . . , i60. Permute A[i1], A[i2] and A[i3], Permute A[i4], A[i5] and A[i6], ..., Permute A[i58], A[i59] and A[i60] (Here, I assume the array index starts with 1).\n";
    
    rand_numbers.clear();
    
    // calling unique_Random_Numbers function, which will return an array of unique numbers
    // between 1 and 1000 and 60 parameter is for size of the array
    rand_numbers = leoHeap.unique_Random_Numbers(1, 1000, 60);
    
    for (int i = 0; i < rand_numbers.size(); i=i+3)
    {
        
        int swap_Index = rand() % (2 - 0 + 1) + 0;
        
        if (swap_Index == 0)
            leoHeap.swap(rand_numbers[i], rand_numbers[i+1], A);
        
        else if (swap_Index == 1)
            leoHeap.swap(rand_numbers[i], rand_numbers[i+2], A);
        
        else
            leoHeap.swap(rand_numbers[i+1], rand_numbers[i+2], A);
        
        
    }
    
    
    cout << "\n============================================ Test Case 8->3 \n";
    cout << "\nApply Smooth Sort to A:\n";
    
    number_of_Comparisons = leoHeap.smooth_Sort(A.begin(), A.end());
    
    
    cout << "\n============================================ Test Case 8->4 \n";
    cout << "\nPrint the following data to the screen:\n";
    
    cout << "\nThe total number of comparisons among elements in A performed = \"" << number_of_Comparisons << "\""<< endl;
    
    
    cout << "\n============================================ Test Case 8->5 \n";
    cout << "\nA shortened listing of element of A :\n";
    cout << "[";
    for (int i = 0; i < 2000; i++)
    {
        if (i % 20 == 0)
        {
            cout << A[i] << ", ";
        }
    }
    cout << "]" << endl;
    
    A.clear();
    // reseting the number_of_Comparisons for next test case
    number_of_Comparisons=0;
    
    
    cout << "============================================ Test Case 8 END ============================================\n\n\n";
    
    
    
    cout << "\n\n============================================ Test Case 9 ============================================\n\n\n";
    
    cout << "\n============================================ Test Case 9->1 \n";
    
    cout << "\nInitially set B to be a list of length 3193, a Leonardo number.\n";
    
    
    // As length is a constrain in this test case, I instantiating a new vector "B"..
    
    vector<int> B(3193); // specifying the length as it is a part of the requriement
    
    cout << "\n============================================ Test Case 9->2 \n";
    cout << "\nFill the entries of B randomly with numbers selected from 1 to 10000. The numbers may not be all distinct.\n";
    
    // generating random number and inserting in array
    for (int i = 0; i< B.size(); i++)
    {
        B[i] = rand() % (10000 - 1 + 1) + 0;
    }
    
    
    cout << "\n============================================ Test Case 9->3 \n";
    cout << "\nApply Smooth Sort to B.\n";
    
    number_of_Comparisons = leoHeap.smooth_Sort(B.begin(), B.end());
    
    
    
    cout << "\n============================================ Test Case 9->4 \n";
    cout << "\nPrint the following data to the screen:\n";
    
    cout << "\nThe total number of comparisons among elements in B performed = \"" << number_of_Comparisons << "\""<< endl;
    
    
    cout << "\n============================================ Test Case 9->5 \n";
    cout << "\nA shortened listing of element of B :\n";
    cout << "[";
    for (int i = 0; i < B.size(); i++)
    {
        if (i % 20 == 0)
        {
            cout << B[i] << ", ";
        }
    }
    cout << "]" << endl;
    
    B.clear();
    // reseting the number_of_Comparisons for next test case
    number_of_Comparisons=0;
    
    
    cout << "============================================ Test Case 9 END ============================================\n\n\n";
    
    
    cout << "\n\n============================================ Test Case 10 ============================================\n\n\n";
    
    cout << "\n============================================ Test Case 10->1 \n";
    
    cout << "\nInitially set A to be a list of length 5166 the sum of two Leonardo numbers.\n";
    
    
    // As length is a constrain in this test case, I instantiating a new vector "C"..
    
    vector<int> C(5166); // specifying the length as it is a part of the requriement
    
    cout << "\n============================================ Test Case 10->2 \n";
    cout << "\nFill the entries of C randomly with numbers selected from 1 to 10000. The numbers may not be all distinct.\n";
    
    for (int i = 0; i< C.size(); i++)
    {
        C[i] = rand() % (10000 - 1 + 1) + 0;
    }
    
    cout << "\n============================================ Test Case 10->3 \n";
    cout << "\nApply Smooth Sort to C.\n";
    
    number_of_Comparisons = leoHeap.smooth_Sort(C.begin(), C.end());
    
    
    
    cout << "\n============================================ Test Case 10->4 \n";
    cout << "\nPrint the following data to the screen:\n";
    
    cout << "\nThe total number of comparisons among elements in C performed = \"" << number_of_Comparisons << "\""<< endl;
    
    
    cout << "\n============================================ Test Case 10->5 \n";
    cout << "\nA shortened listing of element of C :\n";
    cout << "[";
    for (int i = 0; i < C.size(); i++)
    {
        if (i % 20 == 0)
        {
            cout << C[i] << ", ";
        }
    }
    cout << "]" << endl;
    
    C.clear();
    number_of_Comparisons=0;
    
    
    cout << "============================================ Test Case 10 END ============================================\n\n\n";
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

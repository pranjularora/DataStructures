//
//  main.cpp
//  BinarySearchTree
//
//  Created by Pranjul Arora on 11/13/16.
//  Copyright © 2016 Pranjul AroraBST. All rights reserved.
//

#include <iostream>
#include "BSTList.h"
#include "KDList.h"
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>

using namespace std;

int main()
{
    BSTList list1;
    list1.rootElement = NULL;
    // vector for key and value pair and will be used through out
    vector<int> key;
    vector<int> value;
    vector<vector<double> > storeTableValue;
    vector<vector<int> > storeTableValueCase7;
    
    vector<vector<double> > storeTableValue_KD;
    
    // for storing list 1 values as will be used later
    vector<vector<int> > list1Values;
    // for storing list 2 values as will be used later
    vector<vector<int> > list2Values_of_KD;
    
    
    cout << "\n============================================ Test Case 1 ============================================\n";
    
    for (int k = 0, d = 0; d <= 15; k++, d++)
    {
        if (d == 0)
        {
            key.push_back(k);
        }
        else if(d == 1)
        {
            key.push_back(1000);
        }
        else
        {
            int valOfKey = (key[k-1] + key[k-2])/2;
            key.push_back(valOfKey);
        }
        value.push_back(d);
    }
    cout << "value to be inserted: \n";
    for (int i = 0 ; i< key.size() ; i++)
    {
        list1.rootElement = list1.insert(list1.rootElement, key[i], value[i]);
        cout << "[" << key[i] << ", " << value[i] <<"]\n";
        vector<int> localList;
        localList.push_back(key[i]);
        localList.push_back(value[i]);
        list1Values.push_back(localList);
    }
    
    cout << "\n\nIn-Order display of Test Case1 ==> \n";
    list1.displayInOrder(list1.rootElement);
    
    cout << "\n <<===== Created t1.dot file =====> > \n";
    list1.show_BST(list1.rootElement, "t1.dot");
    
    
    cout << "\n============================================ Test Case 1 END ============================================\n";
    
    cout << "\n============================================ Test Case 2 ============================================\n";
    KDList list2;
    list2.root = NULL;
    
    vector<int> x_Axis_V;
    vector<int> y_Axis_V;
    vector<int> value_V;
    
    vector<int> combine_vector;  // this will combine value of x_axis, y_axis and value-data -- it is also used through out
    
    for (int x = 0, y = 0, d = 0; d <= 15; x++, y++, d++)
    {
        if (d == 0)
        {
            x_Axis_V.push_back(x);
        }
        else if(d == 1)
        {
            x_Axis_V.push_back(500);
        }
        else
        {
            int NewElement = (x_Axis_V[x-1] + x_Axis_V[x-2])/2;
            x_Axis_V.push_back(NewElement);
        }
        y_Axis_V.push_back(500 - x_Axis_V[x]);
        value_V.push_back(d);
        
    }
    
    // by this we are inserting into the tree
    for (int i = 0; i < value_V.size(); i++)
    {
        combine_vector.clear();
        combine_vector.push_back(x_Axis_V[i]);
        combine_vector.push_back(y_Axis_V[i]);
        combine_vector.push_back(value_V[i]);
        list2.root = list2.insert_KD(list2.root, combine_vector);
        list2Values_of_KD.push_back(combine_vector);
    }
    
    
    
    
    cout << "In-Order display of Test Case2 ==> \n";
    list2.displayInOrder(list2.root);
    
    cout << "\n <<===== Created t2.dot file =====> > \n";
    list2.show_KD(list2.root, "t2.dot");
    
    
    
    
    cout << "\n============================================ Test Case 2 END ============================================\n";
    
    ////// For case 3..
    cout << "\n============================================ Test Case 3 ============================================\n";
    
    cout << "\n\n";
    key.clear();
    value.clear();
    
    
    BSTList list3;
    list3.rootElement = NULL;
    key = list3.unique_Random_Numbers(0, 1000, 201); // calculating unique keys
    
    
    for (int i = 0 ; i < 201 ; i++)
    {
        int randomval = rand() % (1000 - 0 + 1) + 0;
        value.push_back(randomval);
        
        if (i % 20 == 0)
        {
            vector<double> localVector;
            localVector.clear(); // added later ##############################################################
            localVector.push_back(i);
            localVector.push_back(list1.BSTHeight(list3.rootElement));
            localVector.push_back(log2(i));
            localVector.push_back(sqrt(i));
            
            storeTableValue.push_back(localVector);
        }
        if (i != 200)  // if i is 200 then it will not be inserted
        {
            list3.rootElement = list3.insert(list3.rootElement, key[i], value[i]);
        }
        
    }
    
    list3.displayBstTable(storeTableValue);
    
    cout << "\n============================================ Test Case 3 END ============================================\n";
    
    
    cout << "\n============================================ Test Case 4 ============================================\n";
    
    KDList list4;
    list4.root = NULL;
    
    
    vector<vector<int> > random = list4.unique_Random_Numbers(0, 50, 201);
    for (int i = 0; i < 201; i++)
    {
        combine_vector.clear();
        combine_vector.push_back(random.at(i).at(0));
        combine_vector.push_back(random.at(i).at(1));
        combine_vector.push_back(i+1);
        
        if (i % 20 == 0) // done for display
        {
            vector<double> localVector;
            localVector.push_back(i);
            localVector.push_back(list4.KDHeight(list4.root));
            localVector.push_back(log2(i));
            localVector.push_back(sqrt(i));
            
            storeTableValue_KD.push_back(localVector);
        }
        if (i != 200)
        {
            list4.root = list4.insert_KD(list4.root, combine_vector);
        }
    }
    list4.displayKDTable(storeTableValue_KD);
    
    
    cout << "\n============================================ Test Case 4 END ============================================\n";
    
    cout << "\n============================================ Test Case 5 ============================================\n";
    
    // Iterating randomly on list1
    // list1.displayInOrder(list1.rootElement); cout << "\n\n randomly adding";
    BSTList list5;
    list5.rootElement = NULL;
    vector<int> randomValue = list5.unique_Random_Numbers(0, list1Values.size() - 1, 10);
    
    for (int i = 0; i < 10; i++)
    {
        list5.rootElement = list5.insert(list5.rootElement, list1Values.at(randomValue[i]).at(0), list1Values.at(randomValue[i]).at(1));
        
    }
    
    cout << "In-Order display after insertion --- Test Case5 ==> \n";
    list5.displayInOrder(list5.rootElement);
    
    cout << "\n <<===== Created t5-a.dot file =====> > \n";
    list5.show_BST(list5.rootElement, "t5-a.dot");
    
    list5.Delete(list5.rootElement, list5.rootElement->key, list5.rootElement->value);
    
    cout << "In-Order display after deleting root --- Test Case5 ==> \n";
    list5.displayInOrder(list5.rootElement);
    
    cout << "\n <<===== Created t5-b.dot file =====> > \n";
    list5.show_BST(list5.rootElement, "t5-b.dot");
    
    
    cout << "\n============================================ Test Case 5 END ============================================\n";
    
    
    cout << "\n============================================ Test Case 6 ============================================\n";
    KDList list6;
    list6.root = NULL;
    
    vector<int> randomValue_for_KD = list6.unique_Random_array(0, list2Values_of_KD.size() - 1, 10);
    for(int i = 0; i < 10; i++)
    {
        combine_vector.clear();
        combine_vector.push_back(list2Values_of_KD.at(randomValue_for_KD[i]).at(0));
        combine_vector.push_back(list2Values_of_KD.at(randomValue_for_KD[i]).at(1));
        combine_vector.push_back(list2Values_of_KD.at(randomValue_for_KD[i]).at(2));
        list6.root = list6.insert_KD(list6.root, combine_vector);
    }
    
    cout << "In-Order display after insertion --- Test Case6 ==> \n";
    list6.displayInOrder(list6.root);
    
    cout << "\n <<===== Created t6-a.dot file =====> > \n";
    list6.show_KD(list6.root, "t6-a.dot");
    
    
    
    list6.root =  list6.Delete_KD(list6.root, 0); // calling delete function
    
    cout << "In-Order display after deleting root --- Test Case6 ==> \n";
    list6.displayInOrder(list6.root);
    
    
    cout << "\n <<===== Created t6-b.dot file =====> > \n";
    list6.show_KD(list6.root, "t6-b.dot");
    
    
    
    
    cout << "\n============================================ Test Case 6 END============================================\n";
    
    
    cout << "\n============================================ Test Case 7 ============================================\n";
    
    key.clear();
    value.clear();
    
    BSTList list7;
    list7.rootElement = NULL;
    
    for (int k = 0, d = 0; d <= 20; k++, d++)
    {
        if (k == 11) // if k == 11 then make it 1 again
        {
            k = 1;
        }
        if (k == 0)
        {
            key.push_back(k);
        }
        else if(k == 1)
        {
            key.push_back(1000);
        }
        else
        {
            int valOfKey = (key[k-1] + key[k-2])/2;
            key.push_back(valOfKey);
        }
        value.push_back(d);
    }
    
    for (int i = 1 ; i< key.size() ; i++)
    {
        list7.rootElement = list7.insert(list7.rootElement, key[i], value[i]);
    }
    
    
    vector<int> localVector;
    for (int i = 0 ; i < 20 ; i++)
    {
        if (i == 11)
        {
            list7.show_BST(list7.rootElement, "t7.dot");
        }
        int first = i;
        localVector.clear();
        localVector.push_back(first);
        
        int second_key;
        int second_value;
        if (list7.rootElement == NULL)
	{
            second_key = -1;
            second_value = -1;
	}
	else
	{
            second_key = list7.rootElement->key;
            second_value = list7.rootElement->value;
        }
        localVector.push_back(second_key);
        localVector.push_back(second_value);
        
        
        // After deletion
        list7.rootElement = list7.Delete(list7.rootElement, list7.rootElement->key, list7.rootElement->value);
        
        int third_key;
        int third_value;
        if (list7.rootElement == NULL)
	{
            third_key = -1;
            third_value = -1;
	}
	else
	{
            third_key = list7.rootElement->key;
            third_value = list7.rootElement->value;
        }
        localVector.push_back(third_key);
        localVector.push_back(third_value);
        
        
        // search function with second_key
        BSTNode* searchedElement = NULL;
        searchedElement = list7.search(list7.rootElement, second_key);
        int fourth_key;
        int fourth_value;
	if (searchedElement == NULL)
	{
            fourth_key = -1;
            fourth_value = -1;
	}
	else
	{
            fourth_key = searchedElement->key;
            fourth_value = searchedElement->value;
        }
        localVector.push_back(fourth_key);
        localVector.push_back(fourth_value);
        
        
        
        storeTableValueCase7.push_back(localVector);
        
        
        
    }
    list7.displayCase7(storeTableValueCase7);
    
    cout << "\n============================================ Test Case 7 END ============================================\n";
    
    
    
    
    cout << "\n============================================ Test Case 8  ============================================\n";
    
    KDList list8;
    list8.root = NULL;
    
    x_Axis_V.clear();
    y_Axis_V.clear();
    value_V.clear();
    list2Values_of_KD.clear();
    
    combine_vector.clear();
    
    for (int x = 0, y = 0, d = 0; d <= 18; x++, y++, d++)
    {
        if (x == 0)
        {
            x_Axis_V.push_back(x);
        }
        else if(x == 1)
        {
            x_Axis_V.push_back(500);
        }
        else
        {
            int NewElement = (x_Axis_V[x-1] + x_Axis_V[x-2])/2;
            x_Axis_V.push_back(NewElement);
        }
        
        y_Axis_V.push_back(500 - x_Axis_V[x]);
        value_V.push_back(d);
        
    }
    
    
    
    for (int i = 1, j = 1, k = 1; k < value_V.size(); i++, j++, k++)
    {
        combine_vector.clear();
        combine_vector.push_back(x_Axis_V[i]);
        combine_vector.push_back(y_Axis_V[j]);
        combine_vector.push_back(value_V[k]);
        
        
        if (i == 6 && j == 6) // done as per insertion requirement
        {
            i = 0;
        }
        if (j == 12)
        {
            j = 0;
        }
        
        list8.root = list8.insert_KD(list8.root, combine_vector);
        list2Values_of_KD.push_back(combine_vector);
        
        
    }
    
    
    
    int list_iterator = 0;
    
    while (list8.root != NULL)
    {
        if (list_iterator==6)  // when tree will have 12 nodes
        {
            list8.show_KD(list8.root, "t8-a.dot");
        }
        if (list_iterator==12)  // when tree will have 12 nodes
        {
            list8.show_KD(list8.root, "t8-b.dot");
        }
        list8.root =  list8.Delete_KD(list8.root, 0);
        if (list8.root != NULL)
        {
            cout <<"\n searching for: " << "["<<list2Values_of_KD[list_iterator][0] << ", " << list2Values_of_KD[list_iterator][1] << ", " << list2Values_of_KD[list_iterator][2] << "] \n";
            bool result = list8.search_KD(list8.root, list2Values_of_KD[list_iterator], 0);
            if (result == true)
            {
                cout << "\n************************************************** Element found: ";
                cout << "[" << list2Values_of_KD.at(list_iterator)[0] << ", " << list2Values_of_KD.at(list_iterator)[1] << ", " << list2Values_of_KD.at(list_iterator)[2] << "] \n";
            }
            else
                cout << "\n************************************************** Not found\n";
            
            
        
            list_iterator ++;
            cout << "\n \n";
        }
    }
    
       
    
    
    
    
    
    
    cout << "\n============================================ Test Case 8 END ============================================\n";
    
    
    
    
    
    cout << "\n";
    
    return 0;
}

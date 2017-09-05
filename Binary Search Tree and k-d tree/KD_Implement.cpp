//
//  KD_Implement.cpp
//  BinarySearchTree
//
//  Created by Pranjul Arora on 11/15/16.
//  Copyright © 2016 Pranjul AroraBST. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "KDList.h"
#include <math.h>
#include <sstream>
#include <cstdlib>
using namespace std;

// create new node and return that node
KDNode* KDList::CreateNode(std::vector<int> newVal)
{
    KDNode* newNode = new KDNode();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->nodeValuesVec.push_back(newVal[0]);
    newNode->nodeValuesVec.push_back(newVal[1]);
    newNode->nodeValuesVec.push_back(newVal[2]);
    
    return newNode;
}

// insert in KD
KDNode* KDList::insert_KD(KDNode * root, std::vector<int> newVal)
{
    // newVal is the vector which has all 3 values -> x-axis, y-axis and data
    int i = 0;
    KDNode* current = root;
    KDNode* prev = NULL;
    
    
    while (current != NULL)
    {
        prev = current;
        if (newVal[i] <= current->nodeValuesVec[i])
            current = current-> left;
        else
            current = current->right;
        
        i = (i + 1) % 2;
    }
    if (root == NULL)
    {
        root = CreateNode(newVal);
        root->parent = NULL;
    }
    else if (newVal[(1-i) % 2] <= prev->nodeValuesVec[(1-i) % 2])
    {
        prev->left = CreateNode(newVal);
        prev->left->parent = prev;
    }
    else
    {
        prev->right = CreateNode(newVal);
        prev->right->parent = prev;
    }
    
    return root;
}


// in order traversal
void KDList::displayInOrder(KDNode* rootElement)
{
    if (rootElement == NULL) {
        cout << "\n";
        return;
    }
    displayInOrder(rootElement->left);
    cout << "[" << rootElement->nodeValuesVec[0] << ", " << rootElement->nodeValuesVec[1] << ", " << rootElement->nodeValuesVec[2] << "] ";
    displayInOrder(rootElement->right);
    
}

// find height if the node
int KDList::KDHeight(KDNode* rootElement)
{
    if (rootElement == NULL)
        return -1;
    return max(KDHeight(rootElement->left), KDHeight(rootElement->right)) + 1;
    
    
}


// genreate pair of unique random numbers and return them in a vector of vector -- this is done for unique pair of x&y
vector<vector<int> > KDList::unique_Random_Numbers(int min, int max, int size)
{
    vector<vector<int> > uniqueKeys;
    vector<int> local_vector;
    
    for (int i = 0; i < size; i++)
    {
        int flag = 1;
        while (flag == 1)
        {
            local_vector.clear();
            int x_random = rand() % (max - min + 1) + min;
            int y_random = rand() % (max - min + 1) + min;
            local_vector.push_back(x_random);
            local_vector.push_back(y_random);
            
            if (uniqueKeys.size() == 0)
            {
                uniqueKeys.push_back(local_vector);
                flag = 0;
                break;
            }
            for (int j =0; j < uniqueKeys.size() ; j++)
            {
                if (local_vector[0] == uniqueKeys.at(j).at(0))
                {
                    if (local_vector[1] == uniqueKeys.at(j).at(1))
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                    flag = 0;
            }
            
            if (flag == 0)
                uniqueKeys.push_back(local_vector);
        }
    }
    return uniqueKeys;
}


// Display fucntion as a per Test Case Requirement
void KDList::displayKDTable(vector<vector<double> > KDvector)
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "n = No. of Nodes in the tree\t" << "Height of BST T3\t" << "lg n" << setw(12) << "√n" ;
    cout << "\n---------------------------------------------------------------------------------------\n";
    
    
    for (int i = 0; i < KDvector.size(); i++)
    {
        cout << setw(13) << KDvector.at(i).at(0) << setw(28) << KDvector.at(i).at(1);
        
        isfinite(KDvector.at(i).at(2)) == false ? cout << setw(19) << "N.A." : cout << setw(19) << setprecision(3) << KDvector.at(i).at(2);
              
        cout << setw(10) << KDvector.at(i).at(3) << "\n" ;
        
    }
    
    
    cout << "---------------------------------------------------------------------------------------\n";
    
}

// delete function in KD
KDNode* KDList::Delete_KD(KDNode* root, int i)
{
    // is taken for calculating dimension
    KDNode* node = NULL;
    
    if (root-> right == NULL && root->left == NULL)
    {
        // cout << "\nbefore: address of pis : " << p << "\n";
        if (root->parent != NULL)
        {
            if (root->parent->left == root)
                root->parent->left = NULL;
            else
                root->parent->right = NULL;
        }
        delete root;
        root = NULL;
        
        // cout<<root;
        // cout << "\naddress of pis : " << p << "\n";
        
        return root;
    }
    else if (root->right != NULL)
    {
        node = smallest_in_KD(root->right, i, (i+1) % 2); // using smallest function
    }
    else
    {
        node = smallest_in_KD(root->left, i, (i+1) % 2);
        root->right = root->left;
        root->left = NULL;
    }
    
    root->nodeValuesVec = node->nodeValuesVec;
    
    int new_i = Depth(node) % 2;
    Delete_KD(node, new_i);
    
    return root;
    
}


// finding depth of node helps to calculate the dimension
int KDList::Depth(KDNode* node)
{
    int depth = 0;
    KDNode* temp = node;
    while (temp->parent != NULL)
    {
        depth++;
        temp = temp->parent;
    }
    return depth;
}



// finds smallest in KD
KDNode* KDList::smallest_in_KD(KDNode* find_Node, int i, int j)
{
    KDNode* smallest = find_Node;
    
    
   
    if (find_Node->left != NULL)
    {
        KDNode* left = smallest_in_KD(find_Node->left, i, (j+1)%2 );
        if (smallest->nodeValuesVec[i] >= left->nodeValuesVec[i])
            smallest = left;
    }
    if (find_Node->right != NULL)
    {
        KDNode* right = smallest_in_KD(find_Node->right, i, (j+1)%2);
        
        if (smallest->nodeValuesVec[i] >= right->nodeValuesVec[i])
            smallest = right;
        
    }
    return smallest;
}

// generates unique random numbers and return them in a vector
vector<int> KDList::unique_Random_array(int min, int max, int size)
{
    vector<int> uniqueKeys;
    for (int i=0; i< size; i++)
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
            
            for (int j =0; j < uniqueKeys.size() ; j++)
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



// search in KD
bool KDList::search_KD(KDNode* root, vector<int> x_y_value_vector, int depth)
{
    if(root == NULL)
        return false;
    
    if((root->nodeValuesVec[0] == x_y_value_vector[0]) && (root->nodeValuesVec[1] == x_y_value_vector[1]) && (root->nodeValuesVec[2] == x_y_value_vector[2]))
    {
        return true;
    }
    
    int cd = depth % 2;
    if (x_y_value_vector[cd] <= root->nodeValuesVec[cd])
    {
        return search_KD(root->left, x_y_value_vector, depth+1);
    }
    
    return search_KD(root->right, x_y_value_vector, depth+1);
    
}

// generates null node
void KDList::DotNull(string values, int count, FILE* file_Stream)
{
    fprintf(file_Stream, "    null%d [shape=point];\n", count);
    fprintf(file_Stream, "    \"%s\" -> null%d;\n", values.c_str(), count);
}


// print a single node
void KDList::PrintDotFile(KDNode* root, FILE* file_Stream)
{
    static int count = 0;
    
    if (root->left != NULL)
    {
        ostringstream intToString;
        intToString << root->nodeValuesVec[0] << "," << root->nodeValuesVec[1] << "," << root->nodeValuesVec[2];
        string val1 = intToString.str();
        intToString.str("");
        intToString << root->left->nodeValuesVec[0] << "," <<root->left->nodeValuesVec[1]<<","<< root->left->nodeValuesVec[2];
        string val2 = intToString.str().c_str();
        fprintf(file_Stream, "    \"%s\" -> \"%s\";\n", val1.c_str(), val2.c_str());
        PrintDotFile(root->left, file_Stream);
    }
    else
    {
        ostringstream intToString;
        intToString << root->nodeValuesVec[0] << "," << root->nodeValuesVec[1]  << "," << root->nodeValuesVec[2] ;
        string val3 = intToString.str();
        DotNull(val3, count++, file_Stream);
    }
    
    if (root->right != NULL)
    {
        ostringstream intToString;
        intToString << root->nodeValuesVec[0]  << "," <<root->nodeValuesVec[1] <<","<< root->nodeValuesVec[2] ;
        string val1 = intToString.str();
        intToString.str("");
        intToString << root->right->nodeValuesVec[0]  << "," <<root->right->nodeValuesVec[1] <<","<< root->right->nodeValuesVec[2] ;
        string val2 = intToString.str();
        fprintf(file_Stream, "    \"%s\" -> \"%s\";\n", val1.c_str(), val2.c_str());
        PrintDotFile(root->right, file_Stream);
    }
    else
    {
        ostringstream intToString;
        intToString << root->nodeValuesVec[0]  << "," << root->nodeValuesVec[1] <<","<<root->nodeValuesVec[2] ;
        string val1 = intToString.str();
        DotNull(val1, count++, file_Stream);
    }
    
    
}
// print the whole dot file
void KDList::show_KD(KDNode* root, string file)
{
    FILE* file_Stream = fopen(file.c_str(), "w");
    fprintf(file_Stream, "digraph KD_Tree {\n");
    fprintf(file_Stream, "    node [fontname=\"Arial\"];\n");
    if (root == NULL)
        fprintf(file_Stream, "\n");
    else if (root->right == NULL && root->left == NULL)
    {
        ostringstream intToString;
        intToString << root->nodeValuesVec[0] << "," << root->nodeValuesVec[1]<<","<<root->nodeValuesVec[2];
        string val = intToString.str();
        fprintf(file_Stream, "    \"%s\";\n", val.c_str());
    }
    else
        PrintDotFile(root, file_Stream);
    
    fprintf(file_Stream, "}\n");
    fclose(file_Stream);
}


































































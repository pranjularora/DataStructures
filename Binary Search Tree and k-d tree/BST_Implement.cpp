//
//  BST_Implement.cpp
//  BinarySearchTree
//
//  Created by Pranjul Arora on 11/14/16.
//  Copyright © 2016 Pranjul AroraBST. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <sstream>
#include "BSTList.h"
#include <cstdlib>

using namespace std;


// create new node and return that node
BSTNode* BSTList::CreateNode(int key, int value)
{
    BSTNode* newNode = new BSTNode();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = key;
    newNode->value = value;
    return newNode;
}


// insert in BST function
BSTNode* BSTList::insert(BSTNode* rootElement, int key, int value)
{
    if (rootElement == NULL)
    {
        rootElement = CreateNode(key, value);
    }
    else if(key <= rootElement->key)  // in case if a element is less than its parent then also it will go to its parents left
    {
        rootElement->left = insert(rootElement->left, key, value);
    }
    else
    {
        rootElement->right = insert(rootElement->right, key, value);
    }
    return rootElement;
}


// search in the BST tree -- using recursion
BSTNode* BSTList::search(BSTNode* rootElement, int key)
{
    if(rootElement == NULL)
    {
        return NULL;
    }
    if(rootElement->key == key)
    {
        return rootElement;
    }
    else if(key <= rootElement->key)
    {
        return search(rootElement->left, key);
    }
    else
    {
        return search(rootElement->right, key);
    }
}

// find minimum in the right subtree
BSTNode* BSTList::FindMinInRightSubTree(BSTNode* rootElement)
{
    while (rootElement->left != NULL) {
        rootElement = rootElement->left;
    }
    return rootElement;
}


// delete node in BST
BSTNode* BSTList::Delete(BSTNode * rootElement, int key, int value)
{
    if (rootElement == NULL)
    {
        return rootElement;
    }
    else if(key <= rootElement->key && value != rootElement->value)
    {
        rootElement->left = Delete(rootElement->left, key, value);  // searching for the element
    }
    else if(key > rootElement->key && value != rootElement->value)
    {
        rootElement->right = Delete(rootElement->right, key, value); // searching for the element
    }
    else
    { // element found
        // if left and right nodes are null
        if(rootElement->right == NULL && rootElement->left == NULL)
        {
            delete rootElement;
            rootElement = NULL;
        }
        // if left node are null
        else if (rootElement->left == NULL)
        {
            BSTNode* tempNode = rootElement;
            rootElement=rootElement->right;
            delete tempNode;
            tempNode = NULL;
        }
        // if right node are null
        else if(rootElement-> right == NULL)
        {
            BSTNode* tempNode = rootElement;
            rootElement=rootElement->left;
            delete tempNode;
            tempNode = NULL;
        }
        // if both nodes are not null .. it is done so that the this case can be reduced to one of upper cases
        else
        {
            BSTNode* tempNode = FindMinInRightSubTree(rootElement->right);
            rootElement-> key = tempNode->key;
            rootElement->value = tempNode->value;
            rootElement->right = Delete(rootElement->right, tempNode->key, tempNode->value);
        }
        
    }
    return rootElement;
    
}

// traverse in order and display
void BSTList::displayInOrder(BSTNode* rootElement)
{
    if (rootElement == NULL) {
        cout << "\n";
        return;
    }
    displayInOrder(rootElement->left);
    cout << "[" << rootElement->key << ", " << rootElement->value << "] ";
    displayInOrder(rootElement->right);
    
}


// creates a vector of unique random numbers
vector<int> BSTList::unique_Random_Numbers(int min, int max, int size)
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


// calculate height of the BST node
int BSTList::BSTHeight(BSTNode* rootElement)
{
     
    if (rootElement == NULL)
        return -1;
    return max(BSTHeight(rootElement->left), BSTHeight(rootElement->right)) + 1;
    
}



// Display fucntion as a per Test Case Requirement
void BSTList::displayBstTable(vector<vector<double> > BSTvector)
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "n = No. of Nodes in the tree\t" << "Height of BST T3\t" << "lg n" << setw(12) << "√n" ;
    cout << "\n---------------------------------------------------------------------------------------\n";
    
   
    
    for (int i = 0; i < BSTvector.size(); i++)
    {
        cout << setw(13) << BSTvector.at(i).at(0) << setw(28) << BSTvector.at(i).at(1);
        
        isfinite(BSTvector.at(i).at(2)) == false ? cout << setw(19) << "N.A." : cout << setw(19) << setprecision(3) << BSTvector.at(i).at(2);

        cout << setw(10) << BSTvector.at(i).at(3) << "\n" ;
    }
    cout << "---------------------------------------------------------------------------------------\n";
    
}


// Display fucntion as a per Test Case Requirement
void BSTList::displayCase7(std::vector<std::vector<int> > BSTvector)
{
    cout << "\n-------------------------------------------------------------------------------------------\n";
    cout << "stage\t" << "data item at root\t" << "the root (after deletion)\t" << setw(22) << "search for data with key" ;
    cout << "\n-------------------------------------------------------------------------------------------\n";
    
    for (int i = 0; i < BSTvector.size(); i++)
    {
        
        cout << setw(3) << BSTvector.at(i).at(0) << setw(10) ;
        
        BSTvector.at(i).at(1) == -1 ? cout << "nil" : cout << "[" << BSTvector.at(i).at(1) << ", ";
        
        BSTvector.at(i).at(2) == -1 ? cout << "nil" : cout << BSTvector.at(i).at(2) << "] ";
        cout << setw(15);
        
        
        BSTvector.at(i).at(3) == -1 ? cout << setw(20) << "nil" << setw(4) : cout << "[" << BSTvector.at(i).at(3) << ", ";
        
        
        BSTvector.at(i).at(4) == -1 ? cout << "" : cout << BSTvector.at(i).at(4) << "] ";
        cout << setw(25);
        
        BSTvector.at(i).at(5) == -1 ? cout << setw(30) << "nil" : cout << "[" << BSTvector.at(i).at(5) << ", ";
        
        BSTvector.at(i).at(6) == -1 ? cout << "" : cout << BSTvector.at(i).at(6) << "] ";
        cout << "\n" ;
    }
    cout << "-------------------------------------------------------------------------------------------\n";
    
}

// print a single node
// show function will call it for a single node
void BSTList::PrintDotFile(BSTNode* root, FILE* file_Stream)
{
    static int count = 0;
    
    if (root->left != NULL)
    {
        ostringstream intToString;
        intToString << root->key << "," << root->value;  // converting intergers to string
        string val1 = intToString.str();
        intToString.str("");
        intToString << root->left->key << "," <<root->left->value;   // converting intergers to string
        string val2 = intToString.str().c_str();
        fprintf(file_Stream, "    \"%s\" -> \"%s\";\n", val1.c_str(), val2.c_str());
        PrintDotFile(root->left, file_Stream);
    }
    else
    {
        ostringstream intToString;
        intToString << root->key << "," << root->value;
        string val1 = intToString.str();
        DotNull(val1, count++, file_Stream);
    }
    
    if (root->right != NULL)
    {
        ostringstream intToString;
        intToString << root->key  << "," <<root->value;
        string val1 = intToString.str();
        intToString.str("");
        intToString << root->right->key  << "," <<root->right->value ;
        string val2 = intToString.str();
        fprintf(file_Stream, "    \"%s\" -> \"%s\";\n", val1.c_str(), val2.c_str());
        PrintDotFile(root->right, file_Stream);
    }
    else
    {
        ostringstream intToString;
        intToString << root->key  << "," << root->value;
        string val1 = intToString.str();
        DotNull(val1, count++, file_Stream);
    }
    
    
}
// with this whole dot file will be printed
void BSTList::show_BST(BSTNode* root, string file)
{
    FILE* file_Stream = fopen(file.c_str(), "w");
    fprintf(file_Stream, "digraph BST_Tree {\n");
    fprintf(file_Stream, "    node [fontname=\"Arial\"];\n");
    if (root == NULL)
        fprintf(file_Stream, "\n");
    else if (root->right == NULL && root->left == NULL)
    {
        ostringstream intToString;
        intToString << root->key << "," << root->value;
        string val = intToString.str();
        fprintf(file_Stream, "    \"%s\";\n", val.c_str());
    }
    else
        PrintDotFile(root, file_Stream);
    
    fprintf(file_Stream, "}\n");
    fclose(file_Stream);
}

// print null node
// show function will call it to print null node
void BSTList::DotNull(string values, int count, FILE* file_Stream)
{
    fprintf(file_Stream, "    null%d [shape=point];\n", count);
    fprintf(file_Stream, "    \"%s\" -> null%d;\n", values.c_str(), count);
}























































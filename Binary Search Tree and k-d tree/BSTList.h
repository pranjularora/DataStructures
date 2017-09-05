//
//  BSTList.h
//  BinarySearchTree
//
//  Created by Pranjul Arora on 11/13/16.
//  Copyright © 2016 Pranjul AroraBST. All rights reserved.
//

#ifndef BSTList_h
#define BSTList_h
#include "BSTNode.h"
#include <vector>

class BSTList
{
public:
    BSTNode* rootElement;       // defines root
    BSTNode* insert(BSTNode*, int, int);  // insert in BST function
    BSTNode* CreateNode(int, int);          // create new node function
    BSTNode* search (BSTNode*, int);    // search in BST function
    BSTNode* FindMinInRightSubTree(BSTNode*);   // find minimum in right subtree function
    
    BSTNode* Delete(BSTNode*, int, int); // delete function
    
    void displayInOrder(BSTNode*);  // display the BST using in order traversal
    
    std::vector<int> unique_Random_Numbers(int, int, int);   // creates unique random numbers
    int BSTHeight(BSTNode*);  // calculates height of the node
    
    
    void displayBstTable(std::vector<std::vector<double> >);  // display function as per requirement
    void displayCase7(std::vector<std::vector<int> >);
    
    
    void DotNull(std::string, int, FILE*); // generates null node
    
    void PrintDotFile(BSTNode*, FILE*);   // generates dot node
    void show_BST(BSTNode*, std::string);  // creates whole dot repesentation
    
    
};



#endif /* BSTList_h */

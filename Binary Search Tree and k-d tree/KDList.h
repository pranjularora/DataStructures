//
//  KDList.h
//  BinarySearchTree
//
//  Created by Pranjul Arora on 11/15/16.
//  Copyright © 2016 Pranjul AroraBST. All rights reserved.
//

#ifndef KDList_h
#define KDList_h
#include "KDNode.h"
#include <vector>
#include <sstream>

class KDList
{
public:
    KDNode* root;  // defines root
    KDNode* insert_KD(KDNode*, std::vector<int>);  // insert in KD
    KDNode* CreateNode(std::vector<int>);   // create new node
    void displayInOrder(KDNode*);  // diplays inorder of KD
    
    int KDHeight(KDNode*);        // calculates height
    std::vector<std::vector<int> > unique_Random_Numbers(int, int, int);  // generates random numbers
    
    void displayKDTable(std::vector<std::vector<double> >);  // display function as per requirement
    KDNode* smallest_in_KD(KDNode*, int, int); // smallest function
    
    KDNode* Delete_KD(KDNode*, int);
    std::vector<int> unique_Random_array(int, int, int);
    
    void DotNull(std::string, int, FILE*);   // generates null node
    void PrintDotFile(KDNode*, FILE*);  // generates dot node
    void show_KD(KDNode*, std::string); // creates whole dot repesentation
    
    
    bool search_KD(KDNode*, std::vector<int>, int);
    int Depth(KDNode* q);

    
};



#endif /* KDList_h */

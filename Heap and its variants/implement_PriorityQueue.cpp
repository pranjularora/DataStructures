// this function will iterate through the heap (vector of vector used as a data structure for makingh a heap)
// using recursion, travesing left side and then right
void priorityQueue::all_Minimum(int min)
{ // min here is the parent
    vector<int> newSmallValue = vecQueue.at(min-1);
    minVector.push_back(newSmallValue);
    int left = 2 * min;  // calculating left child
    int right = (2 * min) + 1; // calculating right child
    if(left < vecQueue.size())
        if (vecQueue.at(min-1).at(0) == vecQueue.at(left-1).at(0) )
            priorityQueue::all_Minimum(left); // using recursion
        if (vecQueue.at(min-1).at(0) == vecQueue.at(right-1).at(0))
            priorityQueue::all_Minimum(right);  // using recursion
}
void priorityQueue::min_Heapify(int i)
{
    int left = 2*i;
    int right = (2 * i) + 1;
    int smallest;
    // if the parameter passed to this function is not smallest then using recursion min heap property will be achieved.
    if (left <= vecQueue.size() && vecQueue.at(left-1).at(0) < vecQueue.at(i-1).at(0))
        smallest = left;
    else
        smallest = i;
    if (right <= vecQueue.size() && vecQueue.at(right-1).at(0) < vecQueue.at(smallest-1).at(0))
        smallest = right;
    if (smallest != i)
        vector<int> swap = vecQueue.at(smallest-1);
        vecQueue.at(smallest-1) = vecQueue.at(i-1);
        vecQueue.at(i-1) = swap;
        priorityQueue::min_Heapify(smallest); // calling this function recursively
}
void priorityQueue::extract_All_Min()
{
    if (vecQueue.size() < 1 )
        return;
    extract_all_min_vector.push_back(vecQueue.at(0));
    vecQueue.at(0) = vecQueue.at(vecQueue.size() - 1);
    vecQueue.pop_back();
    // extracting the top most element
    // then applying min heap function to min heapify the tree
    priorityQueue::min_Heapify(1);
    while (vecQueue.size() > 0 && vecQueue.at(0).at(0) == extract_all_min_vector.at(0).at(0))
        priorityQueue::extract_All_Min();
}

void priorityQueue:: decrease_HeapKey(vector<int> vec_child, int position)
{
    if (vecQueue.size() > 1 && vec_child[0] > vecQueue.at(position).at(0))
        return; // this will be called if the new key is larger than the old one
    vecQueue.at(position) = vec_child;
    if (position > 0)
    {
        int i = position+1;
        int parent_i = i/2;
        // decreasing key and comparing with parent and exchanging till min heap property is achieved
        while (i>1 && vecQueue.at(parent_i-1).at(0) > vecQueue.at(i-1).at(0))
        {
            vector<int> swap = vecQueue.at(parent_i-1);
            vecQueue.at(parent_i-1) = vecQueue.at(i-1);
            vecQueue.at(i-1) = swap;
            i = parent_i;
            parent_i = i/2;
        }
    }
}
void priorityQueue:: minHeap_insert_In_PriorityQueue(vector<int> vec_child)
{
    int size = vecQueue.size();
    vector<int> temp(2);
    temp[0] = INT_MAX; // new element is assigned max integer value
    temp[1] = INT_MAX;
    vecQueue.push_back(temp);
    decrease_HeapKey(vec_child, size); // calling decrease key to take the new element at its right position
}
void priorityQueue::displayQueue_withVec(vector<vector<int> > displayVector)
{
    // this will be called when a specific vector will be called
    if (displayVector.size() > 0 )
        for (int i =0; i< displayVector.size(); i++)
            cout << "[" << displayVector.at(i).at(0) << ", " << displayVector.at(i).at(1) << "]" << " ";
    else cout << "Error, Heap Underflow\n";
}

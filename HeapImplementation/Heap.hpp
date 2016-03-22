//
//  Heap.hpp
//  HeapImplementation
//
//  Created by Kevin Zhang on 2016-03-22.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp


#pragma once

#include <stdexcept>
#include <iostream>
using namespace std;

class Heap{
public:
    // Default constructor
    // PRE:
    // POST: creates and empty heap of size 10
    Heap(void);
    
    // Constructor (int)
    // PRE:
    // PARAM: n - size of the heap
    // POST: creates and empty heap of size n
    Heap(int n);
    
    // Destructor
    // PRE:
    // POST: de-allocates memory associated with arr
    ~Heap(void);
    
    // Inserts int into heap
    // PRE: Underlying array is not full
    // PARAM: x - integer to be inserted
    // POST: inserts x into heap, maintaining the heap
    //       properties - throws exception if heap is full
    void Insert(int x);
    
    // Removes and returns root of heap
    // PRE: arr is not empty
    // POST: removes and returns root, maintaining the heap
    //       properties - throws exception if heap is empty
    int Remove();
    
    // Returns true iff heap is empty
    // PRE:
    // POST: returns true iff size == 0
    bool Empty() {return size == 0;};
    
    // Displays the contents of the heap
    // PRE:
    // POST: prints the contents of the heap (for the lab)
    void Print();
    
private:
    int* arr;
    int max_size;
    int size;
    
    // Fixes partial ordering from i to root
    // PRE:
    // PARAM: i is index to be bubbled up from
    // POST: swaps i with parent if arr[i] > parent
    void BubbleUp(int i);
    
    // Fixes partial ordering from i to leaf
    // PRE:
    // PARAM: i is index to be bubbled down from
    // POST: swaps i with parent if arr[i] < larger child
    void BubbleDown(int i);
};

#endif /* Heap_hpp */

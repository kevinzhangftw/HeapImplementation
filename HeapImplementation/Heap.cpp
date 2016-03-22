//
//  Heap.cpp
//  HeapImplementation
//
//  Created by Kevin Zhang on 2016-03-22.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#include "Heap.hpp"

// Default constructor
// PRE:
// POST: creates and empty heap of size 10
Heap::Heap(void){
    max_size = 10;
    arr = new int[max_size];
    size = 0;
}

// Constructor (int)
// PRE:
// PARAM: n - size of the heap
// POST: creates and empty heap of size 10
Heap::Heap(int n){
    max_size = n;
    arr = new int[max_size];
    size = 0;
}

// Destructor
// PRE:
// POST: de-allocates memory associtaed with arr
Heap::~Heap(void){
    delete[] arr;
}

// Inserts int into heap
// PRE: Underlying array is not full
// PARAM: x - integer to be inserted
// POST: inserts x into heap, maintaining the heap
//       properties - throws exception if heap is full
void Heap::Insert(int x){
    if (size == max_size){
        throw runtime_error("heap is full");
    }
    // Insert x
    arr[size] = x;
    BubbleUp(size++);
}

// Removes and returns root of heap
// PRE: arr is not empty
// POST: removes and returns root, maintaining the heap
//       properties - throws exception if heap is empty
int Heap::Remove(){
    if (size == 0){
        throw runtime_error("heap is empty");
    }
    //get the temp variable
    int temp = arr[0];
    //swap the last element with the first
    arr[0] = arr[--size];
    //heapify the sbs
    BubbleDown(0);
    return temp;
}

// Fixes partial ordering from i to root
// PRE:
// PARAM: i is index to be bubbled up from
// POST: swaps i with parent if arr[i] > parent
void Heap::BubbleUp(int i){
    //get the parent index
    int parent = (i - 1)/2;
    // Check to see if partial ordering is violated
    while (i>0 && arr[parent]<arr[i]){
        // Swap
        int temp = arr[parent];
        arr[parent] = arr[i];
        arr[i] = temp;
        // Set index values
        i = parent;
        parent = (i - 1)/2;
    }
}

// Displays the contents of the heap
// PRE:
// POST: prints the contents of the heap (for the lab)
void Heap::Print(){
    cout << "{";
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if (i < size-1){
            cout << ",";
        }
    }
    cout << "}";
}

// Fixes partial ordering from i to leaf
// PRE:
// PARAM: i is index to be bubbled down from
// POST: swaps i with child if arr[i] < larger child
void Heap::BubbleDown(int i){
    
    int leftChild = 2*i +1;
    int rightChild = 2*i +2;
    //base case: if i is leaf node
    if (leftChild > size || rightChild > size){
        return;
    }
    
    if (arr[i]<arr[leftChild] || arr[i]<arr[rightChild]) {
        if (arr[leftChild]>arr[rightChild]) {
            // Swap left child
            int temp = arr[leftChild];
            arr[leftChild] = arr[i];
            arr[i] = temp;
            // continue to check
            BubbleDown(leftChild);
        }else{
            // Swap right child
            int temp = arr[rightChild];
            arr[rightChild] = arr[i];
            arr[i] = temp;
            // continue to check
            BubbleDown(rightChild);
        }
    }
    //The BubbleDown method compares the value of the element given by the index parameter (e.g. i) with the largest value of its two children (which could be either the left or right child). If the value of the larger child is greater than the value of the element at index i, the two values are swapped and the process continues by calling BubbleDown on the child. The process ends when the value at element i is greater than the values of its children,
    //or if i is a leaf. As with all array methods, care must be taken not to access elements that are not valid array elements.
}
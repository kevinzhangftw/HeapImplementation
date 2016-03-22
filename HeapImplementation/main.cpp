//
//  main.cpp
//  HeapImplementation
//
//  Created by Kevin Zhang on 2016-03-22.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#include <iostream>
#include "Heap.hpp"
using namespace std;

void HeapTest();

int main(int argc, const char * argv[]) {
    HeapTest();
    
    system("pause");
    return 0;
}

void HeapTest()
{
    Heap hp;
    hp.Insert(7);
    hp.Insert(1);
    hp.Insert(3);
    hp.Insert(13);
    hp.Insert(11);
    hp.Insert(4);
    
    cout <<"heap: ";
    ht.Print();
    cout << endl;
    
    while (!hp.Empty()){
        cout << "removed: " << hp.Remove();
        cout << " -- heap: ";
        hp.Print();
        cout << endl;
    }
}

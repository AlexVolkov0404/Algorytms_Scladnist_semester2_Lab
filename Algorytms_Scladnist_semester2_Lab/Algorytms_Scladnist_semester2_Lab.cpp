// Algorytms_Scladnist_semester2_Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector> 
#include "binHeap.h"
#include "group.h"
#include "BinomialHeap.h"

using namespace std;
int main()
{
    int ch, key;
    list<BinomialHeap*> _heap;

    // Insert data in the heap
    
    _heap = BinomialHeap::insertE(_heap, 10);
    _heap = BinomialHeap::insertE(_heap, 20);
    _heap = BinomialHeap::insertE(_heap, 30);

    cout << "Heap elements after insertion:\n";
    BinomialHeap::printHeap(_heap);

    BinomialHeap* temp = BinomialHeap::getMin(_heap);
    cout << "\nMinimum element of heap "
        << temp->data << "\n";

    // Delete minimum element of heap
    _heap = BinomialHeap::extractMin(_heap);
    cout << "Heap after deletion of minimum element\n";
    BinomialHeap::printHeap(_heap);

    return 0;
}


// Algorytms_Scladnist_semester2_Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector> 
#include "group.h"
#include "BinomialHeap.h"
//#include "perfectHashS.h"
#include "PerfectHash.h"


using namespace std;
int main()
{
   
    //list<BinomialHeap*> _heap;

    //// Insert data in the heap
    //
    //_heap = BinomialHeap::insertE(_heap, 10);
    //_heap = BinomialHeap::insertE(_heap, 20);
    //_heap = BinomialHeap::insertE(_heap, 30);
    //_heap = BinomialHeap::insertE(_heap, 5);

    //cout << "Heap elements after insertion:\n";
    //BinomialHeap::printHeap(_heap);

    //BinomialHeap* temp = BinomialHeap::getMin(_heap);
    //cout << "\nMinimum element of heap "
    //    << temp->data << "\n";

    //// Delete minimum element of heap
    //_heap = BinomialHeap::extractMin(_heap);
    //cout << "Heap after deletion of minimum element\n";
    //BinomialHeap::printHeap(_heap);

    //return 0;
    // 
    // 
    //clock_t begin, end;
    //double time_spent;
    //std::srand(time(NULL));
    //int numberOfElements;
    ////scanf("%i", &numberOfElements);

    PerfectHash fs;
    //begin = clock();
    //vector<int> inputVector = {12,14,15,17};
    ////fs.setTableSize(numberOfElements);

    ///*for (int i = 0; i < numberOfElements; ++i)
    //{
    //    int elemValue;
    //    scanf("%d", &elemValue);

    //    inputVector.push_back(elemValue);
    //}*/

    //fs.Initialize(inputVector);
    //end = clock();
    //int numberOfElementsForSearch;
    ////scanf("%i", &numberOfElementsForSearch);
    //while(true)
    //{
    //    int elem;
    //    scanf("%d", &elem);
    //    if (fs.Contains(elem))
    //    {
    //        cout << "Yes" << endl;
    //    }
    //    else
    //    {
    //        cout << "No" << endl;
    //    }
    //}

    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //cout << time_spent << endl;
    vector<string> inputVector = { "hello","ted" };
    vector<string> inputVector1 = { "hellowwww" };
    fs.StringInitialize(inputVector[0]);
    fs.StringInitialize(inputVector[1]);
    cout<<fs.StringContains(inputVector1[0]);

}


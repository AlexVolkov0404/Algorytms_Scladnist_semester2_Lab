// Algorytms_Scladnist_semester2_Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector> 

//#include "BinomialHeap.h"
//#include "BinaryTree.h"
//#include "PerfectHashLogic.h"
#include "OptimalBinaryTreeLogic.h"
#include "BinomialHeapLogic.h"



using namespace std;
int main()
{
   
    list<BinomialHeapLogic*> _heap;

    // Insert data in the heap
    
    _heap = BinomialHeapLogic::insertE(_heap, 10);
    _heap = BinomialHeapLogic::insertE(_heap, 20);
    _heap = BinomialHeapLogic::insertE(_heap, 30);
    _heap = BinomialHeapLogic::insertE(_heap, 5);

    cout << "Heap elements after insertion:\n";
    BinomialHeapLogic::printHeap(_heap);

    BinomialHeapLogic* temp = BinomialHeapLogic::getMin(_heap);
    cout << "\nMinimum element of heap "
        << temp->data << "\n";

    // Delete minimum element of heap
    _heap = BinomialHeapLogic::extractMin(_heap);
    cout << "Heap after deletion of minimum element\n";
    BinomialHeapLogic::printHeap(_heap);

    return 0;
    


    // 
    // 
    // 
    //clock_t begin, end;
    //double time_spent;
    //std::srand(time(NULL));
    //int numberOfElements;
    ////scanf("%i", &numberOfElements);

   // PerfectHashLogic fs;
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
   /* vector<string> inputVector = { "hello","ted" };
    vector<string> inputVector1 = { "hellowwww" };
    fs.StringInitialize(inputVector[0]);
    fs.StringInitialize(inputVector[1]);
    cout<<fs.StringContains(inputVector1[0]);*/
   // OptimalBinaryTreeLogic Ot;
   // vector<int> keys = { 1, 2,3,4,5 };
   // vector<int> freq = { 10, 20,15,30,25 };
   // //int n = sizeof(keys) / sizeof(keys[0]);
   // vector<int> sortedKeys = Ot.optimalSearchTree(keys, freq);
   //// cout << sortedKeys[0];
   // BINTRP tr, p;
   // int gdriver = DETECT, gmode, errorcode;
   // char c[256] = " ";
   // tr = zapov(keys);
   // initgraph(&gdriver, &gmode, c);
   // errorcode = graphresult();
   // print_tree1(tr, 1, getmaxx(), 40);
   // //exchange(tr);
   // //cout << poshuk(tr);


   // p= zapov(sortedKeys);
   // initgraph(&gdriver, &gmode, c);
   // errorcode = graphresult();
   // print_tree1(p, 1, getmaxx(), 40);


   // getch();

}


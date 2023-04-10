#pragma once
#include <iostream>
#include <list>
using namespace std;
class  BinomialHeapLogic
{
public:
	int data, degree;
	BinomialHeapLogic* child, * sibling, * parent;
	BinomialHeapLogic();
	BinomialHeapLogic(int data, int degree, BinomialHeapLogic* child, BinomialHeapLogic* sibling, BinomialHeapLogic* parent);
	static BinomialHeapLogic* newNode(int key);
	static BinomialHeapLogic* mergeBinomialTrees(BinomialHeapLogic* b1, BinomialHeapLogic* b2);
	static list<BinomialHeapLogic*> unionBionomialHeap(list<BinomialHeapLogic*> l1, list<BinomialHeapLogic*> l2);
	static list<BinomialHeapLogic*> adjust(list<BinomialHeapLogic*> _heap);
	static list<BinomialHeapLogic*> insertATreeInHeap(list<BinomialHeapLogic*> _heap, BinomialHeapLogic* tree);
	static list<BinomialHeapLogic*> removeMinFromTreeReturnBHeap(BinomialHeapLogic* tree);
	static list<BinomialHeapLogic*> insertE(list<BinomialHeapLogic*> _head, int key);
	static BinomialHeapLogic* getMin(list<BinomialHeapLogic*> _heap);
	static list<BinomialHeapLogic*> extractMin(list<BinomialHeapLogic*> _heap);
	static void printTree(BinomialHeapLogic* h);
	static void printHeap(list<BinomialHeapLogic*> _heap);

};

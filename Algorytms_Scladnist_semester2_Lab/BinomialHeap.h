#pragma once
#include <iostream>
#include <list>
using namespace std;
class  BinomialHeap
{
public:
	int data, degree;
	BinomialHeap* child, * sibling, * parent;
	BinomialHeap();
	BinomialHeap(int data, int degree, BinomialHeap* child, BinomialHeap* sibling, BinomialHeap* parent);
	static BinomialHeap* newNode(int key);
	static BinomialHeap* mergeBinomialTrees(BinomialHeap* b1, BinomialHeap* b2);
	static list<BinomialHeap*> unionBionomialHeap(list<BinomialHeap*> l1, list<BinomialHeap*> l2);
	static list<BinomialHeap*> adjust(list<BinomialHeap*> _heap);
	static list<BinomialHeap*> insertATreeInHeap(list<BinomialHeap*> _heap, BinomialHeap* tree);
	static list<BinomialHeap*> removeMinFromTreeReturnBHeap(BinomialHeap* tree);
	static list<BinomialHeap*> insertE(list<BinomialHeap*> _head, int key);
	static BinomialHeap* getMin(list<BinomialHeap*> _heap);
	static list<BinomialHeap*> extractMin(list<BinomialHeap*> _heap);
	static void printTree(BinomialHeap* h);
	static void printHeap(list<BinomialHeap*> _heap);

};

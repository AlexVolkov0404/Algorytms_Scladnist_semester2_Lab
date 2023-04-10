#include "BinomialHeapLogic.h"

BinomialHeapLogic::BinomialHeapLogic()
{
}

BinomialHeapLogic::BinomialHeapLogic(int data, int degree, BinomialHeapLogic* child, BinomialHeapLogic* sibling, BinomialHeapLogic* parent)
{

}

BinomialHeapLogic* BinomialHeapLogic::newNode(int key)
{
    BinomialHeapLogic* temp = new BinomialHeapLogic;
    temp->data = key;
    temp->degree = 0;
    temp->child = temp->parent = temp->sibling = NULL;
    return temp;
}

BinomialHeapLogic* BinomialHeapLogic::mergeBinomialTrees(BinomialHeapLogic* b1, BinomialHeapLogic* b2)
{
    // Make sure b1 is smaller
    if (b1->data > b2->data)
        swap(b1, b2);

    // We basically make larger valued tree
    // a child of smaller valued tree
    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;

    return b1;
}

list<BinomialHeapLogic*> BinomialHeapLogic::unionBionomialHeap(list<BinomialHeapLogic*> l1, list<BinomialHeapLogic*> l2)
{
    // _new to another binomial heap which contain
  // new heap after merging l1 & l2
    list<BinomialHeapLogic*> _new;
    list<BinomialHeapLogic*>::iterator it = l1.begin();
    list<BinomialHeapLogic*>::iterator ot = l2.begin();
    while (it != l1.end() && ot != l2.end())
    {
        // if D(l1) <= D(l2)
        if ((*it)->degree <= (*ot)->degree)
        {
            _new.push_back(*it);
            it++;
        }
        // if D(l1) > D(l2)
        else
        {
            _new.push_back(*ot);
            ot++;
        }
    }

    // if there remains some elements in l1
    // binomial heap
    while (it != l1.end())
    {
        _new.push_back(*it);
        it++;
    }

    // if there remains some elements in l2
    // binomial heap
    while (ot != l2.end())
    {
        _new.push_back(*ot);
        ot++;
    }
    return _new;
}

list<BinomialHeapLogic*> BinomialHeapLogic::adjust(list<BinomialHeapLogic*> _heap)
{
    if (_heap.size() <= 1)
        return _heap;
    list<BinomialHeapLogic*> new_heap;
    list<BinomialHeapLogic*>::iterator it1, it2, it3;
    it1 = it2 = it3 = _heap.begin();

    if (_heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = _heap.end();
    }
    else
    {
        it2++;
        it3 = it2;
        it3++;
    }
    while (it1 != _heap.end())
    {
        // if only one element remains to be processed
        if (it2 == _heap.end())
            it1++;

        // If D(it1) < D(it2) i.e. merging of Binomial
        // Tree pointed by it1 & it2 is not possible
        // then move next in heap
        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if (it3 != _heap.end())
                it3++;
        }

        // if D(it1),D(it2) & D(it3) are same i.e.
        // degree of three consecutive Binomial Tree are same
        // in heap
        else if (it3 != _heap.end() &&
            (*it1)->degree == (*it2)->degree &&
            (*it1)->degree == (*it3)->degree)
        {
            it1++;
            it2++;
            it3++;
        }

        // if degree of two Binomial Tree are same in heap
        else if ((*it1)->degree == (*it2)->degree)
        {
            BinomialHeapLogic* temp;
            *it1 = mergeBinomialTrees(*it1, *it2);
            it2 = _heap.erase(it2);
            if (it3 != _heap.end())
                it3++;
        }
    }
    return _heap;
}

list<BinomialHeapLogic*> BinomialHeapLogic::insertATreeInHeap(list<BinomialHeapLogic*> _heap, BinomialHeapLogic* tree)
{
    // creating a new heap i.e temp
    list<BinomialHeapLogic*> temp;

    // inserting Binomial Tree into heap
    temp.push_back(tree);

    // perform union operation to finally insert
    // Binomial Tree in original heap
    temp = unionBionomialHeap(_heap, temp);

    return adjust(temp);
}

list<BinomialHeapLogic*> BinomialHeapLogic::removeMinFromTreeReturnBHeap(BinomialHeapLogic* tree)
{
    list<BinomialHeapLogic*> heap;
    BinomialHeapLogic* temp = tree->child;
    BinomialHeapLogic* lo;

    // making a binomial heap from Binomial Tree
    while (temp)
    {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;
        heap.push_front(lo);
    }
    return heap;
}

list<BinomialHeapLogic*> BinomialHeapLogic::insertE(list<BinomialHeapLogic*> _head, int key)
{
    BinomialHeapLogic* temp = newNode(key);
    return insertATreeInHeap(_head, temp);
}

BinomialHeapLogic* BinomialHeapLogic::getMin(list<BinomialHeapLogic*> _heap)
{
    list<BinomialHeapLogic*>::iterator it = _heap.begin();
    BinomialHeapLogic* temp = *it;
    while (it != _heap.end())
    {
        if ((*it)->data < temp->data)
            temp = *it;
        it++;
    }
    return temp;
}

list<BinomialHeapLogic*> BinomialHeapLogic::extractMin(list<BinomialHeapLogic*> _heap)
{
    list<BinomialHeapLogic*> new_heap, lo;
    BinomialHeapLogic* temp;

    // temp contains the pointer of minimum value
    // element in heap
    temp = getMin(_heap);
    list<BinomialHeapLogic*>::iterator it;
    it = _heap.begin();
    while (it != _heap.end())
    {
        if (*it != temp)
        {
            // inserting all Binomial Tree into new
            // binomial heap except the Binomial Tree
            // contains minimum element
            new_heap.push_back(*it);
        }
        it++;
    }
    lo = removeMinFromTreeReturnBHeap(temp);
    new_heap = unionBionomialHeap(new_heap, lo);
    new_heap = adjust(new_heap);
    return new_heap;
}
// print function for Binomial Tree
void BinomialHeapLogic::printTree(BinomialHeapLogic* h)
{
    while (h)
    {
        cout <<  h->data <<endl;
        
        printTree(h->child);
        h = h->sibling;
    }
}
// print function for binomial heap
void BinomialHeapLogic::printHeap(list<BinomialHeapLogic*> _heap)
{
    list<BinomialHeapLogic*> ::iterator it;
    it = _heap.begin();
    while (it != _heap.end())
    {
        printTree(*it);
        it++;
    }
}

#pragma once
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
class PerfectHashLogic
{
    // min 36500, sweetspot 73000
    static const int _size = 73000;
    int _noentry;
    std::vector<int> _set1;
    std::vector<int> _set2;
    std::vector<int> _set3;
public:
    PerfectHashLogic() : _noentry(std::numeric_limits<int>::min()), _set1(_size, _noentry), _set2(_size, _noentry), _set3(_size, _noentry) {  }
    void Initialize(const std::vector<int>& numbers);
    bool Contains(int number);
    void StringInitialize(std::string letter);
    bool StringContains(std::string letter);
private:
    int hash(int rounds, int number);
    inline int bigRand();
    bool add(int number);
};

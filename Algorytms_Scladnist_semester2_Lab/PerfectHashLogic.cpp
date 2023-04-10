#include "PerfectHashLogic.h"



void PerfectHashLogic::Initialize(const std::vector<int>& numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (!Contains(numbers[i])) {
            if (!add(numbers[i]))
            {
                std::ostringstream o;
                o << "Failed to insert after " << i << " elements, rehashing not implemented";
                throw new std::exception(o.str().c_str());
            }
        }
        
    }
}

bool PerfectHashLogic::Contains(int number)
{
    for (int round = 0; round < 3; ++round)
    {
        std::vector<int>& _set = (round % 3 == 0) ? _set1 : ((round % 3 == 1) ? _set2 : _set3);
        int h = hash(round + 1, number);
        if (number == _set[h])
            return true;
    }
    return false;
}

void PerfectHashLogic::StringInitialize(std::string letter)
{
    std::vector<int>numbers;
    std::string message;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        message += std::to_string(int(x));
        if (i % 6 == 0)
        {
            numbers.push_back(std::stoll(message));
            message = "";
        }

    }
    numbers.push_back(std::stoll(message));
    Initialize(numbers);
}

bool PerfectHashLogic::StringContains(std::string letter)
{
    std::string message;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        message += std::to_string(int(x));
        if (i % 6 == 0)
        {
            if (!Contains(std::stoll(message)))
            {
                return false;
            }
            message = "";
        }

    }

    if (!Contains(std::stoll(message)))
    {
        return false;
    }
    return true;
}

int PerfectHashLogic::hash(int rounds, int number)
{
    int withOffset = number;
    srand(withOffset);
    int h = bigRand() % _size;
    while (--rounds)
    {
        h = bigRand() % _size;
    }
    return h;
}

inline int PerfectHashLogic::bigRand()
{
    return (rand() << 15) | rand(); // RAND_MAX is 0x7FFF in VS2010
}

bool PerfectHashLogic::add(int number)
{
    int toInsert = number;
    for (int i = 0; i < _size; ++i)
    {
        int h = hash(i % 3 + 1, toInsert);
        std::vector<int>& _set = (i % 3 == 0) ? _set1 : ((i % 3 == 1) ? _set2 : _set3);
        int current = _set[h];
        if (current == _noentry)
        {
            _set[h] = toInsert;
            return true;
        }
        _set[h] = toInsert;
        toInsert = current;
    }
    return false;
}

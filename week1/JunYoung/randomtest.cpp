#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <set>

int main(void)
{
    int counter = 0;
    int randomNumber;
    std::set<int>::iterator iter;
    std::set<int> newSet;
    randomNumber = 1;
    newSet.insert(randomNumber);
    if (newSet.find(2) == newSet.end())
    {
        std::cout << "값 중복! 1" << std::endl;
    }
    else
    {
        newSet.insert(4);
    }
    newSet.insert(2);
    if (newSet.find(2) == newSet.end())
    {
        std::cout << "값 중복! 2" << std::endl;
    }
    if (newSet.find(3) == newSet.end())
    {
        std::cout << "값 중복! 3" << std::endl;
    }

    for (iter = newSet.begin(); iter != newSet.end(); ++iter)
    {
        std::cout << *iter << ' ';
    }

    return 0;
}

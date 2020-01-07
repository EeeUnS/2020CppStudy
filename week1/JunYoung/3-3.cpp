#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <set>

const int GetRandomNumber(void)
{
    std::random_device rn;
    std::mt19937_64 rnd(rn());

    std::uniform_int_distribution<int>range(INT32_MIN, INT32_MAX);

    return range(rnd);
}

int main(void)
{
    int counter = 0;
    int randomNumber;
    std::set<int>::iterator iter;
    std::set<int> newSet;
    randomNumber = GetRandomNumber();
    newSet.insert(randomNumber);
    while (newSet.size() != 0)
    {
        randomNumber = GetRandomNumber();
        if (newSet.find(randomNumber) != newSet.end())
        {
            std::cout << "값 중복!" << std::endl;
            continue; 
        }
        else
        {
           newSet.insert(randomNumber);
        }
        if (newSet.size() % 10 == 0)
        {
            if (counter < 5)
            {
                for (iter  = newSet.begin(); iter != newSet.end(); ++iter)
                {
                    std::cout << *iter << ' ';
                }
                std::cout << std::endl;
            }
            else
            {
                break;
            }
            counter++;
        }
        
    }
    return 0;
}
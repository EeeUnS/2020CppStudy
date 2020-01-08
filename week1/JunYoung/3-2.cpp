#include <algorithm>
#include <iostream>
#include <list>

int main(void)
{
    std::list<int> newList;
    std::list<int>::iterator iter;
    for (size_t i = 0; i < 1001; ++i)
    {
        newList.push_back(i);
    }
    for (iter = newList.begin(); iter != newList.end(); ++iter)
    {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;
    for (int i : newList)
    {
        std::cout << i << ' ';
    }

    return 0;
}

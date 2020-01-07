#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> newVector(5, 3);
    for (size_t i = 0; i < newVector.size(); ++i)
    {
        std::cout << newVector[i] << ' ';
    }
    newVector.pop_back();
    newVector.pop_back();
    newVector.push_back(7);
    newVector.push_back(1);
    sort(newVector.begin(), newVector.end());
    std::cout << std::endl;
    std::vector<int>::iterator iter;
    for (iter = newVector.begin(); iter != newVector.end(); ++iter)
    {
        std::cout << *iter << ' ';
    }
}
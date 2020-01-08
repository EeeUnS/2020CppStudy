#include <algorithm>
#include <iostream>
#include <vector>

typedef struct node
{
    char name[10];
    int x;
    int y; 
} Node;


int main(void)
{
    std::vector<std::vector<int>> adjList(100, std::vector<int>(0,0));
    std::vector<Node> nodeList;
    Node tempData;
    std::vector<int>::iterator iter;
    int numberOfNode;
    int numberOfEdge;
    int leftSide;
    int rightSide;
    std::cin >> numberOfNode >> numberOfEdge;
    for (size_t i = 0; i < numberOfNode; ++i)
    {
       std::cin >> tempData.name >> tempData.x >> tempData.y;
       nodeList.push_back(tempData);
    }
    for (size_t i = 0; i < numberOfEdge; ++i)
    {
        std::cin >> leftSide >> rightSide;
        adjList[leftSide].push_back(rightSide);
        adjList[rightSide].push_back(leftSide);
    }
    for (size_t i = 0; i < numberOfNode; ++i)
    {
        std::cout << "Node " << nodeList[i].name << ": ";
        for (iter = adjList[i].begin(); iter != adjList[i].end()  ; ++iter)
        {
            std::cout << nodeList[*iter].name << ' ';
        }
        std::cout << std::endl << "x coordinate: " << nodeList[i].x << std::endl << "y coordinate: " << nodeList[i].y << std::endl;
    }
     

    return 0;
}

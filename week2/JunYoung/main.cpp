#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "class.hpp"

int main()
{
    std::string fileName;
    std::cout << "Type File Name" << std::endl;
    std::cin >> fileName;
    CarManager carManager(fileName);
    carManager.Menu();
    return 0;
}

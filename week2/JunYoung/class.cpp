#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "class.hpp"

const int Car::GetPrice()
{
    return mPrice;
}

const std::string Car::GetBrand()
{
    return mBrand;
}
const std::string Car::GetModel()
{
    return mModel;
}

void Car::SetPrice(const int price)
{
    mPrice = price;
}

void CarManager::SaveChanges()
{
    std::ofstream fout;
    fout.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try
    {
        fout.open("CarListFile.txt");
        if (fout.is_open())
        {
            for (auto &i : mCarList)
            {
                fout << i.GetBrand() << ' ' << i.GetModel() << ' ' << i.GetPrice() << std::endl;
            }
        }
    }
    catch (const std::ifstream::failure &e)
    {
        // handle exception
        std::cerr << "exception in writing a file" << std::endl;
        std::cerr << "exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        // handle exception
        std::cerr << "exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        // handle exception
        std::cerr << "any exception!" << std::endl;
    }
}

void CarManager::SortCarList()
{
    std::sort(mCarList.begin(), mCarList.end(),
        [](Car &first, Car &second)
        {
            if (first.GetBrand().compare(second.GetBrand()) == 0)
            {
                return (first.GetModel().compare(second.GetBrand()) < 0);
            }
            else
            {
                return (first.GetBrand().compare(second.GetBrand()) < 0);
            } 
        }); 
}

void CarManager::ChangePrice(const std::string brand, const std::string model, const int price)
{
    for (auto &i : mCarList)
    {
        if (i.GetModel().compare(model) == 0 && i.GetBrand().compare(brand) == 0)
        {
            i.SetPrice(price);
        }
    }
}

void CarManager::FindCarInfo(const std::string brand, const std::string model)
{
    for (auto &i : mCarList)
    {
        if (i.GetModel().compare(model) == 0 && i.GetBrand().compare(brand) == 0)
        {
            std::cout << i.GetBrand() << ' ' << i.GetModel() << ' ' << i.GetPrice() << std::endl;
        }
    }
}

void CarManager::PrintCarList()
{
    for (auto &i : mCarList)
    {
        std::cout << i.GetBrand() << ' ' << i.GetModel() << ' ' << i.GetPrice() << std::endl;
    }
}

void CarManager::Menu()
{
    enum menu
    {
        printCarList = 1,
        findCarInfo = 2,
        changePrice = 3,
        sortCarList = 4,
        saveChanges = 5,
        quit = 6
    };
    while (true)
    {
        int sel;
        std::cout << "Car Manager Menu" << std::endl;
        std::cout << "1. Print Car List" << std::endl;
        std::cout << "2. Find Car Info" << std::endl;
        std::cout << "3. Change Price" << std::endl;
        std::cout << "4. Sort Car List" << std::endl;
        std::cout << "5. Save Changes" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << "Input : ";
        std::cin >> sel;
        std::string brand, model;
        int price;
        if (sel == 6)
            break;
        switch (sel)
        {
        case printCarList:
            std::cout << std::endl;
            PrintCarList();
            break;
        case findCarInfo:
            std::cout << "Brand : ";
            std::cin >> brand;
            std::cout << "Model : ";
            std::cin >> model;
            std::cout << std::endl;
            FindCarInfo(brand, model);
            break;
        case changePrice:
            std::cout << "Brand : ";
            std::cin >> brand;
            std::cout << "Model : ";
            std::cin >> model;
            std::cout << "Price : ";
            std::cin >> price;
            std::cout << std::endl;
            ChangePrice(brand, model, price);
            break;
        case sortCarList:
            SortCarList();
            break;
        case saveChanges:
            SaveChanges();
            break;
        default:
            std::cout << "Input Val Error" << std::endl;
            break;
        }
        std::cout << std::endl << std::endl;
    }
}
CarManager::CarManager(const std::string fileName)
{
    std::string temp;
    std::string tempCarBrand;
    std::string tempCarModel;
    int tempPrice;
    std::ifstream fin;
    fin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        fin.open(fileName);
        if (fin.is_open())
            std::cout << "File Is Opened" << std::endl;
        while (!fin.eof())
        {
            std::getline(fin, temp);
            std::stringstream ss(temp);
            ss >> tempCarBrand >> tempCarModel >> tempPrice;
            Car tempData(tempCarBrand, tempCarModel, tempPrice);
            mCarList.push_back(tempData);
        }
    }
    catch (const std::ifstream::failure &e)
    {
        // handle exception
        if (!fin.eof())
        {
            std::cerr << "exception in reading a file" << std::endl;
            std::cerr << "exception: " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    catch (const std::exception &e)
    {
        // handle exception
        std::cerr << "exception: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    catch (...)
    {
        // handle exception
        std::cerr << "any exception!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

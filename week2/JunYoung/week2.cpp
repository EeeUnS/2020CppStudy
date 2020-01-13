#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

class Car
{
private:
    std::string mBrand;
    std::string mModel;
    int mPrice;
public:
    Car(std::string carBrand, std::string carModel, int carPrice) : mBrand(carBrand), mModel(carModel), mPrice(carPrice);
    ~Car() = default;
    void SetPrice(int price);
};

class CarManager
{
private:
    std::vector<Car> mCarList;
    std::string mFileName;
public:
    CarManager(std::string fileName);
    ~CarManager() = default;
    void Menu();
    void PrintCarList();
    void FindCarInfo(std::string mBrand, std::string mModel);
    void ChangePrice(std::string mBrand, std::string mModel, int mPrice);
    void SortCarList();
    void SaveChanges();
};

CarManager::CarManager(std::string fileName)
{
    std::string temp;
    std::ifstream fin;
    try
    {
        fin.open(fileName);
        if (fin.is_open())
    }
    catch (const std::ifstream::failure& e) 
    {
        // handle exception
        std::cerr << "exception in reading a file" << std::endl;
        std::cerr << "exception: " << e.what() << std::endl;
    } 
    catch (const std::exception& e) 
    {
        // handle exception
        std::cerr << "exception: " << e.what() << std::endl;
    } 
    catch (...) 
    {
        // handle exception
        std::cerr << "any exception!" << std::endl;
    }
    while ()
    {

    }
    
}


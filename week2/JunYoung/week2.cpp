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
    std::ifstream fin;
    try
    {
        fin.open(fileName);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


}


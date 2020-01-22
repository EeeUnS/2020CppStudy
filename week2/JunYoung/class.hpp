#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class Car
{
  private:
    std::string mBrand;
    std::string mModel;
    int mPrice;
	//explicit :  뒤에 어떤 값이 암시적 생성자로 쓰지않아요
  public:
    explicit Car(const std::string carBrand, const std::string carModel, int carPrice)
        : mBrand(carBrand), mModel(carModel), mPrice(carPrice){};
    Car() = delete;
    ~Car() = default;
    void SetPrice(const int price);
    const int GetPrice();
    const std::string GetBrand();
    const std::string GetModel();
};

class CarManager : public Car
{
  private:
    std::vector<Car> mCarList;
    const std::string mFileName;

  public:
    CarManager(const std::string fileName);
    CarManager() = default;
    ~CarManager() = default;
    void Menu();
    void PrintCarList();
    void FindCarInfo(const std::string brand, const std::string model);
    void ChangePrice(const std::string brand, const std::string model, const int price);
    void SortCarList();
    void SaveChanges();
};

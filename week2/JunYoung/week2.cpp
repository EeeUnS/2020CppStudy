#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Car
{
  private:
    std::string mBrand;
    std::string mModel;
    int mPrice;

  public:
    Car(std::string carBrand, std::string carModel, int carPrice)
        : mBrand(carBrand), mModel(carModel), mPrice(carPrice){};
    Car() = default;
    ~Car() = default;
    void SetPrice(int price);
    int GetPrice()
    {
        return mPrice;
    };
    std::string GetBrand()
    {
        return mBrand;
    };
    std::string GetModel()
    {
        return mModel;
    };
};

class CarManager : public Car
{
  private:
    std::vector<Car> mCarList;
    std::string mFileName;

  public:
    CarManager(std::string fileName);
    CarManager() = default;
    ~CarManager() = default;
    void Menu();
    void PrintCarList();
    void FindCarInfo(std::string brand, std::string model);
    void ChangePrice(std::string brand, std::string model, int price);
    void SortCarList();
    void SaveChanges();
    static bool SortCmp(Car &lhs, Car &rhs);
};

void CarManager::SaveChanges()
{
    std::ofstream fout;
    fout.open("CarListFile.txt");
    for (auto &i : mCarList)
    {
        fout << i.GetBrand() << ' ' << i.GetModel() << ' ' << i.GetPrice() << std::endl;
    }
}

bool CarManager::SortCmp(Car &lhs, Car &rhs)
{
    if (lhs.GetBrand().compare(rhs.GetBrand()) == 0)
    {
        return (lhs.GetModel().compare(rhs.GetBrand()) < 0);
    }
    else
    {
        return (lhs.GetBrand().compare(rhs.GetBrand()) < 0);
    }
}

void CarManager::SortCarList()
{
    std::sort(mCarList.begin(), mCarList.end(), SortCmp);
}

void CarManager::ChangePrice(std::string brand, std::string model, int price)
{
    for (auto &i : mCarList)
    {
        if (i.GetModel().compare(model) == 0 && i.GetBrand().compare(brand) == 0)
        {
            i.SetPrice(price);
        }
    }
}

void CarManager::FindCarInfo(std::string brand, std::string model)
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

void Car::SetPrice(int price)
{
    mPrice = price;
}
void CarManager::Menu()
{
    enum menu
    {
        printCarList = 1,
        findCarInfo = 2,
        changePrice = 3,
        sortCarList = 4,
        saveChanges = 5
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
        std::cout << "Input : ";
        std::cin >> sel;
        std::string brand, model;
        int price;
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
CarManager::CarManager(std::string fileName)
{
    std::string temp;
    std::string tempCarBrand;
    std::string tempCarModel;
    int tempPrice;
    std::ifstream fin;
    try
    {
        fin.open(fileName);
        if (fin.is_open())
            ;
    }
    catch (const std::ifstream::failure &e)
    {
        // handle exception
        std::cerr << "exception in reading a file" << std::endl;
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
    do
    {
        std::getline(fin, temp);
        std::stringstream ss(temp);
        ss >> tempCarBrand >> tempCarModel >> tempPrice;
        Car tempData(tempCarBrand, tempCarModel, tempPrice);
        mCarList.push_back(tempData);
    } while (!fin.eof());
}

int main()
{
    CarManager carManager("CarListFile.txt");
    carManager.Menu();
    return 0;
}
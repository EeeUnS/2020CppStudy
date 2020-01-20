#include "class.hpp"

std::string Car::GetBrand() const
{
  return this->brand;
}

std::string Car::GetModel() const
{
  return this->model;
}

int Car::GetPrice() const
{
  return this->price;
}

void Car::SetPrice(int price)
{
  this->price = price;
}

CarManager::CarManager(std::string f)
{
  fileName = f;

  std::ifstream input_file(f);

  if (input_file.is_open())
  {
    std::string brand;
    std::string model;
    int price;

    while (true)
    {
      input_file >> brand >> model >> price;

      if (input_file.eof())
        break;

      carList.push_back(Car(brand, model, price));
    }
  }
  else
  {
    std::cout << "file does not exist\n";
  }
  
  input_file.close();
}

void CarManager::Menu()
{
  while (true)
  {
    int input;

    std::cout << "Car Manager Menu\n"
              << "1. Print Car List\n"
              << "2. Find Car Info\n"
              << "3. Change Price\n"
              << "4. Sort Car List\n"
              << "5. Save Changes\n"
              << "Input : ";
    std::cin >> input;

    std::string brand, model;
    int price;

    switch (input)
    {
    case 1:
      std::cout << "\n";
      PrintCarList();
      break;
    case 2:
      std::cout << "Brand : ";
      std::cin >> brand;
      std::cout << "Model : ";
      std::cin >> model;
      std::cout << "\n";
      FindCarInfo(brand, model);
      break;
    case 3:
      std::cout << "Brand : ";
      std::cin >> brand;
      std::cout << "Model : ";
      std::cin >> model;
      std::cout << "Price : ";
      std::cin >> price;
      std::cout << "\n";
      ChangePrice(brand, model, price);
      break;
    case 4:
      std::cout << "\n";
      SortCarList();
      break;
    case 5:
      std::cout << "\n";
      SaveChanges();
      break;
    default:
      std::cout << "invalid input. try again.\n";
      break;
    }

    std::cout << "\n\n";
  }
}

void CarManager::PrintCarList() const
{
  for (Car const &car : carList)
  {
    std::cout << car.GetBrand() << " "
              << car.GetModel() << " "
              << car.GetPrice() << "\n";
  }
}

void CarManager::FindCarInfo(std::string brand, std::string model)
{
  std::vector<Car>::iterator iter;

  if ((iter = std::find_if(carList.begin(), carList.end(),
                           [&](Car const &car) {
                             return car.GetBrand() == brand &&
                                    car.GetModel() == model;
                           })) != carList.end())
  {
    std::cout << iter->GetBrand() << " "
              << iter->GetModel() << " "
              << iter->GetPrice() << "\n";
  }
  else
  {
    std::cout << "FindCarInfo failed\n";
  }
}

void CarManager::ChangePrice(std::string brand, std::string model, int price)
{
  std::vector<Car>::iterator iter;

  if ((iter = std::find_if(carList.begin(), carList.end(),
                           [&](Car const &car) {
                             return car.GetBrand() == brand &&
                                    car.GetModel() == model;
                           })) != carList.end())
  {
    iter->SetPrice(price);
    std::cout << "Price Changed\n";
  }
  else
  {
    std::cout << "ChangePrice failed\n";
  }
}

void CarManager::SortCarList()
{
  std::sort(carList.begin(), carList.end(),
            [](Car const &a, Car const &b) {
              if (a.GetBrand() == b.GetBrand())
                return a.GetModel() < b.GetModel();
              return a.GetBrand() < b.GetBrand();
            });
}

void CarManager::SaveChanges()
{
  std::ofstream output_file(fileName);
  
  if (output_file.is_open())
  {
    for (Car const &car : carList)
    {
      output_file << car.GetBrand() << " "
                  << car.GetModel() << " "
                  << car.GetPrice() << "\n";
    }
  }
  else
  {
    std::cout << "file open failed.\n";
  }
  
  output_file.close();
}
#ifndef CLASS_HPP
#define CLASS_HPP

#include "common.hpp"

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

class Car
{
private:
  std::string brand;
  std::string model;
  int price;

public:
  Car(std::string b, std::string m, int p) : brand(b), model(m), price(p) {}
  std::string GetBrand() const;
  std::string GetModel() const;
  int GetPrice() const;
  void SetPrice(int price);
};

class CarManager
{
private:
  std::vector<Car> carList;
  std::string fileName;

public:
  // ~CarManager();
  CarManager(std::string fileName);
  void Menu();
  void PrintCarList() const;
  void FindCarInfo(std::string brand, std::string model);
  void ChangePrice(std::string brand, std::string model, int price);
  void SortCarList();
  void SaveChanges();
};

#endif // CLASS_HPP
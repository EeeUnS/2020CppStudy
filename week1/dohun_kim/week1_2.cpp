#include <iostream>
#include <algorithm>
#include <vector>

class Date
{
private:
  int year;
  int month;
  int day;

public:
  Date(int, int, int);
  bool operator<(Date &date);
  void print();
};

Date::Date(int year, int month, int day)
{
  this->year = year;
  this->month = month;
  this->day = day;
}

bool Date::operator<(Date &date)
{
  if (this->year == date.year)
  {
    if (this->month == date.month)
      return this->day < date.day;
    else
      return this->month < date.month;
  }
  else
    return this->year < date.year;
}

void Date::print()
{
  std::cout << year << " " << month << " " << day << std::endl;
}

// bool compare(Date date1, Date date2) {
//   return date1 < date2;
// }

int main()
{

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<Date> v;

  v.push_back(Date(2015, 7, 18));
  v.push_back(Date(1992, 5, 3));
  v.push_back(Date(2015, 5, 3));
  v.push_back(Date(2004, 11, 28));
  v.push_back(Date(2004, 11, 5));
  v.push_back(Date(1993, 3, 19));

  // std::sort(v.begin(), v.end(), compare);

  std::sort(v.begin(), v.end(),
            [](Date date1, Date date2) {
              return date1 < date2;
            });

  for (Date date : v)
    date.print();

  return 0;
}

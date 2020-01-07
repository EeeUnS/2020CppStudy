#include <algorithm>
#include <iostream>
#include <vector>

typedef struct date
{
    int year;
    int month;
    int day;
} Date;

bool operator<(const Date lhs, const Date rhs)
{
    if (lhs.year - rhs.year < 0)
    {
        return true;
    }
    else if (lhs.year - rhs.year > 0)
    {
        return false;
    }
    else
    {
        if (lhs.month - rhs.month < 0)
        {
            return true;
        }
        else if (lhs.month - rhs.month > 0)
        {
            return false;
        }
        else
        {
            if (lhs.day - rhs.day < 0)
            {
                return true;
            }
            else if (lhs.day - rhs.day > 0)
            {
                return false;
            }
            else
            {
                return false;
            }
        }
    }
}

int main(void)
{
    std::vector<Date> dateData;
    int dateNumber;
    Date tempDate;

    std::cin >> dateNumber;
    for (size_t i = 0; i < dateNumber; ++i)
    {
        std::cin >> tempDate.year >> tempDate.month >> tempDate.day;
        dateData.push_back(tempDate);
    }
    sort(dateData.begin(), dateData.end());
    for (size_t i = 0; i < dateNumber; ++i)
    {
        std::cout << dateData[i].year << ' ' << dateData[i].month << ' ' << dateData[i].day << std::endl;
    }
    return 0;
}

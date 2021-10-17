#include "Date.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Date::Date(int dy, int mn,int yr):day(dy),month(mn),year(yr)
{ }
int Date::setDate(int dy, int mn,int yr)
{
   if(mn>0 && mn <= monthsperYear)
        month=mn;
   else
    throw invalid_argument("month must be 1-12");

    year=yr;
   day=chekDay(dy);
}
void Date::print() const
{
    cout<<day<<'/'<<month<<'/'<<year;
}
int Date::chekDay(int testDay) const
{
    static const int daysPerMonth[monthsperYear+1]=
    {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (testDay > 0 && testDay <= daysPerMonth[month] )
        return testDay;

    if(month==2 && testDay ==29 && (year %400 == 0 ||
    (year % 4==0 && year%100 !=0 )))
    return testDay;

    throw invalid_argument(" invalid day for current month and year ");
}
int Date::Getday()
{
    return day;
}
int Date::Getmonth()
{
    return month;
}
int Date::Getyear()
{
    return year;
}




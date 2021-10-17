#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <stdexcept>
using namespace std;

class Date
{
public:
    static const int monthsperYear=12;// Number of month
    Date(int = 1,int =1,int =1900);//constructor
    int setDate(int, int,int);//set date
    void print() const;//show date
     int Getday();//get day
     int Getmonth();//get month
     int Getyear();//get year



private:
    int month;
    int day;
    int year;
    int chekDay(int) const;
};

#endif // DATE_H

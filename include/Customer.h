#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Date.h"
#include <string>
class Customer
{
    public:
        Customer();
        ~Customer();
        void Set_customer_information(const string &,const string &,const Date,const Date,const int );//Function to save customer information
        void showCustomer     ()  const;//function to show customer
        int  checkDate        ( Date , Date );//Function to check dates
        int     GetID         ();//get customer ID
        string  GetFname      ();//get name
        string  GetLname      ();//get family

    private:
        int customer_ID;//customer ID
        string Fname;//customer Name
        string Lname;//customer family
        Date birthDate;//customer birthDate
        Date registerDate;//customer registerDate

};

#endif // CUSTOMER_H

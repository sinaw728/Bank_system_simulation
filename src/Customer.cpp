#include "Customer.h"
Customer::Customer()
{
    //ctor
}
void Customer::Set_customer_information(const string& Fname,
                                       const string&  Lname,const Date birth,const Date  Oaccount,const int ID)
{
    this->Fname=Fname;
    this->Lname=Lname;
    this-> birthDate=birth;
    this-> registerDate=Oaccount;
    this->customer_ID=ID;
}
string Customer::GetFname()
{
    return Fname;
}
string Customer::GetLname()
{
    return Lname;
}
int Customer::GetID()
{
    return customer_ID;
}
void Customer::showCustomer()const
{
    cout<<"    "<<Fname<<"     "<<Lname<<"\t   "<<customer_ID<<"\t  ";
    birthDate.print();
    cout<<"\t  ";
    registerDate.print();

}
int Customer::checkDate(Date B,Date R)
{
    if( (B.Getyear() >= R.Getyear() ) )
    {
        throw invalid_argument ("Register Date must be greater than the Birth Date !!");
    }
    if( (B.Getmonth() >= R.Getmonth()) && (B.Getyear() >= R.Getyear() ) )
    {
        throw invalid_argument ("Register Date must be greater than the Birth Date !!");
    }
    if(  (B.Getday() >=  R.Getday()) && (B.Getmonth()>= R.Getmonth()) && (B.Getyear() >= R.Getyear() ) )
    {
        throw invalid_argument ("Register Date must be greater than the Birth Date !!");
    }

}
Customer::~Customer()
{

}

#include "bank.h"
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

bank object[50];
int bank::count=0;
bank::bank()
{
    accountNumber=0;
    balance =0;
}
void bank::setdata(Customer& ob,Date& Bdate,Date& Rdate,long long int Accno)
{
    this->Owner[count]=ob;
    object[count].accountNumber=Accno;
    count++;
}
////////////////////////check////////////////////////////////////////////
bool bank::customerCheck(string Fname1,string Lname1,long long int  accno,int cID)
{
    SetConsoleTextAttribute(h, 0x02);
    for(int i=0; i<count-1; i++)
    {
        if(object[i].accountNumber==accno)
        {
            count--;
            throw invalid_argument  ("\n Account number is duplicate : Re-enter information");

        }
        if(Owner[i].GetFname()==Fname1 && Owner[i].GetLname()==Lname1)
        {
            count--;
            throw invalid_argument(" \n Account name is duplicate : Re-enter information");
        }
        if(Owner[i].GetID() ==cID)
        {
            count--;
            throw invalid_argument ("\n Customer ID is duplicate : Re-enter information");
        }
    }

}
void bank::setDestination(int y)
{
    Destination=y;
}
int bank::getDestination() const
{
    return Destination;
}
int bank::Find_Destination(int IDD)
{
    SetConsoleTextAttribute(h, 0x02);
    for(int i=0; i<count; i++)
        if(Owner[i].GetID()==IDD)
        {
            setDestination(i);
            return 1;

        }
    throw invalid_argument(" Customer not found !!!\n");
}
int bank::Find_Origin(int IDD)
{
    SetConsoleTextAttribute(h, 0x02);
    for(int i=0; i<count; i++)
        if(Owner[i].GetID()==IDD)
        {
            Setorigin(i);
            return 1;

        }
    throw invalid_argument(" Customer not found !!!\n");
}
int bank::find_Destination(int accno)
{
    SetConsoleTextAttribute(h, 0x02);
    for(int i=0; i<count; i++)
        if(object[i].accountNumber==accno)
        {
            setDestination(i);
            return 1;
        }
    throw invalid_argument(" Customer not found !!!\n");

}
int bank::find_origin(int accno)
{
    SetConsoleTextAttribute(h, 0x02);
    for(int i=0; i<count; i++)
        if(object[i].accountNumber==accno)
        {
            Setorigin(i);
            return 1;

        }
    throw invalid_argument(" Customer not found !!!\n");
}
void bank::Setorigin(int m)
{
    origin=m;
}
int bank::getorigin() const
{
    return origin;
}
void bank::TransferConfirmation(int trf)
{
    SetConsoleTextAttribute(h, 0x02);
    char chk;
    cout<<"Are you sure you want to transfer "<<trf<<" $ to account number <"<<object[getDestination()].accountNumber
        <<"> in the name  of {"<<Owner[getDestination()].GetFname()  <<"}  (y/n):";
    cin>>chk;
    setCheck(chk);
}
void bank::setCheck(char chk)
{
    check=chk;
}
char bank::getCheck()const
{
    return check;
}
void bank::credit( int money)
{
    SetConsoleTextAttribute(h, 0x02);
    if(money<=0)
        throw invalid_argument ("the money most be positive");
    if(getDestination() != -1)
    {
        cout<<"====================================================="<<endl;
        SetConsoleTextAttribute(h, 0x04);
        object[getDestination()].balance += money;
        cout <<"Your money has been deposited"<<endl
             <<"The new amount of money in account {"<<Owner[getDestination()].GetFname()<<Owner[getDestination()].GetLname()<<
             "} is : "<<object[getDestination()].balance<<'$'<<endl;
        SetConsoleTextAttribute(h, 0x02);
        cout<<"======================================================"<<endl;
    }
}
void bank::debit(int money)
{
    SetConsoleTextAttribute(h, 0x02);
    if(balance>money)
        throw invalid_argument ("the balance is not enough");

    if(object[getDestination()].balance >0 && money <object[getDestination()].balance)
    {
        SetConsoleTextAttribute(h, 0x04);
        object[getDestination()].balance -=money;
        cout<<"Your withdrawn money:"<<money<<endl;
        cout<<"The new amount of your money:"<<object[getDestination()].balance<<'$'<<endl;
        SetConsoleTextAttribute(h, 0x02);
    }
    else
        throw invalid_argument (" !The amount entered is greater than the account balance ! ");

}
void bank::Transfer(int transfer)
{
    SetConsoleTextAttribute(h, 0x02);
    TransferConfirmation(transfer);
    {
        if(getCheck() != 'y')
        {
            throw invalid_argument("\n ! Transfer failed ! \n");
        }
        else if(object[getorigin()].balance >0 && transfer<=object[getorigin()].balance && getCheck() =='y' )
        {
            object[getorigin()].balance -= transfer;
            object[getDestination()].balance +=transfer;
            cout<<"The amount "<<transfer<<" $ was transferred"<<endl;
            cout<<"The new amount of your money:"<<object[getorigin()].balance<<" $"<<endl;
            cout<<"______________________________________________________"<<endl;

        }
        else if( (object[getorigin()].balance<0 || transfer>object[getorigin()].balance ) && getCheck() =='y')
            throw invalid_argument(" ! You do not have enough money ! \n ! Transfer failed ! \n");
    }
}
void bank::showInformation() const
{
    SetConsoleTextAttribute(h, 0x04);
    cout <<"                     ! accounts  information ! "<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"|rows|  Name | family | customer ID | Birth Date | Register Date|account Number|  Money  |"<<endl;
    cout<<"=========================================================================================="<<endl;
    if(count==0)
        cout <<" NULL  "<<" NULL  "<<"  NULL     "<<"  NULL    "<<"    NULL    "<<"      NULL    "<<"            NULL   " <<"   NULL    "<<endl;
    for(int i=0; i<count; i++)
    {
        cout<<i+1<<')';
       Owner[i].showCustomer();
        cout<<"\t  "<<object[i].accountNumber<<'\t'<<"\t  "<<object[i].balance<<endl;
    }
    cout<<"=========================================================================================="<<endl;
    SetConsoleTextAttribute(h, 0x02);
    }
void bank::RemoveObj(int R)
{
    Find_Destination(R);
    int poss;
    poss=getDestination();
    for(int i=poss ; i<count-1; i++)
    {
        Owner[i]=Owner[i+1];
        object[i].accountNumber=object[i+1].accountNumber;
        object[i].balance=object[i+1].balance;
    }
    count--;
}
bool bank::CHECK_string(string& Name,string family)
{
    SetConsoleTextAttribute(h, 0x02);
    for(int i=0; i< Name.size(); i++)
    {
        if( ! ( (Name[i]>='a' && Name[i]<='z') ||  (Name[i]>='A' && Name[i]<='Z') ) )
        {
            count--;
            throw invalid_argument("you can not use integer in Name");
        }
    }

    for(int i=0; i< family.size(); i++)
    {
        if( ! ( (family[i]>='A' && family[i]<='Z') || (family[i]>='a' && family[i]<='z') ) )
        {
            count--;
            throw invalid_argument("you can not use integer in Last Name");
        }
    }
}

bank::~bank()
{



}

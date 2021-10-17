#include "bank.h"
#include "Date.h"
#include "Customer.h"
#include <stdlib.h>
using namespace std;
void gotoxy(int x, int y)
{

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorCoord;
    cursorCoord.X = x;
    cursorCoord.Y = y;
    SetConsoleCursorPosition(consoleHandle, cursorCoord);
};
int main()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    Customer account;
    bank Bank;
    Date birth;
    Date Register;
    string Name,last_name;
    int CUSTOMER_ID,d,m,y,d1,m1,y1,ACCOUNT_NUMBER,money;
    SetConsoleTextAttribute(h, 0x02);//change color
    while(true)
    {
        char op;
         SetConsoleTextAttribute(h, 0x04);
        cout<<"                         Menu                             "<<endl;
        SetConsoleTextAttribute(h, 0x02);
        cout<<"**********************************************************"<<endl;
        cout<<"* [1] add Customer                                       *"<<endl;
        cout<<"* [2] Credit money                                       *"<<endl;
        cout<<"* [3] Debit money                                        *"<<endl;
        cout<<"* [4] Transfer money                                     *"<<endl;
        cout<<"* [5] Delete account                                     *"<<endl;
        cout<<"* [6] Show Customer information                          *"<<endl;
        cout<<"* [0] Exit                                               *"<<endl;
        cout<<"**********************************************************"<<endl;
        cin>>op;
        switch(op)
        {

        case '1':
rename:
            try
            {
                system("cls");
                SetConsoleTextAttribute(h, 0x04);
                cout<<"                    ADD Customer                          "<<endl;
                SetConsoleTextAttribute(h, 0x02);
                cout<<"**********************************************************"<<endl;
                cout<<" Name:                                                   *"<<endl;
                cout<<" Last Name:                                              *"<<endl;
                cout<<" Customer ID:                                            *"<<endl;
                cout<<" Birth Date :                                            *"<<endl;
                cout<<" Register Date :                                         *"<<endl;
                cout<<" Account Number:                                         *"<<endl;
                cout<<"**********************************************************"<<endl;
                SetConsoleTextAttribute(h, 0x04);
                gotoxy(6,2);
                cin>>Name;
                gotoxy(11,3);
                cin>>last_name;
                gotoxy(13,4);
                cin>>CUSTOMER_ID;
                gotoxy(13,5);
                cin>>d>>m>>y;
                gotoxy(16,6);
                cin>>d1>>m1>>y1;
                gotoxy(16,7);
                cin>>ACCOUNT_NUMBER;
                SetConsoleTextAttribute(h, 0x02);
                //////////////////////set date///////////////////////////////////////
                birth.setDate(d,m,y);
                Register.setDate(d1,m1,y1);
                account.checkDate(birth,Register);
                account.Set_customer_information(Name,last_name,birth,Register,CUSTOMER_ID);
                Bank.setdata(account,birth,Register,ACCOUNT_NUMBER);
                ////////////////////// customer check///////////////////////////////////////
                Bank.customerCheck(Name,last_name,ACCOUNT_NUMBER,CUSTOMER_ID);
                Bank.CHECK_string(Name,last_name);
            }
            catch(invalid_argument &Error)
            {
                SetConsoleTextAttribute(h, 0x04);
                cout<<"\n\n exception:"<<Error.what()<<endl;
                SetConsoleTextAttribute(h, 0x02);
                cin.ignore(2);
                goto rename;
            }
            system("cls");
            break;
        case '2':
            system("cls");
            try
            {
                   SetConsoleTextAttribute(h, 0x04);
                cout<<"                    Credit money                          "<<endl;
                SetConsoleTextAttribute(h, 0x02);
                cout<<"**********************************************************"<<endl;
                cout<<"Enter the destination card number:                       *"<<endl;
                cout<<"Enter the amount of your money to Credit:                *"<<endl;
                cout<<"**********************************************************"<<endl;
                SetConsoleTextAttribute(h, 0x04);
                gotoxy(34,2);
                cin>>ACCOUNT_NUMBER;
                Bank.find_Destination(ACCOUNT_NUMBER);
                SetConsoleTextAttribute(h, 0x04);
                gotoxy(41,3);
                cin>>money;
                cout<<"\n";
                Bank.credit(money);
                SetConsoleTextAttribute(h, 0x02);
            }
            catch (invalid_argument &Error)
            {
                SetConsoleTextAttribute(h, 0x04);
                cout<<"\n\n exception:"<<Error.what()<<endl;
                SetConsoleTextAttribute(h, 0x02);
            }
            break;
        case '3':
            system("cls");
            try
            {
                SetConsoleTextAttribute(h, 0x04);
                cout<<"                    Debit money                          "<<endl;
                SetConsoleTextAttribute(h, 0x02);
                cout<<"**********************************************************"<<endl;
                cout<<"Enter the destination card number:                       *"<<endl;
                cout<<"Enter the amount of your money to Debit:                 *"<<endl;
                cout<<"**********************************************************"<<endl;
                SetConsoleTextAttribute(h, 0x04);
                gotoxy(34,2);
                cin>>ACCOUNT_NUMBER;
                Bank.find_Destination(ACCOUNT_NUMBER);
                SetConsoleTextAttribute(h, 0x04);
                gotoxy(40,3);
                cin>>money;
               cout<<"\n";
                Bank.debit(money);
                SetConsoleTextAttribute(h, 0x02);
            }
            catch (invalid_argument &Error)
            {
                SetConsoleTextAttribute(h, 0x04);
                cout<<"\n exception:"<<Error.what()<<endl;
                SetConsoleTextAttribute(h, 0x02);
            }
            break;
        case '4':
             system("cls");
            try
            {
                SetConsoleTextAttribute(h, 0x04);
                cout<<"                    Transfer money                        "<<endl;
                SetConsoleTextAttribute(h, 0x02);
                cout<<"**********************************************************"<<endl;
                cout<<"Enter the origin card number:                            *"<<endl;
                cout<<"Enter the destination card number:                       *"<<endl;
                cout<<"Enter the amount you want to transfer:                   *"<<endl;
                cout<<"**********************************************************"<<endl;
                SetConsoleTextAttribute(h, 0x04);
                gotoxy(29,2);
                cin>>ACCOUNT_NUMBER;
                Bank.find_origin(ACCOUNT_NUMBER);
                SetConsoleTextAttribute(h, 0x04);
                gotoxy(34,3);
                cin>>ACCOUNT_NUMBER;
                Bank.find_Destination(ACCOUNT_NUMBER);
                 SetConsoleTextAttribute(h, 0x04);
                gotoxy(38,4);
                cin >>money;
                Bank.Transfer(money);
            }
            catch (invalid_argument &Error)
            {
                SetConsoleTextAttribute(h, 0x04);
                cout<<"\n\n exception:"<<Error.what()<<endl;
                SetConsoleTextAttribute(h, 0x02);
            }
            break;

        case '5':
            system("cls");
            try
            {
            SetConsoleTextAttribute(h, 0x04);
            cout<<"                    Delete account                   "<<endl;
            SetConsoleTextAttribute(h, 0x02);
            cout<<"*****************************************************"<<endl;
            cout<<"enter [ Customer ID ] to Delete customer:           *"<<endl;
            cout<<"*****************************************************"<<endl;
            gotoxy(41,2);
            SetConsoleTextAttribute(h, 0x04);
            cin>>CUSTOMER_ID;
            SetConsoleTextAttribute(h, 0x02);
            Bank.RemoveObj(CUSTOMER_ID);
            }
            catch (invalid_argument &Error)
            {
                SetConsoleTextAttribute(h, 0x04);
                cout<<"\n\n exception:"<<Error.what()<<endl;
                SetConsoleTextAttribute(h, 0x02);
            }
            break;
        case '6':
            system("cls");
            Bank.showInformation();
            break;
        case '0':
            exit(0);
            break;
        default:
            SetConsoleTextAttribute(h, 0x04);
            cout<<" Choose between Number 1 and 7 "<<endl;
            SetConsoleTextAttribute(h, 0x02);
        }
    }
}

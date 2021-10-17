#ifndef BANK_H
#define BANK_H
#include "Customer.h"
#include <iomanip>
#include <windows.h>
#include <sstream>

class bank
{
    long long int  accountNumber;        //save account number
    int balance;                         //save balance
    char check;                          // Confirm money transfer by user
    int Destination=-1;                  //Variable for destination account
    int origin=-1;                       //Variable for destination account
    void TransferConfirmation      (int);//Function to confirm money transfer
public:
    static int count;
    bank                           ();//constructor
    ~bank                          ();//
    ///////////////////set function  //////////////
    void setdata                   (Customer&,Date&,Date&,long long int);//Function to save information in the bank
    void setDestination            (int);//Function to set destination account
    void Setorigin                 (int);//Function to set origin account
    void setCheck                  (char);//Function to confirm money transfer
    /////////////////////get function  //////////////////////
    int getDestination            ()const;//Function to get destination account
    int  getorigin                ()const;//Function to get origin account
    char getCheck                 ()const;//Function to get confirmation transfer
    void showInformation          ()const;//function to show all customer
    //////////////////search function /////////////////////////
    int find_Destination          (int);//Function to find the destination account to transfer
    int find_origin               (int);//Function to find the origin account to transfer
    int Find_Destination          (int);//function to get customer ID
    int Find_Origin               (int);//function to get the index of customer ID
    ///////////////////////check function //////////////////////////
    bool customerCheck            (string,string,long long int,int);//Function to check that both accounts are not the same
    bool CHECK_string             (string&,string);//Function to check the name without having a number
    ///////////////////////////////////////////////////////
    void debit                    (int);//Function for withdrawing money
    void credit                   (int);//Function for depositing money into the account
    void Transfer                 (int);//Function to transfer money to another account
    void RemoveObj                (int);//Function to delete account
/////////////////////object///////////////////////////
   Customer Owner[50];//Object of customer class

};

#endif // BANK_H

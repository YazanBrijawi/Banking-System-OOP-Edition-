#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "\nEnter FirstName: ";
      string  FirstName = clsInputValidate::ReadString();
        Client.SetFirstName(FirstName);
        cout << "\nEnter LastName: ";
     string   LastName = clsInputValidate::ReadString();
        Client.SetLastName(LastName);
        cout << "\nEnter Email: ";
    string    Email = clsInputValidate::ReadString();
        Client.SetEmail(Email);

        cout << "\nEnter Phone: ";
    string    Phone = clsInputValidate::ReadString();
        Client.SetPhone(Phone);
        cout << "\nEnter PinCode: ";
       string PinCode = clsInputValidate::ReadString();
        Client.SetPinCode(PinCode);
        cout << "\nEnter Account Balance: ";

      float  AccountBalance = clsInputValidate::ReadDoubleNumber("Error\n");
        Client.SetAccountBalance(AccountBalance);
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.GetFullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }

public:

    static void ShowAddNewClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermission::epAddClinet))
        {
            return;
        }

        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\nAccount Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResult::svFileEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }
        case clsBankClient::enSaveResult::svFiledToAccountNumberExist:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }
        }
    }
};

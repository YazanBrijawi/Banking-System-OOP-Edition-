#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen

{
private:
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

    static void ReadClientInfo(clsBankClient &Client)
    {
        cout << "\nEnter FirstName: ";
        string FirstName = clsInputValidate::ReadString();
        Client.SetFirstName(FirstName);
        cout << "\nEnter LastName: ";
        string LastName = clsInputValidate::ReadString();
        Client.SetLastName(LastName);
        cout << "\nEnter Email: ";
        string Email = clsInputValidate::ReadString();
        Client.SetEmail(Email);

        cout << "\nEnter Phone: ";
        string Phone = clsInputValidate::ReadString();
        Client.SetPhone(Phone);
        cout << "\nEnter PinCode: ";
        string PinCode = clsInputValidate::ReadString();
        Client.SetPinCode(PinCode);
        cout << "\nEnter Account Balance: ";

        float AccountBalance = clsInputValidate::ReadDoubleNumber("Error\n");
        Client.SetAccountBalance(AccountBalance);
    }

public:
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermission::epUpdateClinet))
        {
            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            ReadClientInfo(Client1);

            clsBankClient::enSaveResult SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResult::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResult::svFiledToAccountNumberExist:
            {
                cout << "\nError account was not saved because it's Empty";
                break;
            }
            }
        }
    }
};

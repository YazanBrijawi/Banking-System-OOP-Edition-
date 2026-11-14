#pragma once
#include "clsScreen.h"
#include <bits/stdc++.h>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
    static void _PrintClientCard(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.GetFullName();
        cout << "\nAcc. Number : " << Client.GetAccountNumber();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }
    static string _ReadAccountNumber()
    {
        string AccountNumber;

        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

public:
    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadDoubleNumber("Error\n");

        while (Amount > SourceClient.GetAccountBalance())
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDoubleNumber("Error\n");
        }
        return Amount;
    }

public:
    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");
        cout << "\nPlease Enter Account Number to Transfer From: ";
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClientCard(SourceClient);
        cout << "\nPlease Enter Account Number to Transfer To: ";
        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClientCard(DestinationClient);

        float Amount = ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Failed \n";
            }
        }

        _PrintClientCard(SourceClient);
        _PrintClientCard(DestinationClient);
    }
};
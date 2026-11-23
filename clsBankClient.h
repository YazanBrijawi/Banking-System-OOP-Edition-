#pragma once
#include <bits/stdc++.h>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddMode = 2
    };

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Separator = "#//#")
    {

        vector<string> vClientData;

        vClientData = clsString::Split(Line, Separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }

    static clsBankClient _EmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {

        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {

        string stClientRecord = "";

        stClientRecord += Client.GetFirstName() + Separator;
        stClientRecord += Client.GetLastName() + Separator;
        stClientRecord += Client.GetEmail() + Separator;
        stClientRecord += Client.GetPhone() + Separator;
        stClientRecord += Client.AccountNumber() + Separator;
        stClientRecord += Client.GetPinCode() + Separator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    vector<clsBankClient> _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }

        return vClients;
    }

    string _PrepareTransactionsRecord(clsBankClient DestinationClient, float Amount, string UserName)
    {
        string Separator = "#//#";

        string TransactionsRecord = "";

        TransactionsRecord += clsDate::GetSystemDateTimeString() + Separator;
        TransactionsRecord += GetAccountNumber() + Separator;
        TransactionsRecord += DestinationClient.AccountNumber() + Separator;
        TransactionsRecord += to_string(Amount) + Separator;
        TransactionsRecord += to_string(GetAccountBalance()) + Separator;
        TransactionsRecord += to_string(DestinationClient.GetAccountBalance()) + Separator;
        TransactionsRecord += UserName;

        return TransactionsRecord;
    }
    void _TransactionsRecord(clsBankClient DestinationClient, float Amount, string UserName)
    {
        string stDataLine = _PrepareTransactionsRecord(DestinationClient, Amount, UserName);

        fstream MyFile;

        MyFile.open("Transactions.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
        }
        MyFile.close();
    }

    void _Update()
    {
        vector<clsBankClient> _Vclient;
        _Vclient = _LoadClientsDataFromFile();
        for (clsBankClient &C : _Vclient)
        {
            if (C._AccountNumber == AccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientsDataToFile(_Vclient);
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
        _Mode = Mode;
    }
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {

        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {

        return _PinCode;
    }
    void SetAccountNumber(string AccountNumber)
    {
        _AccountNumber = AccountNumber;
    }
    string GetAccountNumber()
    {

        return _AccountNumber;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {

        return _AccountBalance;
    }
    /* void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << GetFullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }
 */
    static clsBankClient Find(string AccountNumber)
    {

        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client._AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return _EmptyClientObject();
    }
    static clsBankClient Find(string AccountNumber, string Picode)
    {

        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client._AccountNumber == AccountNumber && Client._PinCode == Picode)
                {
                    MyFile.close();
                    return Client;
                }

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return _EmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    enum enSaveResult
    {
        svFileEmptyObject = 0,
        svSucceeded = 1,
        svFiledToAccountNumberExist = 2
    };

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResult::svFileEmptyObject;
            }
        }
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResult::svSucceeded;
            break;
        }

        case enMode::AddMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResult::svFiledToAccountNumberExist;
            }
            else
            {
                _AddNew();
                return enSaveResult::svSucceeded;
            }
        }
        }
        return enSaveResult::svFileEmptyObject;
    }

    static clsBankClient GetAddNewClient(string AccountNumber)
    {
        return clsBankClient(enMode::AddMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsBankClient &C : _vClients)
        {
            if (C._AccountNumber == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);
        *this = _EmptyClientObject();
        return true;
    }
    static vector<clsBankClient> GetClientList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetClientsBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientList();
        double TotalBalance = 0;
        for (clsBankClient &C : vClients)
        {
            TotalBalance += C.GetAccountBalance();
        }
        return TotalBalance;
    }
    void Deposit(float Amount)
    {
        _AccountBalance += Amount;
        Save();
    }
    bool WithDraw(float Amount)
    {

        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {

            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }
    bool Transfer(float Amount, clsBankClient &DestinaionClient, string UserName)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            if (!WithDraw(Amount))
                return false;
            DestinaionClient.Deposit(Amount);
            _TransactionsRecord(DestinaionClient, Amount, UserName);
            return true;
        }
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient> _Vclients = _LoadClientsDataFromFile();
        double TotalBalances = 0;
        for (clsBankClient &C : _Vclients)
        {
            TotalBalances += C._AccountBalance;
        }

        return TotalBalances;
    }

    struct stTransactionsLog
    {
        string SourceClient;
        string DestinationClient;
        string DateTime;
        double SourceClientBalance;
        double DestinationClientBalance;
        double Amount;
        string User;
    };

    static stTransactionsLog _ConvertLinetoUserTransactions(string Line, string Separator = "#//#")
    {
        stTransactionsLog Transactions;
        vector<string> TransactionsData = clsString::Split(Line, Separator);
        Transactions.DateTime += TransactionsData[0];
        Transactions.SourceClient += TransactionsData[1];
        Transactions.DestinationClient += TransactionsData[2];
        Transactions.Amount += stof(TransactionsData[3]);
        Transactions.SourceClientBalance += stof(TransactionsData[4]);
        Transactions.DestinationClientBalance += stof(TransactionsData[5]);
        Transactions.User += TransactionsData[6];
        return Transactions;
    }

    static vector<stTransactionsLog> GetTransactionsRecord()
    {

        vector<stTransactionsLog> vTransactionsRecord;

        fstream MyFile;
        MyFile.open("Transactions.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;
            stTransactionsLog TransactionsRecord;

            while (getline(MyFile, Line))
            {

                TransactionsRecord = _ConvertLinetoUserTransactions(Line);

                vTransactionsRecord.push_back(TransactionsRecord);
            }

            MyFile.close();
        }

        return vTransactionsRecord;
    }
};
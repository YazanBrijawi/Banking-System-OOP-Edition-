#pragma once
#include <bits/stdc++.h>
#include "clsPerson.h"
#include "clsString.h"

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
};
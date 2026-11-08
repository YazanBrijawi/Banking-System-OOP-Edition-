#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsClientScreenList : protected clsScreen
{

    void static _PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.GetFullName();
        cout << "| " << setw(12) << left << Client.GetPhone();
        cout << "| " << setw(20) << left << Client.GetEmail();
        cout << "| " << setw(10) << left << Client.GetPinCode();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();
    }

public:
    void static ShowClientsList()
    {

        if (!CheckAccessRights(clsUser::enPermission::epShowClinetList))
        {
            return;
        }

        vector<clsBankClient> vClients = clsBankClient::GetClientList();
        string title = "\t  ClientsScreenList";
        string subtitle = "\t  (" + to_string(vClients.size()) + ") Clients ";
        _DrawScreenHeader(title, subtitle);

        cout << "_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};
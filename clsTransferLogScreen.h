
#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

private:
    static void PrintTransferLogRecordLine(clsBankClient::stTransactionsLog TransactionsLog)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransactionsLog.DateTime;
        cout << "| " << setw(8) << left << TransactionsLog.SourceClient;
        cout << "| " << setw(8) << left << TransactionsLog.DestinationClient;
        cout << "| " << setw(8) << left << TransactionsLog.Amount;
        cout << "| " << setw(10) << left << TransactionsLog.SourceClientBalance;
        cout << "| " << setw(10) << left << TransactionsLog.DestinationClientBalance;
        cout << "| " << setw(8) << left << TransactionsLog.User;
    }

public:
    static void ShowTransferLogScreen()
    {

        vector<clsBankClient::stTransactionsLog> vTransferLogRecord = clsBankClient::GetTransactionsRecord();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransactionsLog Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};

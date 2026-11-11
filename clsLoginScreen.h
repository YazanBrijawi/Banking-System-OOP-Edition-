#pragma once
#include <bits/stdc++.h>
#include "clsBankUser.h"
#include "clsGlobal.h"
#include "clsScreen.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{

private:
    static bool _Login()
    {
        bool LoginFailed = false;
        string Password, UserName;
        int FailedCounter = 3;
        do
        {
            if (LoginFailed)
            {
                cout << "Invalid UserName/Password Please Enter Again \n";
                FailedCounter--;
                cout << "\nYou Have " << FailedCounter << " Trials Left\n";
            }
            if (FailedCounter == 0)
            {
                cout << "\nYou Are Locked After 3 Failed Trials\n";
                return false;
            }
            cout << "Enter UserName\n";
            cin >> UserName;
            cout << "Enter Password\n";
            cin >> Password;
            CurrentUser = clsUser::Find(UserName, Password);
            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
        clsMainScreen::ShowMainMenu();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }
};
#pragma once
#include <bits/stdc++.h>
#include "clsBankUser.h"
#include "clsGlobal.h"
#include "clsScreen.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{

private:
    static void _Login()
    {
        bool LoginFailed = false;
        string Password, UserName;

        do
        {
            if (LoginFailed)
            {
                cout << "Invalid UserName/Password Please Enter Again \n";
            }
            cout << "Enter UserName\n";
            cin >> UserName;
            cout << "Enter Password\n";
            cin >> Password;
            CurrentUser = clsUser::Find(UserName, Password);
            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
        clsMainScreen::ShowMainMenu();
    }

public:
    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();
    }
};
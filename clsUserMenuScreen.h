#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUserScreenList.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsUserMenuScreen : protected clsScreen
{
    enum enMangeUsersMenuOptions
    {
        eListUsers = 1,
        eAddNewUsers = 2,
        eDeleteUsers = 3,
        eUpdateUsers = 4,
        eFindUsers = 5,
        eMainMenu = 6
    };

    static short ReadMangeUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }
    static void _GoBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Manage Users Menu...";
        system("pause>0");
        ShowMangeUsersMenu();
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformMangeUsersMenuOptin(enMangeUsersMenuOptions MangeUsersMenuOptions)
    {
        switch (MangeUsersMenuOptions)
        {
        case enMangeUsersMenuOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enMangeUsersMenuOptions::eAddNewUsers:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enMangeUsersMenuOptions::eFindUsers:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enMangeUsersMenuOptions::eDeleteUsers:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enMangeUsersMenuOptions::eUpdateUsers:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enMangeUsersMenuOptions::eMainMenu:
        {
        }
        }
    }

public:
    static void ShowMangeUsersMenu()
    {

        if (!CheckAccessRights(clsUser::enPermission::epManageUsers))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMangeUsersMenuOptin((enMangeUsersMenuOptions)ReadMangeUsersMenuOption());
    }
};
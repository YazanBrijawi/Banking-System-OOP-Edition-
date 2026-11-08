#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\n User Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.GetFullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nAcc. Number : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermission    : " << User.GetPermissions();
        cout << "\n___________________\n";
    }

public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};

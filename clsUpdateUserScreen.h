#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen

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
    static int _ReadPermission()
    {

        short PermissionValue = 0;
        char ans;

        cout << "\nDo You Want To Give The User Full Access? y/n ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            return -1;
        }

        cout << "\nAccess To Show Users List? y/n ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            PermissionValue += clsUser::enPermission::epShowClinetList;
        }

        cout << "Access To Add New User? y/n ";
        cin >> ans;

        if (ans == 'y' || ans == 'Y')
        {
            PermissionValue += clsUser::enPermission::epAddClinet;
        }

        cout << "Access To Delete User? y/n ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            PermissionValue += clsUser::enPermission::epDeleteClinet;
        }

        cout << "Access To Update User? y/n ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            PermissionValue += clsUser::enPermission::epUpdateClinet;
        }

        cout << "Access To Find User? y/n ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            PermissionValue += clsUser::enPermission::epFindClinet;
        }

        cout << "Access To Transactions Menu? y/n ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            PermissionValue += clsUser::enPermission::epTransactions;
        }

        cout << "Access To Manage Users Menu? y/n ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            PermissionValue += clsUser::enPermission::epManageUsers;
        }

        return PermissionValue;
    }

    static void _ReadUserInfo(clsUser &User)
    {
        cout << "\nEnter FirstName: ";
        string FirstName = clsInputValidate::ReadString();
        User.SetFirstName(FirstName);
        cout << "\nEnter LastName: ";
        string LastName = clsInputValidate::ReadString();
        User.SetLastName(LastName);
        cout << "\nEnter Email: ";
        string Email = clsInputValidate::ReadString();
        User.SetEmail(Email);

        cout << "\nEnter Phone: ";
        string Phone = clsInputValidate::ReadString();
        User.SetPhone(Phone);
        cout << "\nEnter PassWord: ";
        string PassWord = clsInputValidate::ReadString();
        User.SetPassword(PassWord);

        int Permission = _ReadPermission();
        User.SetPermissions(Permission);
    }

public:
    static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";

            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUserName Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildUserExists:
            {
                cout << "\nError UserName was not saved because it's Empty";
                break;
            }
            }
        }
    }
};

#pragma once
#include <bits/stdc++.h>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:
    static bool IsNumberBetween(int From, int Number, int To)
    {
        if (Number >= From && Number <= To)
        {
            return 1;
        }

        return 0;
    }

    static bool IsNumberBetween(short From, short Number, short To)
    {
        if (Number >= From && Number <= To)
        {
            return 1;
        }

        return 0;
    }
    static bool IsNumberBetween(double From, double Number, double To)
    {
        if (Number >= From && Number <= To)
        {
            return 1;
        }

        return 0;
    }

    static bool IsValidDate(int Month, int Day, int Year)
    {

        return clsDate::IsValidDate(clsDate(Day, Month, Year));
    }

    static bool IsDateBetween(clsDate From, clsDate Date2, clsDate To)
    {

        if (clsDate::IsDate1BeforeDate2(To, Date2))
        {
            clsDate::SwapDates(Date2, To);
        }

        if (clsDate::IsDate1BeforeDate2(From, Date2) && clsDate::IsDate1BeforeDate2(Date2, To))
        {
            return true;
        }

        return false;
    }

    static int ReadIntNumber(string ErrorMessage)
    {
        string line;
        char Extra;
        int Number;
        while (true)
        {

            getline(cin, line);
            stringstream ss(line);
            if (ss >> Number && !(ss >> Extra))
            {
                return Number;
            }
            cout << ErrorMessage << endl;
        }
    }
    static double ReadDoubleNumber(string ErrorMessage)
    {
        string line;
        char Extra;
        double Number;
        while (true)
        {
            cout << "Enter\n";
            getline(cin, line);
            stringstream ss(line);
            if (ss >> Number && !(ss >> Extra))
            {
                return Number;
            }
            cout << ErrorMessage << endl;
        }
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage)
    {

       
        int Number = ReadIntNumber("Invalid Number, Enter again:\n");

        while (!IsNumberBetween(From, Number, To))
        {
            cout << ErrorMessage << endl;
            Number = ReadIntNumber("Invalid Number, Enter again:\n");
        }
        return Number;
    }

    static double ReadDoubleNumberBetween(double From, double To, string ErrorMessage)
    {
        double Number = ReadDoubleNumber("Invalid Number, Enter again:\n");
        cout << "Enter Number Between " << From << "," << To << "\n";

        while (!IsNumberBetween(From, Number, To))
        {
            cout << ErrorMessage << endl;
            Number = ReadDoubleNumber("Invalid Number, Enter again:\n");
        }
        return Number;
    }

    static string ReadString()
    {
        string s;
        getline(cin >> ws, s);
        return s;
    }
    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
};

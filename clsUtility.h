#pragma once
#include <bits/stdc++.h>
#include "clsDate.h"

class clsUtility
{

public:
    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4,
        MixCharacter = 5
    };
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {

        // Generate a random number between 0 and (To - From) using rand(),
        int random = rand() % (To - From + 1) + From;
        return random;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
            break;

        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
            break;

        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 64));
            break;

        case enCharType::Digit:
            return char(RandomNumber(48, 57));
            break;

        case enCharType::MixCharacter:
            return GetRandomCharacter(static_cast<enCharType>(RandomNumber(1, 3)));
            break;
        }
        return 'N';
    }

    static string GenerateWord(enCharType CharType, int Length)
    {
        string word = "";
        for (int i = 1; i <= Length; i++)
        {
            word = word + GetRandomCharacter(CharType);
        }
        return word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string key;
        key = GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4);

        return key;
    }

    static void GenerateKeys(int Number, enCharType CharType)
    {
        string key;
        for (int i = 1; i <= Number; i++)
        {
            cout << "Keys [" << i << "]   " << GenerateKey(CharType) << endl;
        }
    }

    static void Swap(int &A, int &B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    };

    static void Swap(double &A, double &B)
    {
        double Temp;
        Temp = A;
        A = B;
        B = Temp;
    };

    static void Swap(string &A, string &B)
    {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    };

    static void Swap(clsDate &A, clsDate &B)
    {
        clsDate Temp;
        Temp = A;
        A = B;
        B = Temp;
    };
    static void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {

            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;

            Swap(arr[index1], arr[index2]);
        }
    }
    static void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {

            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;

            Swap(arr[index1], arr[index2]);
        }
    }

    static void FillArrayWithRandomWords(string arrSource[100], int arrLength, enCharType CharType, int length)
    {

        for (int i = 0; i < arrLength; i++)
        {
            arrSource[i] = GenerateWord(CharType, length);
        }
    }
    static void FillArrayWithRandomNumbers(int arrSource[100], int arrLength, int From, int To)
    {

        for (int i = 0; i < arrLength; i++)
        {
            arrSource[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithKeys(string arrSource[100], int arrLength, enCharType CharType)
    {
        string key;
        for (int i = 0; i < arrLength; i++)
        {
            arrSource[i] = GenerateKey(CharType);
        }
    }

    static string NameEncryPtion(string Text, short EncryptionKey)
    {
        for (int i = 0; i < (int)Text.size(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }
    static string AfterDencryPtion(string Text, short EncryptionKey)
    {

        for (int i = 0; i < (int)Text.size(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }
     static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }


   }

};

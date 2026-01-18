#pragma once
#include <bits/stdc++.h>
using namespace std;

class stringLir
{

private:
    string _String;

public:
    stringLir() {};

    stringLir(string s)
    {
        _String = s;
    }

    void setString(string s)
    {
        _String = s;
    }

    string getString()
    {
        return _String;
    }

    // Length Function
    int Length() const
    {
        int counter = 0;
        for (int i : _String)
        {
            counter++;
        }
        return counter;
    }

    // ToUpper Function
    string toupper() const
    {
        string result = "";
        for (char i : _String)
        {
            if (i >= 'a' && i <= 'z')
            {
                result += (i - 32);
            }
            else
            {
                result += i;
            }
        }
        return result;
    }

    // ToLower Function
    string tolower() const
    {
        string result = "";
        for (char i : _String)
        {
            if (i >= 'A' && i <= 'Z')
            {
                result += (i + 32);
            }
            else
            {
                result += i;
            }
        }
        return result;
    }

    // Reverse Function
    string reverse() const
    {
        string result = "";
        for (int i = _String.size() - 1; i >= 0; i--)
        {
            result += _String[i];
        }
        return result;
    }

    // Number of vowels Charachters Function
    /*
        vowels Charachters is:
        a,e,i,o,u
    */
    int countVowels() const
    {
        int counter = 0;
        for (char i : _String)
        {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'u' || i == 'o' || i == 'A' || i == 'E' || i == 'U' || i == 'O' || i == 'I')
            {
                counter++;
            }
        }
        return counter;
    }

    // Number of spaces
    int countSpaces() const
    {
        string temp = _String;
        int counter = 0;
        for (char i : temp)
        {
            if (i == ' ')
            {
                counter++;
            }
        }
        return counter;
    }

    // palindrome Function
    bool palindrome() const
    {
        int size = _String.length();
        for (int i = 0; i < size / 2; i++)
        {
            if (_String[i] != _String[size - i - 1])
            {
                return false;
            }
        }

        return true;
    }

    // Remove Char
    string removeChar(char value)
    {
        string temp = "";
        for (char i : _String)
        {
            if (i != value)
            {
                temp += i;
            }
        }
        return temp;
    }

    // Count Words
   int countWords() const {
    int count = 0;
    bool inWord = false;

    for (char c : _String) {
        if (c != ' ' && !inWord) { 
            count++;
            inWord = true;
        } else if (c == ' ') {    
            inWord = false;
        }
    }

    return count;
}


    // substring
    bool substring(string sub) const
    {
        int n = _String.length();
        int m = sub.length();

        if (m == 0)
            return true;
        if (m > n)
            return false;

        for (int i = 0; i <= n - m; i++)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (_String[i + j] != sub[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                return true;
        }

        return false;
    }
};

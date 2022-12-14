 /*
 * Assignment 9
 * Name: 李倬安
 * Student Number: 110403516
 * Course 2022-CE1001-A
 */
#include <iostream>
using namespace std;
int which_date(int year, int month, int day);
void display_calendar(int year, int month, int day);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int year, month, day, ans;
    cin >> year >> month >> day;
    ans = which_date(year, month, day);
    switch (ans)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 0:
        cout << "Sunday" << endl;
        break;
    }
    cout << endl;
    display_calendar(year, month, day);
    return 0;
}
void display_calendar(int year, int month, int day)
{
    int a = 1;
    for (a = 0; a < 7; a++)
        cout << "    " << a;
    cout << endl
         << "=====================================" << endl;
    int ans = which_date(year, month, day);
    int k = day % 7;
    int rr = day;
    int i;
    switch (k)
    {
    case 1:
        break;
    case 2:
        if (ans == 0)
            ans = 6;
        else
            ans--;
        break;
    case 3:
        if (ans == 0)
            ans = 5;
        else if (ans == 1)
            ans = 6;
        else
            ans -= 2;
        break;
    case 4:
        if (ans == 0)
            ans = 4;
        else if (ans == 1)
            ans = 5;
        else if (ans == 2)
            ans = 6;
        else
            ans -= 3;
        break;
    case 5:
        if (ans == 0)
            ans = 3;
        else if (ans == 1)
            ans = 4;
        else if (ans == 2)
            ans = 5;
        else if (ans == 3)
            ans = 6;
        else
            ans -= 4;
        break;
    case 6:
        if (ans == 0)
            ans = 2;
        else if (ans == 1)
            ans = 3;
        else if (ans == 2)
            ans = 4;
        else if (ans == 3)
            ans = 5;
        else if (ans == 4)
            ans = 6;
        else
            ans -= 5;
        break;
    case 0:
        if (ans == 0)
            ans = 1;
        else if (ans == 1)
            ans = 2;
        else if (ans == 2)
            ans = 3;
        else if (ans == 3)
            ans = 4;
        else if (ans == 4)
            ans = 5;
        else if (ans == 5)
            ans = 6;
        else
            ans -= 6;
        break;
    }
    for (int i = ans; i > 0; i--)
        cout << "     ";
    int yu = 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        yu = 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        yu = 30;
    else if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            yu = 29;
        else
            yu = 28;
    }

    for (int i = 1; i <= yu; i++)
    {
        if (i < 10)
        {
            if (i == rr)
                cout << "   "
                     << "*" << i;
            else
                cout << "    " << i;
        }
        else
        {
            if (i == rr)
        
            cout << "  "
                 << "*" << i;
            else
            cout << "   " << i;
        }
        if (yu)
        if ((i + ans) % 7 == 0 && i != yu)
            cout << endl;
    }

    cout << endl
         << "=====================================" << endl;
}
int which_date(int year, int month, int day)
{
    int ans = 0;
    int a, b, d;
    int c;
    a = year / 100;
    b = year % 100;
    c = month;
    d = day;
    a = 2 * (3 - (a % 4));
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
         if (month == 1 || month == 2)
        {
            if (b == 0)
            {
                b = 6;
            }
            else
            {
                b--;
                int y = (b % 28) % 4;
                int k = (b % 28) / 4;
                if (y)
                {
                    k += 1;
                }
                b = (b % 28 + k) % 7;
            }
        }
        else
        {
            b = (b % 28 + (b % 28 / 4)) % 7;
        }
    }
    else
    {
        b = (b % 28 + (b % 28 / 4)) % 7;
    }
    switch (c)
    {
    case 1:
        c = 0;
        break;
    case 2:
        c = 3;
        break;
    case 3:
        c = 3;
        break;
    case 4:
        c = 6;
        break;
    case 5:
        c = 1;
        break;
    case 6:
        c = 4;
        break;
    case 7:
        c = 6;
        break;
    case 8:
        c = 2;
        break;
    case 9:
        c = 5;
        break;
    case 10:
        c = 0;
        break;
    case 11:
        c = 3;
        break;
    case 12:
        c = 5;
        break;
    }
    d = d % 7;
    ans = (a + b + c + d) % 7;
    return ans;
}
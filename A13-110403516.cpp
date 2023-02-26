/*
 * Assignment 13
 * Name: 李倬安
 * Student Number: 110403516
 * Course 2022-CE1001-A
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int *mergearray(int *arr1, int *arr2, int length, int (*ptr)(int, int))
{
    int *arr = new int[length];
    for (int i = 0; i < length; ++i)
    {
        *(arr + i) = ptr(*(arr1 + i), *(arr2 + i));
    }
    return arr;
}
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int main()
{
    int n;
    cin >> n;
    string s;
    int *arr = new int[n];
    int *arr1 = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> *(arr + i);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> *(arr1 + i);
    }
    cin >> s;
    if (s == "add")
    {
        int *ptr = mergearray(arr, arr1, n, add);
        for (int i = 0; i < n; ++i)
        {
            cout << *(ptr + i) << " ";
        }
        cout << endl;
    }
    else if (s == "sub")
    {
        int *ptr = mergearray(arr, arr1, n, sub);
        for (int i = 0; i < n; ++i)
        {
            cout << *(ptr + i) << " ";
        }
        cout << endl;
    }
    else if (s == "mul")
    {
        int *ptr = mergearray(arr, arr1, n, mul);
        for (int i = 0; i < n; ++i)
        {
            cout << *(ptr + i) << " ";
        }
        cout << endl;
    }

    return 0;
}
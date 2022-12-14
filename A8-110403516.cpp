 /*
 * Assignment 8
 * Name: 李倬安
 * Student Number: 110403516
 * Course 2022-CE1001-A
 */

#include <iostream>
using namespace std;
#include <string>
#define ll long long
using namespace std;
int lcm(int a, int b);
int gcd(int a, int b);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
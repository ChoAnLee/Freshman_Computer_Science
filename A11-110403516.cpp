/*
 * Assignment 11
 * Name: 李倬安
 * Student Number: 110403516
 * Course 2022-CE1001-A
 */
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
map<string, vector<int>> doll_map;
map<int, int> countp;
vector<int> doll_vec[100]; // (100) is the maximum number of dolls
vector<string> arr;
map<string, vector<int>> get_input(map<string, vector<int>> doll_map)
{
    string name;
    int a;
    int i = 0;
    int r = 0;
    int az;
    cin >> az;
    int ori = az;
    int det = 1;
    while (az--)
    {
        cin >> a >> name;
        arr.push_back(name);
        for (int n = 0; n < arr.size(); ++n)
        {
            if (arr[n] == name && det != 1 && n != arr.size() - 1)
            {
                doll_vec[n].push_back(a);
                arr.pop_back();
                det++;
                break;
            }
            else if (n == arr.size() - 1)
            {
                doll_vec[i].push_back(a);
                i++;
                det++;
                break;
            }
            else
                continue;
        }
    }
    for (int n = 0; n < arr.size(); ++n)
    {
        doll_map[arr[n]] = doll_vec[n];
    }
    return doll_map;
    //
}

void calculate_doll(map<string, vector<int>> &doll_map)
{
    // Please write your code here

    int ans = 0;
    for (int y = 0; y < arr.size(); y++)
    {
        int temp = 0;
        for (int i = 0; i < doll_map[arr[y]].size(); ++i)
        {
            countp[doll_map[arr[y]][i]]++;
        }
        for (auto it = countp.begin(); it != countp.end(); ++it)
        {
            if (it->second > temp)
            {
                temp = it->second;
            }
        }
        ans += temp;
        countp.clear();
    }
    cout << ans << endl;
    //
}

int main()
{
    // Please write your code here

    map<string, vector<int>> f;
    f = get_input(doll_map);
    calculate_doll(f);
    //
}
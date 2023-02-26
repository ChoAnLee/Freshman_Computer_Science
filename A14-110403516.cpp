/*
 * Assignment 14
 * Name: 李倬安
 * Student Number: 110403516
 * Course 2022-CE1001-A
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    string name, name2, subject;
    map<string, vector<int>> mymap;
    int chinese, english, math, science;
    ofstream outf("output.txt", ios::out);
    ifstream inf("score.txt");
    ifstream inf_2("cmd.txt");
    while (inf >> name >> chinese >> english >> math >> science)
    {
        mymap[name].push_back(chinese);
        mymap[name].push_back(english);
        mymap[name].push_back(math);
        mymap[name].push_back(science);
        int key = 0;
        if (chinese >= 12)
            key++;
        if (english >= 12)
            key++;
        if (math >= 8)
            key++;
        if (science >= 12)
            key++;
        if (key == 4)
        {
            outf << "Hello " << name << ", welcome to NCU CSIE!" << endl;
        }
        else
        {
            outf << "Sorry, " << name << " can't enter NCU CSIE." << endl;
        }
    }
    while (inf_2 >> name2 >> subject)
    {
        if (mymap.find(name2) != mymap.end())
        {
            if (subject == "chinese")
            {
                outf << mymap[name2][0] << endl;
            }
            else if (subject == "english")
            {
                outf << mymap[name2][1] << endl;
            }
            else if (subject == "math")
            {
                outf << mymap[name2][2] << endl;
            }
            else if (subject == "science")
            {
                outf << mymap[name2][3] << endl;
            }
            else
            {
                outf << "Error." << endl;
            }
        }
        else
        {
            outf << "Error." << endl;
        }
    }
    inf.close();
    inf_2.close();
    outf.close();
    return 0;
}
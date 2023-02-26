/*
 * Assignment 15
 * Name: 李倬安
 * Student Number: 110403516
 * Course 2022-CE1001-A
 */
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <set>
using namespace std;
char arr_c[4];
char key2;

void sort_card(string *p_card)
{
    for (int i = 0; i < 4; i++)
    {
        map<char, set<char>> mymap;
        for (int j = 0; j < 13; j++)
        {
            string g = *(p_card + j + 13 * i);
            if (g[1] == 'T')

                g[1] -= 11;

            else if (g[1] == 'Q')

                g[1] -= 6;

            else if (g[1] == 'K')

                g[1] += 1;

            else if (g[1] == 'A')

                g[1] += 12;
            mymap[g[0]].insert(g[1]);
        }

        int y = 0;

        for (auto h : mymap['C'])
        {
            string tmp = "";
            char yy = h;
            if (yy == 'I')
                yy = 'T';
            else if (yy == 'K')
                yy = 'Q';
            else if (yy == 'L')
                yy = 'K';
            else if (yy == 'M')
                yy = 'A';
            tmp += 'C';
            tmp += yy;
            *(p_card + y + 13 * i) = tmp;
            y++;
        }

        for (auto h : mymap['D'])
        {
            string tmp = "";
            char yy = h;
            if (yy == 'I')
                yy = 'T';
            else if (yy == 'K')
                yy = 'Q';
            else if (yy == 'L')
                yy = 'K';
            else if (yy == 'M')
                yy = 'A';
            tmp += 'D';
            tmp += yy;
            *(p_card + y + 13 * i) = tmp;
            y++;
        }

        for (auto h : mymap['S'])
        {
            string tmp = "";
            char yy = h;
            if (yy == 'I')
                yy = 'T';
            else if (yy == 'K')
                yy = 'Q';
            else if (yy == 'L')
                yy = 'K';
            else if (yy == 'M')
                yy = 'A';
            tmp += 'S';
            tmp += yy;
            *(p_card + y + 13 * i) = tmp;
            y++;
        }

        for (auto h : mymap['H'])
        {
            string tmp = "";
            char yy = h;
            if (yy == 'I')
                yy = 'T';
            else if (yy == 'K')
                yy = 'Q';
            else if (yy == 'L')
                yy = 'K';
            else if (yy == 'M')
                yy = 'A';
            tmp += 'H';
            tmp += yy;
            *(p_card + y + 13 * i) = tmp;
            y++;
        }
    }
}
void show_card(string *p_card)
{
    ofstream output_file("output.txt", ios::out);
    int y = 0;
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (arr_c[i] == 'S' && y == 0)
        {
            output_file << arr_c[i] << ": ";
            for (int j = 0; j < 13; j++)
            {
                if (j != 12)
                    output_file << *(p_card + j + 13 * i) << " ";
                else
                    output_file << *(p_card + j + 13 * i);
            }
            output_file << endl;
            y++;
            i = -1;
        }

        else if (arr_c[i] == 'W' && y == 1)
        {
            output_file << arr_c[i] << ": ";
            for (int j = 0; j < 13; j++)
            {
                if (j != 12)
                    output_file << *(p_card + j + 13 * i) << " ";
                else
                    output_file << *(p_card + j + 13 * i);
            }
            output_file << endl;
            y++;
            i = -1;
        }
        else if (arr_c[i] == 'N' && y == 2)
        {
            output_file << arr_c[i] << ": ";
            for (int j = 0; j < 13; j++)
            {
                if (j != 12)
                    output_file << *(p_card + j + 13 * i) << " ";
                else
                    output_file << *(p_card + j + 13 * i);
            }
            output_file << endl;
            y++;
            i = -1;
        }
        else if (arr_c[i] == 'E' && y == 3)
        {
            output_file << arr_c[i] << ": ";
            for (int j = 0; j < 13; j++)
            {
                if (j != 12)
                    output_file << *(p_card + j + 13 * i) << " ";
                else
                    output_file << *(p_card + j + 13 * i);
            }
            output_file << endl;
            i = 3;
        }
    }
    output_file.close();
}
int main()
{
    char first;
    string card_one;
    string card[4][13];
    int cmd;
    ifstream input_file("input.txt", ios::in);
    ofstream output_file("output.txt", ios::out);
    input_file >> first;
    if (first == 'N')
        first = 'E';
    else if (first == 'E')
        first = 'S';
    else if (first == 'S')
        first = 'W';
    else if (first == 'W')
        first = 'N';
    key2 = first;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            input_file >> card_one;
            card[j][i] = card_one;
            arr_c[j] = first;
            if (first == 'N')
                first = 'E';
            else if (first == 'E')
                first = 'S';
            else if (first == 'S')
                first = 'W';
            else if (first == 'W')
                first = 'N';
        }
    }
    input_file >> cmd;
    if (cmd == 1)
    {
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (card[j][i] == "C3")
                {
                    output_file << arr_c[j] << endl;
                }
            }
        }
    }
    else if (cmd == 2)
    {
        show_card(&card[0][0]);
    }
    else if (cmd == 3)
    {
        sort_card(&card[0][0]);
        show_card(&card[0][0]);
    }
    input_file.close();
    output_file.close();

    return 0;
}
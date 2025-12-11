/*COMSC 210 | Final PRT 1 | Lawrence Bryant
IDE used: VSC*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;



int main()
{
    map<string, int> traffic;
    ifstream fin("210-final-1-FA25.txt");
    string line;
    while(fin.good())
    {
        getline(fin,line);
        traffic[line] += 1;
    }
}
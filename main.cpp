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
    string breaker;
    while(fin.good())
    {
        getline(fin,line);
        breaker = line.substr(0,3);
        traffic[breaker] += 1;
        cout << breaker << "\n";
        breaker = line.substr(4,6);
        traffic[breaker] += 1;
        cout << breaker << "\n";
    }
    fin.close();

    
}
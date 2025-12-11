/*COMSC 210 | Final PRT 1 | Lawrence Bryant
IDE used: VSC*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
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

    
    auto it = traffic.begin();
    vector<string> names = {it->first};
    while(it != traffic.end())
    {
        int checkin = 0;
        for(int i = 0; i < names.size(); i++)
        {
            if(it->first != names[i])
            {
                checkin++;
            }
        }
        if(checkin == names.size())
        {
            names.push_back(it->first);
        }
        it++;
    }

    string order;
    for(int i = 0; i < names.size(); i++)
    {
        for(int j = 0; j <names.size(); j++)
        {
            if(traffic[names[i]] < traffic[names[j]])
            {
                order = names[i];
                names[i] = names[j];
                names[j] = order;
            }
        }
    }

    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " ";
    }

}
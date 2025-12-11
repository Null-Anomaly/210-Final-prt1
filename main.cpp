/*COMSC 210 | Final PRT 1 | Lawrence Bryant
IDE used: VSC*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

void between(map<string,int>, int, int);

int main()
{
    //vvv Milestone 1 vvv
    map<string, int> traffic;
    ifstream fin("210-final-1-FA25.txt");
    string line;
    string breaker;
    while(fin.good())
    {
        getline(fin,line);
        breaker = line.substr(0,3);
        traffic[breaker] += 1;
        breaker = line.substr(4,6);
        traffic[breaker] += 1;
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
        for(int j = 0; j < names.size(); j++)
        {
            if(names[i] < names[j])
            {
                order = names[i];
                names[i] = names[j];
                names[j] = order;
            }
        }
    }

    cout << "All airport traffic counts:\n";
    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i] << ": " << traffic[names[i]] << "\n";
    }
    //^^^ Milestone 1 ^^^

    //vvv Milestone 2 vvv
    int largest = -1;
    for(int i = 0; i < names.size(); i++)
    {
        if(traffic[names[i]] > largest)
        {
            largest = traffic[names[i]];
        }
    }
    cout << "\nBusiest airport(s) with count : " << largest << "\n";
    for(int i = 0; i < names.size(); i++)
    {
        if(traffic[names[i]] == largest)
        {
            cout << names[i] << "\n";
        }
    }
    //^^^ Milestone 2 ^^^

    between(traffic, 5,8);
    return 0;
}

void between(map<string,int> through, int low, int high)
{
    for(auto pair: through)
    {
        if(pair.second )
    }
}
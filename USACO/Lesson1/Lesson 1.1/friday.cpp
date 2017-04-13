/*
ID: NClaus
PROG: friday
LANG: C++               
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <stack>
#include <cmath>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;

vs strsp(string a, string delim=" ")
{
    vs ret;
    string cr = "";
    for(int i = 0; i < a.size(); i++)
    {
       if(delim.find(a[i])==string::npos) cr += a[i];
       else { if(cr.size()) ret.push_back(cr); cr = ""; }
    }
    if(cr.size()) ret.push_back(cr);
    return ret;
}

int days_im[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    
    int N;
    fin >> N;

    int cnts[] = {0,0,0,0,0,0,0};
    int day_of_week = 2;
    int month = 0, day = 1, year = 1900;
    int endyear = year + N;

    while(year < endyear)
    {
        if(day == 13) cnts[day_of_week]++;

        day++;
        day_of_week = (day_of_week + 1) % 7;
        if(days_im[month] < day)
        {
            day = 1;
            month++;
        }
        if(month == 12)
        {
            month = 0;
            day = 1;
            year++;
            //cout << days_im[1];
            //cout << year << endl;
            if(days_im[1] == 29) days_im[1]--;

            if( (year%4==0) && ((year%400==0) || (year%100 > 0)) )
            {
                days_im[1]++;
            }
        }
    }
    fout << cnts[0];
    for(int i = 1; i < 7; i++)
    {
        fout << ' ' << cnts[i];
    }
    fout << endl;

    return 0;
}
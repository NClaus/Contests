/*
ID: NClaus
PROG: ride
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

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string group, comet;
    fin >> group >> comet;

    const int MODULUS = 47;
    int gn = 1, cn = 1;
    for(int idx = 0; idx < group.size(); idx++)
    {
        gn = gn * (int)(group[idx]-'A'+1);
        gn = (gn % MODULUS);
    }
    for(int idx = 0; idx < comet.size(); idx++)
    {
        cn = cn * (int)(comet[idx]-'A'+1);
        cn = (cn % MODULUS);
    }

    cout << cn << ' ' << gn << endl;
    if(cn == gn) fout << "GO\n";
    else fout << "STAY\n";

    return 0;
}
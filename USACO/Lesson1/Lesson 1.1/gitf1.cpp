/*
ID: NClaus
PROG: gift1
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
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    int N;
    fin >> N;
    string names[N];
    int start[N], end[N];

    map<string,int> MM;
    for(int i = 0; i < N; i++)
    {
        fin >> names[i];
        start[i] = end[i] = 0

        MM[names[i]] = i;
    }

    for(int i = 0; i < N; i++)
    {
        string cgiver = "";
        int give_amt = 0, give_idx = 0, give_n;
        fin >> cgiver;
        fin >> give_amt >> give_n;

        give_idx = MM[cgiver];
        start[give_idx] = give_amt;

        if(give_n == 0) continue;
        
        string get_name;
        int get_amt = (give_amt / give_n), get_idx;
        for(int j = 0; j < give_n; j++)
        {
            cin >> get_name;
            get_idx = MM[get_name];
            
            end[give_idx] -= get_amt;
            end[get_idx] += get_amt;
        }
    }
    for(int i = 0; i < N; i++)
    {
        fout << names[i] << ' ' << (end[i] - start[i]) << endl;
    }

    return 0;
}
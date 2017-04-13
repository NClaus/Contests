/*
ID: NClaus
PROG: milk2
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
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    int N;
    fin >> N;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > PQ;

    for(int idx = 0; idx < N; idx++)
    {
        int start,stop;
        fin >> start >> stop;
        PQ.push(make_pair(start,-1));
        PQ.push(make_pair(stop,1));
    }

    int best_on = 0, best_off = 0;

    int last = PQ.top().first, num_cows = 0, last_on = PQ.top().first;

    while(!PQ.empty())
    {
        int next = PQ.top().first, dx = PQ.top().second;
        //cout << next;
        if(num_cows == 0)
        {
             best_off = max(best_off,next-last);
             last_on = next;
        }  
        else
        {
            best_on = max(best_on,next-last_on);
        }
            
        PQ.pop();

        num_cows -= dx;
        last = next;
    }
    fout << best_on << ' ' << best_off << endl;

    return 0;
}
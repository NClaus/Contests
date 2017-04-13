/*
ID: NClaus
PROG: beads
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
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int N;
    string necklace;
    fin >> N >> necklace;

    int right_run[N][2], left_run[N][2];
    right_run[0][0] = right_run[0][1] = left_run[0][0] = left_run[0][1] = -1;

    int start_black = -1, start_red = -1;
    for(int idx = 0; idx < N; idx++)
    {
        if(necklace[idx]=='b') start_black = idx;
        if(necklace[idx]=='r') start_red = idx;
    }
    if(start_black == -1 || start_red == -1)
    {
        fout << N << endl;
        return 0;
    }

    int counter = 0, run = 0;
    for(int cidx = start_black; counter <= N; cidx = (N+cidx-1)%N)
    {
        if(necklace[cidx] == 'b') 
        {
            right_run[cidx][0] = run = 0;
        }
        else
        {
            right_run[cidx][0] = (++run);
        }
        counter++;
    }

    counter=0;
    run = 0;
    for(int cidx = start_red; counter <= N; cidx = (N+cidx-1)%N)
    {
        if(necklace[cidx] == 'r') 
        {
            right_run[cidx][1] = run = 0;
        }
        else
        {
            right_run[cidx][1] = (++run);
        }
        counter++;
    }

    counter = 0;
    run = 0;
    for(int cidx = (start_black)%N; counter <= N; cidx = (cidx+1)%N)
    {
        if(necklace[cidx] == 'b') 
        {
            left_run[(cidx+1)%N][0] = run = 0;
        }
        else
        {
            left_run[(cidx+1)%N][0] = (++run);
        }
        counter++;
    }
    counter = 0;
    run = 0;
    for(int cidx = (start_red)%N; counter <= N; cidx = (cidx+1)%N)
    {
        if(necklace[cidx] == 'r') 
        {
            left_run[(cidx+1)%N][1] = run = 0;
        }
        else
        {
            left_run[(cidx+1)%N][1] = (++run);
        }
        counter++;
    }
    int ret = 0;
    for(int i = 0; i < N; i++)
    {
        int left = max(left_run[i][0], left_run[i][1]);
        int right = max(right_run[i][0], right_run[i][1]);

        ret = max(ret, left+right);
    }


    ret = min(ret,N);


    fout << ret << endl;

    return 0;
}
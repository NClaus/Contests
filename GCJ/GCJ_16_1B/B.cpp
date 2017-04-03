
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

string game = "";
int NG;

string gsolve(int pos)
{
    if(pos == 0)
        return "";
    char lg = game[0];
    int fpos = 0;
    for(int idx = 0; idx < pos; idx++)
    {
        if(lg < game[idx])
        {
            lg = game[idx];
            fpos = idx;
        }
    }
    string all_lg = "";
    for(int idx = 0; idx < pos; idx++)
    {
        if(lg == game[idx])
        {
            all_lg += lg;
        }
    }
    string before = gsolve(fpos);
    string after = "";
    for(int idx = fpos; idx < pos; idx++)
    {
        if(lg != game[idx])
        {
            after += game[idx];
        }
    }
    string ret = all_lg + before + after;

    return ret;
}

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
    int T;
	cin >> T;

	for(int tcase = 1; tcase <= T; tcase++)
	{
        string A,B;
        cin >> A >> B;

        string fa = "", fb = "";
        int lg = 0;
        for(int i = 0; i < A.size(); i++)
        {
            char ax = A[i], bx = B[i];
            if((ax != '?') && (bx != '?'))
            {
                if(lg == 0)
                {
                    if(ax < bx)
                    {
                        lg = -1;
                    }
                    else if(ax > bx)
                    {
                        lg = 1;
                    }
                }
                fa += ax;
                fb += bx;
                continue;
            }
            if(lg == 0)
            {
                if(ax == '?')
                {
                    if(bx == '?')
                    {
                        fa += '0';
                        fb += '0';
                    }
                    else
                    {
                        fa += bx;
                        fb += bx;
                    }
                }
                else
                {
                    fa += ax;
                    fb += ax;
                }
            }
            else if(lg == -1)
            {
                if(ax == '?')
                    fa += '9';
                else
                    fa += ax;

                if(bx == '?')
                    fb += '0';
                else
                    fb += bx;
            }
            else if(lg == 1)
            {
                if(ax == '?')
                    fa += '0';
                else
                    fa += ax;

                if(bx == '?')
                    fb += '9';
                else
                    fb += bx;
            }
        }
        printf("Case #%d: ",tcase);
        cout << fa << ' ' << fb << endl;
	}
	return 0;
}
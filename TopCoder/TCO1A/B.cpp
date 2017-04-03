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

const int MAXN = 101;
int memo[MAXN][MAXN][MAXN];
int SS;
int rec(int a, int b, int c)
{
    int & ret = memo[a][b][c];
    if(ret != -1) return ret;
    if(a < SS || b < SS || c < SS) return ret = 0;
    ret = 0;
    ret = max(a*b,max(b*c,a*c));
    for(int sa = 1; sa < a; sa++)
    {
        ret = max(ret, rec(sa,b,c) + rec(a-sa,b,c));
    }
    for(int sb = 1; sb < b; sb++)
    {
        ret = max(ret, rec(a,sb,c) + rec(a,b-sb,c));
    }
    for(int sc = 1; sc < c; sc++)
    {
        ret = max(ret, rec(a,b,sc) + rec(a,b,c-sc));
    }
    cout << a << ' ' << b << ' ' << c << ' ' << ret << endl;
    return ret;
}
class CheeseSlicing {
    public: 
    int totalArea(int A, int B, int C, int S)
    {
     	
        memset(memo,-1,sizeof(memo));
        SS = S;

        return rec(A,B,C);
        
    }
};
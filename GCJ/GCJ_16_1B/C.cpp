
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


const int MAXN = 10001;
int G[MAXN][MAXN];
int match[MAXN];
int done[MAXN];
int NB, NR;

int augment(int vert)
{
    if(vert == -1) return 1;
    if(done[vert]) return 0;
    done[vert] = 1;
    for(int i = 0; i < NR; i++)
    {
       if(G[vert][i])
       {
           if(augment(match[i]))
           {
               match[i] = vert;
               return 1;
           }
       }
    }
    return 0;
}

int bipmat()
{
    int ret = 0;
    memset(done,0,sizeof(done));
    memset(match,-1,sizeof(match));
    for(int i = 0; i < NB; i++)
    {
       if(augment(i))
       {
           ret++;
       }
       memset(done,0,sizeof(done));
    }
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
        map<string,int> left, right;
        memset(G,0,sizeof(G));
        int N;
        cin >> N;
        int lcnt = 0, rcnt = 0;
        for(int i = 0; i < N; i++)
        {
            string A = "", B = "";
            cin >> A >> B;
            
            int lidx, ridx;
            if(left.find(A) != left.end())
            {
                lidx = left[A];
            }
            else
            {
                lcnt++;
                left[A] = lidx = lcnt;
            }
            if(right.find(B) != right.end())
            {
                ridx = right[B];
            }
            else
            {
                rcnt++;
                right[B] = ridx = rcnt;
            }
            G[lidx-1][ridx-1] = 1;
        }
        NB = lcnt;
        NR = rcnt;
        //deb(NB); deb(NR);
        int min_total = NB + NR - bipmat();
        printf("Case #%d: %d\n",tcase, N-min_total);
	}
	return 0;
}
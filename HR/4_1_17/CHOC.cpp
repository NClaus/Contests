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
#include <queue>
#include <set>
#include <cstring>
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

const int NN = 101;
double memo[NN][NN][NN][3];
int seen[NN][NN][NN][3];
double rec(int K, int N, int S, int T)
{
    if(seen[K][N][S]) return memo[K][N][S][T];
    int & ret = memo[K][N][S][T];
    seen[K][N][S][T] = 1;

    vector<int> Q = {K,N,S};
    if(Q[T] == 0) return ret = 0.0;
    int A = (T+1) % 3, B = (T+2) % 3;
    if(Q[A] == 0 && Q[B] == 0) return ret = 1.0;

    int TA = (Q[T] * Q[A]), TB = (Q[T] * Q[B]), AB = (Q[A] * Q[B]);
    
}


int main()
{
  int numv;
  cin >> numv;
  memset(cap,0,sizeof(cap));
  memset(cost,0,sizeof(cost));

  int SRC = numv, SNK = numv + 1;
  int nodes[numv];
  for(int i = 0; i < numv; i++)
  {
    cin >> nodes[i];
  }
    
  int srcnodes = 0;
  for(int i = 0; i < numv; i++)
  {
    if(nodes[i] < 2) continue;
    srcnodes++;

    cap[SRC][i] = nodes[i] - 1;

    for(int j = 0; j < numv; j++)
    {
        if(nodes[j] == 0)
        {
            cap[i][j] = 1;
            if(i > j)
                cost[i][j] = min(i-j,numv+j-i);
            else
                cost[i][j] = min(j-i,numv+i-j);

            cap[j][SNK] = 1;
        }
    }

  }

  //cout << "starting flow" << endl;
  //  while ( cin >> numV && numV ) {

    int fcost;
    int flow = mcmf3( numv+2, SRC, SNK, fcost );
    cout << fcost << endl;
    //cout << "flow: " << flow << endl;
    //cout << "cost: " << fcost << endl;

    return 0;
}
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
    if(K < 0 || N < 0 || S < 0) return 0.0;
    if(seen[K][N][S][T]) return memo[K][N][S][T];

    //cout << K << ' ' << N << ' ' << S << endl;
    double & ret = memo[K][N][S][T];
    seen[K][N][S][T] = 1;

    int tmp[] = { K, N, S};
    std::vector<int> Q( tmp, tmp+3 );

    if(Q[T] == 0) return ret = 0.0;
    int A = (T+1) % 3, B = (T+2) % 3;
    if(Q[A] == 0 && Q[B] == 0) return ret = 1.0;

    int TA = (Q[T] * Q[A]), TB = (Q[T] * Q[B]), AB = (Q[A] * Q[B]);
    int total = TA + TB + AB;

    ret = 0.0;

    Q[A]--;
    ret += (double)TA/(double)total * ( rec( Q[0], Q[1], Q[2], T   ) );
    Q[A]++;

    Q[T]--;
    ret += (double)TB/(double)total * ( rec( Q[0], Q[1], Q[2], T   ) );
    Q[T]++;

    Q[B]--;
    ret += (double)AB/(double)total * ( rec( Q[0], Q[1], Q[2], T   ) );
    Q[B]++;
    

    return ret;
}


int main()
{
    int num_tests;
    cin >> num_tests;
    memset(seen,0,sizeof(seen));
    for(int testcase = 1; testcase <= num_tests; testcase++)
    {
        int SK, SN, SS;
        cin >> SK >> SN >> SS;

        cout << rec(SK,SN,SS,0) << endl;
        cout << rec(SK,SN,SS,1) << endl;
        cout << rec(SK,SN,SS,2) << endl;
    }
    return 0;
}
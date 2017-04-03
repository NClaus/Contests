
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

int N,K;
double prob;
const int MAXN = 3001;

double chance[MAXN];
int cseen[MAXN];

double pflip(int flip)
{
    double & ret = chance[flip];
    if(cseen[flip] == 1) return ret;
    cseen[flip] = 1;
    ret = 0.0;
    double totals[flip+1];
    totals[0] = pow(1.0-prob,flip);
    for(int i = 1; i <= flip; i++)
    {
        totals[i] = (totals[i-1] * (prob) * (double)(flip-i+1) ) / ( (1.0-prob) * (double)(i) );
    }
    for(int i = K; i <= flip; i++)
        ret += totals[i];

    return ret;
}


double probm[MAXN];
int seen[MAXN];

double rec(int left)
{
    double & ret = probm[left];
    if(seen[left] == 1) return ret;
    seen[left] = 1;
    ret = 0.0;
    if(left < K) return ret;
    for(int flip = K; flip <= left; flip++)
    {
        double next = pflip(flip) + rec(left-flip);
        ret = max(next,ret);
    }
    return ret;
}

int main()
{
    int T;
	cin >> T;

	for(int tcase = 1; tcase <= T; tcase++)
	{
        cin >> N >> K >> prob;        
        memset(seen,0,sizeof(seen));
        memset(cseen,0,sizeof(cseen));
        
        double ret = rec(N);
		printf("Case #%d: %.9lf\n",tcase,ret);
	}
	return 0;
}
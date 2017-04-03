
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
#include <deque>
#include <set>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
typedef pair<pair<long long, long long>, pair<long long, pair<long long, long long> > > quint;
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


quint make_quint(long long a, long long b, long long c, long long d, long long e)
{
	return make_pair(make_pair(a,b),make_pair(c,make_pair(d,e)));
}

const long long MOD = 1e9+7;
int main()
{
	int T;
	cin >> T;
	for(int tcase = 1; tcase <= T; tcase++)
	{
		int N;
		cin >> N;
		vector<pair<long long, long long> > L;
		for(int i = 0; i < N; i++)
		{
			long long x, h;
			cin >> x >> h;
			L.push_back(make_pair(x,h));
		}
		sort(L.begin(), L.end());

		stack< quint > prev;
		long long ret = 0;
		long long NH, PREVX, TDIST, SQDIST, NLAD;
		for(int i = 0; i < N; i++)
		{
			long long CH = L[i].second, CX = L[i].first;
			while(true)
			{
				if(prev.empty() == true)
				{
					prev.push(make_quint(CH,CX,1,0,0));
					break;
				}
				else
				{
					NH = prev.top().first.first;
					if(NH > CH)
					{
						prev.push(make_quint(CH,CX,1,0,0));
						break;
					}
					else if(NH == CH)
					{
						PREVX = prev.top().first.second;
						NLAD = prev.top().second.first;
						TDIST = prev.top().second.second.first;
						SQDIST = prev.top().second.second.second;
						prev.pop();

						long long dx = CX - PREVX;
						long long nadd = (SQDIST + NLAD * dx * dx + 2 * dx * TDIST) % MOD;
						ret = (ret + nadd) % MOD;

						prev.push(make_quint(CH,CX,NLAD+1,(TDIST+dx*NLAD)%MOD, nadd));
						break;

					}
					else
					{
						prev.pop();
					}
				}
			}
		}

		printf("Case #%d: %lld\n",tcase,ret);
	}
	return 0;
}
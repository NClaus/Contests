// cheburashka, bear-mouse, team template

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
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;
#define pb(x) push_back(x)


	
int main()
{
	int T;
	cin >> T;
	for(int tcase = 1; tcase <= T; tcase++)
	{
		long long A,B,N;
		cin >> N >> A >> B;
		long long stops[N];
		long long tm = 0;
		for(int i =0; i < N; i++)
		{
			cin >> stops[i];
			tm += stops[i];
		}

		long long min_cycles = (long long)(A/tm);
		long long max_cycles = (long long)(B/tm);
		long long total_cycles = max_cycles - min_cycles;

		int steps_left = 0, steps_right = 0;
		long long extra_left = A - min_cycles*tm, extra_right = B - max_cycles*tm;
		long long rem_left = extra_left, rem_right = extra_right;
		for(int i = 0; i < N; i++)
		{
			if(extra_left < stops[i])
				break;
			steps_left++;
			extra_left -= stops[i];
		}

		for(int i = 0; i < N; i++)
		{
			if(extra_right < stops[i])
				break;
			steps_right++;
			extra_right -= stops[i];
		}

		//cout << total_cycles << endl;
		//cout << steps_left << ' ' << extra_left << ' ' << steps_right << ' ' << extra_right << endl;

		long long DEN = (B-A)*2;
		long long numer = 0;
		long long ll = extra_left, lr = stops[steps_left];
		numer += (lr+ll)*(lr-ll);
		for(int i = steps_left+1; i < N; i++)
		{
			numer += stops[i]*stops[i];
		}
		long long rl = 0, rr = extra_right;
		numer += (rl+rr)*(rr-rl);
		for(int i = 0; i < steps_right; i++)
		{
			numer += stops[i]*stops[i];
		}
		for(int i = 0; i < N; i++)
		{
			numer += stops[i]*stops[i]*(long long)(total_cycles-1);
		}
		//cout << numer << ' ' << DEN << endl;
		double ret = (double)numer / DEN;
		printf("Case #%d: %.9lf\n",tcase,ret);
	}
	return 0;
}

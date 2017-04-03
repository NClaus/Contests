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
		long long L,N,M,D;
		cin >> L >> N >> M >> D;
		long long washers[N];
		for(int i = 0; i < N; i++)
		{
			cin >> washers[i];
		}

		long long left = 0;
		long long right = (1LL<<55);
		
		while(left < right - 1)
		{
			long long mid = (left+right)/2;
			long long washed = 0;
			for(int i = 0; i < N; i++)
			{
				washed += (long long)(mid/washers[i]);
			}
			if(washed >= L)
			{
				right = mid;
			}
			if(washed < L)
			{
				left = mid;
			}
		}
		long long all_washed_t = right;
		cout << all_washed_t << endl;
		vector<long long> washer_times;
		for(int i = 0; i < N; i++)
		{
			for(long long j = washers[i]; j <= all_washed_t; j += washers[i])
			{
				washer_times.push_back(j);
			}
		}
		sort(washer_times.begin(), washer_times.end());
		queue<long long> Q;
		long long open_dryers = M;
		long long ret = 0;
		for(int idx = 0; idx < washer_times.size(); idx++)
		{
			long long ct = washer_times[idx];
			while(!Q.empty())
			{
				if(ct >= Q.front())
				{
					Q.pop();
					open_dryers += 1;
				}
				else
				{
					break;
				}
			}
			if(open_dryers == 0)
			{
				ct = Q.front();
				Q.pop();
				open_dryers += 1;
			}
			Q.push(ct+D);
			open_dryers -= 1;
		}
		while(!Q.empty())
		{
			long long next = Q.front();
			Q.pop();
			ret = max(next, ret);
		}
		printf("Case #%d: %lld\n",tcase,ret);
	}
	return 0;
}

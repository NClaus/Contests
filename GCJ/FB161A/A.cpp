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
		int N;
		cin >> N;
		int D[N];
		for(int i = 0; i < N; i++)
		{
			cin >> D[i];
		}
		int ret = 0;
		int cp = 0;
		int ln = -1;
		for(int idx = 0; idx < N; )
		{
			int cur = D[idx];
			if(cp == 0)
			{
				if(cur > 97)
				{
					ln = 97;
					cp = 1;
					ret++;
				} 
				else
				{
					ln = cur;
					cp = 1;
					idx++;
				}
			}
			else
			{
				if(ln == -1) cout << "ERROR\n";
				if( (cur>ln) && (cur<=ln+10) && (cur <= 100-(3-cp)) )
				{
					ln = cur;
					cp++;
					idx++;
				}
				else if(cur <= ln)
				{
					cp++;
					ln = ln+1;
					ret++;
				}
				else if((cur > ln+10))
				{
					int next = min(ln+10,100-(3-cp));
					cp++;
					ln = next;
					ret++;
				}
				else
				{
					int next = min(ln+10,100-(3-cp));
					cp++;
					ln = next;
					ret++;
				}
			}
			//cout << ln  << ' ';
			if(cp == 4)
			{
				cp = 0;
				//cout << endl;
				ln = -1;
			}
		}
		//cout << endl;
		if(cp > 0) ret += 4-cp;
		printf("Case #%d: %d\n",tcase,ret);
	}
	return 0;
}

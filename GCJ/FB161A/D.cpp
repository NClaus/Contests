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


int root, N;
const int MAXN = 16;
int G[MAXN][MAXN];
int maxw;
int fin[MAXN+1];
vector<int> mask_hold[17];

inline int bcnt(int a)
{
	if(a==0) return 0;
	return 1+bcnt(a&(a-1));
}


int main()
{
	int T;
	cin >> T;
	memset(fin,0,sizeof(fin));
	fin[2] = 1;
	fin[4] = 2;
	fin[7] = 3;
	fin[11] = 4;
	int mycount[(1<<17)];
	for(int i = 0; i <= (1<<16); i++)
		mycount[i] = bcnt(i);

	for(int i = 0; i < (1<<16); i++ )
	{
		int nm = bcnt(i);
		if(nm == 1) mask_hold[nm].push_back(i);
		if(nm == 2) mask_hold[nm].push_back(i);
		if(nm == 4) mask_hold[nm].push_back(i);
		if(nm == 8) mask_hold[nm].push_back(i);
		if(nm==16) mask_hold[nm].push_back(i);
	}

	
	int beat_wins[17];
	memset(beat_wins,0,sizeof(beat_wins));
	beat_wins[1] = 0;
	beat_wins[2] = 1;
	beat_wins[4] = 2;
	beat_wins[8] = 3;
	beat_wins[16] = 4;
	for(int tcase = 1; tcase <= T; tcase++)
	{
		printf("Case #%d:\n",tcase);
		memset(G,0,sizeof(G));
		cin >> N;
		

		maxw = bcnt(N-1);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				cin >> G[i][j];
		}
		if(N==1)
		{
			printf("1 1\n");
			continue;
		}


		int best[N], worst[N];

		int wt[maxw+1];
		memset(best,0,sizeof(best));
		memset(wt,0,sizeof(wt));
		wt[0] = (N/2)+1;
		for(int j = 1; j <= maxw; j++)
	 	{
			wt[j] = (wt[j-1]+1)/2;
		}

		for(int i = 0; i < N; i++)
		{
			root = i;
			worst[i] = 1;
			for(int j = 0; j < N; j++)
			{
				if(i==j) continue;
				if(G[i][j] == 0)
				{
					worst[i] = (N/2)+1;
				}
			}
		}
	
		bool memo[(1<<16)][16];
		const int MAXMASK = (1<<N);
		memset(memo,0,sizeof(memo));
		for(int i = 0; i < N; i++)
		{
			memo[(1<<i)][i] = 1;
		}

		int nfirst, nsecond, combined, db2 = 0, xx,yy,jj;
		for(int k = 1; k < 5; k *= 2)
		{
			if(k > N) break;
			for(int i = 0; i < mask_hold[k].size(); i++)
			{	
				nfirst = mask_hold[k][i];
				for(xx = 0; xx < N; xx++)
				{
					if(memo[nfirst][xx] == 0) continue;
						
					for(jj = 0; jj < mask_hold[k].size(); jj++)
					{

						nsecond = mask_hold[k][jj];
						if( ((nfirst&nsecond)==0))
						{
							combined = (nfirst|nsecond);
							
							for(yy = 0; yy < N; yy++)
							{
								if(memo[nsecond][yy] == 0) continue;
								if(G[xx][yy]) memo[combined][xx] = 1;
								else memo[combined][yy] = 1;
								db2++;
							}
						}
						
					}
				}
			}
		} 
		if(N == 16)
		{
			for(int emask = 0; emask < (1<<N); emask++)
			{
				int mm = mycount[emask];
				if(mm == 8)
				{
					int fmask = (emask^((1<<N)-1));
					int combined = (1<<N)-1;
					for(int x = 0; x < 16; x++)
					{
						if(memo[emask][x] == 0) continue;
						for(int y = 0; y < 16; y++)
						{
							if(memo[fmask][y] == 0) continue;
							if(G[x][y]) memo[combined][x] = 1;
							else memo[combined][y] = 1;
						}
					}
				}
			}
		}

		for(int smask = 1; smask < (1<<N); smask++)
		{
			int tbits = mycount[smask];
			if(mycount[tbits] != 1) continue;
			for(int x = 0; x < N; x++)
			{
				if(memo[smask][x])
					best[x] = max(best[x],tbits);
			}
		}
		for(int i = 0; i < N; i++)
		{
			int ret = wt[beat_wins[best[i]]];
			//deb(best[i]);
			cout << ret << ' ' << worst[i] << endl;
		}
		//gener(16,994);
	}
	return 0;
}


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

int dx[4] = { 0,1,0,-1};
int dy[4] = { -1,0,1,0 };
int R,C;
int total_arrows;

inline bool OFFGRID(int y, int x)
{
    if(x < 0 || y < 0) return true;
    if(x >= C || y >= R) return true;
    return false;
}

const int MAXN = 105;
int grid_dir[MAXN][MAXN];
int grid_idx[MAXN][MAXN];
int seen[MAXN*MAXN];

int traverse(int y, int x, int dir)
{
    if( OFFGRID(y,x) ) return 1;
    int cidx = grid_idx[y][x];
    if(cidx == -1)
    {
        return traverse(y + dy[dir], x+ dx[dir], dir);
    }
    else
    {
        if(seen[cidx]) return 0;
        seen[cidx] = 1;
        int next_dir = grid_dir[y][x];
        return traverse(y + dy[next_dir], x+ dx[next_dir], next_dir);
    }
}

bool impossible()
{
    int rcnt[MAXN], ccnt[MAXN];
    for(int r = 0; r < R; r++)
    {
        rcnt[r] = 0;
        for(int x = 0; x < C; x++)
        {
            if(grid_idx[r][x] >= 0) rcnt[r]++;
        }
    }
    for(int c = 0; c < C; c++)
    {
        ccnt[c] = 0;
        for(int y = 0; y < R; y++)
        {
            if(grid_idx[y][c] >= 0) ccnt[c]++;
        }
    }
    for(int y = 0; y < R; y++)
        for(int x = 0; x < C; x++)
        {
            if( grid_idx[y][x] >= 0 )
            {
                if((rcnt[y] + ccnt[x]) == 2) return true;
            }
        }
    return false;
}

int main()
{
    int T;
	cin >> T;

	for(int tcase = 1; tcase <= T; tcase++)
	{
        total_arrows = 0;
        memset(seen,0,sizeof(seen));
        memset(grid_idx,-1,sizeof(grid_idx));
        memset(grid_dir,-1,sizeof(grid_dir));

        cin >> R >> C;
        for(int y = 0; y < R; y++)
        {
            string row = "";
            cin >> row;
            for(int x = 0; x < C; x++)
            {
                if(row[x] == '.') continue;
                grid_idx[y][x] = total_arrows;
                total_arrows++;

                if(row[x] == '^') grid_dir[y][x] = 0;
                else if(row[x] == '>') grid_dir[y][x] = 1;
                else if(row[x] == 'v') grid_dir[y][x] = 2;
                else grid_dir[y][x] = 3;
            }
        }
        //deb(total_arrows);
        if(impossible())
        {
            printf("Case #%d: IMPOSSIBLE\n",tcase);
            continue;
        }
        int total = 0;
        for(int y = 0; y < R; y++)
            for(int x = 0; x < C; x++)
            {
                if(grid_idx[y][x] >= 0)
                {
                    total += traverse(y,x,grid_dir[y][x]);
                }
            }
        printf("Case #%d: %d\n",tcase,total);
	}
	return 0;
}
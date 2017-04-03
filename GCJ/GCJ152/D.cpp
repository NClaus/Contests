
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
#include <cstring>
#include <set>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;


int main()
{
    int T;
	cin >> T;

	for(int tcase = 1; tcase <= T; tcase++)
	{
        int R,C;


        cin >> R >> C;
        bool ex = ((C%3) == 0);
        
        long long memo[R+3][3];
        memset(memo,0,sizeof(memo));
        const long long MOD = 1000000007;
        memo[1][0] = memo[2][1] = 1;
        if(ex) memo[2][2] = 1;
        for(int row = 1; row < R; row++)
        {
        	memo[row+2][1] = (memo[row+2][1] + memo[row][0] + memo[row][2]) % MOD;
        	memo[row+1][0] = (memo[row+1][0] + memo[row][1]) % MOD;
        	if(ex)  memo[row+2][2] = (memo[row+2][2] + memo[row][1]) % MOD;
        }
        long long ret = (memo[R][0] + memo[R][1] + memo[R][2]) % MOD;
		printf("Case #%d: %lld\n",tcase,ret);
	}
	return 0;
}

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


long long solve3(long long A, long long cntA, long long B, long long cntB, long long K)
{
    if(K <= (cntA + cntB))
    {
        if(K <= cntA) return A;
        else return B;
    }
    else
    {
        if( A % 2 == 0)
        {
            long long nextA = (A / 2), nextB = (A/2) - 1;
            long long next_cntA = cntA, next_cntB = cntA + 2*cntB;
            return solve3(nextA, next_cntA, nextB, next_cntB, K - cntA - cntB);
        }
        else
        {
            long long nextA = (A-1) / 2;
            long long nextB = nextA - 1;
            long long next_cntA = 2*cntA+cntB, next_cntB = cntB;
            return solve3(nextA, next_cntA, nextB, next_cntB, K - cntA - cntB);
        }
        
    }
}

int main()
{
    int TT;
	cin >> TT;

	for(int test_case = 1; test_case <= TT; test_case++)
	{
        long long N,K;
        cin >> N >> K;
       
        //long long curN = rec(N,K);
        long long curN = solve3(N,1,0,0,K);//solve2(N,K);

        long long half_small = (curN - 1) / 2;
        long long half_large = (curN - 1 - half_small);
        if(half_large < 0) half_large = 0;
        printf("Case #%d: %lld %lld\n",test_case, half_large, half_small);

	}
	return 0;
}
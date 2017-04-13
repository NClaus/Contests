
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


int main()
{
    int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++)
	{
        int N, K;
        string S;
        cin >> S >> K;
        N = S.size();
        
        int pancakes[N];
        for(int i = 0; i < N; i++)
        {
            if(S[i] == '-') pancakes[i] = 1;
            else pancakes[i] = 0;
        }
        bool imp = false;
        int total = 0;
        for(int idx = 0; idx <= (N-K); idx++)
        {
            if(pancakes[idx]==1)
            {
                for(int jdx = 0; jdx < K; jdx++)
                {
                    pancakes[idx+jdx] = 1-pancakes[idx+jdx];
                }
                total++;
            }
        }
        for(int idx = (N-K+1); idx < N; idx++)
        {
            if(pancakes[idx] == 1)
            {
                imp = true;
            }
        }
        if(imp)
        {
            printf("Case #%d: IMPOSSIBLE\n", test_case);
        }
        else
        {
            printf("Case #%d: %d\n", test_case, total);
        }

	}
	return 0;
}
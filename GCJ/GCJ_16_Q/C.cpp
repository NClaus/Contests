
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

	for(int tcase = 1; tcase <= T; tcase++)
	{
        int N;
        cin >> N;
        string first;
        string second;
        cin >> first >> second;

        int left[N+1], right[N+1];
        int paint = 0;
        left[0] = 0;
        for(int idx = 0; idx < N; idx++)
        {
            if(idx == 0 || second[idx] != second[idx-1])
            {
                paint++;
            }
            if(first[idx] != second[idx])
            {
                left[idx+1] = paint;
            }
            else
            {
                left[idx+1] = left[idx];
            }
        }

        right[N] = 0;
        paint = 0;
        for(int idx = N-1; idx >= 0; idx--)
        {
            if(idx == (N-1) || second[idx] != second[idx+1])
            {
                paint++;
            }
            if(first[idx] != second[idx])
            {
                right[idx] = paint;
            }
            else
            {
                right[idx] = right[idx+1];
            }
        }
        int ret = max(right[0],left[N]);
        for(int i = 1; i <= N; i++)
            ret = min(ret, max(right[i],left[i]));
        printf("Case #%d: %d\n",tcase,ret);
	}
	return 0;
}
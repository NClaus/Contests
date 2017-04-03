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
#include <set>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
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


double get_prob(int sides, int times, int Z, int H)
{
    H = H - Z;
    if(H <= times)
        return 1.0;
    if(H > sides*times)
        return 0.0;

    double dp[sides*times+1][times+1];
    for(int i = 0; i < sides*times+1; i++)
    {
        for(int j = 0; j < times+1; j++)
            dp[i][j] = 0.0;
    }
    dp[0][0] = 1.0;
    double INCREMENT = 1.0/(double)sides;
    for(int i = 0; i < times; i++)
    {
        for(int prev = 0; prev <= sides*i; prev++)
        {
            if(dp[prev][i] > 1e-9)
            {
                for(int k = 1; k <= sides; k++)
                {
                    dp[prev+k][i+1] += (dp[prev][i] * INCREMENT);
                }
            }
        }
    }

    double ret = 0.0;
    for(int idx = sides*times; idx >= H; idx--)
    {
        ret += dp[idx][times];
    }
    return ret;
}

int main()
{
	int test_cases = 0;
	cin >> test_cases;

	for(int test_case = 1; test_case <= test_cases; test_case++)
	{
        int N;
        cin >> N;
        vector<int> weights(N,0);
        for(int i = 0; i < N; i++)
        {
            cin >> weights[i];
        }
        sort(weights.begin(), weights.end());
        int start = 0, end = N-1;
        int total_trips = 0;
        while(end >= 0 && weights[end] >= 50)
        {
            total_trips++;
            end--;
        }
        while(end >= start)
        {
            int top_weight = weights[end];
            int total_stacked = 1;
            end--;
            while(end >= start)
            {
                total_stacked++;
                start++;
                if(total_stacked * top_weight >= 50)
                {
                    total_trips++;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",test_case, total_trips);
	}
}

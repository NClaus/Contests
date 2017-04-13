
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
        long long digits[20], N, tot_dig = 0; 
        cin >> N;
        long long tempN = N;

        memset(digits,0,sizeof(digits));
        while(tempN > 0)
        {
            digits[tot_dig] = tempN % 10;
            tot_dig++;
            tempN /= 10;
        }
      
        int first_idx = -1;
        for(int idx = tot_dig-1; idx > 0; idx--)
        {
            if(digits[idx] > digits[idx-1])
            {
                first_idx = idx-1;
                for(int jdx = first_idx -1; jdx >= 0; jdx--)
                    digits[jdx] = 9;
            }
        }
        
        if(first_idx > -1)
        {
            while((digits[first_idx] < digits[first_idx+1]))
            {
                digits[first_idx] = 9;
                digits[first_idx+1]--;
                first_idx++;
            }
        }
        long long ret = 0;
        for(int idx = tot_dig -1; idx >= 0; idx--)
        {
            ret = ret*10 + digits[idx];
        }
        printf("Case #%d: %lld\n",test_case, ret);

	}
	return 0;
}
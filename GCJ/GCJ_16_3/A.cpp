
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

int main()
{
    int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++)
	{
        string names = "";
        cin >> names;
        int N = names.size();
        int mood[N], qq[N+2];
        for(int i = 0; i < N; i++)
        {
            if(names[i]=='C') mood[i] = 0;
            else mood[i] = 1;
        }
        memset(qq,0,sizeof(qq));
        int matches = 0;
        int pnt = -1;

        for(int idx = 0; idx < N; idx++)
        {
            if(pnt == -1)
            {
                pnt++;
                qq[pnt] = mood[idx];
            }
            else
            {
                if(qq[pnt] == mood[idx])
                {
                    matches++;
                    pnt--;
                }
                else
                {
                    pnt++;
                    qq[pnt] = mood[idx];
                }
            }

        }
        if( (pnt+1) % 2  > 0)
        {
            deb("Fail");
        }
        int ret = 10*matches + 5*((pnt+1)/2);
        printf("Case #%d: %d\n", test_case, ret);
	}
	return 0;
}
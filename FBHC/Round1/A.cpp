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

const double PI = 3.14159265359;
int main()
{
	int test_cases = 0;
	cin >> test_cases;

	for(int test_case = 1; test_case <= test_cases; test_case++)
	{
        int P, X, Y;
        cin >> P >> X >> Y;
        string color = "";

        int off_x = X-50;
        int off_y = Y-50;

        int dist = (off_x*off_x)+(off_y*off_y);
        if(dist > 2500)
        {
            color = "white";
        }
        else if(off_x == 0 && off_y == 0)
        {
            if(P == 0) color = "white";
            else color = "black";
        }
        else
        {
            int quadrant;
            if(off_x < 0)
            {
                if(off_y < 0)
                {
                    quadrant = 3;
                }
                else
                {
                    quadrant = 4;
                }
            }
            else if(off_y < 0)
            {
                quadrant = 2;
            }
            else
            {
                quadrant = 1;
            }
            off_x = abs(off_x); off_y = abs(off_y);
            double angle_rad = atan2((double)off_y,(double)off_x);
            if(quadrant % 2 == 1)
            {
                angle_rad = (PI/2.0-angle_rad);
            }
            angle_rad += (quadrant-1) * (PI/2.0);
            double perc_angle_rad = 2.0*PI*(double)P/100.0;

            //cout << angle_rad << " " << perc_angle_rad << endl;

            if(angle_rad <= perc_angle_rad)
            {
                color = "black";
            }
            else
                color = "white";


        }


        cout << "Case #" << test_case << ": " << color << endl;
	}
}

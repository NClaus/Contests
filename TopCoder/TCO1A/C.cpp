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
typedef pair<int,int> PAIR;

#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << "(" << x[i].first << "," << x[i]. second << ") "; cout << endl;
const double PI = 3.14159265358979;
int N;

double calcvolume(double w, double finalw, double h)
{
    deb(w);
    deb(finalw);
    deb(h);
    double slope = (finalw - w) / h;

    double ret = (w*w*h) + (w * slope * h * h) + ((h*h*h*slope*slope)/3.0);

    return (PI*ret) / 4.0;
}

bool mysort(PAIR a, PAIR b)
{
    if(a.first != b.first)
        return (a.first < b.first);

    return abs(b.second) < abs(a.second);
}

class PolygonRotation {
    public: 
    double getVolume(vi x, vi y)
    {
     	vector< PAIR > pos, neg, tot;
        N = x.size();
        for(int i = 0; i < N; i++)
        {
            if(x[i] <= 0)
            {
                neg.push_back(make_pair(y[i],x[i]));
            }
            if(x[i] >= 0)
            {
                pos.push_back(make_pair(y[i],x[i]));
            }
            tot.push_back(make_pair(y[i],x[i]));
        }
        sort(neg.begin(), neg.end(), mysort);
        sort(pos.begin(), pos.end(), mysort);
        sort(tot.begin(), tot.end(), mysort);

        int NN = neg.size(), PN = pos.size();
        int cy = tot[0].first, LDX = 0, RDX = 0;

        double ret = 0.0;
        for(int idx = 1; idx < N; idx++)
        {
            int ny = tot[idx].first;
            int sw = pos[RDX].second - neg[LDX].second;
            if( (LDX < NN-1) && (neg[LDX+1].first == ny) )
            {
                LDX++;
            }
            if( (RDX < PN-1) && pos[RDX+1].first == ny)
            {
                RDX++;
            }
            int fw = pos[RDX].second - neg[LDX].second;

            if(ny > cy)
            {
                ret += calcvolume(sw,fw,ny-cy);
            }
            cy = ny;
        }
        //debv(neg);
        //debv(pos);
        return ret;
    }
};
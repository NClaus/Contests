/*
ID: NClaus
PROG: test
LANG: C++               
*/
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
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}
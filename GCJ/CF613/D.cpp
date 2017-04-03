
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
int colors[26];
int N;
string alph = "abcdefghijklmnopqrstuvwxyz";

string bss()
{
	string ret = "";
	for(int i = 0; i < 26; i++)
	{
		for(int q = 0; q < colors[i]; q++)
			ret += alph[i];
	}
	return ret;
}

int gcd(int a, int b)
{
	if(a % b == 0) return b;
	else return (b,a%b);
}

int main()
{
	cin >> N;
	int total = 0, num_odd = 0;
	
	for(int i = 0; i < N; i++)
	{
		cin >> colors[i];
		total += colors[i];
		if(colors[i] % 2 == 1) num_odd++;
	}
	if(num_odd != (total % 2))
	{
		cout << "0\n" << bss() << endl;
		return 0;
	}

	string mid = "";
	if(num_odd == 1)
	{
		for(int i = 0; i < N; i++)
		{
			if(colors[i] % 2 == 1)
			{
				mid += alph[i];
				colors[i]--;
				break;
			}
		}
	}


	int gd = colors[0]/2;
	if(gd == 0) gd = colors[1] / 2;
	for(int i = 1; i < N; i++)
		if(colors[i] > 0)
			gd = gcd(gd,colors[i]/2);

	string first = ""; 
	for(int i = 0; i < N; i++)
		for(int j = 0; j < (colors[i]/2)/gd; j++)
			first += alph[i];

	string beg = "";
	for(int x = 0; x < gd; x++)
		beg += first;

	string ssend = beg;
	reverse(ssend.begin(), ssend.end());

	if(num_odd) cout << 1 << endl;
	else if(N == 2) cout << gd*4 << endl;
	else cout << gd*2 << endl;
	cout << beg << mid << ssend << endl;
	
	return 0;
}
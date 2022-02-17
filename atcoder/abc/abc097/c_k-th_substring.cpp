//----------------------------
//ABC_097_C
//K-th Substrings
//1108
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	string s;
	int k;
	cin >> s >> k;
	string ans = "";
	set<string> p;
	reps(l, 1, k+1)
	{
		rep(st, s.size() - l +1)
		{
			string t = "";
			reps(si,st,st+l)
			{
				t += s[si];
			}
			p.insert(t);
		}
	}
	for (auto it = p.begin(); it != p.end(); ++it)
	{
		ans = *it;
		--k;
		if (k == 0)
		{	
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
//----------------------------
//ABC 261 C
//NewFolder(1)
//179
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
	int n;
	cin >> n;
	map<string, int> mp;
	rep(i, n)
	{
		string s; cin >> s;
		cout << s;
		if (mp[s]) cout << "(" << mp[s] << ")";
		cout << endl;
		++mp[s];
	}
	return 0;
}
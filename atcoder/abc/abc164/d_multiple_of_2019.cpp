//----------------------------
//ABC_164_D
//1232
//Multiple 2019
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
	const int MOD = 2019;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	int sz = s.size();
	vector<int> a(sz);
	vector<int> S(sz + 1);
	int t = 1;
	rep(i, sz)
	{
		a[sz - i - 1] = (s[i] - '0') * t % MOD;
		t = (t * 10) % MOD;
	}
	rep(i, sz)
	{
		S[i + 1] = (S[i] + a[sz - 1 - i]) % MOD;
	}
	map<int, int> mp;
	ll ans = 0;
	rep(i, sz + 1)
	{
		ans += mp[S[i]];
		++mp[S[i]];
	}
	cout << ans << endl;

	return 0;
}
//----------------------------
//ABC_233_D
//Count Interval
//726
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
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> s(n + 1);
	rep(i, n) s[i + 1] = s[i] + a[i];
	map<ll, int> mp;
	++mp[0];
	ll ans = 0;
	reps(i, 1, n + 1)
	{
		ll x = s[i];
		ans += mp[x - k];
		++mp[x];
	}
	cout << ans << endl;
	return 0;
}

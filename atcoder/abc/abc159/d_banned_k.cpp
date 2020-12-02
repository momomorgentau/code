//496
//abc160_d_banned_k

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> h;
	rep(i, n)
	{
		cin >> a[i];
		++h[a[i]];
	}
	map<int, ll> c;
	ll sum = 0;
	for (auto hi : h)
	{
		int hi1 = hi.first;
		ll hi2 = hi.second;
		c[hi1] = hi2 * (hi2 - 1) / 2;
		sum += c[hi1];
	}
	ll ans = 0;
	rep(i, n)
	{
		/*
		ans = sum;
		ans -= c[a[i]];
		ll bn = (ll)h[a[i]] - 1;
		ans += bn * (bn - 1) / 2;
		cout << ans << endl;
		*/
		cout << sum - h[a[i]] + 1 << endl;
	}
}
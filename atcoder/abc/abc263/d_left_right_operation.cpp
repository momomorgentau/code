//----------------------------
//ABC 263 D
//Left Right Operation
//1016
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	ll now = 0;
	ll d = 0;
	ll mn = 0;
	ll ans = r * n;
	rep(i, n)
	{
		now += a[i];
		d += l - a[i];
		mn = min(d, mn);
		ans = min(now + mn + r * (n - 1 - i), ans);
	}
	cout << ans << endl;
	return 0;
}
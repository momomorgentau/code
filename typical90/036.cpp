//036
//Max_Manhattan_Distance
//*5

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n,q;
	cin >> n >> q;
	vector<ll> u(n),v(n);
	const ll INF = 1e18;
	ll mxu = -INF;
	ll mxv = -INF;
	ll mnu = INF;
	ll mnv = INF;

	rep(i, n)
	{
		ll x, y; cin >> x >> y;
		u[i] = x - y;
		v[i] = x + y;
		mxu = max(mxu, u[i]);
		mxv = max(mxv, v[i]);
		mnu = min(mnu, u[i]);
		mnv = min(mnv, v[i]);
	}
	while (q--)
	{
		ll qi; cin >> qi;
		--qi;
		ll ans = 0;
		ans = max(ans, abs(mxu - u[qi]));
		ans = max(ans, abs(mxv - v[qi]));
		ans = max(ans, abs(mnu - u[qi]));
		ans = max(ans, abs(mnv - v[qi]));
		cout << ans << endl;
	}

	return 0;
}
//----------------------------
//ABC_095_D
//Static Sushi
//1526
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
	ll c;
	cin >> n >> c;
	vector<pair<ll, ll>> xv(n);
	rep(i, n) cin >> xv[i].first >> xv[i].second;
	vector<ll> cs(n),ccs(n),cr(n),ccr(n);
	ll ans = 0;
	{
		ll px = 0;
		rep(i, n)
		{
			auto [x, v] = xv[i];
			cs[i] = -(x-px) + v + ((i == 0) ? 0 : cs[i - 1]);
			cr[i] = -2 * (x-px) + v + ((i == 0) ? 0 : cr[i - 1]);
			ans = max(ans, cs[i]);
			px = x;
		}
	}
	{
		ll px = c;
		sort(xv.rbegin(), xv.rend());
		rep(i, n)
		{
			auto [x, v] = xv[i];
			ccs[i] = -(px-x) + v + ((i == 0) ? 0 : ccs[i - 1]);
			ccr[i] = -2 * (px - x) + v + ((i == 0) ? 0 : ccr[i - 1]);
			ans = max(ans, ccs[i]);
			px = x;
		}
	}
	
	{
		ll mx = 0;
		rep(i, n)
		{
			ll now = cr[n - i - 1] + mx;
			ans = max(ans, now);
			mx = max(mx, ccs[i]);
		}
	}
	{
		ll mx = 0;
		rep(i, n)
		{
			ll now = ccr[n - i - 1] + mx;
			ans = max(ans, now);
			mx = max(mx, cs[i]);
		}
	}
	cout << ans << endl;

	return 0;
}
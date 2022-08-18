//Educational DP Contest D
//Knapsack1
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int n, w;
	cin >> n >> w;
	vector<ll> vw(n), vv(n);
	rep(i, n) cin >> vw[i] >> vv[i];
	vector<ll> dp(w + 10);
	rep(i, n)
	{
		vector<ll> tmp(w + 10);
		tmp = dp;
		rep(j, w)
		{
			ll nw = min(j + vw[i], (ll)w + 1);
			tmp[nw] = max(dp[j] + vv[i], tmp[nw]);
		}
		swap(dp, tmp);
	}
	ll ans = 0;
	rep(i, w + 1)
	{
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;
}
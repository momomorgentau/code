//Educational DP Contest E
//Knapsack2
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
	const int V = 1e5;
	const ll INF = 1e18;
	vector<ll> vw(n), vv(n);
	rep(i, n) cin >> vw[i] >> vv[i];
	vector<ll> dp(V + 10, INF);
	dp[0] = 0;
	rep(i, n)
	{
		vector<ll> tmp(V + 10);
		tmp = dp;
		rep(j, V)
		{
			if (j + vv[i] > V) break;
			tmp[j + vv[i]] = min(dp[j] + vw[i], dp[j + vv[i]]);
		}
		swap(dp, tmp);
	}
	ll ans = 0;
	rep(i, V + 10)
	{
		if (dp[i] > w) continue;
		ans = i;
	}
	cout << ans << endl;
	return 0;
}
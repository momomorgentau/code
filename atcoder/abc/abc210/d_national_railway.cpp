//ABC_210_D
//Nationall Railway
//1507
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int h, w;
	ll c;
	cin >> h >> w >> c;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h)rep(j, w) cin >> a[i][j];
	const ll INF = 1e18;
	ll ans = INF;
	rep(i, 2)
	{
		vector<vector<ll>> dp(h, vector<ll>(w, INF));
		rep(hi, h)rep(wi, w)
		{
			ll now = INF;
			if (hi > 0) now = min(now, dp[hi - 1][wi]);
			if (wi > 0) now = min(now, dp[hi][wi - 1]);
			ans = min(ans, a[hi][wi] + c * (hi + wi) + now);
			dp[hi][wi] = min(now, a[hi][wi] - c * (hi + wi));
		}
		reverse(a.begin(), a.end());
	}
	cout << ans << endl;


}
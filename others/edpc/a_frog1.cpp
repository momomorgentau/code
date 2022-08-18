//Educational DP Contest A
//Frog1
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int n; cin >> n;
	const ll INF = 1e18;
	vector<ll> h(n + 10, INF);
	vector<ll> dp(n + 10, INF);
	rep(i, n) cin >> h[i];
	dp[0] = 0;
	rep(i, n)
	{
		dp[i + 1] = min(dp[i] + abs(h[i] - h[i + 1]), dp[i + 1]);
		dp[i + 2] = min(dp[i] + abs(h[i] - h[i + 2]), dp[i + 2]);
	}
	cout << dp[n - 1] << endl;
	return 0;
}
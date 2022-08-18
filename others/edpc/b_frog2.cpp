//Educational DP Contest B
//Frog2
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int n, k; cin >> n >> k;
	const ll INF = 1e18;
	vector<ll> h(n + k + 10, INF);
	vector<ll> dp(n + k + 10, INF);
	rep(i, n) cin >> h[i];
	dp[0] = 0;
	rep(i, n)reps(j, 1, k + 1)
	{
		dp[i + j] = min(dp[i] + abs(h[i] - h[i + j]), dp[i + j]);
	}
	cout << dp[n - 1] << endl;
	return 0;
}
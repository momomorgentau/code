//039
//Tree_Distance
//*5
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<vector<int>> g;
vector<int> dp;
vector<int> used;

void dfs(int s)
{
	for (auto e : g[s])
	{
		if (used[e]==1) continue;
		used[e] = 1;
		dfs(e);
		dp[s] += dp[e];	
	}
	
}
int main()
{
	int n;
	cin >> n;
	g.resize(n);
	dp.resize(n,1);
	used.resize(n, -1);
	rep(i,n-1)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	used[0] = 1;
	dfs(0);
	ll ans = 0;

	for (auto di : dp) ans += (ll)di * (n - di);
	cout << ans << endl;


	return 0;
}
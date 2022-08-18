//Educational DP Contest G
//Longest Path
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<vector<int>> g;
vector<int> dp;
int n, m;

void dfs(int a)
{
	for (const auto& e : g[a])
	{
		if (dp[e] == -1)
		{
			dfs(e);
		}
		dp[a] = max(dp[a], dp[e] + 1);
	}
	if (g[a].size() == 0)
	{
		dp[a] = 0;
	}
}


int main()
{
	cin >> n >> m;
	g.resize(n);
	dp.resize(n, -1);
	vector<int> dim(n, 0);
	rep(i, m)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[v].emplace_back(u);
		++dim[u];
	}

	rep(i, n)
	{
		if (dim[i] == 0) dfs(i);
	}


	int ans = 0;
	rep(i, n)ans = max(ans, dp[i]);
	cout << ans << endl;

	return 0;
}
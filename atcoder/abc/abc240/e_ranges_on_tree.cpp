//----------------------------
//ABC 240 E
//Ranges on Tree
//1068
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int INF = 1e9;

vector<vector<int>> g;
vector<int> used;
vector<P> ans;
int cnt = 0;

P dfs(int a)
{
	P res = make_pair(INF, -INF);
	for (const auto& e : g[a])
	{
		if (used[e] == 1) continue;
		used[e] = 1;
		P tmp = dfs(e);
		res.first = min(res.first, tmp.first);
		res.second = max(res.second, tmp.second);
	}
	if (res == make_pair(INF, -INF))
	{
		++cnt;
		res = make_pair(cnt, cnt);
	}
	ans[a] = res;
	return res;
}
int main()
{
	int n;
	cin >> n;
	g.resize(n);
	used.resize(n, -1);
	ans.resize(n);
	rep(i, n - 1)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	used[0] = 1;
	dfs(0);
	for (const auto& [l, r] : ans)
	{
		cout << l << " " << r << endl;
	}
	return 0;
}
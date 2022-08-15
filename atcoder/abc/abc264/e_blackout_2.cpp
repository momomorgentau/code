//----------------------------
//ABC 264 E
//Blackout 2
//1229
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<int> used;
vector<vector<int>> g;
int n, m, e;
int ans = 0;
void dfs(int a)
{
	for (const auto& e : g[a])
	{
		if (used[e] != -1) continue;
		if (e >= n) continue;
		used[e] = 1;
		++ans;
		dfs(e);
	}
}

int main()
{
	cin >> n >> m >> e;
	g.resize(n + m);
	vector<pair<int, int>> E;
	rep(i, e)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		E.emplace_back(u, v);
	}
	int q;
	cin >> q;
	vector<int> Q(q);
	rep(i, q) cin >> Q[i];
	vector<int> P;
	P = Q;
	sort(P.rbegin(), P.rend());
	rep(i, e)
	{
		if (P.size() > 0 && i == P[P.size() - 1] - 1)
		{
			P.pop_back();
		}
		else
		{
			auto [u, v] = E[i];
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
	}
	used.resize(n + m, -1);
	reps(i, n, n + m)
	{

		used[i] = 1;
		dfs(i);
	}

	vector<int> anss(q + 1);
	anss[q] = ans;
	while (q--)
	{
		auto [u, v] = E[Q[q] - 1];
		g[u].emplace_back(v);
		g[v].emplace_back(u);

		if (used[u] == 1 && used[v] == -1)
		{
			used[v] = 1;
			++ans;
			dfs(v);
		}
		if (used[u] == -1 && used[v] == 1)
		{
			used[u] = 1;
			++ans;
			dfs(u);
		}
		anss[q] = ans;


	}
	reps(i, 1, anss.size()) cout << anss[i] << endl;
	return 0;
}

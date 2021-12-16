//----------------------------
//ABC_220_F
//Distance Sum 2
//1304
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int const N = 3e5 + 10;
vector<int> used0(N);
vector<vector<int>> g(N);
int leaf = -1;
void dfs0(int a)
{
	bool last = true;
	for (const auto& e : g[a])
	{
		if (used0[e]) continue;
		used0[e] = 1;
		last = false;
		dfs0(e);

	}
	if (last) leaf = a;
}

int n;
vector<int> used(N);
vector<int> d(N);
map<P, int> mp;
ll ans = 0;
void dfs1(int a)
{
	for (const auto& e : g[a])
	{
		if (used[e]) continue;
		used[e] = 1;
		dfs1(e);
		d[a] += d[e] + 1;
		mp[make_pair(a, e)] = d[e] + 1;
		mp[make_pair(e, a)] = n - (d[e] + 1);
		ans += d[e] + 1;
	}
}
vector<ll> A(N);

void dfs2(int a)
{
	for (const auto& e : g[a])
	{
		if (A[e] != 0) continue;
		A[e] = A[a] - mp[make_pair(a, e)] + mp[make_pair(e, a)];
		dfs2(e);
	}
}

int main()
{
	cin >> n;
	rep(i, n - 1)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	used0[0] = 1;
	dfs0(0);
	used[leaf] = 1;
	dfs1(leaf);
	A[leaf] = ans;
	dfs2(leaf);
	rep(i, n)
	{
		cout << A[i] << endl;

	}




	return 0;
}
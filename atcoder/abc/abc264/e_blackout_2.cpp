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
/////////////////////////////////////////////////
// 頂点に重みを付けたUnionFind
/*
struct UnionFind {
	vector<T> d;
	//コンストラクタ
	UnionFind(int n = 0) : d(n, -1) {}

	void update_weight(int u, int w) {
		d[u] = -w;
	}
	//根の探索と張り替え
	T find(int x) {
		if (d[x] < 0) return x;
		//根のはりかえ
		return d[x] = find(d[x]);
	}
	//根の結合
	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		//大きい方に小さい方をくっつける
		if (d[x] > d[y]) swap(x, y);
		//サイズの更新
		d[x] += d[y];
		//結合
		d[y] = x;
		return true;
	}
	//サイズの取得
	T size(int x) { return -d[find(x)]; }
	//同じ集合に属しているか
	bool same(int x, int y) { return (find(x) == find(y)); }
};

int main()
{
	int n, m, e;
	cin >> n >> m >> e;
	vector<pair<int, int>> E;
	rep(i, e)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		E.emplace_back(u, v);
	}
	int q; cin >> q;
	vector<int> x(q);
	rep(i, q) cin >> x[i];
	UnionFind<ll> UF(n + m);
	rep(i, m)UF.update_weight(n + i, INF);
	set<int> s;
	rep(i, e) s.insert(i);
	rep(i, q) s.erase(x[i] - 1);
	const ll INF = 1e9;
	int ans = 0;

	auto query = [&](int u, int v)
	{
		if (UF.same(u, v))return;

		bool bu = (UF.size(u) >= INF);
		bool bv = (UF.size(v) >= INF);

		if ((bu ^ bv))
		{
			if (!bu)ans += UF.size(u) % INF;
			if (!bv)ans += UF.size(v) % INF;
		}

		UF.unite(u, v);

	};
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		int u, v;
		u = E[*it].first;
		v = E[*it].second;
		query(u, v);
	}
	vector<int> anss(q);
	for (int qi = q - 1; qi >= 0; qi--)
	{
		anss[qi] = ans;
		int u, v;
		u = E[x[qi] - 1].first;
		v = E[x[qi] - 1].second;
		query(u, v);
	}
	for (const auto& ai : anss) cout << ai << endl;

	return 0;
}
*/
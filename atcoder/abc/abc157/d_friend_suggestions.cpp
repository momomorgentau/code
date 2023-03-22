//----------------------------
// ABC 157 D
// Friend Suggestions
// 1208
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

template<typename T>
struct UnionFind {
	vector<int> d;
	//コンストラクタ
	UnionFind(int n = 0) : d(n, -1) {}
	//根の探索と張り替え
	int find(int x) {
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
	int size(int x) { return -d[find(x)]; }
	//同じ集合に属しているか
	bool same(int x, int y) { return (find(x) == find(y)); }
};


int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	UnionFind<int> uf(n);
	vector<vector<int>> block(n);
	vector<int> f(n);
	rep(i, m)
	{
		int u, v; cin >> u >> v;
		--u, --v;
		f[u]++;
		f[v]++;
		uf.unite(u, v);
	}
	rep(i, k)
	{
		int u, v; cin >> u >> v;
		--u, --v;
		block[u].emplace_back(v);
		block[v].emplace_back(u);
	}
	rep(i, n)
	{
		ll now = uf.size(i) - 1;
		now -= f[i];
		for (const auto& b : block[i])
		{
			now -= uf.same(i, b);
		}
		printf("%d ", now);
	}

	return 0;
}
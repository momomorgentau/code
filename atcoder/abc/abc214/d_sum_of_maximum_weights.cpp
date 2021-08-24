//ABC_214_D
//Sum of Maximum Weights
//1341
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using T = tuple<int, int, int>;

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
	int n;
	cin >> n;
	vector<T> node(n - 1);
	for (auto& [w, u, v] : node)
	{
		cin >> u >> v >> w;
		--u, --v;
	}
	sort(node.begin(), node.end());
	UnionFind<int> uf(n);
	ll ans = 0;
	for (auto const& [w, u, v] : node)
	{
		ans += (ll)uf.size(u) * uf.size(v) * w;
		uf.unite(u, v);
	}
	cout << ans << endl;
	return 0;
}
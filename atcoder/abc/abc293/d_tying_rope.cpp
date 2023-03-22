//----------------------------
// ABC 293 D
// Typing Rope
// 830
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
	int n, k;
	cin >> n >> k;
	UnionFind<int> uf(2 * n);
	rep(i, n) uf.unite(2 * i, 2 * i + 1);
	ll x = 0;
	rep(i, k)
	{
		int a, c;
		char b, d;
		cin >> a >> b >> c >> d;
		--a, --c;
		int idx0 = a * 2 + (b == 'R');
		int idx1 = c * 2 + (d == 'R');
		if (uf.same(idx0, idx1))
		{
			x++;
		}
		uf.unite(idx0, idx1);
	}
	ll y = 0;
	set<int> p;
	rep(i, n) p.insert(uf.find(i * 2));
	y = p.size() - x;
	cout << x << " " << y << endl;
	return 0;
}
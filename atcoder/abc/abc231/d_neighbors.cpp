//----------------------------
//ABC 231 D
//Neighbors
//726
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
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
    int n, m;
    cin >> n >> m;
    vector<int> ab(n);
	UnionFind<int> uf(n);
    bool ok = true;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (uf.same(a,b) || ab[a] >= 2 || ab[b] >= 2)
        {
            ok = false;
        }
        ab[a]++;
        ab[b]++;
		uf.unite(a, b);
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
//ABC_120_D_Decayed_Bridges
//1355
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


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
    ll n,m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    rep(i,m) cin >> a[m-i-1] >> b[m-i-1];
    rep(i,m) --a[i];
    rep(i,m) --b[i];

    UnionFind<int> UF(n);
    ll now = n * (n-1) / 2;
    vector<ll> ans(m);
    rep(i,m)
    {
        ans[m-i-1] = now;
        int ai = a[i],bi = b[i];
        if(UF.same(ai,bi)) continue;
        ll s1 = UF.size(ai);
        ll s2 = UF.size(bi);
        ll c1 = s1 * (s1-1) /2;
        ll c2 = s2 * (s2-1) /2;

        UF.unite(ai,bi);
        ll s3 = UF.size(ai);
        ll c3 = s3*(s3-1)/2;
        now += c1 + c2 - c3;        
    }
    for(auto v:ans) cout << v << endl;
    return 0;
}
/*
1 0  1 0
2 1

2 1  1 0
3 3

3 3 1 0
4 6

3 3 2 1
5 10

*/
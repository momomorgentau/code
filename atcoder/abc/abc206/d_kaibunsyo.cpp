//ABC_206_D
//KAIBUNsyo
//879

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

const int M = 2e5;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n)--a[i];
    UnionFind<int> uf(M);
    int ans = 0;
    rep(i, n)
    {
        int a1 = a[i];
        int a2 = a[n - i - 1];
        uf.unite(a1, a2);
    }
    map<int, int> mp;
    rep(i, n)
    {
        int root = uf.find(a[i]);
        if (mp[root] != 0) continue;
        ans += uf.size(root) - 1;
        ++mp[root];
    }
    cout << ans << endl;

    return 0;
}
//----------------------------
// ABC 295 G
// Minimum Reachable City
// 2091
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
        //if (d[x] > d[y]) swap(x, y);
        // 頂点番号が小さいほうにくっつけます
        if (x > y) swap(x, y);
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
    vector<int> p(n);
    reps(i, 1, n) cin >> p[i];
    rep(i, n) p[i]--;

    UnionFind<int> uf(n);
    int q; cin >> q;
    while (q--)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            u = uf.find(u);
            v = uf.find(v);
            queue<int> q;
            q.emplace(u);
            while (!q.empty())
            {
                int a = q.front();
                q.pop();
                if (v == a)break;
                int t = p[a];
                uf.unite(a, t);
                q.emplace(t);
            }
        }
        if (op == 2)
        {
            int x; cin >> x;
            x--;
            printf("%d\n", uf.find(x) + 1);
        }
    }
    return 0;
}
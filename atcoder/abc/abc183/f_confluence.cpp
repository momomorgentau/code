//diff 1552
//abc182_f_confluence

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;

template<typename T>
struct UnionFind {
    vector<int> d;
    //mp[i][c]
    //人iが所属する集団のクラスcの人数
    vector<map<int, int>> mp;
    UnionFind(int n = 0) : d(n, -1), mp(n) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        //xの方が大きい
        //p.first : クラス番号
        //p.second : クラスに所属する人数
        for (auto p : mp[y])
        {
            mp[x][p.first] += p.second;
        }
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    int size(int x) { return -d[find(x)]; }
    bool same(int x, int y) { return (find(x) == find(y)); }
};

int main()
{
    int n, q;
    cin >> n >> q;
    UnionFind<int> uf(n);

    rep(i, n)
    {
        int c; cin >> c;
        ++uf.mp[i][c];
    }
    rep(i, q)
    {
        int qi; cin >> qi;
        if (qi == 1)
        {
            int a, b; cin >> a >> b;
            --a; --b;
            uf.unite(a, b);
        }
        else
        {
            int x, y; cin >> x >> y;
            --x;
            cout << uf.mp[uf.find(x)][y] << endl;
        }
    }

    return 0;
}




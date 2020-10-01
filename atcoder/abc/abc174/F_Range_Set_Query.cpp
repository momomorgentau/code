#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using  P = pair<int, int>;
//BITの実装
template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    BIT(int n = 0) :n(n), bit(n + 1) {}
    void add(int i, T x = 1) {
        for (i++; i <= n; i += i & -i) {
            bit[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i & -i) {
            x += bit[i];
        }
        return x;
    }
};
int main()
{
    int n, q; cin >> n >> q;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }

    //クエリを始点の大きさをもとに並べる---
    vector<vector<P>> query(n);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        //番号も保持しておく
        query[l].emplace_back(r, i);
    }

    //矢印の配列をつくる------------------
    vector<vector<int>> arrow(n);
    //既に現れた数字を格納する
    vector<int> app(n, -1);

    rep(i, n)
    {
        int num = app[c[i]];
        if (num != -1)
        {
            arrow[num].emplace_back(i);
        }
        app[c[i]] = i;
    }
    //X軸に関して走査を行う-----------------
    vector<int> ans(q);
    BIT<int> bit(n);

    //x軸の大きい順に調べる
    for (int x = n - 1; x >= 0; --x)
    {
        //矢印の座標と一致したら、bitのy座標番目を+1
        for (int y : arrow[x]) bit.add(y, 1);
        //クエリを調べる
        for (P qu : query[x])
        {
            int r = qu.first, i = qu.second;
            //bitのrまでの数字の合計が重複分
            ans[i] = (r - x + 1) - bit.sum(r);
        }
    }
    rep(i, q) cout << ans[i] << endl;

    return 0;
}
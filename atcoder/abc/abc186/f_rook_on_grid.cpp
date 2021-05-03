//ABC_186_F_Rook_on_Grid
//1833
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


template<class T>
class BIT
{
public:
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
    T sum(int l, int r)
    {
        return sum(r - 1) - sum(l - 1);
    }
    void debug()
    {
        for (auto bi : bit) cout << bi << " ";
        cout << endl;
    }
private:
    int n;
    vector<T> bit;
};

int main()
{
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> x(w, h);
    vector<int> y(h, w);
    rep(i, m)
    {
        int th, tw; cin >> th >> tw;
        --th, --tw;
        if (x[tw] > th) x[tw] = th;
        if (y[th] > tw) y[th] = tw;
    }
    ll ans = 0;
    rep(i, w)
    {
        if (x[i] == 0) break;
        ans += x[i];
    }
    rep(i, h)
    {
        if (y[i] == 0) break;
        ans += y[i];
    }


    //壁の位置を逆引き
    vector<vector<int>> rx(h+1);
    rep(i, w)
    {
        if (x[i] == 0) break;
        rx[x[i]].emplace_back(i);
    }

    //bitの用意
    BIT<int> bit(w);
    rep(i, w)
    {
        if (x[i] == 0) break;
        bit.add(i,1);
    }

    rep(i, h)
    {
        if (y[i] == 0) break;
        for (auto rxi : rx[i])
        {
            bit.add(rxi, -1);
        }
        ans -= bit.sum(0,y[i]);
    }  
    cout << ans << endl;
    return 0;
}
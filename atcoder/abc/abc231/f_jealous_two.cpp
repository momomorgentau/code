//----------------------------
//ABC_231_F
//Jealous Tow
//1580
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    set<int> cmp;
    rep(i, n)
    {
        cmp.insert(a[i]);
        cmp.insert(b[i]);
    }

    vector<int> dcr;
    for (auto it = cmp.begin(); it != cmp.end(); ++it)
    {
        dcr.emplace_back(*it);
    }

    vector<P> ab(n);
    rep(i, n)
    {
        ab[i].first = lower_bound(dcr.begin(), dcr.end(), a[i]) - dcr.begin();
        ab[i].second = lower_bound(dcr.begin(), dcr.end(), b[i]) - dcr.begin();
    }

    sort(ab.rbegin(), ab.rend());
    ll dp = 0;
    BIT<int> bit(dcr.size());
    int pre = 1e9;
    int cnt = 0;
    rep(i, n)
    {
        auto [a, b] = ab[i];
        bit.add(b);

        if (a == pre)
        {
            ++cnt;
        }
        else
        {
            pre = a;
            cnt = 0;
        }
        dp += bit.sum(b) + cnt;
    }
    cout << dp << endl;

    return 0;
}
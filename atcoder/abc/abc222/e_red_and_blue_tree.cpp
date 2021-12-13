//----------------------------
//ABC_222_E
//Red and Blue Tree
//1491
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int mod = 998244353;
class mint
{
public:
    long long x;
    mint(long long x = 0) :x((x% mod + mod) % mod) {}
    mint operator -() const { return mint(-x); }
    mint& operator +=(const mint a)
    {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator -=(const mint a)
    {
        if ((x += -a.x + mod) >= mod) x -= mod;
        return *this;
    }
    mint& operator *=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a)
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a)
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a)
    {
        mint res(*this);
        return res *= a;
    }
    mint pow(long long t) const
    {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    //for only prime number
    //Fermat's little theorem
    mint inv() const
    {
        return pow(mod - 2);
    }
    mint& operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a)
    {
        mint res(*this);
        return res /= a;
    }
};


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    rep(i, m) --a[i];
    vector<vector<P>> g(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    vector<int> t(n - 1);

    rep(i, m - 1)
    {
        int x = a[i];
        int y = a[i + 1];
        if (x == y) continue;

        deque<pair<int, vector<int>>> dq;
        vector<int> qi;
        dq.emplace_back(x, qi);
        vector<int> used(n);
        used[x] = 1;
        bool ok = false;

        while (!ok)
        {
            int xi = dq.front().first;

            for (const auto& [e, u] : g[xi])
            {
                if (used[e])continue;
                vector<int> qj = dq.front().second;
                qj.emplace_back(u);
                dq.emplace_back(e, qj);
                used[e] = 1;
                if (e == y)
                {
                    ok = true;
                    break;
                }
            }
            dq.pop_front();
        }
        auto [e, v] = dq.back();
        for (const auto& vi : v)
        {
            ++t[vi];
        }
    }
    map<ll, mint> dp;
    dp[0] = 1;
    for (const auto& ti : t)
    {
        map<ll, mint> dpi;
        for (auto const& [rb, val] : dp)
        {
            dpi[rb + ti] += val;
            dpi[rb - ti] += val;
        }
        swap(dp, dpi);
    }

    cout << dp[k].x << endl;
    return 0;
}
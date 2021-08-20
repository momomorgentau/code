//ABC_208_E
//Safety Journey
//1410
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;

const int mod = 998244353;
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
    vector<mint> dp(n);
    vector<vector<int>> uv(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    dp[0] = 1;
    rep(i, k - 1)
    {
        mint sum = 0;
        rep(j, n) sum += dp[j];
        vector<mint> next(n);
        rep(i, n)
        {
            next[i] += sum - dp[i];
            for (auto const& v : uv[i])
            {
                next[i] -= dp[v];
            }
        }
        swap(dp, next);
    }
    mint ans = 0;
    reps(i, 1, n) ans += dp[i];
    for (auto const& v : uv[0]) ans -= dp[v];

    cout << ans.x << endl;
    return 0;
}
//----------------------------
//ABC 265 E
//Warp
//1531
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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
const int  N = 305;
mint dp[N][N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    map<pair<ll, ll>, int> mp;
    rep(i, m)
    {
        ll x, y;
        cin >> x >> y;
        mp[make_pair(x, y)] = 1;
    }
    dp[0][0][0] = 1;
    for (ll i = 0; i <= n; ++i)
    {
        for (ll j = 0; i + j <= n; ++j)
        {
            for (ll k = 0; i + j + k <= n; ++k)
            {
                ll p = i * a + j * c + k * e;
                ll q = i * b + j * d + k * f;
                if (!mp.count(make_pair(p + a, q + b)))
                {
                    dp[i + 1][j][k] += dp[i][j][k];
                }
                if (!mp.count(make_pair(p + c, q + d)))
                {
                    dp[i][j + 1][k] += dp[i][j][k];
                }
                if (!mp.count(make_pair(p + e, q + f)))
                {
                    dp[i][j][k + 1] += dp[i][j][k];
                }
            }
        }
    }
    mint ans = 0;
    rep(i, n + 1)rep(j, n + 1)
    {
        if (i + j > n) break;
        ans += dp[i][j][n - i - j];
    }
    cout << ans.x << endl;
    return 0;
}
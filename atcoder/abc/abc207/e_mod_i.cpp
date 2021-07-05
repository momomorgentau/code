//ABC_207_E
//Mod i
//1820
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


const int mod = 1e9 + 7;
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

const int M = 3000;
mint dp[M + 5][M + 5];
mint ds[M + 5][M + 5];

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> sum(n + 1);
    rep(i, n) sum[i + 1] = sum[i] + a[i];
    dp[0][1] = 1;
    ds[1][0] = 1;
    for (int j = 1; j <= n; ++j)
    {
        for (int i = j; i >= 1; --i)
        {
            mint now = ds[i][sum[j] % i];
            dp[j][i + 1] += now;
            ds[i + 1][sum[j] % (i + 1)] += now;
        }
    }
    mint ans = 0;
    for (int i = 0; i <= n + 1; ++i) ans += dp[n][i];

    cout << ans.x << endl;


    return 0;
}
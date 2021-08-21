//ABC_209_F
//Deforestation
//2307
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

const int M = 4005;
mint dp[M][M];
int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    dp[0][0] = 1;
    rep(i, n - 1)
    {
        if (h[i] <= h[i + 1])
        {
            mint s = 0;
            rep(j, i + 1)
            {
                s += dp[i][j];
                dp[i + 1][j + 1] += s;
            }
        }
        if (h[i] >= h[i + 1])
        {
            mint s = 0;
            for (int j = i; j >= 0; --j)
            {
                s += dp[i][j];
                dp[i + 1][j] += s;
            }
        }
    }
    mint ans = 0;
    rep(i, n) ans += dp[n - 1][i];
    cout << ans.x << endl;
    return 0;
}
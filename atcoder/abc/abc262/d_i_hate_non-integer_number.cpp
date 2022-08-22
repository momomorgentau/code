//----------------------------
//ABC 262 D
//I Hate Non-integer Number
//1213
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    mint ans = 0;
    for (int m = 1; m <= n; ++m)
    {
        vector<int>b(n);
        rep(i, n) b[i] = a[i] % m;
        vector<vector<mint>> dp(m + 1, vector<mint>(m));
        dp[0][0] = 1;
        rep(i, n)
        {
            vector<vector<mint>> tmp(m + 1, vector<mint>(m));
            tmp = dp;
            rep(j, m)
            {
                rep(k, m)
                {
                    tmp[k + 1][(j + b[i]) % m] += dp[k][j];
                }
            }
            swap(tmp, dp);
        }
        ans += dp[m][0];
    }
    cout << ans.x << endl;
    return 0;
}
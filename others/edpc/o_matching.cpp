//Educational DP Contest O
//Matching
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n)rep(j, n) cin >> a[i][j];
    vector<mint> dp(1 << n);
    dp[0] = 1;
    rep(i, n)
    {
        vector<mint> tmp(1 << n);
        rep(j, (1 << n))
        {
            int bit = j;
            int up = 0;
            //if(dp[bit].x == 0) continue; Ž}Š ‚èibit‚ª‚©‚Ý‡‚í‚È‚¢‰ÓŠ‚Í0‚Æ‚È‚éj
            rep(k, n) up += (bit >> k) & 1;
            if (up != i) continue;
            rep(k, n)
            {
                if ((bit >> k) & 1) continue;
                if (a[i][k] == 0) continue;
                tmp[bit | (1 << k)] += dp[bit];
            }
        }
        swap(dp, tmp);
    }
    cout << dp[(1 << n) - 1].x << endl;

    return 0;
}
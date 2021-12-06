//----------------------------
//ABC_230_F
//Predilection
//2113
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

//first:2020/12/05

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
    int n; cin >> n;
    vector<int> fi(n + 1);
    fi[0] = 0;
    map<ll, int> apped;
    ll sum = 0;
    rep(i, n)
    {
        int a; cin >> a;
        sum += a;
        fi[i + 1] = apped[sum];
        apped[sum] = i + 1;
    }
    vector<mint> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    reps(i, 1, n)
    {
        dp[i + 1] = dp[i] * 2 - dp[fi[i]];
    }
    cout << dp[n].x << endl;

    return 0;
}
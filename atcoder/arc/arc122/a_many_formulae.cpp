//ARC_122_A
//Many_Formulae
//783
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using T = tuple<int,int,int>;

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

const int M = 1e5;
mint dp[M + 5][2];
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i, M)
    {
        dp[i + 1][0] = dp[i][1];
        dp[i + 1][1] = dp[i][1]+dp[i][0];
    }
    mint ans = 0;
    ans += (mint)a[0]*dp[n-1][1];
    reps(i, 1, n)
    {
        ans += (mint)a[i] * dp[i - 1][1] * dp[n - 1 - i][1];
        ans += (mint)a[i] * dp[i - 1][0] * dp[n-1-i][0] * -1;
    }
    cout << ans.x << endl;
    return 0;
}
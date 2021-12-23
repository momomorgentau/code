//------------------------------
//ABC_216_F
//Max Sum Counting
//1541
//------------------------------
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
    //[0,i]
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i & -i) {
            x += bit[i];
        }
        return x;
    }
};

const int A = 5000;
int main()
{

    int n;
    cin >> n;
    vector<P> ab(n);
    rep(i, n) cin >> ab[i].first;
    rep(i, n) cin >> ab[i].second;

    vector<BIT<mint>> dp(A + 5, A + 5);

    sort(ab.begin(), ab.end());

    rep(i, n)
    {
        auto [a, b] = ab[i];
        for (int bi = A - b; bi >= 0; --bi)
        {
            dp[b + bi].add(a, dp[bi].sum(a));
        }
        dp[b].add(a);
    }

    mint ans = 0;
    rep(i, A + 1)
    {
        ans += dp[i].sum(A + 1) - dp[i].sum(i - 1);
    }
    cout << ans.x << endl;
    return 0;
}
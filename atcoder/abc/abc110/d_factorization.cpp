//ABC_110_D
//Factorization
//1695
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

vector<mint> b(int(1e5) + 1000);

int main()
{
    int n, m;
    unordered_map<int, int> mp;
    vector<int> d;
    cin >> n >> m;
    b[0] = 1;
    reps(i, 1, n + 100) b[i] = b[i - 1] * i;
    int M = m;
    for (ll i = 2; i * i <= m; ++i)
    {
        while (M % i == 0)
        {
            mp[i]++;
            M /= i;
        }
    }
    if (M != 1) ++mp[M];

    mint ans = 1;
    for (auto [key, value] : mp)
    {
        ans *= b[value + n - 1] / (b[value] * b[n - 1]);
    }
    cout << ans.x << endl;
    return 0;
}
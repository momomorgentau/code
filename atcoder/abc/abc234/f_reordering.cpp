//----------------------------
//ABC_234_F
//Reordering
//1596
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
    string s;
    cin >> s;
    vector<int> f(26);
    for (const auto& c : s)
    {
        ++f[c - 'a'];
    }

    vector<vector<mint>> c(5005, vector<mint>(5005));
    c[0][0] = 1;
    rep(i, 5000)rep(j, 5000)
    {
        c[i + 1][j] += c[i][j];
        c[i + 1][j + 1] += c[i][j];
    }

    vector<vector<mint>> dp(27, vector<mint>(5005));
    int now = 0;
    dp[0][0] = 1;
    reps(i, 1, 27)
    {
        int m = f[i - 1];
        now += m;
        for (int j = now; j >= 0; --j)
        {
            rep(k, m + 1)
            {
                if (j - k < 0)
                {
                    break;
                }
                dp[i][j] += dp[i - 1][j - k] * c[j][k];
            }
        }
    }
    mint ans = 0;
    rep(i, 5005)
    {
        ans += dp[26][i];
    }
    cout << ans.x - 1 << endl;

    return 0;
}
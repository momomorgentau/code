//1442
//abc167_e_colorful_blocks
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

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
mint comb(int n, int a)
{
    mint x = 1, y = 1;
    rep(i, a)
    {
        x *= (ll)n - i;
        y *= (ll)i + 1;
 
    }
    return x / y;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    mint ans;
    mint tans = m;
    rep(i,n-k-1)
    {
        tans *= (m-1);
    }
    ans = 0;
    mint c = comb(n-1,k);
    for(int i=k;i>0;--i)
    {
        ans += tans * c;
        mint tn = n-i;
        mint ti = i; 
        c *= (ti / tn);
        //c = comb(n-1,i);
        tans *= (m-1);
    }
    ans += tans;
    cout << ans.x << endl;

    return 0;
}
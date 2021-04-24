//015
//*6
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

//first:2020/12/05

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

const int M = 100100;
mint fact[M];

mint ncr(int n,int r)
{
    if(n < r) return -1;
    return fact[n] / (fact[n-r]*fact[r]);
}

int main()
{
    int n;
    cin >> n;
    fact[0] = 1;
    for(int i = 1;i<M-1;++i)
    {
        fact[i] = fact[i-1]*i;
    }
    for(int k = 1;k<=n;++k )
    {
        mint ans = 0;
        for(int a=1;a<=(n+k-1)/k;++a)
        {
            ans += ncr(n-(k-1)*(a-1),a);
        }
        cout << ans.x << endl;
    }
    return 0;
}

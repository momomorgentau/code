//----------------------------
//ABC 262 E
//Red and Blue Graph
//1719
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

template<class T>
class Comb
{
private:
    vector<T> v;
public:
    // 0indexed
    T aCbCalc(int a, int b)
    {
        if (b > a)
        {
            cout << "error" << endl;
        }
        b = min({ b, a - b, 0 });
        T res = 1;
        for (int i = 0; i < b; ++i)
        {
            res *= a - i;
            res /= i + 1;
        }
        return res;
    }

    // mintの場合を想定してテーブルを事前に用意します
    T aCb(int a, int b)
    {
        if (a < b)return 0;
        if (a < 0 || b < 0) return 0;
        return v[a] / v[b] / v[a - b];
    }
    //***********************
    // a - 種類数
    // b - 総数
    //***********************
    T aHb(int a, int b)
    {
        if (a <= 0)
        {
            cout << "error" << endl;
        }
        return v[a - 1 + b] / v[a - 1] / v[b];
    }

    void Set(int n)
    {
        v.resize(n + 1);
        v[0] = 1;
        for (int i = 1; i < n + 1; ++i)
        {
            v[i] = (T)i * v[i - 1];
        }
    }

};


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> e(n);
    rep(i, m)
    {
        int u, v; cin >> u >> v;
        --u, --v;
        ++e[u];
        ++e[v];
    }
    int odd = 0;
    rep(i, n) odd += e[i] % 2;
    mint ans = 0;
    Comb<mint> comb;
    comb.Set(n + 1);
    for (int i = 0; i <= odd; i += 2)
    {
        ans += comb.aCb(odd, i) * comb.aCb(n - odd, k - i);
    }
    cout << ans.x << endl;
    return 0;
}
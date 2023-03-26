//----------------------------
// ABC 295 E
// Kth Number
// 2157
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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
            return -1;
        }
        b = min({ b, a - b });
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
    vector<int> a;
    int z = 0;
    rep(i, n)
    {
        int ai; cin >> ai;
        if (ai == 0) z++;
        else a.emplace_back(ai);
    }

    vector<mint> f(m + 1);
    Comb<mint> comb;
    comb.Set(n + 5);

    rep(i, m + 1)
    {
        int s = 0;
        for (const auto& e : a) s += (e <= i);
        // z個ある0のうちj個をi以下にします
        rep(j, z + 1)
        {
            if (s + j >= k) break;
            mint now = 0;
            now += comb.aCb(z, j);
            now *= mint(i).pow(j);
            now *= mint(m - i).pow(z - j);
            f[i] += now;
        }

    }
    mint ans = 0;
    reps(i, 1, m + 1)
    {
        /*
        x-1 以下が k コ未満 → k 番目は x   以上 : f[x-1]
        x   以下が k コ未満 → k 番目は x+1 以上 : f[x]

        → k 番目は x となる                    ： f[x-1] - f[x]
        */
        ans += (f[i - 1] - f[i]) * mint(i);
    }
    ans /= mint(m).pow(z);
    cout << ans.x << endl;
    return 0;
}
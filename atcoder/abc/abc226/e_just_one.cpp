//----------------------------
//ABC_226_E
//Just One
//1327
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int mod = 998244353;
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


const int N = 2e5 + 5;
vector<vector<int>> g(N);
vector<int> used(N);
vector<int> d(N);

void dfs(int a, int& t, int& q)
{
    for (const auto& e : g[a])
    {
        if (!used[e])
        {
            q += d[e];
            t += 1;
            used[e] = 1;
            dfs(e, t, q);
        }
    }
}



int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        d[u]++, d[v]++;
    }
    int s = 0;
    bool ok = true;
    rep(i, n)
    {
        if (used[i]) continue;
        int q = d[i];
        int t = 1;
        used[i] = 1;
        dfs(i, t, q);
        if (t != q / 2)
        {
            ok = false;
            break;
        }
        else
        {
            s++;
        }
    }
    mint ans = 0;
    if (ok) ans = mint(2).pow(s);
    cout << ans.x << endl;
    return 0;
}
//ABC_201_E
//Xor_Distances
//1694
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
vector<vector<pair<int, ll>>> g;

vector<int> used;
vector<vector<int>> x;
void dfs(int s)
{
	for (auto [e, w] : g[s])
	{
	    if (used[e]) continue;
		used[e] = 1;
		rep(i, 60)
		{
			x[e][i] = x[s][i] ^ (w>>i & 1);
		}
		dfs(e);
	}

}

int main()
{
	int n;
	cin >> n;
	g.resize(n);
	used.resize(n);
	x.resize(n);
	rep(i, n) x[i].resize(60,0);
	rep(i, n-1)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u, --v;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	used[0] = 1;
	dfs(0);
    mint ans = 0;
	rep(i, 60)
	{
		int zero = 0;
	    int one = 0;
		rep(j, n)
		{
			if (x[j][i] == 0) ++zero;
			else ++one;
		}
		mint bit = 1LL << i;
        ans += bit * zero * one;
	}
	cout << ans.x << endl;


	return 0;
}
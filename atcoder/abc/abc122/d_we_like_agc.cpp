//ABC_122_D_We_Like_AGC
//1533
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1e9+7;
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
mint dp[105][4][4][4];
/*
A 0
T 1
C 2
G 3

prohibit
#ACG #023
#AGC #032
#GAC #302
A#GC 0#32
AG#C 03#2
*/


int main()
{
    int n;
    cin >> n;
    rep(i,4)rep(j,4)rep(k,4) dp[3][i][j][k] = 1;
    dp[3][0][2][3] = 0;
    dp[3][0][3][2] = 0;
    dp[3][3][0][2] = 0;

    for(int idx = 3;idx < n; ++idx)
    {
        rep(i,4)rep(j,4)rep(k,4)rep(l,4)
        {
            if(j == 0 && k == 3 && l == 2) continue;
            if(j == 0 && k == 2 && l == 3) continue;
            if(j == 3 && k == 0 && l == 2) continue;
            if(i == 0 && k == 3 && l == 2) continue;
            if(i == 0 && j == 3 && l == 2) continue;
            
            dp[idx+1][j][k][l] += dp[idx][i][j][k];
        }
    }
    mint ans = 0;
    rep(i,4)rep(j,4)rep(k,4) ans += dp[n][i][j][k];
    cout << ans.x << endl;
    return 0;
}
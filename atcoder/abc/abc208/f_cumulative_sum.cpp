//ABC_208_F
//Cumulative Sum
//2772

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using T = tuple<int, int, int>;

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


int main()
{
    ll n,m,k;
    cin >> n >> m >> k;
    int d = m+k;
    //まず愚直な計算でd*dの表を埋める
    vector<vector<mint>> table(d+1,vector<mint> (m+1));
    rep(i,d+1) table[i][0] = mint(i).pow(k);
    reps(i,1,d+1)reps(j,1,m+1)
    {
        table[i][j] = table[i-1][j] + table[i][j-1];
    }

    //n<=dなら表から答えを出力して終了する
    if(n <= d)
    {
        cout << table[n][m].x << endl;
        return 0;
    }
    //ラグランジュ補間の分子
    vector<mint> mol_l(d+2), mol_r(d+2);
    mol_l[0] = 1;
    mol_r[d+1] = 1;
    rep(i,d+2) 
    {
        mol_l[i+1] = mol_l[i]*mint(n-i);
        mol_r[d-i] = mol_r[d-i+1] * mint(n-(d-i));
    }

    //分母
    vector<mint> den(d+1);
    den[0] = 1;
    rep(i,d) den[i+1] = den[i] * (i+1);

    //ラグランジュ補間の各項の計算
    mint ans = 0;
    rep(i,d+1)
    {
        mint Li = mol_l[i] * mol_r[i+1];
        Li /= den[i] * mint(-1).pow(d-i) * den[d-i];
        ans += table[i][m]*Li; 
    } 
    cout << ans.x << endl;    
    return 0;
}
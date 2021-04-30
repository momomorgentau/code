//ABC_199_F
//Graph_Smoothing
//2065

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

//modint ライブラリ
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
    //逆元
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
//行列の構造体
struct Matrix
{
    int s;
    mint A[100][100];
};
//行列計算
Matrix cal_matrix(Matrix X, Matrix Y)
{
    int s = X.s;
    Matrix Z = {s};
    rep(i,s)rep(j,s) Z.A[i][j] = 0;
    //xとyのサイズが同じとする
    rep(i,s)rep(j,s)rep(k,s)
    {
        Z.A[i][j] += X.A[i][k]*Y.A[k][j];
    }
    return Z;
}
//行列の繰り返し２乗法
Matrix matrix_pow(Matrix X,ll n)
{
    Matrix table[64];
    Matrix An = X;

    //A^(2n)を計算
    for(int i = 0;i<64;++i)
    {
        table[i] = An;
        An = cal_matrix(An,An);
    }
    //基本行列
    Matrix I = {X.s};
    rep(i,X.s)rep(j,X.s)
    {
        if(i==j) I.A[i][j] = 1;
        else I.A[i][j] = 0;
    }
    if(n == 0) return I;
    //繰り返し2乗法
    for(int i = 0;i < 64;++i)
    {
        if(n & (1LL<<i)) I = cal_matrix(I,table[i]);
    }

    return I;
}
//繰り返し２乗法
mint pow_mod(mint x,int n)
{
    if(n == 0) return 1;
    mint table[64];
    for(int i=0;i<60;++i)
    {
        table[i] = x;
        x = x*x;
    }
    mint res = 1;
    for(int i = 0;i < 64;++i)
    {
        if(n & (1LL<<i)) res *= table[i];
    }
    return res;
}
bool g[100][100];

int main()
{
    int n,m,k;
    cin>> n >> m >> k;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    //頂点の次数
    vector<int> D(n);
    rep(i,m)
    {
        int a,b;cin >> a >> b;
        --a,--b;
        g[a][b] = true;
        g[b][a] = true;
        ++D[a],++D[b];
    }
    Matrix F;
    F.s = n;
    //行列の作成
    //分子だけ計算する
    rep(i,n)rep(j,n)
    {
        if(i==j)F.A[i][j] = 2*(m-D[i])+D[i];
        else
        {
            if(g[i][j]) F.A[i][j] = 1;
            else F.A[i][j] = 0;
        }
    }
    //繰り返し2情報で行列累乗
    F = matrix_pow(F,k);
    //分母の計算
    mint x = 2*m;
    x = pow_mod(x,k); 
    //累乗した行列に対して計算する
    mint Y[100];
    rep(i,n)
    {
        rep(j,n)
        {
            Y[i] += F.A[i][j]*A[j];
        }
    }
    //分母の逆元に分子をかける
    rep(i,n)
    {      
        cout << (x.inv()*Y[i]).x << endl;
    }
    return 0;
}
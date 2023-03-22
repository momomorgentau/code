//----------------------------
// ABC 293 E
// Geometric Progression
// 1453
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//modint
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

//Matrix
struct Matrix
{
    int s;
    mint A[30][30];
};

Matrix cal_matrix(Matrix X, Matrix Y)
{
    int s = X.s;
    Matrix Z = { s };
    rep(i, s)rep(j, s) Z.A[i][j] = 0;
    //x‚Æy‚ÌƒTƒCƒY‚ª“¯‚¶‚Æ‚·‚é
    rep(i, s)rep(j, s)rep(k, s)
    {
        Z.A[i][j] += X.A[i][k] * Y.A[k][j];
    }
    return Z;
}

Matrix Matrix_pow(Matrix X, ll n)
{
    Matrix table[64];
    Matrix An = X;

    //A^(2n)‚ðŒvŽZ
    for (int i = 0; i < 64; ++i)
    {
        table[i] = An;
        An = cal_matrix(An, An);
    }
    //Šî–{s—ñ
    Matrix I = { X.s };
    rep(i, X.s)rep(j, X.s)
    {
        if (i == j) I.A[i][j] = 1;
        else I.A[i][j] = 0;
    }
    //ŒJ‚è•Ô‚µ2æ–@
    for (int i = 0; i < 64; ++i)
    {
        if (n & (1LL << i)) I = cal_matrix(I, table[i]);
    }

    return I;
}

int main()
{
    ll a, x, m;
    cin >> a >> x >> m;
    mod = m;
    Matrix mx;
    mx.s = 2;
    mx.A[0][0] = a;
    mx.A[0][1] = 1;
    mx.A[1][0] = 0;
    mx.A[1][1] = 1;
    mx = Matrix_pow(mx, x);
    mint ans = mx.A[0][1];
    cout << ans.x << endl;
    return 0;
}
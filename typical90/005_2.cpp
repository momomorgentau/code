//005
//*7
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
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



struct Matrix
{
    int s;
    mint A[35][35];
    //vector<vector<mint>> A(s,vector<mint> (s));
};

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

Matrix Matrix_pow(Matrix X,ll n)
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
    //繰り返し2乗法
    for(int i = 0;i < 64;++i)
    {
        if(n & (1LL<<i)) I = cal_matrix(I,table[i]);
    }

    return I;
}

int main() 
{
    ll n;
    int b,k;
    cin >> n >> b >> k;
    vector<int> c;
    rep(i,k)
    {
        int ci; cin >> ci;
        c.emplace_back(ci);
    }
    //A0をつくる
    Matrix A0 = {b};
    rep(q,b)
    {
        for(auto add:c)
        {
            int qi = (10*q + add) % b;
            A0.A[qi][q] += 1;
        }
    }
    Matrix ANS = Matrix_pow(A0,n);
    cout << ANS.A[0][0].x << endl;
	return 0;
}
    /*
int main()
{
    ll n;
    int b,k;
    cin >> n >> b >> k;
    vector<int> c;
    rep(i,k)
    {
        int ci; cin >> ci;
        c.emplace_back(ci);
    }
    Matrix A0 = {b};
    rep(q,b)
    {
        for(auto add:c)
        {
            int qi = (q + add) % b;
            A0.A[qi][q] += 1;
        }
    }


    rep(i,7)
    {
        rep(j,7) cout << A0.A[i][j].x << " ";
        cout << endl;
    }





}
    */
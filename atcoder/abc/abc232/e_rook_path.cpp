//----------------------------
//ABC 232 E
//Rook Path
//1380
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

int main()
{
    int h, w, k;
    int x1, y1, x2, y2;
    cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;

    mint ff = 0;
    mint ft = 0;
    mint tf = 0;
    mint tt = 0;

    if (x1 == x2 && y1 == y2)
    {
        tt = 1;
    }
    else if (x1 == x2)
    {
        tf = 1;
    }
    else if (y1 == y2)
    {
        ft = 1;
    }
    else
    {
        ff = 1;
    }
    rep(i, k)
    {
        mint tff = 0;
        mint tft = 0;
        mint ttf = 0;
        mint ttt = 0;

        tff += ff * (w - 2) + ff * (h - 2);
        tft += ff * 1 + ff * 0;
        ttf += ff * 0 + ff * 1;
        ttt += ff * 0 + ff * 0;

        tff += ft * (w - 1) + ft * 0;
        tft += ft * 0 + ft * (h - 2);
        ttf += ft * 0 + ft * 0;
        ttt += ft * 0 + ft * 1;

        tff += tf * 0 + tf * (h - 1);
        tft += tf * 0 + tf * 0;
        ttf += tf * (w - 2) + tf * 0;
        ttt += tf * 1 + tf * 0;

        tff += tt * 0 + tt * 0;
        tft += tt * 0 + tt * (h - 1);
        ttf += tt * (w - 1) + tt * 0;
        ttt += tt * 0 + tt * 0;

        ff = tff;
        ft = tft;
        tf = ttf;
        tt = ttt;
    }

    cout << tt.x << endl;

    return 0;
}

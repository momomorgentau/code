//ABC_200_F
//Minflip Summation
//2556
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



int main()
{
	string s;
	int k;
    cin >> s >> k;

    int n = s.size();
    //コーナーケース
    if (n == 1 && k == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    //?の数を数える
    ll question = 0;
    for (auto c : s)
    {
        if (c == '?') ++question;
    }
    question *= k;
    //?乗したものが組み合わせ数
    mint comb = mint(2).pow(question);
    //循環を表現するために先頭を末尾に追加する
    s += s[0];
    mint ans = 0;
    rep(i, n)
    {
        int c1 = s[i];
        int c2 = s[i + 1];
        //?があったら、?は1個へるので1/2する
        if (c1 == '?' || c2 == '?')
        {
            ans += comb / 2;
        }
        //10, 01のときには組み合わせ数
        else
        {
            if (c1 != c2) ans += comb;
        }
    }
    //k倍して/2するのを忘れない
    ans *= k;
    ans /= 2;

    cout << ans.x << endl;
	return 0;
}
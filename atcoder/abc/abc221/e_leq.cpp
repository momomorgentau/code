//----------------------------
//ABC_221_E
//LEQ
//1515
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

//0-indexed
template<class T, T(*op)(T, T), T(*e)()>
class segtree
{
private:
    int n;
    vector<T> v;
public:
    segtree(int n_)
    {
        int x = 1;
        while (n_ > x) x <<= 1;
        n = x;
        v.resize(2 * n - 1, e());
    }
    void set(int k, T x)
    {
        k += n - 1;
        v[k] = x;
        while (k > 0)
        {
            k = (k - 1) / 2;
            v[k] = op(v[k * 2 + 1], v[k * 2 + 2]);
        }
    }
    T get(int k) { return v[k + n - 1]; }
    //[a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return e();
        if (a <= l && r <= b) return v[k];
        T c1 = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
        T c2 = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
        return op(c1, c2);
    }

    //display segtree value
    void display(string text = "segtree value")
    {
        cout << text << endl;
        int cnt = 0;
        int end = 1 << cnt;
        int l = v.size();
        for (int i = 0; i < l; ++i)
        {
            cout << v[i] << " ";
            //cout << v[i] << " ";
            if (i == end - 1)
            {
                ++cnt;
                end += 1 << cnt;
                cout << endl;
            }
        }
        cout << endl;
    }
};

mint op(mint a, mint b)
{
    return a + b;
}

mint e() { return 0; }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    set<int> s;
    rep(i, n) s.insert(a[i]);
    vector<int> v;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        v.emplace_back(*it);
    }
    vector<int> b;
    for (const auto& ai : a)
    {
        b.emplace_back(lower_bound(v.begin(), v.end(), ai) - v.begin());
    }
    segtree<mint, op, e> st(s.size());
    st.set(b[0], 1);
    mint ans = 0;

    reps(i, 1, n)
    {
        mint p = mint(2).pow(i - 1);
        ans += p * st.query(0, b[i] + 1);
        st.set(b[i], st.get(b[i]) + mint(1) / (p * 2));
    }

    cout << ans.x << endl;




    return 0;
}
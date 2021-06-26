//ABC_201_F
//Insertion_SOrt
//2484
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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

ll op(ll a, ll b) { return max(a, b); }
ll e() { return 0; }

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    rep(i, n) --p[i];
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    rep(i, n) b[i] = min(b[i], a[i]);
    rep(i, n) c[i] = min(c[i], a[i]);
    vector<int> q(n);
    rep(i, n)q[p[i]] = i;

    segtree<ll,op,e> seg(n);
    ll sl = 0,sr = 0;
    rep(i, n) sr += a[i] - c[i];
    ll ans = 0;

    rep(i, n)
    {

        //i番目までに1つでも固定している場合
        //iを小さい順に更新するため、
        //iより大きな値が左にあっても0となっている
        ll now = seg.query(0,q[i]) + a[i];

        //i番目で初めて固定した場合
        now = max(now, sl+a[i]);
        //セグ木の更新
        seg.set(q[i], now);

        //区間和の更新
        sl += a[i]-b[i];
        //判定の前にsrからa[i]-c[i]を取り除く、
        //i番目は固定している（a[i]-c[i]の割引は使えない）
        sr -= a[i]-c[i];

        //１）今のans
        //２）now(iを含めて左の値)とsr（iより右の値）の和
        //この2つを比べる
        ans = max(ans, now+sr);
    }
    ans *= -1;
    rep(i, n) ans += a[i];
    cout << ans << endl;

    return 0;
}
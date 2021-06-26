//037
//Dont_Leave_the_Spice
//*5

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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

const ll INF = 1e18;
ll op(ll a, ll b) { return max(a, b); };
ll e() { return -INF; };

int main()
{
    int w, n;
    cin >> w >> n;
    segtree<ll, op, e> segtree(w+1);
    segtree.set(0, 0);
    while (n--)
    {
        int l, r, v;
        cin >> l >> r >> v;
        for (int i = w; i >= l; --i)
        {
            ll now = segtree.query(max(0,i-r), i-l+1);
            segtree.set(i,max(segtree.get(i),now+v));
        }
    }
    ll ans = segtree.get(w);
    if (ans < 0) ans = -1;
    cout << ans << endl;
	return 0;
}
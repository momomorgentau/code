#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<typename T>
struct segtree {
    const T inf = numeric_limits<T>::max();
    int n;
    vector<T> v;
    segtree(int n_) { //ˆø”‚Ìn‚¾‚©‚çn_,struct“à‚Ìn‚Æ‹æ•Ê‚·‚éB
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
        v.resize(2 * n - 1, inf);
    }

    void update(int k, T x) {
        k += n - 1;
        v[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            v[k] = min(v[k * 2 + 1], v[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return inf;
        if (a <= l && r <= b) return v[k];
        T c1 = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
        T c2 = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(c1, c2);
    }
};
int main() {
    ll n, q;
    cin >> n >> q;
    int mx, my;
    mx = n - 2, my = n - 2;

    segtree<int> sgx(n - 2);
    segtree<int> sgy(n - 2);
    rep(i, n - 2) sgx.update(i, n - 2);
    rep(i, n - 2) sgy.update(i, n - 2);
    ll w = 0;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        b -= 2;
        if (a == 1) {
            int y = sgx.query(b, n - 1);
            w += y;
            if (mx > b) {
                sgy.update(y - 1, b);
                mx = b;
            }
        }
        else {
            int x = sgy.query(b, n - 1);
            w += x;
            if (my > b) {
                sgx.update(x - 1, b);
                my = b;
            }
        }
    }
    ll ans = (n - 2) * (n - 2);
    ans -= w;
    cout << ans << endl;



    return 0;
}
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
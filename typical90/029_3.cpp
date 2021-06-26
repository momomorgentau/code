//029
//*5
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
//0-indexed
template<class T, T(*op)(T, T), T(*e)()>
class lazy_segtree
{
private:
    int n;
    vector<T> v,L;
public:
    lazy_segtree(int n_)
    {
        int x = 1;
        while (n_ > x) x <<= 1;
        n = x;
        v.resize(2 * n - 1, e());
        L.resize(2 * n - 1,0);
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
    void eval(int k)
    {
        if(L[k] == e()) return;
        if(k < n-1)
        {
            L[k*2+1] = L[k];
            L[k*2+2] = L[k];
        }
        v[k] = L[k];
        L[k] = e();
    }
 
    //[a,b)
    void update(int a, int b, T x) { update_sub(a, b, x,0, 0, n); }
    void update_sub(int a, int b, T x ,int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b)
        {
            L[k] = x;
            eval(k);
        }
        else if(a < r && l < b)
        {
            update_sub(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update_sub(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            v[k] = op(v[k * 2 + 1], v[k * 2 + 2]);

        }
    }

    
    T get(int k) { return v[k + n - 1]; }
    //[a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) 
    {
        eval(k);
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
const int INF = 1e9;
int op(int a, int b) { return max(a,b); }
int e() { return -INF; }

int main()
{
    int n,w;
    cin >> w >> n;
    lazy_segtree<int,op,e> lsg(w);
    rep(i,w) lsg.set(i,0);
    rep(i,n)
    {
        int l,r; cin >> l >> r;
        int ans = lsg.query(l-1,r)+1;
        printf("%d\n",ans);
        lsg.update(l-1,r,ans);
    }
    return 0;
}
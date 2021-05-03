//ABC_190_F_Shift_and_Inversions
//1321
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


//bit
template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    BIT(int n = 0) :n(n), bit(n + 1) {}
    void add(int i, T x = 1) {
        for (i++; i <= n; i += i & -i) {
            bit[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i & -i) {
            x += bit[i];
        }
        return x;
    }
    void debug()
    {
        for (auto b : bit) cout << b << " ";
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> ans(n);
    BIT<ll> bit(n);
    bit.add(a[n-1], 1);
    for(int i = n-2;i>=0;--i)
    {
        ans[0] += bit.sum(a[i]);
        bit.add(a[i], 1);
    }
    rep(i,n-1)
    {
        //+(n-1-ai) - ai
        ans[i+1] = ans[i]+((ll)n - 1 - 2 * a[i]);
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
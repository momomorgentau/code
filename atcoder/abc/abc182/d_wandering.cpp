//656
//abc182d_wandering
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

const ll inf = 1e18;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> sa(n);
    vector<ll> ma(n);
    sa[0] = a[0];
    reps(i, 1, n) sa[i] = a[i] + sa[i - 1];
    ll tm = 0;
    ll np = 0;
    rep(i, n)
    {
        np += a[i];
        tm = max(np, tm);
        ma[i] = tm;
    }

    np = 0;
    ll ans = 0;
    rep(i, n)
    {
        ans = max(ans, np + ma[i]);
        np += sa[i];
    }
    cout << ans << endl;
    return 0;

}

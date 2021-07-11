//64
//Uplift
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), d(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) d[i] = a[i] - a[i + 1];
    ll ans = 0;
    for (auto di : d) ans += abs(di);

    while (q--)
    {
        int l, r, v;
        cin >> l >> r >> v;
        --l; --r;
        if (l > 0)
        {
            ll vor = d[l - 1];
            d[l - 1] -= v;
            ans += abs(d[l - 1]) - abs(vor);
        }
        if (r < n - 1)
        {
            ll vor = d[r];
            d[r] += v;
            ans += abs(d[r]) - abs(vor);
        }
        cout << ans << endl;

    }
    return 0;
}
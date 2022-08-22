//----------------------------
//ABC 265 B
//Explore
//152
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n - 1);
    rep(i, n - 1) cin >> a[i];
    vector<ll> p(n, 0);
    rep(i, m)
    {
        ll x, y;
        cin >> x >> y;
        --x;
        p[x] = y;
    }
    bool ok = true;
    rep(i, n - 1)
    {
        t += p[i];
        t -= a[i];
        if (t <= 0) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
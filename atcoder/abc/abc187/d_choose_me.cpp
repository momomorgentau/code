//ABC_187_D_Choose_Me
//650
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main() 
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll sa = 0;
    rep(i, n) sa += a[i];
    vector<ll> d(n);
    rep(i, n)d[i] = a[i] + a[i] + b[i];
    
    sort(d.begin(), d.end(), greater<ll>());
    int ans = 0;
    rep(i, n)
    {
        sa -= d[i];
        ans++;
        if (sa < 0) break;
    }
    cout << ans << endl;
    return 0;
}
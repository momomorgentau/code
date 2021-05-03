//ABC_186_D_Sum_of_difference
//436
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    sort(a.begin(), a.end(),greater<int>());
    vector<ll> s(n+1);
    s[n] = 0;
    rep(i, n)
    {
        s[n - 1 - i] = s[n - i] + a[n - 1 - i];
    }
    ll ans = 0;
    rep(i, n)
    {
        ans += (ll)a[i] * ((ll)n - 1 - i) - s[i + 1];
    }
    cout << ans << endl;

    return 0;
}
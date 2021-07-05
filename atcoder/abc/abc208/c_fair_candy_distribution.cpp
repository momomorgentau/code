//ABC_208_C
//Fair Candy Distribution
//142
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<P> a(n);
    rep(i, n)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<ll> ans(n);
    ll base = 0;
    base = k / n;
    k %= n;
    rep(i, k)
    {
        ans[a[i].second]++;
    }
    rep(i, n) cout << ans[i] + base << endl;
    return 0;
}
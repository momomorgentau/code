//ABC_209_C
//Not Equal
//285
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    ll ans = 1;
    vector<ll> c(n);
    rep(i, n) cin >> c[i];
    sort(c.begin(), c.end());
    rep(i, n)
    {
        ans *= max(0LL, c[i] - i);
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}
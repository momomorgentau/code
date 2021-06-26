//ABC_206_E
//Divide_Both
//1745

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


int main()
{
    int l,r;
    cin >> l >> r;
    ll ans = 0;
    vector<ll> f(r + 1,0);
    for (ll g = r; g >= 2; --g)
    {
        ll m = r / g - (l - 1) / g;
        f[g] += m * m;
        for (int t = 2 * g; t <= r; t += g)
        {
            f[g] -= f[t];
        }
        ans += f[g];
    }
    for (int i = max(2,l); i <= r; ++i)
    {
        ans -= r / i*2-1;
    }
    cout << ans << endl;
    return 0;
}